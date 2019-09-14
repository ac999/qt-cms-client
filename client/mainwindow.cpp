#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "haveibeenpwned.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    ui->label->hide() ;
    haveibeenpwned* pwdCheck = new haveibeenpwned(ui->lineEdit->text());
    if (pwdCheck->getStatus() == false){
        ui->lineEdit->setText( "password is gut" ) ;
    }
    else{
        ui->lineEdit->setText("password is not gut") ;
        ui->label->show();
        ui->label->setText(QString::number(pwdCheck->getCount())) ;
    }
}
