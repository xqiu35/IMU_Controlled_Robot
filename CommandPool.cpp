#pragma once
#include "CommandPool.h"
#include <iterator>
#include <utility>
#include "mbed.h"

typedef std::map<char,Command*>::const_iterator mapIterator;

CommandPool:: ~CommandPool()
{
   mapIterator map_it;
   
    for(map_it = _pool.begin(); map_it != _pool.end(); map_it++)
    {
        if(map_it->second)
        {
            delete map_it->second;       // free command*
        }
    }
   
}

void CommandPool::init()
{
    /* Allocate commands in heap to avoid push/pop to/from the stack */
    _pool[LED] = new LedCommand();
    _pool[TURN_LEFT] = new TurnLeftCommand();
    _pool[TURN_RIGHT] = new TurnRightCommand();
    _pool[STRAIGHT] = new GoStraightCommand();
    _pool[STOP] = new StopCommand();
    
}
    
Command* CommandPool::getCommand(const char& cmdstr)
{
    static char cmd = '\0';
    static int8_t is_negative = 0;
    static int8_t sp = 0;
    
    cmd = cmdstr & 0x07;
    is_negative = (cmdstr & 0x08) >> 3;
    sp = (cmdstr & 0xF0) >> 4;
    
    _pool[cmd]->setSpeed(sp,is_negative);
    return _pool[cmd];
}
