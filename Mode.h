#pragma once
#include "mbed.h"
#include "PinDetect.h"


/** Mode class.
 *  Author Xiaofei Qiu
 */
 
class Mode
{
public:

    /** Push button default using p8*/
    Mode(PinName itrp = p8);
    
    /** "on = 1" to enable the IMU controll */
    static int on;

private:

    /** use push button to switch on/off */
    PinDetect _pb;
};



