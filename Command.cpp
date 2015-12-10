#pragma once
#include "Command.h"
#include "mbed.h"
#include "Motor.h"

Motor _LEFT_WHEEL(p25, p6, p5);    // Motor A pwm, fwd, rev
Motor _RIGHT_WHEEL(p26, p7, p8);     // Motor B pwm, fwd, rev
DigitalOut _STBY(p12);              // Set STBY = 1, enable both motor; Set STBY = 0; disable both motor. 
AnalogIn _IR(p17);                  // IR sensor
DigitalOut _LED1(LED1);

DigitalIn _LEFT_ENCODER(p19);
DigitalIn _RIGHT_ENCODER(p20);

Command::Command():_SPEED(0),_IS_NEGATIVE(0)
{}    

#define SENSITIVITY 0.9

void Command::setSpeed(const std::int8_t& sp, const std::int8_t& is_negative)
{
    _STBY = 1;
    _SPEED = sp * 0.33;
    _IS_NEGATIVE = is_negative;
}

void LedCommand :: execute()
{
    _LED1 = !_LED1;
}

void TurnLeftCommand :: execute()
{
    _STBY = 1;
    if(_IS_NEGATIVE)
    {
        _RIGHT_WHEEL.speed(-_SPEED);
        _LEFT_WHEEL.speed(-_SPEED*SENSITIVITY);
    }
    else
    {
        _RIGHT_WHEEL.speed(_SPEED);
        _LEFT_WHEEL.speed(_SPEED*SENSITIVITY);
    }
}

void TurnRightCommand :: execute()
{
    _STBY = 1;
    if(_IS_NEGATIVE)
    {
        _RIGHT_WHEEL.speed(-_SPEED*SENSITIVITY);
        _LEFT_WHEEL.speed(-_SPEED);
    }
    else
    {
        _RIGHT_WHEEL.speed(_SPEED*SENSITIVITY);
        _LEFT_WHEEL.speed(_SPEED);
    }
}

void GoStraightCommand :: execute()
{
    _STBY = 1;
    if(_IS_NEGATIVE)
    {
        _RIGHT_WHEEL.speed(-_SPEED);
        _LEFT_WHEEL.speed(-_SPEED);
    }
    else
    {
        _RIGHT_WHEEL.speed(_SPEED);
        _LEFT_WHEEL.speed(_SPEED);
    }
}

void StopCommand :: execute()
{ 
    _RIGHT_WHEEL.speed(0.0);
    _LEFT_WHEEL.speed(0.0);
    _STBY = 0;
}

