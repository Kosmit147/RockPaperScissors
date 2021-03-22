#pragma once
#include <QRandomGenerator>
#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonRockClicked();
    void onButtonPaperClicked();
    void onButtonScissorsClicked();
    void onButtonResetClicked();

private:
    Ui::MainWindow *ui;
    int random;
    void setImageRight();
    void setResult(int r, QString v);
    int result;
    int playerScore;
    int computerScore;
};
