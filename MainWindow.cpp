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
    connect(ui->buttonReset, SIGNAL(clicked()), this, SLOT(onButtonResetClicked()));

    playerScore = 0;
    computerScore = 0;
    ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
    ui->aiScore->setText("Punkty komputera: " + QString::number(computerScore));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonRockClicked()
{



    QPixmap Rock(":/img/Rock.png");
    ui->imageLeft->setPixmap(Rock);
    setImageRight();
    setResult(result,"Rock");
}

void MainWindow::onButtonPaperClicked()
{

    QPixmap Paper(":/img/Paper.png");
    ui->imageLeft->setPixmap(Paper);
    setImageRight();
    setResult(result,"Paper");

}

void MainWindow::onButtonScissorsClicked()
{

    QPixmap Scissors(":/img/Scissors.png");
    ui->imageLeft->setPixmap(Scissors);
    setImageRight();
    setResult(result,"Scissors");

}

void MainWindow::onButtonResetClicked()
{
    QPixmap defult(":/img/QuestionMark.png");
    playerScore = 0;
    computerScore = 0;
    ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
    ui->aiScore->setText("Punkty komputera: " + QString::number(computerScore));
    ui->imageRight->setPixmap(defult);
    ui->imageLeft->setPixmap(defult);
    ui->resultLabel->setText("");
}



void MainWindow::setImageRight()
{

   random = QRandomGenerator::global()->bounded(0,3);
   QPixmap Rock(":/img/Rock.png");
   QPixmap Paper(":/img/Paper.png");
   QPixmap Scissors(":/img/Scissors.png");


   switch (random){
   case 0:
       ui->imageRight->setPixmap(Rock);
       result = 0;
       break;
   case 1:
       ui->imageRight->setPixmap(Paper);
       result = 1;
       break;
   case 2:
       ui->imageRight->setPixmap(Scissors);
       result = 2;
       break;

   }

}

void MainWindow::setResult(int r, QString v)
{
    if(v == "Rock")
    {
        if (r == 1){
            ui->resultLabel->setText("Przegrywasz");
            computerScore++;
            ui->aiScore->setText("Punkty komputera: " + QString::number(computerScore));

        }
        else if(r == 2){
            ui->resultLabel->setText("Wygrywasz");
            playerScore++;
            ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
        }
        else
            ui->resultLabel->setText("Remis");
    }
  else if(v == "Paper")
   {
       if (r == 2){
           ui->resultLabel->setText("Przegrywasz");
           computerScore++;
           ui->aiScore->setText("Punkty komputera: " + QString::number(computerScore));
       }
       else if(r == 0){
           ui->resultLabel->setText("Wygrywasz");
           playerScore++;
           ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
       }
       else
           ui->resultLabel->setText("Remis");
   }
    else
    {
        if (r == 0){
            ui->resultLabel->setText("Przegrywasz");
            computerScore++;
            ui->aiScore->setText("Punkty komputera: " + QString::number(computerScore));

        }
        else if(r == 1){
            ui->resultLabel->setText("Wygrywasz");
            playerScore++;
            ui->playerScore->setText("Punkty gracza: " + QString::number(playerScore));
        }
        else
            ui->resultLabel->setText("Remis");
    }

}


