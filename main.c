/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K83
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"    // prototypes are in here as well

/*
    Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    STBY_SetLow();
    PWR_SetHigh();
    TMR0_StartTimer();
    
    uCAN_MSG rxMSG;
    uint16_t busOffCounter = 0;
    uint16_t counter = 0;
    uint8_t messageReceived = 0;
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    while (1) {
         //Check for bus activity to determine if device should sleep
        if (!CAN_receive(&rxMSG)) {         // I believe messages are filtered by the acceptance filter (module will ignore everything else?)
            busOffCounter++;
            messageReceived = 0;
            __delay_ms(5);
            } else {
            busOffCounter = 0;
            messageReceived = 1;
        }
        if (busOffCounter >= 2000){
            busOffCounter = 0;
            powerDown();                    // No activity on CAN bus, sleep.
        }
        if (((rxMSG.frame.data0 & 0x70) == 0x40) && messageReceived){
            messageReceived = 0;
            //rxMSG.frame.data0 = 0;
            counter++;
            if (counter > 50){
                counter = 0;
                //DIAG_Toggle();
                PWR_Toggle();
            }
            
        }
        ERR_LAT = (CAN_isRXErrorPassive() || CAN_isTXErrorPassive() || CAN_isBusOff());     // set ERR LED if bus error exists
    }
}

/**
 * Called by TMR0 ISR every 100ms
 */
void sendTPMSmessage() {
    //DIAG_Toggle();
    static uint8_t messageNumber = 0;             // keep track of current message to be sent
    uCAN_MSG MSG;

    MSG.frame.idType = dSTANDARD_CAN_MSG_ID_2_0B; // 1 = standard, 2 = extended
    MSG.frame.id = 0x333;
    MSG.frame.dlc = 8;

    switch (messageNumber) {
        case 0:
            MSG.frame.data0 = 0x00;
            MSG.frame.data1 = 0x00;
            MSG.frame.data2 = 0x00;
            MSG.frame.data3 = 0x00;
            MSG.frame.data4 = 0x00;
            MSG.frame.data5 = 0x00;
            MSG.frame.data6 = 0x00;
            MSG.frame.data7 = 0x0F;
            ERR_LAT = (!CAN_transmit(&MSG));            // Set error LED if message not sent 
            messageNumber++;
            break;

        case 1:
            MSG.frame.data0 = 0x00;
            MSG.frame.data1 = 0x00;
            MSG.frame.data2 = 0x00;
            MSG.frame.data3 = 0x00;
            MSG.frame.data4 = 0x00;
            MSG.frame.data5 = 0x00;
            MSG.frame.data6 = 0x00;
            MSG.frame.data7 = 0x1E;
            ERR_LAT = (!CAN_transmit(&MSG));            // Set error LED if message not sent 
            messageNumber++;
            break;

        case 2:
            MSG.frame.data0 = 0x00;
            MSG.frame.data1 = 0x00;
            MSG.frame.data2 = 0x00;
            MSG.frame.data3 = 0x00;
            MSG.frame.data4 = 0x00;
            MSG.frame.data5 = 0x00;
            MSG.frame.data6 = 0x00;
            MSG.frame.data7 = 0x2D;
            ERR_LAT = (!CAN_transmit(&MSG));            // Set error LED if message not sent 
            messageNumber++;
            break;
        case 3:
            MSG.frame.data0 = 0x00;
            MSG.frame.data1 = 0x00;
            MSG.frame.data2 = 0x00;
            MSG.frame.data3 = 0x00;
            MSG.frame.data4 = 0x00;
            MSG.frame.data5 = 0x00;
            MSG.frame.data6 = 0x00;
            MSG.frame.data7 = 0x3C;
            messageNumber = 0;
            ERR_LAT = (!CAN_transmit(&MSG));            // Set error LED if message not sent 


    }
}

void wakeUP(){
    STBY_SetLow();
    PWR_SetHigh();
    TMR0_StartTimer();
    //CANCONbits.REQOP = 0b000;       // CAN normal
}

void powerDown(){
    TMR0_StopTimer();
    canSleep();
    PWR_SetLow();                   // Turn off PWR LED
    ERR_SetLow();
    DIAG_SetLow();
    
    CPUDOZEbits.IDLEN = 1;
    SLEEP();        
    wakeUP();
}

void canSleep() {
    STBY_SetHigh();             // Put CAN transceiver in sleep mode (TX off)
    CANCONbits.REQOP = 0b001;   // CAN module sleep
    PIR5bits.WAKIF = 0;         // clear CAN bus wakeup interrupt
    PIE5bits.WAKIE = 1;         // CAN wake-on bus activity
}