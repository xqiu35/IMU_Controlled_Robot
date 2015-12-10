#pragma once
#include "mbed.h"
#include "LSM9DS0.h"
#include "protocol.h"

/** GenCMD class.
 *  Author Xiaofei Qiu
 */
 
class GenCMD
{
public:
    GenCMD();
    
    /** Initialize IMU device */
    void init();
    
    /** Generate command and speed based on accelerometer value */
    void GenerateCMD(char&, const size_t sz = 1);
    
private:

    /** imu object */
    LSM9DS0 imu;
};
