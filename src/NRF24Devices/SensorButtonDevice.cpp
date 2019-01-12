/*
 * SensorButton.cpp
 *
 * Created: 12.01.2019 19:30:15
 *  Author: Bogdan
 */ 

#include "SensorButtonDevice.h"

namespace nrf24dev {
	
int SensorButtonDevice::init(uint32_t dev_id) {
	this->dev_id = dev_id;
}

int SensorButtonDevice::EncodeEvent(uint8_t button_id, Event ev, uint8_t* buf, uint8_t* max_len) {
	if (*max_len < 2) 
		return -1;
	
	buf[0] = button_id;
	buf[1] = ev;	
	*max_len = 2;
	
	return 0;
}

int SensorButtonDevice::DecodeEvent(uint8_t* buf, uint8_t max_len,
							 uint8_t* button_id, Event* ev) {
	if (max_len != 2)
		return -1;
	
	*button_id = buf[0];
	switch (buf[1]) {
		case Event::kPressed:
			*ev = Event::kPressed;
		break;
		case Event::kReleased :
			*ev = Event::kReleased;
		break;
	}	
	
	return 0;
}
			
uint64_t SensorButtonDevice::GetAddress(void) {
	uint64_t addr;
	addr = GROUP_ADDR;
	addr += dev_id;
	
	return addr;
}

}