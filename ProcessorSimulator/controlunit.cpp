#include "controlunit.h"

ControlUnit::ControlUnit()
{
    this->PC = new int;
    this->IR = new QString("");

    this->AAddr = new int;
    this->BAddr = new int;
    this->UlaOp = new int;
    this->SwitchPos = new int;
    this->CAddr = new int;
    this->RWAddr = new int;

    this->PC = 0;

    this->AAddr = 00;
    this->BAddr = 00;
    this->UlaOp = 00;
    this->SwitchPos = 0000;
    this->CAddr = 00;
    this->RWAddr = 00000;
}

ControlUnit::~ControlUnit()
{
    delete this->PC;
    delete this->IR;

    delete this->AAddr;
    delete this->BAddr;
    delete this->UlaOp;
    delete this->SwitchPos;
    delete this->CAddr;
    delete this->RWAddr;
}
