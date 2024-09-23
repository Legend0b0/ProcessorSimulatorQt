#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>
#include <QTimer>
#include <QEventLoop>
#include "controlunit.h"
#include "datapath.h"

class Processor : public QObject
{
    Q_OBJECT

public:
    Processor(QObject* parent = nullptr);
    ~Processor();

    bool halt = false;
    bool changePC = false;
    bool cicle_dataPath = false;
    int time;

    ControlUnit *controlUnit = nullptr;
    DataPath *dataPath = nullptr;
    QStringList *mainMemory = nullptr;

    int *get();
    void delay(int ms);
    int binToDec(QString bin);
    QString decToBin(int dec, int bits);
    void instructionInterpretation();
    void ALUOperation();
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
    void updateInstruction();
    void updateIR();
    void updateArrowsControlUnit();
    void updatePC();
    void updateControlUnit();
    void updateAaddr_Baddr();
    void updateABus_BBus();
    void updateALU_1();
    void updateALU_2();
    void updateArrowAluToCBus();
    void updateCBus();
    void updateArrowCBusToMMBus();
    void updateMMBus();
    void updateMainMemory();
    void updateArrowMMBusToCBus();
    void updateArrowCBusToCAdr();
    void updateRegisters();

};

#endif // PROCESSOR_H
