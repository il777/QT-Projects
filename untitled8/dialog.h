#ifndef DIALOG_H
#define DIALOG_H

#include <QKeyEvent>
#include <QDialog>
#include <QSlider>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void input();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

public slots:
    void bin();
    void hex();
    void dec();

private slots:

    void clear();
    void clr();
    void func();
    void rav();
    void change();
    void procent();
    void hedic();
    void slender();

    //void on_to_hex_clicked(bool checked);

    //void on_to_bin_clicked(bool checked);

    //void on_to_dec_clicked(bool checked);

    void on_verticalSlider_actionTriggered(int action);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
