#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *layoutWindow = nullptr;

    QVBoxLayout *mainLayout = nullptr;

protected:
    void configureWindow();
    void createLayouts();
    void settingLayouts();

public slots:
    void darkTheme();
};

#endif // MAINWINDOW_H
