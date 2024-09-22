#ifndef DATAPATH_H
#define DATAPATH_H

#include <QMainWindow>

class ALU
{
public:
    ALU();
    ~ALU();

    int A;
    int B;
    int C;

    void (ALU::*Op[4])();

    void operationAdd();
    void operationSub();
    void operationAnd();
    void operationOr();

public slots:

};

class DataPath
{
public:
    DataPath();
    ~DataPath();

    int R[4];

    int ABus;
    int BBus;
    int CBus;

    int MainMemoryBus;

    ALU *alu = nullptr;
};

#endif // DATAPATH_H
