// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>
#define xpin A0
#define ypin A1
int x,y;
const int transmit_pin = 12;
char msg;
int flag=0;
void setup()
{   pinMode(xpin,INPUT);
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
}

void loop()
{   
   const char *msg = "a";
   
    if(Serial.available())
    {
      if(Serial.read()=='a')
      {
       while(1){
       digitalWrite(13, true); // Flash a light to show transmitting
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, false);
      delay(300);
      Serial.write("done");
      }
      }
   }
}
