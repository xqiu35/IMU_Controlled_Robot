#pragma once
#include <cstdint>

/** Command class.
 *  Author Xiaofei Qiu
 */
class Command
{
public:
    Command();
    
    Command(const Command&);
    
    virtual ~Command(){}
    
    /** Uses vitual function for dynamic binding */
    virtual void execute() = 0; 
    
    /** Sets Speed, if is_negative is true, then speed will be negative. otherwaise, speed is posotive */
    void setSpeed(const std::int8_t& sp, const std::int8_t& is_negative = 0);
    
protected:
    /** Motor speed */
    float _SPEED;
    
    /** Direction of the motor speed */
    bool  _IS_NEGATIVE;
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

class GoStraightCommand : public Command
{
public:
    GoStraightCommand(){}
    virtual void execute();
};

class StopCommand : public Command
{
public:
    StopCommand(){}
    virtual void execute();
};
