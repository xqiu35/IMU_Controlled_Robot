#pragma once
#include "Mode.h"

DigitalOut led2(LED2);

void pb_hit(void)
{
    Mode::on = !Mode::on;
}

Mode::Mode(PinName itrp):_pb(itrp)
{
    _pb.mode(PullUp);
    wait(0.01);
    _pb.attach_deasserted(&pb_hit);
    _pb.setSampleFrequency();
}

int Mode::on = 0;