/*
 * CPPFile1.cpp
 *
 * Created: 28.12.2017 21:24:07
 *  Author: Bogdan
 */ 

#include "BL_Main.h"
#include "Rf.h"
#include "power_management.h"

extern Rf rf;

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
		rf.send(1);
		break;
	case kSwitchRelease:
		rf.send(2);
		break;
	}
	
	enter_sleep_set(true);
}