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
#include <QTableWidget>
#include <QHeaderView>

#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>

#include "controlunit.h"
#include "datapath.h"

class Processor
{
public:
    ControlUnit *controlUnit = new ControlUnit;
    DataPath *dataPath = new DataPath;
    QStringList *mainMemory = new QStringList;

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

    QFile file;


private:
    QPushButton *file_buton = new QPushButton("Input File");

    QSplitter *split = nullptr;

    QScrollArea *controlUnitScroll = nullptr;
    QScrollArea *dataPathScroll = nullptr;

    QWidget *controlUnitLayoutWindow = nullptr;
    QWidget *dataPathLayoutWindow = nullptr;
    QWidget *mainMemoryLayoutWindow = nullptr;
    QWidget *mainLayoutWindow = nullptr;

    QVBoxLayout *controlUnitLayout = nullptr;
    QVBoxLayout *dataPathLayout = nullptr;
    QVBoxLayout *mainMemoryLayout = nullptr;
    QHBoxLayout *mainLayout = nullptr;

    Processor *processor = new Processor;

    QTableWidget *tableMemory = nullptr;

protected:
    void configureWindow();
    void createWidgets();
    void createMainMemory();
    void createLayouts();
    void settingLayouts();
    void iniciateMemory();
    void connectButons();

public slots:
    void darkTheme();
    void textChanged(QTableWidgetItem *item);
    void Readfile();
};

#endif // MAINWINDOW_H
