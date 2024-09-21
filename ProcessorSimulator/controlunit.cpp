#include "controlunit.h"

ControlUnit::ControlUnit()
{
    PC = 0;
    IR = "";

    AAddr = "00";
    BAddr = "00";
    UlaOp = "00";
    SwitchPos = "0000";
    CAddr = "00";
    RWAddr = "00000";
}

ControlUnit::~ControlUnit()
{
}
