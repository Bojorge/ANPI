#include "calculadora_funtras.h"
#include "funtras.h"
#include "ui_calculadora_funtras.h"
#include <QDoubleValidator>
calculadora_funtras::calculadora_funtras(QWidget *parent): QMainWindow(parent){
    QDoubleValidator *validator = new QDoubleValidator(0, 10, 4, this);
    //INPUTS
    inputx = new QLineEdit(this);
    inputx->setAlignment(Qt::AlignCenter);
    inputx->setValidator(validator);
    inputx->setText("");
    inputy = new QLineEdit(this);
    inputy->setAlignment(Qt::AlignCenter);
    inputy->setValidator(validator);
    inputy->setText("");
    labelx = new QLabel(this);
    labelx->setText("X");
    labelx->setStyleSheet("QLabel { font: bold 20px; height: 10px; }");
    labelx->setAlignment(Qt::AlignCenter);
    labely = new QLabel(this);
    labely->setText("Y");
    labely->setStyleSheet("QLabel { font: bold 20px; height: 10px; }");
    labely->setAlignment(Qt::AlignCenter);
    //OUTPUTS
    output = new QLabel(this);
    output->setText("OUTPUT");
    output->setAlignment(Qt::AlignCenter);
    output->setStyleSheet("font-size: 20px; color: black;");
    //ETIQUETA
    info = new QLabel(this);
    info->setText("Inserte los parametros necesarios y presione el boton de operacion");
    info->setAlignment(Qt::AlignCenter);
    //MATRIZ COLOCA WIDGETS CREADOS
    mainLayout = new QGridLayout(this);
    //QGridLayout *mainLayout = new QGridLayout(9, 4);
    for (int row = 0; row < 13; ++row) {
        mainLayout->setRowStretch(row, 1);
    }
    for (int col = 0; col < 3; ++col) {
        mainLayout->setColumnStretch(col, 1);
    }
    mainLayout->addWidget(inputx, 2, 0);
    mainLayout->addWidget(inputy, 2, 2);
    mainLayout->addWidget(labelx, 1, 0);
    mainLayout->addWidget(labely, 1, 2);
    mainLayout->addWidget(output, 3, 0, 2, 3);
    mainLayout->addWidget(info, 4, 0, 1, 3);
    //BOTONES
    QPushButton *groupInfo = new QPushButton("Informacion del grupo", this);
    QPushButton *clear = new QPushButton("Limpiar todos los campos", this);
    QPushButton *test = new QPushButton("TEST SCRIPT", this);
    QPushButton *button1 = new QPushButton("sinh(x)", this);
    QPushButton *button2 = new QPushButton("cosh(x)", this);
    QPushButton *button3 = new QPushButton("tanh(x)", this);
    QPushButton *button4 = new QPushButton("asin(x)", this);
    QPushButton *button5 = new QPushButton("acos(x)", this);
    QPushButton *button6 = new QPushButton("atan(x)", this);
    QPushButton *button7 = new QPushButton("sec(x)", this);
    QPushButton *button8 = new QPushButton("csc(x)", this);
    QPushButton *button9 = new QPushButton("cot(x)", this);
    QPushButton *button10 = new QPushButton("sin(x)", this);
    QPushButton *button11 = new QPushButton("cos(x)", this);
    QPushButton *button12 = new QPushButton("tan(x)", this);
    QPushButton *button13 = new QPushButton("ln(x)", this);
    QPushButton *button14 = new QPushButton("log10(x)", this);
    QPushButton *button15 = new QPushButton("log_y(x)", this);
    QPushButton *button16 = new QPushButton("1/x", this);
    QPushButton *button17 = new QPushButton("√x", this);
    QPushButton *button18 = new QPushButton("y_√x", this);
    QPushButton *button19 = new QPushButton("exp(x)", this);
    QPushButton *button20 = new QPushButton("x^y", this);
    QPushButton *button21 = new QPushButton("x!", this);
    mainLayout->addWidget(groupInfo, 0, 0);
    mainLayout->addWidget(clear, 0, 2);
    mainLayout->addWidget(button1, 5, 0);
    mainLayout->addWidget(button2, 5, 1);
    mainLayout->addWidget(button3, 5, 2);
    mainLayout->addWidget(button4, 6, 0);
    mainLayout->addWidget(button5, 6, 1);
    mainLayout->addWidget(button6, 6, 2);
    mainLayout->addWidget(button7, 7, 0);
    mainLayout->addWidget(button8, 7, 1);
    mainLayout->addWidget(button9, 7, 2);
    mainLayout->addWidget(button10, 8, 0);
    mainLayout->addWidget(button11, 8, 1);
    mainLayout->addWidget(button12, 8, 2);
    mainLayout->addWidget(button13, 9, 0);
    mainLayout->addWidget(button14, 9, 1);
    mainLayout->addWidget(button15, 9, 2);
    mainLayout->addWidget(button16, 10, 0);
    mainLayout->addWidget(button17, 10, 1);
    mainLayout->addWidget(button18, 10, 2);
    mainLayout->addWidget(button19, 11, 0);
    mainLayout->addWidget(button20, 11, 1);
    mainLayout->addWidget(button21, 11, 2);
    mainLayout->addWidget(test, 12, 1);
    // CONECTAR BOTON CON SU FUNCION
    connect(groupInfo, &QPushButton::clicked, this, &calculadora_funtras::groupInfo);
    connect(clear, &QPushButton::clicked, this, &calculadora_funtras::clear);
    connect(test, &QPushButton::clicked, this, &calculadora_funtras::test);
    connect(button1, &QPushButton::clicked, this, &calculadora_funtras::sinh_x);
    connect(button2, &QPushButton::clicked, this, &calculadora_funtras::cosh_x);
    connect(button3, &QPushButton::clicked, this, &calculadora_funtras::tanh_x);
    connect(button4, &QPushButton::clicked, this, &calculadora_funtras::asin_x);
    connect(button5, &QPushButton::clicked, this, &calculadora_funtras::acos_x);
    connect(button6, &QPushButton::clicked, this, &calculadora_funtras::atan_x);
    connect(button7, &QPushButton::clicked, this, &calculadora_funtras::sec_x);
    connect(button8, &QPushButton::clicked, this, &calculadora_funtras::csc_x);
    connect(button9, &QPushButton::clicked, this, &calculadora_funtras::cot_x);
    connect(button10, &QPushButton::clicked, this, &calculadora_funtras::sin_x);
    connect(button11, &QPushButton::clicked, this, &calculadora_funtras::cos_x);
    connect(button12, &QPushButton::clicked, this, &calculadora_funtras::tan_x);
    connect(button13, &QPushButton::clicked, this, &calculadora_funtras::ln_x);
    connect(button14, &QPushButton::clicked, this, &calculadora_funtras::log10_x);
    connect(button15, &QPushButton::clicked, this, &calculadora_funtras::log_base_y_de_x);
    connect(button16, &QPushButton::clicked, this, &calculadora_funtras::inverso_x);
    connect(button17, &QPushButton::clicked, this, &calculadora_funtras::raiz_de_x);
    connect(button18, &QPushButton::clicked, this, &calculadora_funtras::indice_y_raiz_x);
    connect(button19, &QPushButton::clicked, this, &calculadora_funtras::exp_x);
    connect(button20, &QPushButton::clicked, this, &calculadora_funtras::x_elevado_a_y);
    connect(button21, &QPushButton::clicked, this, &calculadora_funtras::factorial);
    //ESTILOS
    groupInfo->setStyleSheet("QPushButton { background-color: green; color: white; font-size: 15px; } QPushButton:hover { background-color: blue; }");
    clear->setStyleSheet("QPushButton { background-color: white; color: black; font-size: 15px; } QPushButton:hover { background-color: blue; }");
    button1->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button2->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button3->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button4->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button5->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button6->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button7->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button8->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button9->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button10->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button11->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button12->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button13->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button14->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button15->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button16->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button17->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button18->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button19->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button20->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    button21->setStyleSheet("QPushButton { background-color: grey; color: black; font-size: 20px; font-style: italic; } QPushButton:hover { background-color: orange; }");
    //CONECTAR INPUTS
    connect(inputx, &QLineEdit::textChanged, [=]() {
        QString textx = inputx->text();
        textx.replace(",", ".");
        inputx->setText(textx);
    });
    connect(inputy, &QLineEdit::textChanged, [=]() {
        QString texty = inputy->text();
        texty.replace(",", ".");
        inputy->setText(texty);
    });
    // CENTRAL DE CALCULADORA INTERFAZ
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("FunTras");
    mainLayout->setAlignment(Qt::AlignCenter);
    int numRows = mainLayout->rowCount();
    int numCols = mainLayout->columnCount();
    int cellSize = 50;
    int minWidth = numCols * cellSize * 9;
    int minHeight = numRows * cellSize;
    setMinimumSize(minWidth, minHeight);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    show();
}
calculadora_funtras::~calculadora_funtras()
{
    delete ui;
}
void calculadora_funtras::groupInfo(){
    QMessageBox::information(this, "INTEGRANTES", "Manuel Bojorge Araya 2016093626 \n Joseph Jimenez Zuñiga 2016133677");
    QMessageBox::about(this, "Informacion", "Ingrese valores de X y Y para calcular la aproximacion de las funciones trascendentales");
}
void calculadora_funtras::clear(){
    output->setText("---");
    info->setText("---");
    inputx->setText("");
    inputy->setText("");
}
//FUNCIONES DE INTERFAZ CONECTAN CON FUNCIONES PROGRAMADAS
void calculadora_funtras::sinh_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended sinh_t_RESULT = funciones->sinh_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(sinh_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::cosh_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended cosh_t_RESULT = funciones->cosh_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(cosh_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::tanh_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended tanh_t_RESULT = funciones->tanh_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(tanh_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::asin_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);

    if(inputxValue >= -1 && inputxValue <= 1){
        cpp_bin_float_double_extended asin_t_RESULT = funciones->asin_t(inputxValue);
        QString resultStr = QString::number(static_cast<long double>(asin_t_RESULT), 'f', 51);
        output->setText(resultStr);
    }
    else{
        output->setText("El valor de X debe estar entre -1 y 1");
    }
    delete funciones;
}
void calculadora_funtras::acos_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    if(inputxValue >= -1 && inputxValue <= 1){
        cpp_bin_float_double_extended acos_t_RESULT = funciones->acos_t(inputxValue);
        QString resultStr = QString::number(static_cast<long double>(acos_t_RESULT), 'f', 51);
        output->setText(resultStr);
    }
    else{
        output->setText("El valor de X debe estar entre -1 y 1");
    }
    delete funciones;
}
void calculadora_funtras::atan_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended atan_t_RESULT = funciones->atan_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(atan_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::sec_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended sec_t_RESULT = funciones->sec_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(sec_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::csc_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended csc_t_RESULT = funciones->csc_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(csc_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::cot_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended cot_t_RESULT = funciones->cot_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(cot_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::sin_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    //double inputxRadians = (inputxValue) * (pi_t / 180);
    cpp_bin_float_double_extended sin_t_RESULT = funciones->sin_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(sin_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::cos_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended cos_t_RESULT = funciones->cos_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(cos_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::tan_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    double inputxRadians = qDegreesToRadians(inputxValue);
    cpp_bin_float_double_extended tan_t_RESULT = funciones->tan_t(inputxRadians);
    QString resultStr = QString::number(static_cast<long double>(tan_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::ln_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    cpp_bin_float_double_extended ln_t_RESULT = funciones->ln_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(ln_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::log10_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    cpp_bin_float_double_extended log10_t_RESULT = funciones->log10_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(log10_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::log_base_y_de_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    QString inputyText = inputy->text();
    double inputyValue = inputyText.toDouble();
    cpp_bin_float_double_extended log_y_t_RESULT = funciones->log_y_t(inputxValue, inputyValue);
    QString resultStr = QString::number(static_cast<long double>(log_y_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::inverso_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    //double inputxValue = inputxText.toDouble();
    //long double inputxValue = inputxText.toLongDouble();
    long double inputxValue = std::stold(inputxText.toStdString());
    cpp_bin_float_double_extended inverso_RESULT = funciones->inverso_de_x(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(inverso_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::raiz_de_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    cpp_bin_float_double_extended root_t_RESULT = funciones->root_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(root_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::indice_y_raiz_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    QString inputyText = inputy->text();
    double inputyValue = inputyText.toDouble();
    cpp_bin_float_double_extended indice_y_raiz_x__t_RESULT = funciones->indice_y_raiz_x(inputxValue, inputyValue);
    QString resultStr = QString::number(static_cast<long double>(indice_y_raiz_x__t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::exp_x(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    cpp_bin_float_double_extended exp_t_RESULT = funciones->exp_t(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(exp_t_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::x_elevado_a_y(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    //double inputxRadians = qDegreesToRadians(inputxValue);
    QString inputyText = inputy->text();
    double inputyValue = inputyText.toDouble();
    cpp_bin_float_double_extended x_elevado_a_y_RESULT = funciones->x_elevado_a_y(inputxValue, inputyValue);
    QString resultStr = QString::number(static_cast<double>(x_elevado_a_y_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
void calculadora_funtras::factorial(){
    funtras* funciones = new funtras();
    QString inputxText = inputx->text();
    double inputxValue = inputxText.toDouble();
    if(inputxValue > 0 && inputxValue < 50){
        output->setStyleSheet("font-size: 20px; color: black;");
    }
    else if(inputxValue > 50 && inputxValue < 70){
        output->setStyleSheet("font-size: 15px; color: black;");
    }
    else if(inputxValue >= 70){
        output->setStyleSheet("font-size: 11px; color: black;");
    }
    cpp_bin_float_double_extended factorial_RESULT = funciones->factorial(inputxValue);
    QString resultStr = QString::number(static_cast<long double>(factorial_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}

void calculadora_funtras::test(){
    funtras* funciones = new funtras();
    cpp_bin_float_double_extended test_RESULT = funciones->test_t();
    QString resultStr = QString::number(static_cast<long double>(test_RESULT), 'f', 51);
    output->setText(resultStr);
    delete funciones;
}
