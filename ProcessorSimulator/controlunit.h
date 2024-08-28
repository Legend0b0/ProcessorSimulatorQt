#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <QString>

class ControlUnit
{
public:
    ControlUnit();

    int PC = 0;
    QString IR = "";

    int AAddr = 00;
    int BAddr = 00;
    int UlaOp = 00;
    int SwitchPos = 0000;
    int CAddr = 00;
    int RWAddr = 00000;
};

#endif // CONTROLUNIT_H
