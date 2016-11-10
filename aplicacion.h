#ifndef APLICACION_H
#define APLICACION_H

#include <QDialog>
#include <QtSerialPort>
#include <QGraphicsScene>

namespace Ui {
class Aplicacion;
}

class Aplicacion : public QDialog
{
    Q_OBJECT

public:
    explicit Aplicacion(QWidget *parent = 0);
    ~Aplicacion();

private slots:
    void obtenerDatos();

private:
    Ui::Aplicacion *ui;
    QSerialPort *arduino;
    QPixmap *pixmap;
    QPixmap *pixmap2;


    //Fuciones para establecer comunicacion con el arduino
    void establecerArduino();

    //Funciones para actualizar widgets
    void actualizarLCD(const QString valor);
    void actualizarTanqueA(int valor);
    void actualizarTanqueB(int valor);
};

#endif // APLICACION_H
