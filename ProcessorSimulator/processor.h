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

    bool cicle_dataPath = false;
    bool halt = false;
    int time;

    ControlUnit *controlUnit = nullptr;
    DataPath *dataPath = nullptr;
    QStringList *mainMemory = nullptr;

    void delay(int ms);
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
    void updateIR();
    void updateIR();
    void updatePC();
    void updateControlUnit();
};

#endif // PROCESSOR_H
