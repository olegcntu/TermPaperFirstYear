

#include "functions.h"


void ** InitArray()//?н?ц?ал?зац?я
{
    void ** p=new void* [SIZE_AR_FIRST+2];//створення динам?чного масиву заданого розм?ру
    p=p+2;
    ((int*)p)[POS_CNT]  = 0;//к?льк?сть елемент?в
    ((int*)p)[POS_SZ]  = SIZE_AR_FIRST;//розм?р масиву
    return p;//повертаємо масив
}

void ExpendArrPtr (void** &ar)//функц?я розширення маисву безтипових вказывник?в
{

      int Cnt=((int *)ar) [POS_CNT];
      int	   SizeW =((int *)ar) [POS_SZ];   /*збереження старого розм?ру масиву*/
      ((int *)ar) [POS_SZ] = ((int *)ar) [POS_SZ] + DELTA;   /*визначення нового розм?ру масиву*/
      void**   arW;              //дпом?жний безтиповий покажчик на
       int SizeAr= ((int *)ar) [POS_SZ] ;                       //початок масиву покажчик?в
      arW = new void*[((int *)ar) [POS_SZ]+2]; /*видо?лення м?сця для нового масиву*/
      /*коп?ювання старого масиву вказ?вник?в в новий масив*/
      for (int i=0; i<SizeW; i++)
        { arW[i+2] = ar[i]; }
      ar=ar-2;      // ставимо вказ?вник на початок старого масиву
      delete []ar;  //зв?льняємо пам'ять
      ar=arW+2;  //ставимо вказ?вник масиву на перший вказ?вник в новому масив?
      ((int*)ar)[POS_CNT]  = Cnt;    /* заповнюємо службов? елементи */
        ((int*)ar)[POS_SZ]  = SizeAr;
}
void addToSort(void** &start,  void* pnew, int posAdd)// додавання до в?дсортованого безтипового маисву
{
    int cnt=((int*)start)[POS_CNT];//читаємо службов? елементи
    int sz= ((int*)start)[POS_SZ];
    if (cnt == sz)//якщо службовий елемент вказує на переповнення масиву, розширюємо
    {
        ExpendArrPtr (start);
    }
    if (posAdd == cnt) //елемент додається в к?нець списку
    {
        start[posAdd] = pnew;
    }
    else
    {     // зсув елемент?в масиву вправо
        for (int k = cnt-1; k >= posAdd; k--)//доки не буде знайдене потр?бне м?сце
        { start[k+1] = start[k]; }//перезаписуємо на одну ком?рку назад
        start[posAdd] = pnew;//п?сля виходу з циклу записуємо елемент в потр?бну ком?рку
    }
    cnt++;//зб?льшуємо розм?р
    ((int*)start)[POS_CNT]=cnt;//записуємо
}

void FindElListforww(void** start,  int key, int &posFndEl, bool &findOK)//пошук елементту, перев?рка, чи знайдено
{//пошук м?сця для вставки
    if(start==NULL){posFndEl=0;findOK=false;return;}//якщо р?вень пустий, то повертаємо false
    // по амперсенту та виходимо з функц?ї
    int	middl;    // ?ндекс середнього елемента масиву
    int	hi, low;  // поточн? меж? - верхня, нижня
    findOK = false;  // елемент не знайдено
    if (((int*)start)[POS_CNT] == 0)//якщо список пустий
    {
        posFndEl = 0;
        return;
    }
    // Встановлюємо меж? пошуку на меж? масиву
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //?ндекс середнього елементу
        if (key==((what_where*)(start[middl]))->num) //Елемент знайдено
        {
            posFndEl = middl;
            findOK = true;//якщо елемент знайдено завершуємо функц?ю
            return;
        }
        if (key<((what_where*)(start[middl]))->num) /*зм?на меж пошуку*/
        { hi = middl - 1; }
        else
        { low = middl + 1; }
    } while  (low <= hi);
    posFndEl = low;//Перебрано весь масив. Елемент не знайдено.
     //Визначена позиц?я можливої вставки нового елемента
}
void FindElListforcom(void** start,  QString key, int &posFndEl, bool &findOK)
{//аналог?чна до попередньої,лише для середньго р?вня
    if(start==NULL) {posFndEl=0;findOK=false;return;}//якщо р?вень пустий, то повертаємо false
    // по амперсенту та виходимо з функц?ї
    int	middl;    // ?ндекс середнього елемента масиву
    int	hi, low;  // поточн? меж? - верхня, нижня
    findOK = false;  // елемент не знайдено
    if (((int*)start)[POS_CNT] == 0)
    {      /* якщо список пустий */
        posFndEl = 0;
        return;
    }
    // Встановлюємо меж? пошуку на меж? масиву
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //ндекс середнього елементу
        if (key==((commands*)(start[middl]))->name) //Елемент знайдено
        {
            posFndEl = middl;
            findOK = true;
            return;
        }
        if (key<((commands*)(start[middl]))->name) /*зм?на меж пошуку*/
        { hi = middl - 1; }
        else { low = middl + 1; }
    } while  (low <= hi);
    posFndEl = low;    //Перебрано весь масив. Елемент не знайдено.
                    //Визначена позиц?я можливої вставки нового елемента
}

void FindElList2(void** start,  QString key, int &posFndEl, bool &findOK)
{//аналог?чна до попередньої,лише для найнижчого р?вня р?вня
    if(start==NULL){posFndEl=0;findOK=false;return;}
    int	middl;    // ?ндекс середнього елемента масиву*/
    int	hi, low;  // поточн? меж? - верхня, нижня*/
    findOK = false;  /* елемент не знайдено*/
    if (((int*)start)[POS_CNT] == 0)
    {      // якщо список пустий
        posFndEl = 0;
        return;
    }
    // Встановлюємо меж? пошуку на меж? масиву*/
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //?ндекс середнього елементу
        if (key==((participants*)(start[middl]))->name) //Елемент знайдено*/
        {
            posFndEl = middl;
            findOK = true;
            return;
        }
        if (key<((participants*)(start[middl]))->name) //зм?на меж пошуку
        { hi = middl - 1; }
        else{ low = middl + 1; }
    } while  (low <= hi);//Перебрано весь масив. Елемент не знайдено.
    posFndEl = low;      //  Визначена позиц?я можливої вставки нового елемента
                }

void creatWW(Ui::MainWindow *ui,void **&p1,championships* &p,void **p2,int a,QString q,float a2)// створення р?вня "що/де/коли"
{
    if(p1==NULL){p1=InitArray();p->what_whereArray=p1;}
    what_where *ww=new what_where;
    int u=0;bool f;
    ww->num=a;
    ww->venue=q;
    ww->time=a2;
    ww->comandArray=p2;
    FindElListforww(p1, ww->num, u, f);
    addToSort(p1,ww,u);
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    for(int i=0;i<((int *)p1)[POS_CNT];i++)
    {
        ui->comboBox->addItem(QString::number((((what_where*)(p1)[i]))->num));
        ui->comboBox_2->addItem(QString::number((((what_where*)(p1)[i]))->num));

    }
}


void creatCom(void **&p1,void **p3,QString q1,int a,QString q2,QString q3,int l)
{
    int u=0,u1;bool f=false;
    FindElListforww(p1, l, u, f);
    if(f==false){ return;}
    if((( what_where*)p1[u])->comandArray==NULL){(( what_where*)p1[u])->comandArray=InitArray();}
    commands *com=new commands;
    com->name=q1;
    com->prize_place =a;
    com->city =q2;
    com->captain=q3;
    com->firstparticipants=p3;//присвлюємо значення п?др?вню
    FindElListforcom((( what_where*)p1[u])->comandArray, com->name, u1, f);
    addToSort((( what_where*)p1[u])->comandArray,com,u1);



}

void creatpLAYER(void **&p1,QString q,int a,int l,QString l1,bool& j)
{
    int u=0,u1=0,u2=0;bool f;//допом?жн? зм?нн?
    FindElListforww(p1, l, u, f);
    if(f==false){j=false;return;}
    FindElListforcom((( what_where*)p1[u])->comandArray,l1, u1, f);
    if(f==false){j=false;return;}
    if(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants==NULL){((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants=InitArray();}
    participants *pa=new participants;
    pa->name=q;
    pa->age=a;
    pa->status=j;
    FindElList2(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants, pa->name, u2, f);
    addToSort(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants,pa,u2);
     j=true;

}






void delltur(void** &start,  int posAdd,int y)//видалення туру
{
    int cnt=((int*)start)[POS_CNT];//читаємо к?льк?сть
    if(((what_where*)start[posAdd])->comandArray!=NULL && y==0 )//якщо п?др?вень не порожн?й та передане
    {//?нтове значення не 0 (оск?льки ?нод? не потр?бно видаляти п?др?вень, при редагуванн?*)
        //був створений перемикач, int y в який передається 0 коли треба видалити п?др?вень, вбо ?нше значення, якщо не треба
        while(((what_where*)start[posAdd])->comandArray!=NULL)// поки п?др?вень не стане порожн?м
        {
            int  posAdd1=((int*)(((what_where*)start[posAdd])->comandArray))[-2]-1;//читаємо к?льк?сть
            dellCom((( what_where*)start[posAdd])->comandArray, posAdd1,0);//видаляємо останн?й елемент з п?др?вня
            //доки в?н не буде порожн?м
        }
    }
    delete ((what_where*)start[posAdd]);//видаляєио елемент
    for (int k = posAdd; k <= cnt; k++)//зм?щуємо елементи
    { start[k] = start[k+1];}
    start[cnt]=NULL;//останн?й - нал
    cnt--;
    ((int*)start)[POS_CNT]=cnt;//записуємо к?льк?сть
}
void dellCom(void** &start,  int posAdd,int y)//видалення команди
{//аналог?чна до попередньої, лише для ?ншого р?вня та таким же перимикачем
    int cnt=((int*)start)[POS_CNT];//читаємо к?льк?сть
    if(((commands*)start[posAdd])->firstparticipants!=NULL && y==0)// дивимось чи є елементи нижчого р?вня
    {
        while(((commands*)start[posAdd])->firstparticipants!=NULL)//видаляємо поки п?др?вень не стане нал
        {
            int  posAdd1=((int*)(((commands*)start[posAdd])->firstparticipants))[-2]-1;//читаємо к?льк?сть елмент?в п?др?вня
            dellPlayer((( commands*)start[posAdd])->firstparticipants, posAdd1);//видаляємо починаючи з останнього
        }
    }
    delete ((commands*)start[posAdd]);//видаляємо елемент
    for (int k = posAdd; k <= cnt; k++)//зм?щуємо показники
    { start[k] = start[k+1];}
    start[cnt]=NULL;// останн?й налл
    cnt--;
    if(cnt==0){start=NULL;return ;}//якщо масив порожн?й, то в?н - нал
    ((int*)start)[POS_CNT]=cnt;//записуємо к?льк?сть
}

void dellPlayer(void** &start,  int posAdd)//видалення з найнижчого р?вня
{
   int cnt=((int*)start)[POS_CNT];//читаємо к?льк?сть елемент?в
    delete ((participants*)start[posAdd]);//видаляємо очищаючи память
    for (int k = posAdd; k <= cnt; k++)//зм?щуємо елементи
    { start[k] = start[k+1];}//зм?щуємо
    start[cnt]=NULL;//обриваємо останн?й звязок
    cnt--;
    if(cnt==0){start=NULL;return;}//якщо елмент?в немає, стає налл
    ((int*)start)[POS_CNT]=cnt;//записуємо к?льк?сть
}


void FindFTur(Ui::MainWindow *ui,void **p1)//пошук туру
{


    QString q;
    q=ui->lineEdit_20->text();
    q=q.trimmed();
    for(QChar item:q)
    {if(!item.isNumber()){ui->textBrowser_6->setTextColor(Qt::red);ui->textBrowser_6->setText(QObject::tr("Eror: not number"));ui->textBrowser->clear();
            ui->textBrowser_2->clear();return;};}
    int u=0;bool f;
    FindElListforww(p1,ui->lineEdit_20->text().toInt(), u, f);//пошук туру
    if(f==true){ ui->textBrowser_6->setTextColor(Qt::green) ;ui->textBrowser_6->setText("Found");}//в?дпов?дн? пов?домлення
    else{ ui->textBrowser_6->setTextColor(Qt::red);ui->textBrowser_6->setText("Not Found");ui->textBrowser->clear();
        ui->textBrowser_2->clear();return;}
    ui->textBrowser->setText((( what_where*)p1[u])->venue);
    ui->textBrowser_2->setText(QString::number((( what_where*)p1[u])->time));
}


void FindFPlayer(Ui::MainWindow *ui,void **p1,void **p3)//пошук гравця(для користувача)
{
    int u=0,u1=0,u2=0;bool f=false;//допом?жн? зм?нн?
    FindElListforww(p1, ui->lineEdit_24->text().toInt(), u, f);//пошук
    if(f==false){ui->textBrowser_11->setTextColor(Qt::red);ui->textBrowser_11->setText("Not Found");ui->textBrowser_10->clear();
        ui->textBrowser_8->clear();return;}//виыд, або продовження
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_25->text(), u1, f);//пошук
    if(f==false){ui->textBrowser_11->setTextColor(Qt::red); ui->textBrowser_11->setText("Not Found");ui->textBrowser_8->clear();
        ui->textBrowser_10->clear();return;}//вихыд, або продовження
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;
    FindElList2(p3,ui->lineEdit_34->text() ,u2, f);
    if(f==true){ui->textBrowser_11->setTextColor(Qt::green);ui->textBrowser_11->setText("Found");}//выдповыдны повыдомлення
    else{ui->textBrowser_11->setTextColor(Qt::red); ui->textBrowser_11->setText("Not Found");ui->textBrowser_8->clear();
        ui->textBrowser_10->clear();return;}
    ui->textBrowser_8->setText(QString::number(((((participants*)((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants[u2])->age))));
    QString h;
    if((((((participants*)((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants[u2])->status)))){h="Osn";}
    else{h="Zap";}
    ui->textBrowser_10->setText(h);
}


void FindFCom(Ui::MainWindow *ui,void **p1)//пошук команди(для користувача)
{
    int u=0,u1=0;bool f=false;//допом?жн? зм?нн?
    FindElListforww(p1, ui->lineEdit_23->text().toInt(), u, f);//пошук туру
    if(f==false){ui->textBrowser_12->setTextColor(Qt::red);ui->textBrowser_12->setText("Not Found");ui->textBrowser_3->clear();
        ui->textBrowser_4->clear();ui->textBrowser_5->clear();return;}//якщо не знайдено - вих?д
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_33->text(), u1, f);//пошук команди
    if(f==true){ui->textBrowser_12->setTextColor(Qt::green); ui->textBrowser_12->setText("Found");}//знайдено - в?дпов?дне пов?домлення
    else{ ui->textBrowser_12->setTextColor(Qt::red);ui->textBrowser_12->setText("Not Found");ui->textBrowser_3->clear();
        ui->textBrowser_4->clear();ui->textBrowser_5->clear();return;}//не знайдено - вив?д пов?домлення
    ui->textBrowser_5->setText(((commands*)(((what_where*)p1[u])->comandArray[u1]))->city);
    ui->textBrowser_4->setText(QString::number(((commands*)(((what_where*)p1[u])->comandArray[u1]))->prize_place));
    ui->textBrowser_3->setText(((commands*)(((what_where*)p1[u])->comandArray[u1]))->captain);
}

void redTur(Ui::MainWindow *ui,void **p1,void **p2,championships *&p)//редактування туру
{
     QString q5;
     q5=ui->lineEdit_35->text();
    for(QChar item:q5)
    {if(!item.isNumber()){ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setText("Error: tour");return;};}
    int u=0;bool f;//допом?жн? зм?нн?
    FindElListforww(p1,ui->lineEdit_35->text().toInt(), u, f);//знаходження туру
    if(f==false){ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setText("Error: tour");return;}//якщо не знайдено- вих?д
    p2=(( what_where*)p1[u])->comandArray;//вказ?вник на п?др?вень
     QString q1,q2;
     q2=ui->lineEdit_13->text();
    q1=ui->lineEdit_14->text();
    q1=q1.trimmed();
    for(QChar item:q1)
    {if(!item.isNumber()){ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setTextColor("Error: new tour");return;};}
    int a=(ui->lineEdit_14->text().toInt());
    QString q=(ui->lineEdit_10->text());
    float a2;

    for(int i=0;q2[i]!='\0';i++)
    {if(!q2[i].isNumber() && q2[i]!=QChar('.')){{ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setText("Error: time");return;}}}
    a2=ui->lineEdit_13->text().toFloat();

    (ui->lineEdit_13->text().toFloat());
    delltur(p1, u,1);
    creatWW(ui,p1,p,p2,a, q,a2);//створюємо елемент з? старим п?др?внем, але новими даними
    ui->textBrowser_17->setTextColor(Qt::green);ui->textBrowser_17->setText("Ok");
}

void redCom(Ui::MainWindow *ui,void **p1,void**p3)//редагування команди
{
    QString q5;
    q5=ui->lineEdit_36->text();
   for(QChar item:q5)
   {if(!item.isNumber()){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: tour");return;};}

    int u=0,u1;bool f=false;//допом?жн? зм?нн?
    FindElListforww(p1, ui->lineEdit_36->text().toInt(), u, f);//пошук туру, в якому треба редагувати команду
    if(f==false){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: tour");return;};//якщо не знайдено - вих?д
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_37->text(), u1, f);//пошук команди
    if(f==false){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: command");return;};//незнайдено - вих?д
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;//вказ?вник на п?др?вень
    dellCom((( what_where*)p1[u])->comandArray, u1,1);//видалення, без п?др?вня
    QString q1=ui->lineEdit_41->text();
    int a= ui->lineEdit_43->text().toInt();
    QString q2= ui->lineEdit_44->text();
    QString q3= ui->lineEdit_45->text();
   creatCom(p1,p3,q1,a,q2,q3,ui->lineEdit_36->text().toInt());
   ui->textBrowser_18->setTextColor(Qt::green);ui->textBrowser_18->setText("Ok");
}


void redPlayer(Ui::MainWindow *ui,void **p1,void**p3)//редагування гравця
{  
    QString q5;
    q5=ui->lineEdit_38->text();
   for(QChar item:q5)
   {if(!item.isNumber()){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: tour ");return;};}
    int u=0,u1,u2=0;bool f=false;//допом?жн? зм?нн?
    FindElListforww(p1, ui->lineEdit_38->text().toInt(), u, f);//пошук
    if(f==false){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: new tour ");return;}//перев?рка наявност?
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_39->text(), u1, f);//пошук
    if(f==false){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error:command ");return;}//перев?рка
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;//вказ?вник на п?др?вень
    FindElList2(p3,ui->lineEdit_40->text() ,u2, f);//пошук
    if(f==false){{ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: player");return;};return;}
    dellPlayer(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants, u2);//видалення
    QString q=ui->lineEdit_29->text();
    int a=ui->lineEdit_30->text().toUInt();
    bool j;
    if(ui->radioButton_3->isChecked()){j=true;}
    else j=false;
    creatpLAYER(p1,q,a,ui->lineEdit_38->text().toInt(),ui->lineEdit_39->text(),j);
    ui->textBrowser_19->setTextColor(Qt::green);ui->textBrowser_19->setText("Ok");
}

struct   agestr//структура для знаходження тур?в команд
{
    QString  name;//назва команди
    QString vik;//тури в яких брала участь команда
};


void age(void** p1,void ** p2,void **p3,Ui::MainWindow *ui)//пошук середньго в?ку
{
    agestr *ag =new  agestr;
    int u,a=0;bool f;
    FindElListforww(p1,ui->lineEdit_46->text().toInt(), u, f);//пошук туру в якому треба знайти середн?й в?к
    if(f==false){ui->lineEdit_46->setText("touro not faund");return;}
    p2=((what_where*)p1[u])->comandArray;
    if(p2==NULL){ui->textBrowser_26->setText("No conand");return;}//перев?ряємо наявн?сть команд
    int cnt=((int*)p2)[POS_CNT];//читаємо к?льк?сть команд
    QString q;
    for(int i=0;i<cnt;i++)//цикл проходу по кожн?й з команд
    {
        a=0;//оновлюємо зм?нну
        ag->name=((commands*)p2[i])->name;//записуємо назву команди
        p3=((commands*)p2[i])->firstparticipants;
        if(p3==NULL){ag->vik="comad emty"; q=q+((commands*)p2[i])->name+" com - "+(ag->vik)+"; ";q=q+"\n";continue;}//перев?ряємо чи не пуста команда
        int cnt1=((int *)p3)[POS_CNT];
        for(int j=0;j<cnt1;j++)
        {//знаходимо сумарний в?к
            a=a+((participants*)p3[j])->age;
        }
        a=a/(cnt1);//знаходимо середн?й в?к
        ag->vik=QString::number(a);
        q=q+((commands*)p2[i])->name+" com - "+(ag->vik)+"; ";q=q+"\n";//записуємо
    }
    ui->textBrowser_26->setText(q);//(виводимо тимчасово)
}


void Findpr(void** start,Ui::MainWindow *ui)//пошук призових м?сць
{
    if(start==NULL){ui->textBrowser_27->setText("touro not faund"); return;}//якщо немає тур?в зак?нчуємо функц?ю
    int cnt=((int*)start)[POS_CNT];//читаємо к?льк?сть тур?в
    QString q;//для запису результату
    for(int i=0;i<cnt;i++)//основний цикл заходу до кожного туру
    {
        q=q+QString::number(((what_where*)(start[i]))->num)+"tour:";//записуємо номер тура
        if(((what_where*)start[i])->comandArray!=NULL)//якщо масив команд не пустий
        {
            bool l=false;
            int cnt1=((int*)((what_where*)start[i])->comandArray)[POS_CNT];//читаэмо уылькысть команд
            QString z,z1,z2;
            for(int j=0;j<cnt1;j++)// цикл проходу по кожный команд?
            {
                int x=((commands*)(((what_where*)start[i])->comandArray[j]))->prize_place;//читаємо
                //призове м?сце
                if(x==1){z=z+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//пор?внюємо його
                else if(x==2){z1=z1+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//пор?внюємо його
                else if(x==3){z2=z2+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//пор?внюємо його
            }
            if(z.isEmpty()){z="none";}
            if(z1.isEmpty()){z1="none";}
            if(z2.isEmpty()){z2="none";}
            if(l==0){q=q+"None Prize";q=q+"\n";}//якщо не було знайдено призових м?сць
            else  q=q+" 1-"+z+" 2-"+z1+" 3-"+z2;
            q=q+"\n";

        }
        else {q=q+" None Kommand ";q=q+"\n";}//якщо тур порожн?й
    }
    ui->textBrowser_27->setText(q);//виводимо (тимчасово)
}




struct   turforComand//структура для знаходження тур?в команд
{
    QString  name;//назва команди
    QString teru;//тури в яких брала участь команда
};

void turforCom(void** p1,void **p2,Ui::MainWindow *ui)//знахождення туру для команди
{
    turforComand *tf=new  turforComand;
    tf->name=ui->lineEdit_48->text();
    bool f=false;
    if(p1==NULL){ui->textBrowser_30->setText("Error: tour");return;}
    int cnt=((int*)p1)[POS_CNT];//читаємо к?льк?сть тур?в
    for(int i=0;i<cnt;i++)//проходимо по кожному туру
    {
        p2=((what_where*)p1[i])->comandArray;
        if(p2==NULL){continue;}//якщо команди пуст?, пропуск циклу
        int cnt1=((int *)p2)[POS_CNT];//читаємо к?льк?сть команд
        for(int j=0;j<cnt1;j++)//проходимо по кожн?й команд?
        {
            if(tf->name==((commands*)p2[j])->name)
            {//якщо знаходимо потр?бну команду
                tf->teru=tf->teru+" "+(QString::number(((what_where*)p1[i])->num)+";");//записуємо
                f=true;
            }} }
    if(f==false){tf->teru="Command not Play";}//якщо в команд? немає гравц?в
   ui->textBrowser_30->setText(tf->teru);//виводимо тимчасово результат
    delete  tf;
 }
