#pragma once
#include "mbed.h"

/** Xbee class.
 *  Author Xiaofei Qiu
 */
 
class Xbee
{
public:
    /** Use p9 and p10 as default serial pins and p11 for reset */
    Xbee(PinName tx = p9, PinName rx = p10, PinName rst = p11);
    
    /** Reset Xbee before use it */
    void Reset();
    
    /** Send 8 bit data */
    void Send(const char&);
    
    /** Read 8 bit data */
    void Recv(char&);
        
private:
    Serial _xbee;
    DigitalOut _rst;
};