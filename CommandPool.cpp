#pragma once
#include "CommandPool.h"
#include <iterator>
#include <utility>
#include "mbed.h"

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

void CommandPool::init(const size_t& num_entries)
{
    /* Allocate commands in heap to avoid push/pop to/from the stack */
    _pool[LED] = new LedCommand();
    _pool[TURN_LEFT] = new TurnLeftCommand();
    _pool[TURN_RIGHT] = new TurnRightCommand();
    _pool[MOVE_FORWARD] = new MoveForwardCommand();
    _pool[MOVE_BACKWARD] = new MoveBackwardCommand();
    _pool[STOP] = new StopCommand();
}
    
Command* CommandPool::getCommand(const char& cmdstr)
{
    static char cmd = cmdstr & 0x01;
    static int8_t sp = (cmdstr & 0x10) >> 4;
    _pool[cmd]->setSpeed(sp);
    return _pool[cmd];
}