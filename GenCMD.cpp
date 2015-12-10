#include "GenCMD.h"
#include <cmath>

#define LSM9DS0_XM_ADDR  0x1D // Would be 0x1E if SDO_XM is LOW
#define LSM9DS0_G_ADDR   0x6B // Would be 0x6A if SDO_G is LOW


GenCMD::GenCMD():imu(p28,p27,LSM9DS0_G_ADDR,LSM9DS0_XM_ADDR){}

void GenCMD::init()
{
    imu.begin();
}

void GenCMD::GenerateCMD(char& cmd_buffer, const size_t sz)
{ 
    imu.readAccel();
    
    if(imu.fay > 0.0 && imu.fay <= 0.20)
    {
        cmd_buffer = STRAIGHT;
    }
    else if(imu.fay > 0.20 && imu.fay <= 0.45)
    {
        cmd_buffer = TURN_LEFT;
    }
    else if(imu.fay > 0.45)
    {
        cmd_buffer = TURN_LEFT;
    }
    else if(imu.fay < 0.0 && imu.fay >= -0.20)
    {
        cmd_buffer = STRAIGHT;
    }
    else if(imu.fay < -0.20 && imu.fay >= -0.45)
    {
        cmd_buffer = TURN_RIGHT;
    }
    else if(imu.fay < -0.45)
    {
        cmd_buffer = TURN_RIGHT;
    }
    
    if(abs(imu.fax) < 0.25 )
    {
        cmd_buffer |= SPEED1;
    }
    else if(abs(imu.fax) > 0.25 && abs(imu.fax) < 0.45)
    {
        cmd_buffer |= SPEED2;
    }
    else if(abs(imu.fax) > 0.45)
    {
        cmd_buffer |= SPEED3;
    }
    
    if(imu.fax < 0 && (cmd_buffer & 0x8)==0)
    {
        cmd_buffer |= NEGATIVE;
    }
}   
