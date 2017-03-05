// the setup function runs once when you press reset or power the board
#include<SPI.h>
#include<RF24.h>
RF24 radio(9,10);


void setup() {
  pinMode(13, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.enableDynamicPayloads();
  radio.powerUp();
}

// the loop function runs over and over again forever
void loop() {
  float temperatureC = (5.0 * analogRead(A1) * 100.0) / 1024;
  
  String data = String(temperatureC);
  char info[10];
  data.toCharArray(info,10);
  Serial.println(info);
  radio.write(&info,sizeof(float)+1);
  
  delay(1000);
  
}