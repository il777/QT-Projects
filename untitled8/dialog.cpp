#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QString>
#include <math.h>
#include <QSlider>

QString p;
QString q;
QString s;
QLabel *lab;
int six=0;
int two=0;

double N=0.0;
char oper;
QByteArray str1;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{

    ui->setupUi(this);
    //input the number
    connect(ui->push0,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push1,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push2,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push3,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push4,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push5,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push6,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push7,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push8,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->push9,SIGNAL(clicked(bool)),this,SLOT(input()));

    connect(ui->pushA,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->pushB,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->pushC,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->pushD,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->pushE,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->pushF,SIGNAL(clicked(bool)),this,SLOT(input()));


    //Clear and <
    connect(ui->pushCCCP,SIGNAL(clicked(bool)),this,SLOT(clear()));
    connect(ui->pushV,SIGNAL(clicked(bool)),this,SLOT(clr()));
    //operations
    connect(ui->pushplus,SIGNAL(clicked(bool)),this,SLOT(func()));
    //
    connect(ui->pushminus,SIGNAL(clicked(bool)),this,SLOT(func()));
    connect(ui->pushX,SIGNAL(clicked(bool)),this,SLOT(func()));
    connect(ui->pushdivide,SIGNAL(clicked(bool)),this,SLOT(func()));
    connect(ui->ravno,SIGNAL(clicked(bool)),this,SLOT(rav()));
    //double
    connect(ui->pushtochka,SIGNAL(clicked(bool)),this,SLOT(input()));
    //change +/-
    connect(ui->pushchange,SIGNAL(clicked(bool)),this,SLOT(change()));
    //procent
    connect(ui->pushprocent,SIGNAL(clicked(bool)),this,SLOT(procent()));
    //Slider
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)),this, SLOT(slender()));

}


void Dialog::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    p+=QString(QChar(key));
    if (key>=Qt::Key_0 && key<=Qt::Key_9) ui->label->setText(p);

    if (key==Qt::Key_A)ui->label->setText(p);
    if (key==Qt::Key_B)ui->label->setText(p);
    if (key==Qt::Key_C)ui->label->setText(p);
    if (key==Qt::Key_D)ui->label->setText(p);
    if (key==Qt::Key_E)ui->label->setText(p);
    if (key==Qt::Key_F)ui->label->setText(p);

    if (key==Qt::Key_Backspace)
    {
        p=ui->label->text();
        int quont=p.size();
        p.remove(quont-1,1);
        ui->label->setText(p);
    }
    if (key==Qt::Key_Escape)
    {this->close();}
}

void Dialog::hedic()
{
    ////////////
   int n, ost;
   n=p.toInt();
   p="";
   do
   {
       ost=n%16;
       n/=16;
       if(ost<10)
       {
           p+=ost;
       }
       if(ost>=10)
       {
           switch(ost)
           {
            case 10:p+="A";break;
            case 11:p+="B";break;
            case 12:p+="C";break;
            case 13:p+="D";break;
            case 14:p+="E";break;
            case 15:p+="F";break;
           }
       }

   }while(n!=0);
   ui->label->setText(p);
}

void Dialog::input()
{

    QPushButton *btn=(QPushButton*)sender();
    p += btn->text();
    N=p.toDouble();
    QString q=QString::number(N);
    ui->label->setText(p);

}

void Dialog::clear()
{
    p.clear();
    ui->label->setText(p);
}

void Dialog::clr()
{
    int siz;
    siz=p.length();
    p=p.remove(siz-1, 1);
    ui->label->setText(p);
}

void Dialog::procent()
{
    N=p.toDouble();
    N=N/100;
    p=QString::number(N);
    ui->label->setText(p);
}

void Dialog::change()
{
    N=p.toDouble();
    N=N*(-1);
    p=QString::number(N);
    ui->label->setText(p);
}

void Dialog::func()
{
    q=p;
    p.clear();
    ui->label->setText(p);
    QPushButton *btn=(QPushButton*)sender();
    s = btn->text();
}

void Dialog::rav()
{
    QByteArray str1 =s.toUtf8();
    char *oper = str1.data();
    double a,b;
    a=q.toDouble();
    b=p.toDouble();

    if (oper[0] == '+')N=a+b; p=QString::number(N);
    if (oper[0] == '-')N=a-b; p=QString::number(N);
    if (oper[0] == 'X')N=a*b; p=QString::number(N);
    if (oper[0] == '/')N=a/b; p=QString::number(N);
    ui->label->setText(QString::number(N));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::hex()
{
        int n, ost;
        n=p.toInt();
        p.clear();
        do
        {
            ost=n%16;
            n/=16;
            if(ost<10)
            {
                p.push_front(QString::number(ost));
            }
            if(ost>=10)
            {
                switch(ost)
                {
                 case 10:p.push_front("A");break;
                 case 11:p.push_front("B");break;
                 case 12:p.push_front("C");break;
                 case 13:p.push_front("D");break;
                 case 14:p.push_front("E");break;
                 case 15:p.push_front("F");break;
                }
            }

        }while(n!=0);
        ui->label->setText(p);
    six=-1;

}
//перевод в 2-ичную
void Dialog::bin()
{
    p=ui->label->text();
    int N, ost;
    N=p.toInt();
    p.clear();
    do{
        ost=N%2;
        p.push_front(QString::number(ost));
        N/=2;
    }while(N!=0);
    ui->label->setText(p);
    two=-1;
}

void Dialog::dec()
{
    //перевод из 2-ичной
    int sum=0,i=0;
    if (two==-1)
    {
        p=ui->label->text();
        int temp=p.toInt();
        while(temp>0)
        {
            sum+=(temp%10)*pow(2,i);
            temp/=10;
            i++;
        }
        two=0;
        p=QString::number(sum);
        ui->label->setText(p);
    }
    //перевод из 16-тиричной
    sum=0;
    if(six==-1){
        std::string str = p.toUtf8().constData();
        int size = str.size();
        for (int i=0; i<size; i++){
        char a=str[size-i-1];
            int b=0;

            if (a=='1'){b=1;}
            if (a=='2'){b=2;}
            if (a=='3'){b=3;}
            if (a=='4'){b=4;}
            if (a=='5'){b=5;}
            if (a=='6'){b=6;}
            if (a=='7'){b=7;}
            if (a=='8'){b=8;}
            if (a=='9'){b=9;}

            if (a=='A'){b=10;}
            if (a=='B'){b=11;}
            if (a=='C'){b=12;}
            if (a=='D'){b=13;}
            if (a=='E'){b=14;}
            if (a=='F'){b=15;}

            sum+=b*pow(16,i);
            }
        p=QString::number(sum);
        six=0;
        ui->label->setText(p);
    }
}

void Dialog::slender()
{
    int change;
    change=ui->verticalSlider->value();
    switch(change)
    {
        case 1: six=1;break;
        case 3: two=1;break;
    }
    if ((six==-1)||(two==-1)) {Dialog::dec();}
    if (two==1) {Dialog::bin();}
    if (six==1) {Dialog::hex();}
}
