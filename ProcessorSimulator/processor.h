#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>
#include "controlunit.h"
#include "datapath.h"

class Processor : public QObject
{
    Q_OBJECT

public:
    Processor(QObject* parent = nullptr);
    ~Processor();

    bool cicle_dataPath = false;
    bool halt = false;

    ControlUnit *controlUnit = nullptr;
    DataPath *dataPath = nullptr;
    QStringList *mainMemory = nullptr;

    int binToDec(QString bin);
    QString decToBin(int dec, int bits);
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
