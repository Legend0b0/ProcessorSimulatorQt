#include "controlunit.h"

ControlUnit::ControlUnit()
{
    this->IR = new QString("0");
}

ControlUnit::~ControlUnit()
{
    delete this->IR;
}
