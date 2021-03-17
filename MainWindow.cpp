#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonRock, SIGNAL(clicked()), this, SLOT(onButtonRockClicked()));
    connect(ui->buttonPaper, SIGNAL(clicked()), this, SLOT(onButtonPaperClicked()));
    connect(ui->buttonScissors, SIGNAL(clicked()), this, SLOT(onButtonScissorsClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonRockClicked()
{

}

void MainWindow::onButtonPaperClicked()
{

}

void MainWindow::onButtonScissorsClicked()
{

}

