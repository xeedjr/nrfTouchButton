/*
 * RF24HALChibios.h
 *
 *  Created on: 26 лют. 2018 р.
 *      Author: Bogdan
 */

#ifndef NRF24_RF24HALCHIBIOS_CONFIG_H_
#define NRF24_RF24HALCHIBIOS_CONFIG_H_

#include <hal.h>

#define RFM7x_USE_SPI SPID1
#define RFM7x_CSN_PORT IOPORT3
#define RFM7x_CSN_PAD (0)
#define RFM7x_CE_PORT IOPORT3
#define RFM7x_CE_PAD (1)

#endif /* NRF24_RF24HALCHIBIOS_CONFIG_H_ */
