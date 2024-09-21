#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <QMainWindow>
#include <QString>

class ControlUnit
{
public:
    ControlUnit();
    ~ControlUnit();

    int PC;
    QString IR;

    QString AAddr;
    QString BAddr;
    QString UlaOp;
    QString SwitchPos;
    QString CAddr;
    QString RWAddr;
};

#endif // CONTROLUNIT_H
