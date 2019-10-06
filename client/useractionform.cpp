#include "useractionform.h"
#include "ui_useractionform.h"

userActionForm::userActionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userActionForm)
{
    ui->setupUi(this);
}

userActionForm::~userActionForm()
{
    delete ui;
}
