#ifndef DATAPATH_H
#define DATAPATH_H

#include <QMainWindow>

class ALU
{
public:
    ALU();
    ~ALU();

    int *A = nullptr;
    int *B = nullptr;
    int *C = nullptr;

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
    ~DataPath();

    int *R0 = nullptr;
    int *R1 = nullptr;
    int *R2 = nullptr;
    int *R3 = nullptr;

    int *ABus = nullptr;
    int *BBus = nullptr;
    int *CBus = nullptr;

    int *MainMemoryBus = nullptr;

    ALU *alu = nullptr;
};

#endif // DATAPATH_H
