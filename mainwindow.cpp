#include"functions.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/chess.jpg");
    QPixmap pix1(":/img/img/chess2.jpg");
    QPixmap pix2(":/new1/img/chess3.jpg");
    QPixmap pix3(":/new1/img/chess4.jpg");
    QPixmap pix4(":/img/chess5.jpg");
    QPixmap pix5(":/img/chess6.jpg");
    QPixmap pix6(":/img/chess7.jpg");
    QPixmap pix7(":/img/chess8.jpg");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h));
    ui->label_3->setPixmap(pix1.scaled(w,h));
    ui->label_9->setPixmap(pix2.scaled(w,h));
    ui->label_16->setPixmap(pix2.scaled(w,h));
    ui->label_23->setPixmap(pix3.scaled(w,h));
    ui->label_28->setPixmap(pix4.scaled(w,h));
    ui->label_36->setPixmap(pix5.scaled(w,h));
    ui->label_58->setPixmap(pix6.scaled(w,h));
    ui->label_49->setPixmap(pix6.scaled(w,h));
    ui->label_68->setPixmap(pix7.scaled(w,h));
    ui->label_70->setPixmap(pix.scaled(w,h));
    ui->label_71->setPixmap(pix.scaled(w,h));
    ui->label_66->setPixmap(pix.scaled(w,h));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pushButton_2_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_pushButton_5_clicked(){ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_pushButton_6_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_pushButton_7_clicked(){exit(1);}
void MainWindow::on_pushButton_9_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_12_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_17_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_27_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_26_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_23_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_22_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_34_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_30_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_35_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_36_clicked(){ ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_25_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_32_clicked(){turforCom(p1,p2,ui);}
void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_4->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_8->clear();
    ui->textBrowser_10->clear();
     ui->textBrowser_11->clear();
      ui->textBrowser_12->clear();
       ui->textBrowser_6->clear();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_8_clicked()//додaти тур
{
    int a;
    float a2;
    QString q,q1;
    q=ui->lineEdit_3->text();
    q=q.trimmed();
    for(QChar item:q)
    {if(!item.isNumber()){ui->textBrowser_7->setTextColor(Qt::red);ui->textBrowser_7->setText(QObject::tr("Error: not number"));return;};}
    a=q.toInt();
    q=ui->lineEdit->text();
    q1=ui->lineEdit_2->text();
    for(int i=0;q1[i]!='\0';i++)
    {if(!q1[i].isNumber() && q1[i]!=QChar('.')){{ui->textBrowser_7->setTextColor(Qt::red);ui->textBrowser_7->setText("Error: time");return;}}}
    a2=ui->lineEdit_2->text().toFloat();
    creatWW(ui,p1,p,NULL, a, q, a2);
    ui->textBrowser_7->setTextColor(Qt::green);ui->textBrowser_7->setText("Ok!");
}
void MainWindow::on_pushButton_10_clicked()//додати ком нду
{
    if(p1==NULL){ui->textBrowser_9->setTextColor(Qt::red);ui->textBrowser_9->setText("Error: tour");return;}
    QString q3,q1,q2,q4;
    int l,a;
    q4=ui->lineEdit_5->text();
    q4=q4.trimmed();
    for(QChar item:q4)
    {if(!item.isNumber()){ui->textBrowser_9->setTextColor(Qt::red);ui->textBrowser_9->setText("Error: prize place");return;};}
    a=q4.toInt();
    q1=ui->lineEdit_6->text();
    q2=ui->lineEdit_7->text();
    q3=ui->lineEdit_8->text();
    QString g;
    g=ui->comboBox->currentText();
    l=g.toInt();
    creatCom(p1,NULL,q1,a,q2,q3,l);
    ui->textBrowser_9->setTextColor(Qt::green);ui->textBrowser_9->setText("Ok");
}
void MainWindow::on_pushButton_11_clicked()//додати гравця
{
    bool j;
    int l,a;
    QString q,q1,g,g1,l1;
    q=ui->lineEdit_12->text();
    for(QChar item:q)
    {if(!item.isNumber()){;ui->textBrowser_13->setTextColor(Qt::red);ui->textBrowser_13->setText("Error: age"); return;}}
    a=q.toInt();
    q1=ui->lineEdit_9->text();
    g=ui->comboBox_2->currentText();
    l=g.toInt();
    l1=ui->lineEdit_42->text();
    if(ui->radioButton->isChecked()){j=true;}
    else j=false;
    creatpLAYER(p1,q1,a,l,l1,j);
    if(j==true){ ui->textBrowser_13->setTextColor(Qt::green);ui->textBrowser_13->setText("Ok");}
    else{ ui->textBrowser_13->setTextColor(Qt::red);ui->textBrowser_13->setText("Error: command");}
}
void MainWindow::on_pushButton_15_clicked()//Видалити гравця
{
    int u=0,u1=0,u2=0;bool f=false;
    FindElListforww(p1, ui->lineEdit_19->text().toInt(), u, f);
    if(f==false){ ui->textBrowser_15->setTextColor(Qt::red);ui->textBrowser_15->setText("Error: tour");return;}
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_18->text(), u1, f);
    if(f==false){  ui->textBrowser_15->setTextColor(Qt::red);ui->textBrowser_15->setText("Error: command!");return;}
    p3=(((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants);
    FindElList2(p3,ui->lineEdit_17->text() , u2, f);
    if(f==false){ ui->textBrowser_15->setTextColor(Qt::red);ui->textBrowser_15->setText("Error: player");return;}
    dellPlayer( (((commands*)(((what_where*)p1[u])->comandArray[u1]))->firstparticipants),u2 );
    ui->textBrowser_15->setTextColor(Qt::green);ui->textBrowser_15->setText("Ok");
}

void MainWindow::on_pushButton_14_clicked()//Видалити команду
{
    int u=0,u1=0;bool f=false;
    FindElListforww(p1, ui->lineEdit_16->text().toInt(), u, f);
    if(f==false){ ui->textBrowser_14->setTextColor(Qt::red);ui->textBrowser_14->setText("Error: tour");return;}
    FindElListforcom((( what_where*)p1[u])->comandArray, ui->lineEdit_15->text(), u1, f);
    if(f==false){ ui->textBrowser_14->setTextColor(Qt::red);ui->textBrowser_14->setText("Error: сommand");return;}
    dellCom((( what_where*)p1[u])->comandArray,u1,0);
    ui->textBrowser_14->setTextColor(Qt::green);ui->textBrowser_14->setText("Ok");

}
void MainWindow::on_pushButton_13_clicked()//Видалити тур
{
    int u=0;bool f=false;
    FindElListforww(p1, ui->lineEdit_4->text().toInt(), u, f);
    if(f==false){ ui->textBrowser_16->setTextColor(Qt::red);ui->textBrowser_16->setText("Error: tour");return;}
    delltur(p1, u,0);
    if(p1==NULL){return;}
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    for(int i=0;i<((int *)p1)[POS_CNT];i++)
    {
        ui->comboBox->addItem(QString::number((((what_where*)(p1)[i]))->num));
        ui->comboBox_2->addItem(QString::number((((what_where*)(p1)[i]))->num));

    }
    ui->textBrowser_16->setTextColor(Qt::green);ui->textBrowser_16->setText("Ok");
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    Findpr(p1,ui);
    ui->treeWidget->clear();
    QTreeWidgetItem *k=new  QTreeWidgetItem;
    k->setText(0,p->name);
    k->setText(1,p->janr);
    k->setText(2,p->level);
    k->setText(3,QString::number(p->fond));
    ui->treeWidget->addTopLevelItem(k);
    ui->treeWidget->setColumnCount(6);
    if(p1==NULL){return;}
    for(int i=0;i<((int*)p1)[POS_CNT];i++)
    {

        QTreeWidgetItem *itm=new  QTreeWidgetItem;
        itm->setText(0,QString::number((( what_where*)p1[i])->num));
        itm->setText(1,((( what_where*)p1[i])->venue));
        itm->setText(2,QString::number((( what_where*)p1[i])->time));
        ui->treeWidget->addTopLevelItem(itm);
        if((( what_where*)p1[i])->comandArray==NULL){continue;}
        for(int j=0;j<(((int*)((( what_where*)p1[i])->comandArray))[POS_CNT]);j++)
        {
            QTreeWidgetItem *child=new  QTreeWidgetItem;
            child->setText(1,(((commands*)(((what_where*)p1[i])->comandArray[j]))->name));
            child->setText(2,(((commands*)(((what_where*)p1[i])->comandArray[j]))->city));
            child->setText(3,QString::number((((commands*)(((what_where*)p1[i])->comandArray[j]))->prize_place)));
            child->setText(4,(((commands*)(((what_where*)p1[i])->comandArray[j]))->captain));
            itm->addChild(child);


            if((((commands*)(((what_where*)p1[i])->comandArray[j])))->firstparticipants==NULL){continue;}

            for(int p=0;p<(((int*)(((commands*)(((what_where*)p1[i])->comandArray[j])))->firstparticipants)[POS_CNT]);p++)
            {
                QTreeWidgetItem *child2=new  QTreeWidgetItem;
                child2->setText(2,(((participants*)((commands*)(((what_where*)p1[i])->comandArray[j]))->firstparticipants[p])->name));
                child2->setText(3,QString::number((((participants*)((commands*)(((what_where*)p1[i])->comandArray[j]))->firstparticipants[p])->age)));
                QString m;
                if((((participants*)((commands*)(((what_where*)p1[i])->comandArray[j]))->firstparticipants[p])->status)){m="Osn";}else {m="Zap";}
                child2->setText(4,m);
                child->addChild(child2);
            }}}}
void MainWindow::on_pushButton_18_clicked()//Пошук туру
{
    FindFTur(ui,p1);
}
void MainWindow::on_pushButton_19_clicked()//Пошук команди
{
    FindFCom(ui,p1);
}
void MainWindow::on_pushButton_20_clicked()//Пошукагравця
{
    FindFPlayer(ui,p1,p3);
}

void MainWindow::on_pushButton_21_clicked()//редагування туру
{
    redTur(ui,p1,p2,p);
}
void MainWindow::on_pushButton_29_clicked()//редагування команди
{
    redCom(ui,p1,p3);
}
void MainWindow::on_pushButton_24_clicked()//редагування команди
{
    redPlayer(ui,p1,p3);
}
void MainWindow::on_pushButton_28_clicked()//виведення в?ку
{
    age( p1,p2,p3,ui);
}



char *toChar(QString string)//функц?я переведення до масиву char[]
{
    QByteArray ba=string.toUtf8();//до массиву
    char *str=new char[ba.size()+1];//в дин м?чн?й памят?
    memcpy(str, ba.data(), ba.size()+1);//коп?юємо з data в строку
    str[ba.size()]='\0';//ост нн?й символ - к?нець
    return str;//повернення м сиву символ?в
}
void MainWindow::on_pushButton_31_clicked()
{
    FILE *file; //ф йлов  зм?нн
    char name[40];//м сив символ?в для н зви
    strcpy(name,toChar(ui->lineEdit_47->text()));//беремо дорогу до ф йлу т  перетворюємо в м сив символ?в
    file = fopen(name,"wb"); //в?дкрив ємо н  з пис
    if (file==NULL){ui->lineEdit_47->setText("Error");fclose(file);return;}//перев?ряємочи створено ф йл
    Fchampionships SF1;//зм?нн  типу структури для з пису у ф йл
    int SC;//к?льк?сть тур?в
    if(p1!=NULL){SF1.Turcount=((int*)p1)[POS_CNT];} //к?льк?сть тур?в
    else{SF1.Turcount=0;}//якщо нем є, то  з писуємо 0
    SC=SF1.Turcount;
    rewind(file); //переходимо н  поч ток ф йлу
    fwrite(&SF1,sizeof(Fchampionships),1,file); //з писуємо д н?
    if(p1 == NULL){fclose(file);return;}//якщо п?др?вень порожн?й з к?нчуємо функц?ю т  з крив ємо ф йл
    for(int i = 0; i < SC; i++){ //цикл: перегляд елемент?в
        p2 = (( what_where*)p1[i])->comandArray; //переходимо н  п?др?вень ком нд
        int comand;
        if(p2!=NULL)comand = ((int*)p2)[POS_CNT];//з писуємо к?льк?сть ком нд
        else{comand=0;}
        Fwhat_where FTUR; //зм?нн  для з пису у ф йл
        FTUR.Comcount = comand; //коп?юємо ?нформ ц?йн? поля Тур?в
        FTUR.num= (( what_where*)p1[i])->num;
        strcpy(FTUR.venue,toChar((( what_where*)p1[i])->venue));
        FTUR.time=(( what_where*)p1[i])->time;
        fwrite(&FTUR,sizeof(Fwhat_where),1,file); //з писуємо до ф йлу
        if(p2 == NULL) continue; //якщо п?др?вень порожн?й, переходимо до н ступної ?тер ц?ї
        for(int j = 0; j < comand; j++){ //цикл: перегляд елемент?в ком нд
            p3 = ((commands*)p2[j])->firstparticipants; //переходимо н  п?др?вень
            int aPL;//к?льк?сть гр вц?в
            if(p3!=NULL) aPL = ((int*)p3)[POS_CNT];//з писуємо к?льк?сть гр вц?в
            else aPL=0;
            Fcommands FC; //зм?нн  для з пису у ф йл
            strcpy( FC.name,toChar((( commands*)p2[j])->name));//з писуємо д н?
            strcpy( FC.city,toChar((( commands*)p2[j])->city));
            strcpy( FC.captain,toChar((( commands*)p2[j])->captain));
            FC.prize_place=(( commands*)p2[j])->prize_place;
            FC.Player=aPL;
            fwrite(&FC,sizeof(Fcommands),1,file); //з писуємо до ф йлу
            if(p3 == NULL) continue; //якщо п?др?вень порожн?й, переходимо до н ступної ?тер ц?ї
            for(int k = 0; k < aPL; k++){//цикл проходу по вс?х гр вцях
                Fparticipants PLA;//структур  з пису до ф йлу
                strcpy(PLA.name,toChar((( participants*)p3[k])->name));
                PLA.age=(( participants*)p3[k])->age;
                PLA.status=1;
                fwrite(&PLA,sizeof(Fparticipants),1,file); //з писуємо у ф йл
            }}}
    fclose(file); //з крив эмо ф йл
}

void MainWindow::on_pushButton_33_clicked()
{

//    if(p1!=NULL)
//    {
//    int u=0;
//    while(p1!=NULL)
//    {
//        u++;
//     delltur(p1, u,0);
//    }
//    }

   p1=NULL;
   p1 = InitArray();//вид ляємо все, що було з пис но до
    FILE *file;//ф йлов  зм?нн
    char name[40];//шлях до ф йлу
    strcpy(name,toChar(ui->lineEdit_47->text()));
    file = fopen(name,"rb");//в?дкрив ємо для чит ння
    if(file==NULL){{ui->lineEdit_47->setText("Error");fclose(file);return;};}//якщо не ?снує
    //з к?нчуємо функц?ю т  поверт ємо помилку
    Fchampionships SF1;//ф йлов  структур
    rewind(file);//переходимо н  поч ток ф йлу
    fread(&SF1,sizeof(Fchampionships),1,file);//читаємо в структуру
    p->what_whereArray = p1;
    for(int i = 0; i < SF1.Turcount; i++){//цикл отрим ння туру
        Fwhat_where FW;//переписуємо з ф йлу т  дод ємо в дин м?чну п мять
        fread(&FW,sizeof(Fwhat_where),1,file);
        what_where *WW = new what_where;//дин м?чн  структур
        WW->num=FW.num ;
        WW->time=FW.time;
        WW->venue=FW.venue;
        if(FW.Comcount!=0){WW->comandArray=InitArray();}
        else{WW->comandArray=NULL;}
        addToSort(p1,  WW, i);//дод ємо, д л? ?дуть  н лог?чн? опер ц?ї з ?ншими р?внями
        for(int j = 0; j < FW.Comcount; j++){ //цикл: зчитув ння елемент?в 2-ого р?вня
            Fcommands FC; //зм?нн  для зчитув ння ?з ф йл
            fread(&FC,sizeof(Fcommands),1,file); //зчит ли
            commands *NC = new commands; //вид?ляємо п м'ять
            NC->name=FC.name;
            NC->city=FC.city;
            NC->prize_place=FC.prize_place;
            NC->captain=FC.captain;
            NC->firstparticipants = InitArray();
            if(FC.Player!=0){ NC->firstparticipants=InitArray();}
            else{ NC->firstparticipants=NULL;}
            addToSort((((what_where*)p1[i])->comandArray), NC, j);
            for(int k = 0; k < FC.Player; k++){ //цикл: зчитув ння елемент?в 3-ого р?вня
                Fparticipants FP; //зм?нн  для зчитув ння ?з ф йл
                fread(&FP,sizeof(Fparticipants),1,file);
                participants *P= new participants; //вид?ляємо п м'ять
                P->name=FP.name;
                P->age=FP.age;
                P->status=FP.status;
                addToSort( ((commands *)((what_where*)p1[i])->comandArray[j])->firstparticipants, P, k);
            }
        }
    }
    fclose(file);//з крив ємо ф йл
      ui->comboBox->clear();
        ui->comboBox_2->clear();
    for(int i=0;i<((int *)p1)[POS_CNT];i++)//переписуємо отрим н? д н? в comboBox
    {
        ui->comboBox->addItem(QString::number((((what_where*)(p1)[i]))->num));
        ui->comboBox_2->addItem(QString::number((((what_where*)(p1)[i]))->num));
    }}


