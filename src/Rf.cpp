/*
 * Rf.cpp
 *
 * Created: 30.01.2018 22:26:49
 *  Author: Bogdan
 */ 
#include "Rf.h"
#include "RF24HALChibios.h"

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

      radio->openWritingPipe(addresses[1]);
      radio->openReadingPipe(1,addresses[0]);
	  radio->stopListening();
	radio->powerDown();

    /* init hardware pins */
 //   nrf24_init();
    
    /* Channel #2 , payload length: 4 */
  //  nrf24_config(2, 1);

    /* Set the device addresses */
  //  nrf24_tx_address(tx_address);
  //  nrf24_rx_address(rx_address);
}

void Rf::send(uint8_t status) {
	data_array[0] = status;
volatile uint8_t temp;
	radio->powerUp();

	if(!radio->write(data_array, 1)){     //Write to the FIFO buffers
		temp++;                      //Keep count of failed payloads
	}

	radio->powerDown();
/*
        // Automatically goes to TX mode 
        nrf24_send(data_array);
        
        // Wait for transmission to end 
        while(nrf24_isSending());

        // Make analysis on last tranmission attempt 
        temp = nrf24_lastMessageStatus();

        if(temp == NRF24_TRANSMISSON_OK)
        {
        }
        else if(temp == NRF24_MESSAGE_LOST)
        {
        }
        
        // Retranmission count indicates the tranmission quality 
        temp = nrf24_retransmissionCount();

        // Optionally, go back to RX mode ... 
        //nrf24_powerDown();      
		*/
}