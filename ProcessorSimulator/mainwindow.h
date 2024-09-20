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
#include <QRegularExpression>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include "processor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QFile file;

private:
    QPushButton *data_button = nullptr;
    QPushButton *control_button = nullptr;
    QPushButton *file_button = nullptr;

    QLabel *memory_label = nullptr;

    QSplitter *split = nullptr;

    QScrollArea *controlUnitScroll = nullptr;
    QScrollArea *dataPathScroll = nullptr;

    QWidget *controlUnitLayoutWindow = nullptr;
    QWidget *dataPathLayoutWindow = nullptr;
    QWidget *mainMemoryAuxLayoutWindow = nullptr;
    QWidget *mainMemoryLayoutWindow = nullptr;
    QWidget *mainLayoutWindow = nullptr;

    QVBoxLayout *controlUnitLayout = nullptr;
    QVBoxLayout *dataPathLayout = nullptr;
    QHBoxLayout *mainMemoryAuxLayout = nullptr;
    QVBoxLayout *mainMemoryLayout = nullptr;
    QHBoxLayout *mainLayout = nullptr;

    Processor *processor = nullptr;

    QTableWidget *tableMemory = nullptr;

protected:
    void configureWindow();
    void createWidgets();
    void createTableMemory();
    void createLayouts();
    void settingLayouts();
    void iniciateMemory();
    void connectButons();
    void verifyInstruction(QTableWidgetItem *item);

public slots:
    void darkTheme();
    void readFile();
    void textChanged(QTableWidgetItem *item);
    void sintaxeMemoryCatch(int i, int signal);

signals:
    void sintaxeMemoryThrow(int i, int signal);
};

#endif // MAINWINDOW_H
