import argparse
import serial
import time
import sys
import csv
import os
import matplotlib.pyplot as plt
import numpy as np
from SelectFromCollection import SelectFromCollection

DEBUG = True

'''
TODO:
    * have fileName be edited so that I don't need to worry about extensions
    * potentially change .txt to a csv file since it writes to it faster
    * 
'''

class DataDictionary:
    def __init__(self):
        self.DictValues = dict()
        self.Is_Empty = True
    
    def keys(self):
        return self.DictValues.keys()

    def values(self):
        return self.DictValues.values()

    def items(self):
        return self.DictValues.items()

    def IsEmpty(self):
        return self.Is_Empty

    def __getitem__(self, key):
        try:
            return self.DictValues[key]
        except:
            self.DictValues[key] = []
            self.Is_Empty = False

    def __setitem__(self, key,value):
        try:
            if isinstance(value,list):
                self.DictValues[key] = value
            else:
                self.DictValues[key].append(value)
        except:
            self.Is_Empty = False
            if isinstance(value,list):
                print('the value is', value)
                self.DictValues[key] = value
            else:
                self.DictValues[key] = [value]


# *** Global Variables ***
try:
    if os.name == 'posix':
        COM_PORT = '/dev/ttyUSB0'
        BAUD_RATE = 9600
    else:
        COM_PORT = 'COM3'

    SerialLogger = serial.Serial(COM_PORT, BAUD_RATE)
    SerialLogger.flushInput()
    IsSerialLoaded = True
except:
    print('Cannot load Serial properly. From the Terminal/Command Prompt use the following command:')
    print('\tWindows:\tmode')
    print('\tUbuntu: \tls /dev/ttyUSB*')
    print('to figure out your com-port number.\n')
    IsSerialLoaded = False

AaronsData = DataDictionary() 
TestSplitter = "***New Data***\n"
LoggedDataFolder = './LoggedData/'
txtExtension = '.txt'
csvExtension = '.csv'
# *** End Global Variables ***

# *** Helper Functions ***
def DataSelection():
    # Plot the Raw Data
    for k in AaronsData.keys():
        data = np.array(AaronsData[k])
        subplot_kw = dict(xlim=(-0.1*len(AaronsData[k]),len(AaronsData[k])+0.1*len(AaronsData[k])), 
                                ylim=(min(AaronsData[k])-0.1*max(AaronsData[k]),max(AaronsData[k])+0.1*max(AaronsData[k])),
                                autoscale_on =False )
        fig, ax = plt.subplots(subplot_kw=subplot_kw)
        pts = ax.scatter(np.array(range(0,len(data))),data,s=80)
        selector = SelectFromCollection(ax,pts)

        def accept(event):
            if event.key == "enter":
                AaronsData[k] = list(selector.xys[selector.ind][:,1])
                
                if DEBUG:
                    print("Selected points:")
                    print(AaronsData[k])

                selector.disconnect()
                ax.set_title("")
                fig.canvas.draw()
    
        fig.canvas.mpl_connect("key_press_event", accept)
        ax.set_title("Press enter to accept selected points." + k)
            
        plt.show()

def PlotData():
    print('TODO Implement this')

def ReadDataIn(fileName):
    loggedFile = open(fileName,"r")

    testNumber = 0
    # Read Logged Data File and put it into a Usable Format
    for line in loggedFile:
        if line == TestSplitter:
            testNumber += 1
        else:
            line = line.rstrip();
            line = line.split(',')
            for word in line:
                key, listItem = word.split(':')
                key += "_test" + str(testNumber)
                AaronsData[key] = int(listItem)

def ReadCommandPrompt(argv):
    '''
    For Help type -h:
    To change something from command line you type -a A1 or --actions A1 ...
    '''
    parser = argparse.ArgumentParser(description = 'Collect and Analyze Data')
    # parser.set_defaults(generateSolutions=False, edxOutput=False, muteOutput=False, print)
    # Variable -h cannot be used since default is help
    parser.add_argument('--dataLogging','-l',
                    dest = 'DATA_LOGGING',
                    type=str,
                    choices={'arduino','saleae','dont_run'},
                    required = False,
                    default = 'dont_run',
                    help = "Run Data Collecting from an arduino board, or saleae digital logic analyzer.")
    parser.add_argument('--stats','-s',
                    dest = 'STATISTICS',
                    type = str,
                    choices = {'all','stats','arduino','dont_run'},
                    required = False,
                    default = 'dont_run',
                    help = 'Run Statistics for user to analyze.')
    parser.add_argument('--file','-f',
                    dest = 'FILE',
                    type = str,
                    default = 'ERROR!',
                    help = 'Specified file for you to log or analyze from.')
    parser.add_argument('--dataSelect','-g',
                    dest = 'DATA_SELECT',
                    type = bool,
                    default = True,
                    help = 'Use the graphs to calculate specific data')
    arguments = parser.parse_args(argv[1:])
    return arguments
# *** End Helper Functions ***

def LogDataFromArduino(fileName):
    print('Logging Arduino, press Cntrl C to stop')
    # fileName = LoggedDataFolder + fileName + txtExtension
    print(fileName)

    if os.path.exists(fileName):
        print("file exists")
        loggingFile = open(fileName, "a")
        loggingFile.write(TestSplitter)
    else:
        print("file doesn't exists")
        loggingFile = open(fileName, "w")

    print("going into while loop")
    while True:
        try:
            ser_bytes = SerialLogger.readline()
            serialString = ser_bytes.decode()
            # serialString = serialString.rstrip()
            # Time start
            # start = time.time()

            loggingFile.write(serialString) # slower than csv writing but less commas and easier
                                            # for me to 
            # writer = csv.writer(loggingFile,delimiter=",")
            # writer.writerow(serialString)
            # end = time.time()
            print(serialString.rstrip())

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
            SerialLogger.close()
            loggingFile.close()
            break 
        except:
            e = sys.exc_info()[0]
            if DEBUG:
                print("Broke because:",str(e))
            SerialLogger.close()
            loggingFile.close()
            break
        finally:
            pass # left empty not handling closing things since breaks code

def LogDataFromSaleae(fileName):
    print('Logging Saleae')
    print(fileName)

    with open(fileName) as loggedFile:
        # Read Logged Data File and put it into a Usable Format
        count = 0
        breakIt = False
        print('Going into loop')
        columnMap = dict()
        for line in csv.reader(loggedFile,delimiter=','):
            if count > 1:
                for k in range(0,len(line)):
                    # print('line 215',k)

                    # Read the columns that don't contain time.
                    # Value is packed in as a string ' 3439' = 3.439
                    if '.' not in line[k]:
                        line[k] = line[k][0:2] + '.' + line[k][2:]
                    AaronsData[columnMap[k]] = float(line[k])
                    if k == 0 and float(line[k]) >= 1.0:
                        breakIt = True
                        break
            elif count == 1:
                for k in range(0,len(line)):
                    columnMap[k] = line[k]
                for k in columnMap.keys():
                    print(columnMap[k])
            if breakIt:
                break

            count += 1
            # if count == 10:
            #     # print(columnMap.keys())
            #     print('keys:',AaronsData.keys())
            #     print('items:',AaronsData.items())
            #     sys.exit()
    print(len(AaronsData[' Time [s]']))
    
def AnalyzeStatistics(fileName, selectData):
    print('Analyzing Statistics')
    print(fileName)

    if AaronsData.IsEmpty():
        ReadDataIn(fileName)

    # Plot the Data for me to select
    DataSelection()
    # PlotData()
    # Min and Max
    testMin = DataDictionary()
    testMax = DataDictionary()
    testMean = DataDictionary()
    testVariance = DataDictionary() # sample variance
    testSD = DataDictionary()

    currentTest = 0
    resultsFileName = fileName[:-4] + '_Results' + txtExtension    # [:-4 removes .txt from filename]
    resultsFile = open(resultsFileName, "w")
    for k in AaronsData.keys():
        testMin[k] = min(AaronsData[k])
        testMax[k] = max(AaronsData[k])
        if len(AaronsData[k]) > 0:
            testMean[k] = sum(AaronsData[k])/len(AaronsData[k])
            testVariance[k] = sum([(x - testMean[k][0])**2 for x in AaronsData[k]])/len(AaronsData[k])
            testSD[k] = testVariance[k][0]**0.5

        # Results for user
        resultsFile.write('Min for '                + k + ' is ' + str(testMin[k][0])      + '\n')
        resultsFile.write('Max for '                + k + ' is ' + str(testMax[k][0])      + '\n')
        resultsFile.write('Mean for '               + k + ' is ' + str(testMean[k][0])     + '\n')
        resultsFile.write('Variance for '           + k + ' is ' + str(testVariance[k][0]) + '\n')
        resultsFile.write('Standard Deviation for ' + k + ' is ' + str(testSD[k][0])       + '\n')

        if 'test' in k:
            if int(k.split('test')[-1]) != currentTest:
                resultsFile.write(TestSplitter)
                currentTest += 1

        print('Min for',               k,'is',testMin[k][0])
        print('Max for',               k,'is',testMax[k][0])
        print('Mean for',              k,'is',testMean[k][0])
        print('Variance for',          k,'is',testVariance[k][0])
        print('Standard Deviation for',k,'is',testSD[k][0])

def GetArduinoIformation(fileName):
    '''
    The purpose is to get analog data and convert it to 
    a format useful to arduino such as 0-5V as 0-1023.
    '''
    print('Getting Arduino Iformation')
    print(fileName)




# ** Main **
if __name__ == "__main__":
    print('os shows as ',os.name)
    options = ReadCommandPrompt(sys.argv)

    fileName = LoggedDataFolder + options.FILE + txtExtension
    # Data Logging Functions
    if options.DATA_LOGGING == 'dont_run':
        print('Not running any logging program\n')
    elif options.DATA_LOGGING.lower() == 'arduino':
        if IsSerialLoaded:
            LogDataFromArduino(fileName)
        else:
            print('Serial Not Connected')
    elif options.DATA_LOGGING.lower() == 'saleae':
        fileName = LoggedDataFolder + options.FILE + csvExtension
        LogDataFromSaleae(fileName)
    else:
        print('Data logging command is not recognized\n')

    # Data Processing Functions
    if options.STATISTICS == 'dont_run':
        print('Not running any anayzing program\n')
    elif options.STATISTICS.lower() == 'all':
        AnalyzeStatistics(fileName, options.DATA_SELECT)
        GetArduinoIformation(fileName)
    elif options.STATISTICS.lower() == 'stats':
        AnalyzeStatistics(fileName, options.DATA_SELECT)
    elif options.STATISTICS.lower() == 'arduino':
        GetArduinoIformation(fileName)
    else:
        print('Data statistics command is not recognized\n')