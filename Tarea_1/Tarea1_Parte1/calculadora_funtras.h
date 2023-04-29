#ifndef CALCULADORA_FUNTRAS_H
#define CALCULADORA_FUNTRAS_H
#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QIcon>
#include <boost/lexical_cast.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class calculadora_funtras; }
QT_END_NAMESPACE
class calculadora_funtras : public QMainWindow{
    Q_OBJECT
public:
    calculadora_funtras(QWidget *parent = nullptr);
    ~calculadora_funtras();
private:
    Ui::calculadora_funtras *ui;
    QGridLayout *mainLayout;
    QLineEdit *inputx;
    QLineEdit *inputy;
    QLabel *labelx;
    QLabel *labely;
    QLabel *output;
    QLabel *info;
private slots:
    void groupInfo();
    void clear();
    void sinh_x();
    void cosh_x();
    void tanh_x();
    void asin_x();
    void acos_x();
    void atan_x();
    void sec_x();
    void csc_x();
    void cot_x();
    void sin_x();
    void cos_x();
    void tan_x();
    void ln_x();
    void log10_x();
    void log_base_y_de_x();
    void inverso_x();
    void raiz_de_x();
    void indice_y_raiz_x();
    void exp_x();
    void x_elevado_a_y();
    void factorial();
    void test();
};
#endif // CALCULADORA_FUNTRAS_H
