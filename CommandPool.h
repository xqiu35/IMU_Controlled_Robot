#pragma once
#include "Command.h"
#include "protocol.h"
#include <map>
#include <vector>
#include <string>

typedef std::map<char,Command*>::const_iterator mapIterator;

class CommandPool
{   
public:
    CommandPool(){}
    ~CommandPool();
    
    /* init pool, push all commands to _pool*/
    void init(const size_t& num_entries = 2);  
    
    /* this will return a pointer to the command    
       first four bit is used to determine the command
       last four bit is used to determine the speed 
    */  
    Command* getCommand(const char& cmdstr);            
                                                        
        
private:
    /* container holds all commands */
    std::map<char,Command*> _pool;                      
};