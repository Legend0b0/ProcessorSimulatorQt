#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QSplitter>
#include <QScrollArea>
#include <QSizePolicy>
#include <QLineEdit>
#include <QLabel>
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
    QSplitter *split1 = nullptr;
    QSplitter *split2 = nullptr;

    QScrollArea *controlUnitScroll = nullptr;
    QScrollArea *dataPathScroll = nullptr;
    QScrollArea *mainMemoryScroll = nullptr;

    QWidget *controlUnitLayoutWindow = nullptr;
    QWidget *dataPathLayoutWindow = nullptr;
    QWidget *mainMemoryAuxLayoutWindow = nullptr;
    QWidget *mainMemoryLayoutWindow = nullptr;
    QWidget *containerLayoutWindow = nullptr;
    QWidget *mainLayoutWindow = nullptr;

    QVBoxLayout *controlUnitLayout = nullptr;
    QVBoxLayout *dataPathLayout = nullptr;
    QHBoxLayout *mainMemoryAuxLayout = nullptr;
    QGridLayout *mainMemoryLayout = nullptr;
    QHBoxLayout *containerLayout = nullptr;
    QHBoxLayout *mainLayout = nullptr;

    Processor *processor = new Processor;

    QVector<QLabel*> *positionLabel = nullptr;
    QVector<QLineEdit*> *lineMemory = nullptr;

protected:
    void configureWindow();
    void createWidgets();
    void createMainMemory();
    void createLayouts();
    void settingLayouts();
    void iniciateMemory();

public slots:
    void darkTheme();
};

#endif // MAINWINDOW_H
