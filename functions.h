#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
void dellPlayer(void** &start,  int posAdd);//��������� �ࠢ��
void delltur(void** &start,  int posAdd,int y);//��������� ����
void dellCom(void** &start,  int posAdd,int y);//��������� �������
void ** InitArray();//?�?�?��?���?� ��ᨢ�
void addToSort(void** &start,  void* pnew, int posAdd);//��������� ���讣� �?���
void creatWW(Ui::MainWindow *ui,void **&p1,championships* &p,void **p9,int a,QString q,float a2);//�⢮७�� ����
void creatCom(void **&p1,void **p3,QString q1,int a,QString q2,QString q3,int l);//�⢮७�� �������
void creatpLAYER(void **&p1,QString q,int a,int l,QString l1,bool& j);//�⢮७�� �ࠢ��
void ExpendArrPtr (void** &ar);//஧�७�� ��ᨢ�
void FindElListforww(void** start,  int key, int &posFndEl, bool &findOK);//���� ���� ��� ��⠢��
void FindElListforcom(void** start,  QString key, int &posFndEl, bool &findOK);//���� ������� ��� ��⠢��
void FindElList2(void** start,  QString key, int &posFndEl, bool &findOK);//���� �ࠢ�� ��� ��⠢��
void FindFTur(Ui::MainWindow *ui,void **p1);//���� ���� ��� �����㢠�
void FindFPlayer(Ui::MainWindow *ui,void **p1,void **p3);//���� �ࠢ��(��� �����㢠�)
void FindFCom(Ui::MainWindow *ui,void **p1);//���� �������(��� �����㢠�)
void redTur(Ui::MainWindow *ui,void **p1,void **p2,championships *&p);//।���㢠��� ����
void redCom(Ui::MainWindow *ui,void **p1,void**p3);//।��㢠��� �������
void redPlayer(Ui::MainWindow *ui,void **p1,void**p3);//।��㢠��� �ࠢ��
void age(void** p1,void ** p2,void **p3,Ui::MainWindow *ui);//���� �।�죮 �?��
void Findpr(void** start,Ui::MainWindow *ui);//���� �ਧ���� �?���
void turforCom(void** p1,void **p2,Ui::MainWindow *ui);//���宦����� ���� ��� �������




class functions
{
public:
    functions();
};

#endif // FUNCTIONS_H
