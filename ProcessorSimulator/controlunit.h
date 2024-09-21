#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <QMainWindow>
#include <QString>

class ControlUnit
{
public:
    ControlUnit();
    ~ControlUnit();

    int PC = 0;
    QString *IR = nullptr;

    QString AAddr = "00";
    QString BAddr = "00";
    QString UlaOp = "00";
    QString SwitchPos = "0000";
    QString CAddr = "00";
    QString RWAddr = "00000";
};

#endif // CONTROLUNIT_H
