#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    operandA = operandA * 10 + 1;
    updateLcdOperand();
}


void MainWindow::on_button2_clicked()
{
    operandA = operandA * 10 + 2;
    updateLcdOperand();
}


void MainWindow::on_button3_clicked()
{
    operandA = operandA * 10 + 3;
    updateLcdOperand();
}


void MainWindow::on_button4_clicked()
{
    operandA = operandA * 10 + 4;
    updateLcdOperand();
}


void MainWindow::on_button5_clicked()
{
    operandA = operandA * 10 + 5;
    updateLcdOperand();
}


void MainWindow::on_button6_clicked()
{
    operandA = operandA * 10 + 6;
    updateLcdOperand();
}


void MainWindow::on_button7_clicked()
{
    operandA = operandA * 10 + 7;
    updateLcdOperand();
}


void MainWindow::on_button8_clicked()
{
    operandA = operandA * 10 + 8;
    updateLcdOperand();
}


void MainWindow::on_button9_clicked()
{
    operandA = operandA * 10 + 9;
    updateLcdOperand();
}


void MainWindow::on_button0_clicked()
{
    operandA = operandA * 10;
    updateLcdOperand();
}


void MainWindow::on_buttonSign_clicked()
{
    operandA *= -1;
    updateLcdOperand();
}


void MainWindow::on_buttonClear_clicked()
{
    operandA = 0;
    operandB = 0;
    line.clear();
    updateLcdOperand();
    updateLineResult();
}


void MainWindow::on_buttonBackspace_clicked()
{
    operandA = (int)operandA / 10;
    updateLcdOperand();
}


void MainWindow::on_buttonCalculate_clicked()
{
    calculate();
    updateLcdOperand();
    updateLineResult();
}


void MainWindow::on_buttonPlus_clicked()
{
    checkPrevInput();
    operandAction = '+';
    line = QString::number(operandB) + operandAction;
    updateOutput();
}


void MainWindow::on_buttonMinus_clicked()
{
    checkPrevInput();
    operandAction = '-';
    line = QString::number(operandB) + operandAction;
    updateOutput();
}


void MainWindow::on_buttonMultiplication_clicked()
{
    checkPrevInput();
    operandAction = '*';
    line = QString::number(operandB) + operandAction;
    updateOutput();
}


void MainWindow::on_buttonDivide_clicked()
{
    if(operandA != 0)
    {
        checkPrevInput();
        operandAction = '/';
        line = QString::number(operandB) + operandAction;
    }
    else
    {
        operandA = 0;
        operandB = 0;
        line = "Error: Division by zero!";
    }
    updateOutput();
}

void MainWindow::updateLcdOperand()
{
    ui->lcdOperand->display(operandA);
}

void MainWindow::updateLineResult()
{
    ui->lineResult->setText(line);
}

void MainWindow::calculate()
{
    if (operandAction == '/' && operandA == 0)
    {
        line = "Error: Division by zero!";
        operandA = 0;
        operandB = 0;
        return;
    }
    if (operandAction == '+')
        operandB = operandB + operandA;
    if (operandAction == '-')
        operandB = operandB - operandA;
    if (operandAction == '*')
        operandB = operandA * operandB;
    if (operandAction == '/' && operandA != 0)
        operandB = operandB / operandA;
    line = QString::number(operandB);
    operandA = 0;
}

void MainWindow::checkPrevInput()
{
    if(!line.isEmpty())
    {
        calculate();
    }
    else
    {
        std::swap(operandA, operandB);
        operandA = 0;
    }
}

void MainWindow::updateOutput()
{
    updateLineResult();
    updateLcdOperand();
}

