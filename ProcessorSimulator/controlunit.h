#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <QString>

class ControlUnit
{
public:
    ControlUnit();
    ~ControlUnit();

    int *PC = nullptr;
    QString *IR = nullptr;

    int *AAddr = nullptr;
    int *BAddr = nullptr;
    int *UlaOp = nullptr;
    int *SwitchPos = nullptr;
    int *CAddr = nullptr;
    int *RWAddr = nullptr;
};

#endif // CONTROLUNIT_H
