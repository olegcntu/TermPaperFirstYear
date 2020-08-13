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
    QString  name="Chess";                       // ����� ��
    int fond=100;                                //�ਧ���� 䮭� ��
    QString level="All-Ukrainian";               // �?���� ��
    QString janr="strategic";  // ���� ��
    void **what_whereArray=NULL;                 //��ᨢ ���?�
}Tchampionships;

typedef struct  what_where{
    int num;                     //����� ����
    QString  venue;              // �?�� �஢������ ����
    float time;                  // �� �஢������ ����
    void **comandArray;          //��ᨢ ����?����?� �� �������
}Twhat_where;

typedef struct commands{
    QString name;                // ����� �������
    int prize_place;             //������ �?�� ��������
    QString city;                // �?�� � 类�� �������
    QString captain;             //���?⠭ �������
    void **firstparticipants;    //����뢭�� �� ���讣� ��᭨��
}Tcommands;

typedef struct participants{
    QString name ;              // �?� ��᭨��
    int age;                    // �?�
    bool status;                // ����� ��᭨��
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
        char name[20]="Chess";                       // ����� ��
        int fond=100;                                //�ਧ���� 䮭� ��
        char level[20] ="All-Ukrainian";               // �?���� ��
        char janr[35] ="strategic/antagonistic game";  // ���� ��
        int Turcount;               //��ᨢ ���?�
    };


    struct  Fwhat_where{
        int num;                     //����� ����
        char venue[40];              // �?�� �஢������ ����
        float time;                  // �� �஢������ ����
        int Comcount;          //��ᨢ ����?����?� �� �������
    };

    struct Fcommands{
        char name[40];                // ����� �������
        int prize_place;             //������ �?�� ��������
        char city[40];                // �?�� � 类�� �������
        char captain[40];             //���?⠭ �������
        int Player;              //����뢭�� �� ���讣� ��᭨��
    };


    struct Fparticipants{
        char name[40];              // �?� ��᭨��
        int age;                    // �?�
        bool status;                // ����� ��᭨��
    };

    void **p1=NULL;//�⢮७�� ��஦�?� ����?����?�, ��� ������⠭�� � ������讬�
    void **p2=NULL;
    void **p3=NULL;

#define POS_CNT -2//�㦡��? ���?��
#define POS_SZ  -1
#define SIZE_AR_FIRST 20//���⪮��� ஧�?� ��ᨢ�
#define DELTA 4//��� ஧�७�� ��ᨢ�


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
