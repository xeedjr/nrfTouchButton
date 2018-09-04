/*
 * BL_Main.h
 *
 * Created: 28.12.2017 21:24:49
 *  Author: Bogdan
 */ 


#ifndef BL_MAIN_H_
#define BL_MAIN_H_

#include <cmsis_os.h>

class BL_Main {
	osThreadId thread_id;
	enum EvType {
		kSwitchPush = 1,	
		kSwitchRelease,	
	};
public:	
	BL_Main() {};
	~BL_Main() {};
	void init();

	void SwitchPress();
	void SwitchRelease();

	void iteration();
	
	
private:
		
};



#endif /* BL_MAIN_H_ */