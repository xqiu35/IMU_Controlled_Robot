#pragma once
#include <cstdint>

class Command
{
public:
    Command():_speed(0){}
    Command(const Command&);
    virtual ~Command(){}
    virtual void execute() = 0; 
    void setSpeed(const std::int8_t& sp){_speed = sp;}
    
protected:
    float _speed;
};

class LedCommand : public Command
{
public:
    LedCommand(){}
    virtual void execute();
};

class TurnLeftCommand : public Command
{
public:
    TurnLeftCommand(){}
    virtual void execute();
};

class TurnRightCommand : public Command
{
public:
    TurnRightCommand(){}
    virtual void execute();
};

class MoveForwardCommand : public Command
{
public:
    MoveForwardCommand(){}
    virtual void execute();
};

class MoveBackwardCommand : public Command
{
public:
    MoveBackwardCommand(){}
    virtual void execute();
};

class StopCommand : public Command
{
public:
    StopCommand(){}
    virtual void execute();
};
