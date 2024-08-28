#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include "controlunit.h"
#include "datapath.h"

class Processor
{
public:
    ControlUnit *controlUnit = new ControlUnit;
    DataPath *dataPath = new DataPath;
    QStringList *mainMemory = new QStringList;

protected:
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
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Processor *processor = new Processor;

    QWidget *layoutWindow = nullptr;

    QVBoxLayout *mainLayout = nullptr;

protected:
    void configureWindow();
    void createLayouts();
    void settingLayouts();
    void iniciateMemory();

public slots:
    void darkTheme();
};

#endif // MAINWINDOW_H
