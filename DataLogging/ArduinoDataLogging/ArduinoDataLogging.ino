#define BAUD_RATE 9600
#define STRAIN_OUTPUT A0
#define STRAIN_REFERENCE A1

unsigned int Start;
unsigned int End;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  Start = millis();
  Serial.print("A0:");
  Serial.print( analogRead(STRAIN_OUTPUT) );
  Serial.print(",A1:");
  Serial.print( analogRead(STRAIN_REFERENCE) ); 
  End = millis();
  Serial.print(",Time:");
  Serial.println(End - Start);
}
