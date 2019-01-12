/*
 * Rf.h
 *
 * Created: 30.01.2018 22:26:59
 *  Author: Bogdan
 */ 


#ifndef RF_H_
#define RF_H_

#include "RF24.h"
#include "RF24HAL.h"
//#include "nrf24.h"

class Rf {
	RF24HAL* radio_hal = nullptr;
	RF24* radio = nullptr;
	const uint64_t addresses[2] = { 0xD7D7D7D7D7LL, 0xE7E7E7E7E7LL };
	volatile uint8_t temp;
	uint8_t q = 0;
	//uint8_t data_array[32];
	//uint8_t tx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
	//uint8_t rx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};


public:
	Rf() {};
	~Rf() {};
	void init();
	int send_payload(uint8_t* buf, uint8_t len);
	
private:
};

#endif /* RF_H_ */