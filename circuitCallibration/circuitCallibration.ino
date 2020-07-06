#define BAUD_RATE 9600
#define STRAIN_OUTPUT A0
#define SPRING_OUTPUT A1
String ANGLE = "A30";

unsigned int Start;
unsigned int End;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  
//  Serial.print( analogRead(STRAIN_OUTPUT) );
//  Serial.print(" ");
  Serial.println( analogRead(SPRING_OUTPUT) ); 
//
//  Serial.print("SG_"+ANGLE+":");
//  Serial.print( analogRead(STRAIN_OUTPUT) );
//  Serial.print(",SP_"+ANGLE+":");
//  Serial.println( analogRead(SPRING_OUTPUT) ); 
  
}
