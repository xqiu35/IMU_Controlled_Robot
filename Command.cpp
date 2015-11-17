#pragma once
#include "Command.h"
#include "mbed.h"

static DigitalOut led1(LED1);


void LedCommand :: execute()
{
    led1 = !led1;
}

void TurnLeftCommand :: execute()
{
}

void TurnRightCommand :: execute()
{
}

void MoveForwardCommand :: execute()
{
}

void MoveBackwardCommand :: execute()
{
}

void StopCommand :: execute()
{ 
}

