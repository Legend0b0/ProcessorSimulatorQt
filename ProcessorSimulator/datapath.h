#ifndef DATAPATH_H
#define DATAPATH_H

#include <QMainWindow>

class ULA
{
public:
    int A = 0;
    int B = 0;
    int C = 0;

public slots:
    void operationAdd();
    void operationSub();
    void operationAnd();
    void operationOr();
};

class DataPath
{
public:
    DataPath();
    int R0 = 0;
    int R1 = 0;
    int R2 = 0;
    int R3 = 0;

    int ABus = 0;
    int BBus = 0;
    int CBus = 0;

    int MainMemoryBus = 0;

    ULA ula;
};

#endif // DATAPATH_H
