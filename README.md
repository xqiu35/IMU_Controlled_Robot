# IMU_Controlled_Robot

This project uses mbed plate form<br/>

Design a robotic car to be able to move a certain path based on gesture commands<br/>
Commands can be sent by using Xbee<br/>
Uses first 4 bit to identify the command, and last four bit to identify the speed<br/>
All Commands will be initialized in the heap "Pool" before the system start<br/>
Program is be able to get the Commands from the pool and excute<br/>
<br/>

At this point, LED command had been tested and it verifies this software structure works fine<br/>
