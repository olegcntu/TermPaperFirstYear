

#include "functions.h"


void ** InitArray()//?�?�?��?���?�
{
    void ** p=new void* [SIZE_AR_FIRST+2];//�⢮७�� �����?筮�� ��ᨢ� �������� ஧�?��
    p=p+2;
    ((int*)p)[POS_CNT]  = 0;//�?��?��� �������?�
    ((int*)p)[POS_SZ]  = SIZE_AR_FIRST;//஧�?� ��ᨢ�
    return p;//������� ��ᨢ
}

void ExpendArrPtr (void** &ar)//�㭪�?� ஧�७�� ����� ���⨯���� ����뢭��?�
{

      int Cnt=((int *)ar) [POS_CNT];
      int	   SizeW =((int *)ar) [POS_SZ];   /*���०���� ��ண� ஧�?�� ��ᨢ�*/
      ((int *)ar) [POS_SZ] = ((int *)ar) [POS_SZ] + DELTA;   /*�����祭�� ������ ஧�?�� ��ᨢ�*/
      void**   arW;              //����?���� ���⨯���� �����稪 ��
       int SizeAr= ((int *)ar) [POS_SZ] ;                       //���⮪ ��ᨢ� �����稪?�
      arW = new void*[((int *)ar) [POS_SZ]+2]; /*����?����� �?��� ��� ������ ��ᨢ�*/
      /*���?��� ��ண� ��ᨢ� ����?����?� � ����� ��ᨢ*/
      for (int i=0; i<SizeW; i++)
        { arW[i+2] = ar[i]; }
      ar=ar-2;      // �⠢��� ����?���� �� ���⮪ ��ண� ��ᨢ�
      delete []ar;  //��?���� ���'���
      ar=arW+2;  //�⠢��� ����?���� ��ᨢ� �� ���訩 ����?���� � ������ ��ᨢ?
      ((int*)ar)[POS_CNT]  = Cnt;    /* �������� �㦡��? ������� */
        ((int*)ar)[POS_SZ]  = SizeAr;
}
void addToSort(void** &start,  void* pnew, int posAdd)// ��������� �� �?���⮢����� ���⨯����� �����
{
    int cnt=((int*)start)[POS_CNT];//��� �㦡��? �������
    int sz= ((int*)start)[POS_SZ];
    if (cnt == sz)//�� �㦡���� ������� ������ �� ��९������� ��ᨢ�, ஧����
    {
        ExpendArrPtr (start);
    }
    if (posAdd == cnt) //������� ��������� � �?���� ᯨ��
    {
        start[posAdd] = pnew;
    }
    else
    {     // ��� �������?� ��ᨢ� ��ࠢ�
        for (int k = cnt-1; k >= posAdd; k--)//���� �� �㤥 �������� ����?��� �?��
        { start[k+1] = start[k]; }//��१������ �� ���� ���?�� �����
        start[posAdd] = pnew;//�?�� ��室� � 横�� ������� ������� � ����?��� ���?��
    }
    cnt++;//��?����� ஧�?�
    ((int*)start)[POS_CNT]=cnt;//�������
}

void FindElListforww(void** start,  int key, int &posFndEl, bool &findOK)//���� ���������, ��ॢ?ઠ, � ��������
{//���� �?��� ��� ��⠢��
    if(start==NULL){posFndEl=0;findOK=false;return;}//�� �?���� ���⨩, � ������� false
    // �� �����ᥭ�� � ��室��� � �㭪�?�
    int	middl;    // ?����� �।�쮣� ������� ��ᨢ�
    int	hi, low;  // ����? ���? - �����, �����
    findOK = false;  // ������� �� ��������
    if (((int*)start)[POS_CNT] == 0)//�� ᯨ᮪ ���⨩
    {
        posFndEl = 0;
        return;
    }
    // ��⠭����� ���? ����� �� ���? ��ᨢ�
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //?����� �।�쮣� ��������
        if (key==((what_where*)(start[middl]))->num) //������� ��������
        {
            posFndEl = middl;
            findOK = true;//�� ������� �������� �������� �㭪�?�
            return;
        }
        if (key<((what_where*)(start[middl]))->num) /*��?�� ��� �����*/
        { hi = middl - 1; }
        else
        { low = middl + 1; }
    } while  (low <= hi);
    posFndEl = low;//��ॡ࠭� ���� ��ᨢ. ������� �� ��������.
     //�����祭� �����?� �������� ��⠢�� ������ �������
}
void FindElListforcom(void** start,  QString key, int &posFndEl, bool &findOK)
{//������?筠 �� ����।���,��� ��� �।�죮 �?���
    if(start==NULL) {posFndEl=0;findOK=false;return;}//�� �?���� ���⨩, � ������� false
    // �� �����ᥭ�� � ��室��� � �㭪�?�
    int	middl;    // ?����� �।�쮣� ������� ��ᨢ�
    int	hi, low;  // ����? ���? - �����, �����
    findOK = false;  // ������� �� ��������
    if (((int*)start)[POS_CNT] == 0)
    {      /* �� ᯨ᮪ ���⨩ */
        posFndEl = 0;
        return;
    }
    // ��⠭����� ���? ����� �� ���? ��ᨢ�
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //����� �।�쮣� ��������
        if (key==((commands*)(start[middl]))->name) //������� ��������
        {
            posFndEl = middl;
            findOK = true;
            return;
        }
        if (key<((commands*)(start[middl]))->name) /*��?�� ��� �����*/
        { hi = middl - 1; }
        else { low = middl + 1; }
    } while  (low <= hi);
    posFndEl = low;    //��ॡ࠭� ���� ��ᨢ. ������� �� ��������.
                    //�����祭� �����?� �������� ��⠢�� ������ �������
}

void FindElList2(void** start,  QString key, int &posFndEl, bool &findOK)
{//������?筠 �� ����।���,��� ��� ������箣� �?��� �?���
    if(start==NULL){posFndEl=0;findOK=false;return;}
    int	middl;    // ?����� �।�쮣� ������� ��ᨢ�*/
    int	hi, low;  // ����? ���? - �����, �����*/
    findOK = false;  /* ������� �� ��������*/
    if (((int*)start)[POS_CNT] == 0)
    {      // �� ᯨ᮪ ���⨩
        posFndEl = 0;
        return;
    }
    // ��⠭����� ���? ����� �� ���? ��ᨢ�*/
    low = 0;
    hi = ((int*)start)[POS_CNT] - 1;
    do
    {  middl = (hi + low) / 2 ; //?����� �।�쮣� ��������
        if (key==((participants*)(start[middl]))->name) //������� ��������*/
        {
            posFndEl = middl;
            findOK = true;
            return;
        }
        if (key<((participants*)(start[middl]))->name) //��?�� ��� �����
        { hi = middl - 1; }
        else{ low = middl + 1; }
    } while  (low <= hi);//��ॡ࠭� ���� ��ᨢ. ������� �� ��������.
    posFndEl = low;      //  �����祭� �����?� �������� ��⠢�� ������ �������
                }

void creatWW(Ui::MainWindow *ui,void **&p1,championships* &p,void **p2,int a,QString q,float a2)// �⢮७�� �?��� "�/��/����"
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
    com->firstparticipants=p3;//��᢫�� ���祭�� �?��?���
    FindElListforcom((( what_where*)p1[u])->comandArray, com->name, u1, f);
    addToSort((( what_where*)p1[u])->comandArray,com,u1);



}

void creatpLAYER(void **&p1,QString q,int a,int l,QString l1,bool& j)
{
    int u=0,u1=0,u2=0;bool f;//�����?��? ��?��?
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






void delltur(void** &start,  int posAdd,int y)//��������� ����
{
    int cnt=((int*)start)[POS_CNT];//��� �?��?���
    if(((what_where*)start[posAdd])->comandArray!=NULL && y==0 )//�� �?��?���� �� ��஦�?� � ��।���
    {//?�⮢� ���祭�� �� 0 (��?�쪨 ?���? �� ����?��� ������� �?��?����, �� ।��㢠��?*)
        //�� �⢮७�� ��६����, int y � 直� ��।������ 0 ���� �ॡ� ������� �?��?����, ��� ?�� ���祭��, �� �� �ॡ�
        while(((what_where*)start[posAdd])->comandArray!=NULL)// ���� �?��?���� �� �⠭� ��஦�?�
        {
            int  posAdd1=((int*)(((what_where*)start[posAdd])->comandArray))[-2]-1;//��� �?��?���
            dellCom((( what_where*)start[posAdd])->comandArray, posAdd1,0);//������� ��⠭�?� ������� � �?��?���
            //���� �?� �� �㤥 ��஦�?�
        }
    }
    delete ((what_where*)start[posAdd]);//������� �������
    for (int k = posAdd; k <= cnt; k++)//��?��� �������
    { start[k] = start[k+1];}
    start[cnt]=NULL;//��⠭�?� - ���
    cnt--;
    ((int*)start)[POS_CNT]=cnt;//������� �?��?���
}
void dellCom(void** &start,  int posAdd,int y)//��������� �������
{//������?筠 �� ����।���, ��� ��� ?�讣� �?��� � ⠪�� �� ��ਬ���祬
    int cnt=((int*)start)[POS_CNT];//��� �?��?���
    if(((commands*)start[posAdd])->firstparticipants!=NULL && y==0)// �������� � � ������� ���箣� �?���
    {
        while(((commands*)start[posAdd])->firstparticipants!=NULL)//������� ���� �?��?���� �� �⠭� ���
        {
            int  posAdd1=((int*)(((commands*)start[posAdd])->firstparticipants))[-2]-1;//��� �?��?��� ������?� �?��?���
            dellPlayer((( commands*)start[posAdd])->firstparticipants, posAdd1);//������� ��稭��� � ��⠭�쮣�
        }
    }
    delete ((commands*)start[posAdd]);//������� �������
    for (int k = posAdd; k <= cnt; k++)//��?��� ���������
    { start[k] = start[k+1];}
    start[cnt]=NULL;// ��⠭�?� ����
    cnt--;
    if(cnt==0){start=NULL;return ;}//�� ��ᨢ ��஦�?�, � �?� - ���
    ((int*)start)[POS_CNT]=cnt;//������� �?��?���
}

void dellPlayer(void** &start,  int posAdd)//��������� � ������箣� �?���
{
   int cnt=((int*)start)[POS_CNT];//��� �?��?��� �������?�
    delete ((participants*)start[posAdd]);//������� ����� ������
    for (int k = posAdd; k <= cnt; k++)//��?��� �������
    { start[k] = start[k+1];}//��?���
    start[cnt]=NULL;//��ਢ�� ��⠭�?� ��燐�
    cnt--;
    if(cnt==0){start=NULL;return;}//�� ������?� �����, ��� ����
    ((int*)start)[POS_CNT]=cnt;//������� �?��?���
}


void FindFTur(Ui::MainWindow *ui,void **p1)//���� ����
{


    QString q;
    q=ui->lineEdit_20->text();
    q=q.trimmed();
    for(QChar item:q)
    {if(!item.isNumber()){ui->textBrowser_6->setTextColor(Qt::red);ui->textBrowser_6->setText(QObject::tr("Eror: not number"));ui->textBrowser->clear();
            ui->textBrowser_2->clear();return;};}
    int u=0;bool f;
    FindElListforww(p1,ui->lineEdit_20->text().toInt(), u, f);//���� ����
    if(f==true){ ui->textBrowser_6->setTextColor(Qt::green) ;ui->textBrowser_6->setText("Found");}//�?����?��? ���?��������
    else{ ui->textBrowser_6->setTextColor(Qt::red);ui->textBrowser_6->setText("Not Found");ui->textBrowser->clear();
        ui->textBrowser_2->clear();return;}
    ui->textBrowser->setText((( what_where*)p1[u])->venue);
    ui->textBrowser_2->setText(QString::number((( what_where*)p1[u])->time));
}


void FindFPlayer(Ui::MainWindow *ui,void **p1,void **p3)//���� �ࠢ��(��� �����㢠�)
{
    int u=0,u1=0,u2=0;bool f=false;//�����?��? ��?��?
    FindElListforww(p1, ui->lineEdit_24->text().toInt(), u, f);//����
    if(f==false){ui->textBrowser_11->setTextColor(Qt::red);ui->textBrowser_11->setText("Not Found");ui->textBrowser_10->clear();
        ui->textBrowser_8->clear();return;}//���, ��� �த�������
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_25->text(), u1, f);//����
    if(f==false){ui->textBrowser_11->setTextColor(Qt::red); ui->textBrowser_11->setText("Not Found");ui->textBrowser_8->clear();
        ui->textBrowser_10->clear();return;}//����, ��� �த�������
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;
    FindElList2(p3,ui->lineEdit_34->text() ,u2, f);
    if(f==true){ui->textBrowser_11->setTextColor(Qt::green);ui->textBrowser_11->setText("Found");}//�뤯��뤭� ���뤮������
    else{ui->textBrowser_11->setTextColor(Qt::red); ui->textBrowser_11->setText("Not Found");ui->textBrowser_8->clear();
        ui->textBrowser_10->clear();return;}
    ui->textBrowser_8->setText(QString::number(((((participants*)((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants[u2])->age))));
    QString h;
    if((((((participants*)((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants[u2])->status)))){h="Osn";}
    else{h="Zap";}
    ui->textBrowser_10->setText(h);
}


void FindFCom(Ui::MainWindow *ui,void **p1)//���� �������(��� �����㢠�)
{
    int u=0,u1=0;bool f=false;//�����?��? ��?��?
    FindElListforww(p1, ui->lineEdit_23->text().toInt(), u, f);//���� ����
    if(f==false){ui->textBrowser_12->setTextColor(Qt::red);ui->textBrowser_12->setText("Not Found");ui->textBrowser_3->clear();
        ui->textBrowser_4->clear();ui->textBrowser_5->clear();return;}//�� �� �������� - ���?�
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_33->text(), u1, f);//���� �������
    if(f==true){ui->textBrowser_12->setTextColor(Qt::green); ui->textBrowser_12->setText("Found");}//�������� - �?����?��� ���?��������
    else{ ui->textBrowser_12->setTextColor(Qt::red);ui->textBrowser_12->setText("Not Found");ui->textBrowser_3->clear();
        ui->textBrowser_4->clear();ui->textBrowser_5->clear();return;}//�� �������� - ���?� ���?��������
    ui->textBrowser_5->setText(((commands*)(((what_where*)p1[u])->comandArray[u1]))->city);
    ui->textBrowser_4->setText(QString::number(((commands*)(((what_where*)p1[u])->comandArray[u1]))->prize_place));
    ui->textBrowser_3->setText(((commands*)(((what_where*)p1[u])->comandArray[u1]))->captain);
}

void redTur(Ui::MainWindow *ui,void **p1,void **p2,championships *&p)//।���㢠��� ����
{
     QString q5;
     q5=ui->lineEdit_35->text();
    for(QChar item:q5)
    {if(!item.isNumber()){ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setText("Error: tour");return;};}
    int u=0;bool f;//�����?��? ��?��?
    FindElListforww(p1,ui->lineEdit_35->text().toInt(), u, f);//���室����� ����
    if(f==false){ui->textBrowser_17->setTextColor(Qt::red);ui->textBrowser_17->setText("Error: tour");return;}//�� �� ��������- ���?�
    p2=(( what_where*)p1[u])->comandArray;//����?���� �� �?��?����
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
    creatWW(ui,p1,p,p2,a, q,a2);//�⢮��� ������� �? ��ਬ �?��?����, ��� ������ ������
    ui->textBrowser_17->setTextColor(Qt::green);ui->textBrowser_17->setText("Ok");
}

void redCom(Ui::MainWindow *ui,void **p1,void**p3)//।��㢠��� �������
{
    QString q5;
    q5=ui->lineEdit_36->text();
   for(QChar item:q5)
   {if(!item.isNumber()){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: tour");return;};}

    int u=0,u1;bool f=false;//�����?��? ��?��?
    FindElListforww(p1, ui->lineEdit_36->text().toInt(), u, f);//���� ����, � 类�� �ॡ� ।��㢠� �������
    if(f==false){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: tour");return;};//�� �� �������� - ���?�
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_37->text(), u1, f);//���� �������
    if(f==false){ui->textBrowser_18->setTextColor(Qt::red);ui->textBrowser_18->setText("Error: command");return;};//���������� - ���?�
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;//����?���� �� �?��?����
    dellCom((( what_where*)p1[u])->comandArray, u1,1);//���������, ��� �?��?���
    QString q1=ui->lineEdit_41->text();
    int a= ui->lineEdit_43->text().toInt();
    QString q2= ui->lineEdit_44->text();
    QString q3= ui->lineEdit_45->text();
   creatCom(p1,p3,q1,a,q2,q3,ui->lineEdit_36->text().toInt());
   ui->textBrowser_18->setTextColor(Qt::green);ui->textBrowser_18->setText("Ok");
}


void redPlayer(Ui::MainWindow *ui,void **p1,void**p3)//।��㢠��� �ࠢ��
{  
    QString q5;
    q5=ui->lineEdit_38->text();
   for(QChar item:q5)
   {if(!item.isNumber()){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: tour ");return;};}
    int u=0,u1,u2=0;bool f=false;//�����?��? ��?��?
    FindElListforww(p1, ui->lineEdit_38->text().toInt(), u, f);//����
    if(f==false){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: new tour ");return;}//��ॢ?ઠ �����?
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_39->text(), u1, f);//����
    if(f==false){ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error:command ");return;}//��ॢ?ઠ
    p3=((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants;//����?���� �� �?��?����
    FindElList2(p3,ui->lineEdit_40->text() ,u2, f);//����
    if(f==false){{ui->textBrowser_19->setTextColor(Qt::red);ui->textBrowser_19->setText("Error: player");return;};return;}
    dellPlayer(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants, u2);//���������
    QString q=ui->lineEdit_29->text();
    int a=ui->lineEdit_30->text().toUInt();
    bool j;
    if(ui->radioButton_3->isChecked()){j=true;}
    else j=false;
    creatpLAYER(p1,q,a,ui->lineEdit_38->text().toInt(),ui->lineEdit_39->text(),j);
    ui->textBrowser_19->setTextColor(Qt::green);ui->textBrowser_19->setText("Ok");
}

struct   agestr//������� ��� ���室����� ���?� ������
{
    QString  name;//����� �������
    QString vik;//��� � 直� �ࠫ� ����� �������
};


void age(void** p1,void ** p2,void **p3,Ui::MainWindow *ui)//���� �।�죮 �?��
{
    agestr *ag =new  agestr;
    int u,a=0;bool f;
    FindElListforww(p1,ui->lineEdit_46->text().toInt(), u, f);//���� ���� � 类�� �ॡ� ����� �।�?� �?�
    if(f==false){ui->lineEdit_46->setText("touro not faund");return;}
    p2=((what_where*)p1[u])->comandArray;
    if(p2==NULL){ui->textBrowser_26->setText("No conand");return;}//��ॢ?��� ��?��� ������
    int cnt=((int*)p2)[POS_CNT];//��� �?��?��� ������
    QString q;
    for(int i=0;i<cnt;i++)//横� ��室� �� ����?� � ������
    {
        a=0;//������� ��?���
        ag->name=((commands*)p2[i])->name;//������� ����� �������
        p3=((commands*)p2[i])->firstparticipants;
        if(p3==NULL){ag->vik="comad emty"; q=q+((commands*)p2[i])->name+" com - "+(ag->vik)+"; ";q=q+"\n";continue;}//��ॢ?��� � �� ���� �������
        int cnt1=((int *)p3)[POS_CNT];
        for(int j=0;j<cnt1;j++)
        {//���室��� �㬠୨� �?�
            a=a+((participants*)p3[j])->age;
        }
        a=a/(cnt1);//���室��� �।�?� �?�
        ag->vik=QString::number(a);
        q=q+((commands*)p2[i])->name+" com - "+(ag->vik)+"; ";q=q+"\n";//�������
    }
    ui->textBrowser_26->setText(q);//(�������� ⨬�ᮢ�)
}


void Findpr(void** start,Ui::MainWindow *ui)//���� �ਧ���� �?���
{
    if(start==NULL){ui->textBrowser_27->setText("touro not faund"); return;}//�� ����� ���?� ���?���� �㭪�?�
    int cnt=((int*)start)[POS_CNT];//��� �?��?��� ���?�
    QString q;//��� ������ १�����
    for(int i=0;i<cnt;i++)//�᭮���� 横� ��室� �� ������� ����
    {
        q=q+QString::number(((what_where*)(start[i]))->num)+"tour:";//������� ����� ���
        if(((what_where*)start[i])->comandArray!=NULL)//�� ��ᨢ ������ �� ���⨩
        {
            bool l=false;
            int cnt1=((int*)((what_where*)start[i])->comandArray)[POS_CNT];//��� ������� ������
            QString z,z1,z2;
            for(int j=0;j<cnt1;j++)// 横� ��室� �� ����� ������?
            {
                int x=((commands*)(((what_where*)start[i])->comandArray[j]))->prize_place;//���
                //�ਧ��� �?��
                if(x==1){z=z+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//���?���� ����
                else if(x==2){z1=z1+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//���?���� ����
                else if(x==3){z2=z2+((commands*)(((what_where*)start[i])->comandArray[j]))->name+" ";l=1;}//���?���� ����
            }
            if(z.isEmpty()){z="none";}
            if(z1.isEmpty()){z1="none";}
            if(z2.isEmpty()){z2="none";}
            if(l==0){q=q+"None Prize";q=q+"\n";}//�� �� �㫮 �������� �ਧ���� �?���
            else  q=q+" 1-"+z+" 2-"+z1+" 3-"+z2;
            q=q+"\n";

        }
        else {q=q+" None Kommand ";q=q+"\n";}//�� ��� ��஦�?�
    }
    ui->textBrowser_27->setText(q);//�������� (⨬�ᮢ�)
}




struct   turforComand//������� ��� ���室����� ���?� ������
{
    QString  name;//����� �������
    QString teru;//��� � 直� �ࠫ� ����� �������
};

void turforCom(void** p1,void **p2,Ui::MainWindow *ui)//���宦����� ���� ��� �������
{
    turforComand *tf=new  turforComand;
    tf->name=ui->lineEdit_48->text();
    bool f=false;
    if(p1==NULL){ui->textBrowser_30->setText("Error: tour");return;}
    int cnt=((int*)p1)[POS_CNT];//��� �?��?��� ���?�
    for(int i=0;i<cnt;i++)//��室��� �� ������� ����
    {
        p2=((what_where*)p1[i])->comandArray;
        if(p2==NULL){continue;}//�� ������� ����?, �ய�� 横��
        int cnt1=((int *)p2)[POS_CNT];//��� �?��?��� ������
        for(int j=0;j<cnt1;j++)//��室��� �� ����?� ������?
        {
            if(tf->name==((commands*)p2[j])->name)
            {//�� ���室��� ����?��� �������
                tf->teru=tf->teru+" "+(QString::number(((what_where*)p1[i])->num)+";");//�������
                f=true;
            }} }
    if(f==false){tf->teru="Command not Play";}//�� � ������? ����� �ࠢ�?�
   ui->textBrowser_30->setText(tf->teru);//�������� ⨬�ᮢ� १����
    delete  tf;
 }
