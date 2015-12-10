#pragma once
#include "Command.h"
#include "protocol.h"
#include <map>
#include <vector>
#include <string>

/** CommandPool class.
 *  Author Xiaofei Qiu
 */
 
class CommandPool
{   
public:
    CommandPool(){}
    ~CommandPool();
    
    /** init pool, push all commands to _pool*/
    void init();  
    
    /** This will return a command object
      * Check input commands in protocol.h file  
      * use first 3 bits are used to determine the command
      * use 3th bit for speed direction
      * use 4th bit and 5th bit to define the speed
    */  
    Command* getCommand(const char& cmdstr);            
                                                        
        
private:
    /** container holds all commands */
    std::map<char,Command*> _pool;                      
};
