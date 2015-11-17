#include "mbed.h"
#include "CommandPool.h"

Command* cmd;
CommandPool pool;
char CMD = LED;
Serial pc(USBTX,USBRX);

int main()
{
    pool.init();
    while(1)
    {
        cmd = pool.getCommand(CMD);              // if cmd is valid
        if(cmd)
        {
            cmd->execute();                      // execute cmd
        }               
    } 
 return 0;
}
