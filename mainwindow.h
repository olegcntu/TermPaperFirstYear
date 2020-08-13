#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using std::string;

struct what_where;
struct commands;
struct participants;
//signed
typedef struct   championships
{
    QString  name="Chess";                       // назва гри
    int fond=100;                                //призовий фонд гри
    QString level="All-Ukrainian";               // р?вень гри
    QString janr="strategic";  // жанр гри
    void **what_whereArray=NULL;                 //масив тур?в
}Tchampionships;

typedef struct  what_where{
    int num;                     //номер туру
    QString  venue;              // м?сце проведення туру
    float time;                  // час проведення туру
    void **comandArray;          //масив вказ?вник?в на команди
}Twhat_where;

typedef struct commands{
    QString name;                // назва команди
    int prize_place;             //зайняте м?сце командою
    QString city;                // м?сто з якого команда
    QString captain;             //кап?тан команди
    void **firstparticipants;    //вказывник на першого учасника
}Tcommands;

typedef struct participants{
    QString name ;              // П?Б учасника
    int age;                    // в?к
    bool status;                // статус учасника
}Tparticipants;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    championships *p=new  Tchampionships;
    struct   Fchampionships
    {
        char name[20]="Chess";                       // назва гри
        int fond=100;                                //призовий фонд гри
        char level[20] ="All-Ukrainian";               // р?вень гри
        char janr[35] ="strategic/antagonistic game";  // жанр гри
        int Turcount;               //масив тур?в
    };


    struct  Fwhat_where{
        int num;                     //номер туру
        char venue[40];              // м?сце проведення туру
        float time;                  // час проведення туру
        int Comcount;          //масив вказ?вник?в на команди
    };

    struct Fcommands{
        char name[40];                // назва команди
        int prize_place;             //зайняте м?сце командою
        char city[40];                // м?сто з якого команда
        char captain[40];             //кап?тан команди
        int Player;              //вказывник на першого учасника
    };


    struct Fparticipants{
        char name[40];              // П?Б учасника
        int age;                    // в?к
        bool status;                // статус учасника
    };

    void **p1=NULL;//створення порожн?х вказ?вник?в, для використання в подальшому
    void **p2=NULL;
    void **p3=NULL;

#define POS_CNT -2//службов? зам?ни
#define POS_SZ  -1
#define SIZE_AR_FIRST 20//початковий розм?р масиву
#define DELTA 4//для розширення масиву


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();



    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
