#include "datapath.h"

DataPath::DataPath()
{

}

void ULA::operationAdd()
{
    this->C = this->A + this->B;
}

void ULA::operationSub()
{
    this->C = this->A - this->B;
}

void ULA::operationAnd()
{
    this->C = this->A & this->B;
}

void ULA::operationOr()
{
    this->C = this->A | this->B;
}
