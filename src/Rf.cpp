/*
 * Rf.cpp
 *
 * Created: 30.01.2018 22:26:49
 *  Author: Bogdan
 */ 
#include "Rf.h"
#include "RF24HALChibios.h"
#include "NRF24Devices\SensorButtonDevice.h"

extern nrf24dev::SensorButtonDevice nrfButtonDev;

void Rf::init(){
	radio_hal = new RF24HAL_Chibios();
	radio = new RF24(radio_hal);
	
  radio->begin();                           // Setup and configure rf radio
  radio->setChannel(2);
  radio->setPALevel(RF24_PA_MAX);
  radio->setDataRate(RF24_1MBPS);
  radio->setAutoAck(1);                     // Ensure autoACK is enabled
  radio->setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries
  radio->setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance
  radio->setPayloadSize(1);

      radio->openWritingPipe(nrfButtonDev.GetAddress());
      //radio->openReadingPipe(1,addresses[0]);
	  radio->stopListening();
	radio->powerDown();
}

int Rf::send_payload(uint8_t* buf, uint8_t len) {
	if (len > 32) 
		return -1;
		
	radio->powerUp();
	radio->write(buf, len);
	radio->powerDown();
}