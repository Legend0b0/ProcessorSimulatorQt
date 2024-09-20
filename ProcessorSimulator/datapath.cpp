#include "datapath.h"

DataPath::DataPath()
{
    this->R0 = new int;
    this->R1 = new int;
    this->R2 = new int;
    this->R3 = new int;

    this->ABus = new int;
    this->BBus = new int;
    this->CBus = new int;

    this->MainMemoryBus = new int;

    this->alu = new ALU;

    this->R0 = 0;
    this->R1 = 0;
    this->R2 = 0;
    this->R3 = 0;
    this->ABus = 0;
    this->BBus = 0;
    this->CBus = 0;
    this->MainMemoryBus = 0;
}

DataPath::~DataPath()
{
    delete this->R0;
    delete this->R1;
    delete this->R2;
    delete this->R3;

    delete this->ABus;
    delete this->BBus;
    delete this->CBus;

    delete this->MainMemoryBus;

    delete this->alu;
}

ALU::ALU()
{
    this->A = new int;
    this->B = new int;
    this->C = new int;

    this->A = 0;
    this->B = 0;
    this->C = 0;
}

ALU::~ALU()
{
    delete this->A;
    delete this->B;
    delete this->C;
}

void ALU::operationAdd()
{
    *this->C = *this->A + *this->B;
}

void ALU::operationSub()
{
    *this->C = *this->A - *this->B;
}

void ALU::operationAnd()
{
    *this->C = *this->A & *this->B;
}

void ALU::operationOr()
{
    *this->C = *this->A | *this->B;
}
