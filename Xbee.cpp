#pragma once
#include "Xbee.h"

//Serial pc(USBTX, USBRX);

Xbee::Xbee(PinName tx, PinName rx , PinName rst):_xbee(tx,rx),_rst(rst)
{
    _xbee.baud(9600);
}

void Xbee::Reset()
{
    _rst = 0;
    wait(0.01);
    _rst = 1;
    wait(0.01);
    
}

void Xbee::Send(const char& buffer)
{
    while(1)
    {
        if(_xbee.writeable())
        {
            _xbee.putc('\0');
            _xbee.putc(buffer);
        }
        if(_xbee.readable())
        {
            _xbee.getc();
            break;
        }
    }
}

void Xbee::Recv(char& buffer)
{
    while(1)
    { 
        if(!_xbee.readable())
        {
            _xbee.putc('\0');
        }
        else
        {
            if(_xbee.getc()=='\0');
            {
                buffer = _xbee.getc();
            }
            break;
        }
    }
}