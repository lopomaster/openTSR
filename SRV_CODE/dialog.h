#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    int camselect;
    ~Dialog();

public slots:
    void keyPressEvent(QKeyEvent *event);
    void cerrar_configuracion();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
