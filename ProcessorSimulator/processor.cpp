#include "processor.h"

Processor::Processor()
{
    this->controlUnit = new ControlUnit;
    this->dataPath = new DataPath;
    this->mainMemory = new QStringList;
}

Processor::~Processor()
{
    delete this->controlUnit;
    delete this->dataPath;
    delete this->mainMemory;
}

void Processor::LOAD()
{

}

void Processor::STORE()
{

}

void Processor::MOVE()
{

}

void Processor::ADD()
{

}

void Processor::SUB()
{

}

void Processor::AND()
{

}

void Processor::OR()
{

}

void Processor::BRANCH()
{

}

void Processor::BZERO()
{

}

void Processor::BNEG()
{

}

void Processor::NOP()
{

}

void Processor::HALT()
{

}
