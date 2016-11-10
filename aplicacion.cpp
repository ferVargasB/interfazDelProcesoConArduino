#include "aplicacion.h"
#include "ui_aplicacion.h"
#include <QDebug>
#include <QPainter>

Aplicacion::Aplicacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aplicacion)
{
    ui->setupUi(this);
    arduino = new QSerialPort();
    pixmap = new QPixmap(ui->labelTanqueA->width(), ui->labelTanqueA->height());
    pixmap2 = new QPixmap(ui->labelTanqueB->width(), ui->labelTanqueB->height());
    establecerArduino();
    //Solo se invoca a la funcion para mostrar el nivel del tanque B
    actualizarTanqueB(20);
    Aplicacion::connect(arduino, SIGNAL(readyRead()), this, SLOT(obtenerDatos()));
}

Aplicacion::~Aplicacion()
{
    delete ui;
}

void Aplicacion::obtenerDatos()
{
    qDebug() << "La lectura funciona";
    QByteArray datosSeriales = arduino->readAll();
    QString datosEnCadena = QString::fromStdString(datosSeriales.toStdString());
    actualizarLCD(datosEnCadena);
    bool ok = true;
    int datosEnEntero = datosEnCadena.toInt(&ok, 10);
    actualizarTanqueA(datosEnEntero);
    qDebug() << datosEnCadena; //Función para monitorear
}

void Aplicacion::establecerArduino()
{
    for ( auto item : QSerialPortInfo::availablePorts() ){
        if ( item.portName() == "cu.wchusbserialfd130")
        {
            qDebug() << "Se ha encontrado el Arduino";
            arduino->setPortName(item.portName());
            arduino->open(QSerialPort::ReadOnly);
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
        }

    }
}

void Aplicacion::actualizarLCD(const QString valor)
{
    ui->lcdNumber->display(valor);
}

void Aplicacion::actualizarTanqueA(int valor)
{
    valor = ( valor * 300) / 100;
    pixmap->fill(Qt::white);
    QPainter p(pixmap);
    p.setPen(Qt::red);
    p.drawLine(0, pixmap->height() - valor, pixmap->width() - 1, pixmap->height() - valor);
    ui->labelTanqueA->setPixmap(*pixmap);
}

void Aplicacion::actualizarTanqueB(int valor)
{
    pixmap2->fill(Qt::white);
    QPainter p(pixmap2);
    p.setPen(Qt::blue);
    p.drawLine(0, pixmap2->height() - 10, pixmap2->width() - 1, pixmap2->height() - 10);
    ui->labelTanqueB->setPixmap(*pixmap2);
}
