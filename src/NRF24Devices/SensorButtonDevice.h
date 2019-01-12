/*
 * SensorButton.h
 *
 * Created: 12.01.2019 19:30:32
 *  Author: Bogdan
 */ 


#ifndef SENSORBUTTONDEVICE_H_
#define SENSORBUTTONDEVICE_H_

#include <stdint.h>

/***********************************
 ****************************
 * U8 buttID  *   U8 Event  *
 ****************************
*************************************/
namespace nrf24dev {
class SensorButtonDevice {
	#define GROUP_ADDR 0x7777000000LL
	uint32_t dev_id;
public:
	SensorButtonDevice() {};
	~SensorButtonDevice() {};
		
	enum Event {
		kPressed = 1,
		kReleased = 2,
	};
	
	int init(uint32_t dev_id);
	int EncodeEvent(uint8_t button_id, Event ev, uint8_t* buf, uint8_t* max_len);
	int DecodeEvent(uint8_t* buf, uint8_t max_len, uint8_t* button_id, Event* ev);
	uint64_t GetAddress(void);
};

}

#endif /* SENSORBUTTONDEVICE_H_ */