/*
 * CPPFile1.cpp
 *
 * Created: 28.12.2017 21:24:07
 *  Author: Bogdan
 */ 

#include "BL_Main.h"
#include "Rf.h"
#include "power_management.h"
#include "NRF24Devices\SensorButtonDevice.h"

extern Rf rf;
extern nrf24dev::SensorButtonDevice nrfButtonDev;

void BL_Main::init() {
	thread_id = osThreadGetId();
}

void BL_Main::SwitchPress() {
	osSignalSet(thread_id, kSwitchPush);
}

void BL_Main::SwitchRelease() {
	osSignalSet(thread_id, kSwitchRelease);
}

void BL_Main::iteration() {
	osEvent ev;
	
	ev = osSignalWait(0, osWaitForever);
	
	switch(ev.value.signals) {
	case kSwitchPush:
		{
			uint8_t buf[5];
			uint8_t len = sizeof(buf);
			nrfButtonDev.EncodeEvent(1, nrf24dev::SensorButtonDevice::kPressed, buf, &len);
			rf.send_payload(buf, len);
		};
		break;
	case kSwitchRelease:
		{
			uint8_t buf[5];
			uint8_t len = sizeof(buf);
			nrfButtonDev.EncodeEvent(1, nrf24dev::SensorButtonDevice::kReleased, buf, &len);
			rf.send_payload(buf, len);
		};
		break;
	}
	
	enter_sleep_set(true);
}