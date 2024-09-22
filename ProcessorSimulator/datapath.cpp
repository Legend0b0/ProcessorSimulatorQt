#include "datapath.h"

DataPath::DataPath()
{
    this->alu = new ALU;

    this->R[0] = 0;
    this->R[1] = 0;
    this->R[2] = 0;
    this->R[3] = 0;
    this->ABus = 0;
    this->BBus = 0;
    this->CBus = 0;
    this->MainMemoryBus = 0;
}

DataPath::~DataPath()
{
    delete this->alu;
}

ALU::ALU()
{
    this->A = 0;
    this->B = 0;
    this->C = 0;

    this->Op[0] = this->operationAdd();
    this->Op[1] = this->operationSub();
    this->Op[2] = this->operationAnd();
    this->Op[3] = this->operationOr();
}

ALU::~ALU()
{
}

void ALU::operationAdd()
{
    this->C = this->A + this->B;
}

void ALU::operationSub()
{
    this->C = this->A - this->B;
}

void ALU::operationAnd()
{
    this->C = this->A & this->B;
}

void ALU::operationOr()
{
    this->C = this->A | this->B;
}
