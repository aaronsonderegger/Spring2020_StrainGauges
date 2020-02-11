 // ** Preprocessor Commands **
#define TopGauge 9
#define BottomGauge 3
#define VoltageIn A0

// ** Data Type Definitions **

// ** Global Variables **
int ForceX = 0;
int ForceY = 0;
int Reading = 0;

// ** Function Prototypes **

// ** Main Functions **
void setup() {
  Serial.begin(9600);
  pinMode(TopGauge, OUTPUT);
  pinMode(BottomGauge, OUTPUT);
}

void loop() {
  Reading = analogRead(VoltageIn);
  Serial.println(Reading);
//  analogWrite(TopGauge, Reading/4);
  analogWrite(BottomGauge, Reading/4);
}

// ** Helper Functions **

