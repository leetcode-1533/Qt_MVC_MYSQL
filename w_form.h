#ifndef W_FORM_H
#define W_FORM_H

#include <QWidget>
class QTabWidget;
namespace Ui {
class W_Form;
}

class W_Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit W_Form(QWidget *parent = 0);
    ~W_Form();
    
private:
    Ui::W_Form *ui;
    QTabWidget *tab;
};

#endif // W_FORM_H
