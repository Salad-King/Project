#include<SPI.h>
#include<RF24.h>

RF24 radio(9,10);

void setup(void){
	radio.begin();
	radio.setPALevel(RF24_PA_MAX);
	radio.setChannel(0x76);
	radio.openWritingPipe(0xF0F0F0F0E1LL);
	radio.enableDynanamicPayloads();
	radio.powerUp();
}

void loop(void){
	const char text[] = "Data sent from arduino";
	radio.write(&text,sizeof(text))
	delay(1000);
}