#ifndef S_FORM_H
#define S_FORM_H

#include <QWidget>


namespace Ui {
class s_Form;
}

class s_Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit s_Form(QWidget *parent);
    ~s_Form();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::s_Form *ui;

};

#endif // S_FORM_H
