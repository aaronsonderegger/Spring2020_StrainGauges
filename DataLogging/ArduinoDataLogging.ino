#define BAUD_RATE 115200
#define STRAIN_OUTPUT A0
#define STRAIN_REFERENCE A1

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  Serial.print( analogRead(STRAIN_OUTPUT) );
  Serial.print(" ");
  Serial.println( analogRead(STRAIN_REFERENCE) ); 
}
