#ifndef USERACTIONFORM_H
#define USERACTIONFORM_H

#include <QWidget>

namespace Ui {
class userActionForm;
}

class userActionForm : public QWidget
{
    Q_OBJECT

public:
    explicit userActionForm(QWidget *parent = nullptr);
    ~userActionForm();

private:
    Ui::userActionForm *ui;
};

#endif // USERACTIONFORM_H
