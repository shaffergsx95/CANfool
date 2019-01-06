/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K83
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PWR aliases
#define PWR_TRIS                 TRISBbits.TRISB0
#define PWR_LAT                  LATBbits.LATB0
#define PWR_PORT                 PORTBbits.RB0
#define PWR_WPU                  WPUBbits.WPUB0
#define PWR_OD                   ODCONBbits.ODCB0
#define PWR_ANS                  ANSELBbits.ANSELB0
#define PWR_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define PWR_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define PWR_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define PWR_GetValue()           PORTBbits.RB0
#define PWR_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define PWR_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define PWR_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define PWR_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define PWR_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define PWR_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define PWR_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define PWR_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set ERR aliases
#define ERR_TRIS                 TRISBbits.TRISB1
#define ERR_LAT                  LATBbits.LATB1
#define ERR_PORT                 PORTBbits.RB1
#define ERR_WPU                  WPUBbits.WPUB1
#define ERR_OD                   ODCONBbits.ODCB1
#define ERR_ANS                  ANSELBbits.ANSELB1
#define ERR_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define ERR_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define ERR_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define ERR_GetValue()           PORTBbits.RB1
#define ERR_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define ERR_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define ERR_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define ERR_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define ERR_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define ERR_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define ERR_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define ERR_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set STBY aliases
#define STBY_TRIS                 TRISBbits.TRISB2
#define STBY_LAT                  LATBbits.LATB2
#define STBY_PORT                 PORTBbits.RB2
#define STBY_WPU                  WPUBbits.WPUB2
#define STBY_OD                   ODCONBbits.ODCB2
#define STBY_ANS                  ANSELBbits.ANSELB2
#define STBY_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define STBY_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define STBY_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define STBY_GetValue()           PORTBbits.RB2
#define STBY_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define STBY_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define STBY_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define STBY_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define STBY_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define STBY_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define STBY_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define STBY_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()               do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()                do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()                do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()       do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()      do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()               do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()                do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()                do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()       do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()      do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set DIAG aliases
#define DIAG_TRIS                 TRISBbits.TRISB5
#define DIAG_LAT                  LATBbits.LATB5
#define DIAG_PORT                 PORTBbits.RB5
#define DIAG_WPU                  WPUBbits.WPUB5
#define DIAG_OD                   ODCONBbits.ODCB5
#define DIAG_ANS                  ANSELBbits.ANSELB5
#define DIAG_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DIAG_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DIAG_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DIAG_GetValue()           PORTBbits.RB5
#define DIAG_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DIAG_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DIAG_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DIAG_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DIAG_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define DIAG_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define DIAG_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define DIAG_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()               do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()                do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()                do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()       do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()      do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/