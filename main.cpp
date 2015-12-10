// Controller code
#pragma once
#include "mbed.h"                              
#include "CommandPool.h"
#include "Xbee.h"
#include "GenCMD.h"
#include "PinDetect.h"
#include "Mode.h"

GenCMD      gen_cmd;                        // Command Generator
Xbee        xbee(p9,p10,p11);               // Xbee
DigitalOut  led(LED1);                      // LED
Mode        mode;                           // Mode
char        cmd_buffer = '\0';              // Command Buffer

Serial pc(USBTX,USBRX);

int main()
{   
    gen_cmd.init();                                 // Init Command Generator
    xbee.Reset();                                   // Reset Xbee

    while(1)
    {
        if(mode.on)                                 // If mode on
        {
            gen_cmd.GenerateCMD(cmd_buffer);        // Generate command based on IMU value
            xbee.Send(cmd_buffer);                  // Send Command
            led = !led;  
        }    
        else
        {
            xbee.Send(STOP);                        // If mode off, Send STOP Command
        }  
        
        wait(0.01);
    } 
 return 0;
}

/* Robot code 
#pragma once
#include "mbed.h"
#include "CommandPool.h"
#include "Xbee.h"

Command* cmd;                   // Command Object
CommandPool pool;               // Command Pool
Xbee xbee(p9,p10,p11);          // Xbee
DigitalOut led(LED1);           // LED
char cmd_buffer='\0';           // Command Buffer

int main()
{
    pool.init();                // Init Command Poll
    xbee.Reset();               // Reset Xbee

    while(1)
    {
        xbee.Recv(cmd_buffer);              // Receive command from IMU controller
        cmd = pool.getCommand(cmd_buffer);  // Get command object from command pool 
        if(cmd)                             // If valid
        {
            cmd->execute();                 // Execute command
        }
        led = !led;
        wait(0.01);  
    } 
 return 0;
}
*/
