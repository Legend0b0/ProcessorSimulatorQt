#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "controlunit.h"
#include "datapath.h"

class Processor
{
public:
    Processor();
    ~Processor();

    ControlUnit *controlUnit = nullptr;
    DataPath *dataPath = nullptr;
    QStringList *mainMemory = nullptr;

    int binToDec(QString bin);
    QString decToBin(int dec);
    void instructionInterpretation();
    void clock();

    void LOAD();
    void STORE();
    void MOVE();
    void ADD();
    void SUB();
    void AND();
    void OR();
    void BRANCH();
    void BZERO();
    void BNEG();
    void NOP();
    void HALT();

signals:
    void throwControlUnit();
    void throwPC();
};

#endif // PROCESSOR_H
