#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
void dellPlayer(void** &start,  int posAdd);//видалення гравця
void delltur(void** &start,  int posAdd,int y);//видалення туру
void dellCom(void** &start,  int posAdd,int y);//видалення команди
void ** InitArray();//?н?ц?ал?зац?я масиву
void addToSort(void** &start,  void* pnew, int posAdd);//додавання першого р?вня
void creatWW(Ui::MainWindow *ui,void **&p1,championships* &p,void **p9,int a,QString q,float a2);//створення туру
void creatCom(void **&p1,void **p3,QString q1,int a,QString q2,QString q3,int l);//створення команди
void creatpLAYER(void **&p1,QString q,int a,int l,QString l1,bool& j);//створення гравця
void ExpendArrPtr (void** &ar);//розширення масиву
void FindElListforww(void** start,  int key, int &posFndEl, bool &findOK);//пошук туру для вставки
void FindElListforcom(void** start,  QString key, int &posFndEl, bool &findOK);//пошук команди для вставки
void FindElList2(void** start,  QString key, int &posFndEl, bool &findOK);//пошук гравця для вставки
void FindFTur(Ui::MainWindow *ui,void **p1);//пошук туру для користувача
void FindFPlayer(Ui::MainWindow *ui,void **p1,void **p3);//пошук гравця(для користувача)
void FindFCom(Ui::MainWindow *ui,void **p1);//пошук команди(для користувача)
void redTur(Ui::MainWindow *ui,void **p1,void **p2,championships *&p);//редактування туру
void redCom(Ui::MainWindow *ui,void **p1,void**p3);//редагування команди
void redPlayer(Ui::MainWindow *ui,void **p1,void**p3);//редагування гравця
void age(void** p1,void ** p2,void **p3,Ui::MainWindow *ui);//пошук середньго в?ку
void Findpr(void** start,Ui::MainWindow *ui);//пошук призових м?сць
void turforCom(void** p1,void **p2,Ui::MainWindow *ui);//знахождення туру для команди




class functions
{
public:
    functions();
};

#endif // FUNCTIONS_H
