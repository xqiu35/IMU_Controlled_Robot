#ifndef PROTOCOL_H
#define PROTOCOL_H

// Commands
const char LED = 0x00;
const char TURN_LEFT = 0x01;
const char TURN_RIGHT = 0x02;
const char STRAIGHT = 0x03;
const char STOP = 0x05;

// Speeds for left wheel
const char SPEED1 = 0x10;
const char SPEED2 = 0x20;
const char SPEED3 = 0x30;

const char NEGATIVE = 0x08;

#endif
