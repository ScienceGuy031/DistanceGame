#include <iostream>
#include "spielfigur.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "windows.h"

using namespace std;

spielfigur::spielfigur()
{
    //ctor
}
spielfigur::~spielfigur()
{
    //dtor
}

    spielfigur wh1 (3,8,0,0,0,0); //white helper 1
    spielfigur wh2 (4,8,0,0,0,0); //white helper 2
    spielfigur wh3 (7,8,0,0,0,0); //white helper 3
    spielfigur wk (6,8,0,0,1,0);  //Ronald McDonald

    spielfigur bh1(2,1,0,1,0,0); //black helper 1
    spielfigur bh2(5,1,0,1,0,0); //black helper 2
    spielfigur bh3(6,1,0,1,0,0); // black helper 3
    spielfigur bk (3,1,0,1,1,0); // BurgerKing

//Zeigt das Spielfeld mit allen Spielfiguren an.
void spielfeld(){
    int x=0;
    int y=0;
    int xh1=wh1.Getxpos();
    int yh1=wh1.Getypos();
    int xh2=wh2.Getxpos();
    int yh2=wh2.Getypos();
    int xh3=wh3.Getxpos();
    int yh3=wh3.Getypos();
    int xk=wk.Getxpos();
    int yk=wk.Getypos();
    int xH1=bh1.Getxpos();
    int yH1=bh1.Getypos();
    int xH2=bh2.Getxpos();
    int yH2=bh2.Getypos();
    int xH3=bh3.Getxpos();
    int yH3=bh3.Getypos();
    int xK=bk.Getxpos();
    int yK=bk.Getypos();
    bool gh1=wh1.Getgefangen();
    bool gh2=wh2.Getgefangen();
    bool gh3=wh3.Getgefangen();
    bool gH1=bh1.Getgefangen();
    bool gH2=bh2.Getgefangen();
    bool gH3=bh3.Getgefangen();

    cout << "     1   2   3   4   5   6   7   8  " << endl;
    while (y<8){
        cout << "   ---------------------------------" << endl;
        cout << " " << y+1 << " ";
        x=0;
        if (y+1==yh1||y+1==yh2||y+1==yh3||y+1==yk||y+1==yH1||y+1==yH2||y+1==yH2||y+1==yH3||y+1==yK){
            cout << "|";
            while (x<8){
                if ((x+1==xh1&&y+1==yh1)||(x+1==xh2&&y+1==yh2)||(x+1==xh3&&y+1==yh3)){
                    if(x+1==xh1&&y+1==yh1&&gh1==true){
                        cout<<"gh |";
                    }else if (x+1==xh2&&y+1==yh2&&gh2==true){
                        cout<<"gh |";
                    }else if(x+1==xh3&&y+1==yh3&&gh3==true){
                    cout<<"gh |";
                    }else{
                        cout<<" h |";
                    }
                }else{
                    if((x+1==xH1&&y+1==yH1)||(x+1==xH2&&y+1==yH2)||(x+1==xH3&&y+1==yH3)){
                        if (x+1==xH1&&y+1==yH1&&gH1==true){
                            cout<<"gH |";
                        }else if(x+1==xH2&&y+1==yH2&&gH2==true){
                            cout<<"gH |";
                        }else if (x+1==xH3&&y+1==yH3&&gH3==true){
                            cout<<"gH |";
                        }else{
                            cout<<" H |";
                        }
                    }else{
                        if((x+1==xk&&y+1==yk)){
                            if(wk.Getgefangen()==1){
                                cout << " gk |";
                            }else{
                                cout<<" k |";
                            }
                        }else{
                            if (x+1==xK&&y+1==yK){
                                if(bk.Getgefangen()==1){
                                    cout << " gK |";
                                }else{
                                    cout<<" K |";
                                }
                            }else{
                                cout<<"   |";
                            }
                        }
                    }
                }
            if (x==7){
                cout << endl;
            }
            x++;
            }
        }else{
            cout << "|   |   |   |   |   |   |   |   |" << endl;
        }
        y++;
    }
}

//Überprüft ob ein eingegebener Zug mit den Spielregeln übereinstimmt.
int legitim(int gewuenschte_x_Koordinate,int gewuenschte_y_Koordinate)
   {
      int x_wh1 = wh1.Getxpos();
      int y_wh1 = wh1.Getypos();
      int x_wh2 = wh2.Getxpos();
      int y_wh2 = wh2.Getypos();
      int x_wh3 = wh3.Getxpos();
      int y_wh3 = wh3.Getypos();
      int x_wk = wk.Getxpos();
      int y_wk = wk.Getypos();
      bool wh1_gefangen = wh1.Getgefangen();
      bool wh2_gefangen = wh2.Getgefangen();
      bool wh3_gefangen = wh3.Getgefangen();
      bool wk_gefangen = wk.Getgefangen();
      bool wh1_ziehen = wh1.Getziehen();
      bool wh2_ziehen = wh2.Getziehen();
      bool wh3_ziehen = wh3.Getziehen();
      bool wk_ziehen = wk.Getziehen();
      int x_dif=-2;
      int y_dif=-2;
      int x_dif_1=-1;
      int y_dif_1=-1;
      int x_dif_2=-1;
      int y_dif_2=-1;
      int x_dif_3=-1;
      int y_dif_3=-1;

      if (wh1_ziehen==true && wh1_gefangen==false)
      {
          if (x_wh1>=gewuenschte_x_Koordinate)                          // gewünschte X Distanz mit Helfer 1
              {x_dif = x_wh1 - gewuenschte_x_Koordinate; }
          else{x_dif = gewuenschte_x_Koordinate - x_wh1;}

          if (y_wh1>=gewuenschte_y_Koordinate)
          {  y_dif = y_wh1 - gewuenschte_y_Koordinate;}
          else {y_dif = gewuenschte_y_Koordinate - y_wh1;}


            if(x_wh2>=x_wh3) { x_dif_1 = x_wh2 - x_wh3;}              //positive X Differenz zwischen Helfer 2 und Helfer 3
                else {x_dif_1 = x_wh3 - x_wh2;}

            if (y_wh2>=y_wh3) { y_dif_1 = y_wh2 - y_wh3;}             //positive Y Differenz wischen Helfer 2 und Helfer 3
                else {y_dif_1 = y_wh3 - y_wh2;}

            if(x_wh2>=x_wk){ x_dif_2 = x_wh2 - x_wk;}                 //positve X Differenz zwischen Helfer 2 und König
                else {x_dif_2 = x_wk - x_wh2;}

            if (y_wh2>=y_wk){ y_dif_2 = y_wh2 - y_wk;}                 //positive Y Differenz zwischen Helfer 2 und König
                else {y_dif_2 = y_wk - y_wh2;}

            if(x_wh3>=x_wk){x_dif_3 = x_wh3 - x_wk;}                    //positive X Differenz zwischen Helfer 3 und König
                else {x_dif_3 = x_wk - x_wh3;}

            if (y_wh3>=y_wk){ y_dif_3 = y_wh3 - y_wk;}                  //positive Y Differenz zwischen Helfer 3 und König
                else {y_dif_3 = y_wk - y_wh3;}
        }

     if (wh2_ziehen==true&&wh2_gefangen==false)
      { if (x_wh2>=gewuenschte_x_Koordinate)                          // gewünschte X Distanz mit Helfer 2
              {x_dif = x_wh2 - gewuenschte_x_Koordinate; }
            else{x_dif = gewuenschte_x_Koordinate - x_wh2;}

          if (y_wh2>=gewuenschte_y_Koordinate)                         //gewünschte Y-Distanz mit Helfer 2
          {  y_dif = y_wh2 - gewuenschte_y_Koordinate;}
            else {y_dif = gewuenschte_y_Koordinate - y_wh2;}


          if(x_wh1>=x_wh3){ x_dif_1 = x_wh1 - x_wh3;}                   //positive X Distanz zwischen Helfer 1 und 3
            else {x_dif_1 = x_wh3 - x_wh1;}

            if (y_wh1>=y_wh3){ y_dif_1 = y_wh1 - y_wh3;}                //positive Y Distanz zwischen Helfer 1 und 3
                else {  y_dif_1 = y_wh3 - y_wh1;}

            if(x_wh1>=x_wk){x_dif_2 = x_wh1 - x_wk;}                    //positive X Distanz zwischen Helfer 1 und König
                else {x_dif_2 = x_wk - x_wh1;}

            if (y_wh1>=y_wk){y_dif_2 = y_wh1 - y_wk;}                   //positive Y Distanz zwischen Helfer 1 und König
                else {y_dif_2 = y_wk - y_wh1;}

            if(x_wh3>=x_wk){ x_dif_3 = x_wh3 - x_wk;}                   //positive X Distanz zwischen Helfer 3 und König
                else {x_dif_3 = x_wk - x_wh3;}

            if (y_wh3>=y_wk){y_dif_3 = y_wh3 - y_wk;}                   //positive Y Distanz zwischen Helfer 3 und König
                else {y_dif_3 = y_wk - y_wh3;}
        }


     if (wh3_ziehen==true&&wh3_gefangen==false)
      { if (x_wh3>=gewuenschte_x_Koordinate)                          // gewünschte X Distanz mit Helfer 3
              {x_dif = x_wh3 - gewuenschte_x_Koordinate; }
          else{x_dif = gewuenschte_x_Koordinate - x_wh3;}

          if (y_wh3>=gewuenschte_y_Koordinate)
          {  y_dif = y_wh3 - gewuenschte_y_Koordinate;}
          else {y_dif = gewuenschte_y_Koordinate - y_wh3;}


         if(x_wh1>=x_wh2){ x_dif_1 = x_wh1 - x_wh2;}                    //positive x Distanz zwischen Helfer 1 und 2
          else {x_dif_1 = x_wh2 - x_wh1;}

         if (y_wh1>=y_wh2){ y_dif_1 = y_wh1 - y_wh2;}                   //positive x Distanz zwischen Helfer 1 und 2
          else {y_dif_1 = y_wh2 - y_wh1;}

         if(x_wh1>=x_wk)  { x_dif_2 = x_wh1 - x_wk;}                    //positive x Distanz zwischen Helfer 1 und 2
          else {x_dif_2 = x_wk - x_wh1;}

         if (y_wh1>=y_wk) { y_dif_2 = y_wh1 - y_wk;}                    //positive x Distanz zwischen Helfer 1 und 2
          else {y_dif_2 = y_wk - y_wh1;}

         if(x_wh2>=x_wk)  { x_dif_3 = x_wh2 - x_wk;}                    //positive x Distanz zwischen Helfer 1 und 2
          else {x_dif_3 = x_wk - x_wh2;}

         if (y_wh2>=y_wk){ y_dif_3 = y_wh2 - y_wk;}                     //positive x Distanz zwischen Helfer 1 und 2
          else {y_dif_3 = y_wk - y_wh2;}
        }

    if (wk_ziehen==true&&wk_gefangen==false)
      { if (x_wk>=gewuenschte_x_Koordinate)                                 // gewünschte Distanz mit König
              {x_dif = x_wk - gewuenschte_x_Koordinate; }
          else{x_dif = gewuenschte_x_Koordinate - x_wk;}

          if (y_wk>=gewuenschte_y_Koordinate)
          {  y_dif = y_wk - gewuenschte_y_Koordinate;}
          else {y_dif = gewuenschte_y_Koordinate - y_wk;}

           if(x_wh1>=x_wh2){ x_dif_1 = x_wh1 - x_wh2;}                      //positive X Distanz zwischen Helfer 1 und 2
            else {x_dif_1 = x_wh2 - x_wh1;}

           if (y_wh1>=y_wh2){ y_dif_1 = y_wh1 - y_wh2;}                     //positive Y_Distanz zwschen Helfer 1 und 2
            else {y_dif_1 = y_wh2 - y_wh1;}

           if(x_wh1>=x_wh3){ x_dif_2 = x_wh1 - x_wh3;}                      //positive X Distanz wischen Helfer 1 und 3
            else {x_dif_2 = x_wh3 - x_wh1;}

           if (y_wh1>=y_wh3){ y_dif_2 = y_wh1 - y_wh3;}                     //positive Y Distanz zwischen Helfer 1 und 3
            else {y_dif_2 = y_wh3 - y_wh1;}

           if(x_wh2>=x_wh3){ x_dif_3 = x_wh2 - x_wh3;}                      //positive X Distanz zwischen Helfer 2 und 3
            else {x_dif_3 = x_wh3 - x_wh2;}

           if (y_wh2>=y_wh3){ y_dif_3 = y_wh2 - y_wh3;}                     //positive Y Distanz zwischen Helfer 2 und 3
            else {y_dif_3 = y_wh3 - y_wh2;}

        }
        if(x_dif==x_dif_1 && y_dif==y_dif_1){return 1;}                    //Vergleich gewünschte Disatnz mit Distanzen der Figuren, die nicht ziehen
        if(x_dif==y_dif_1 && y_dif==x_dif_1){return 1;}
        if(x_dif==x_dif_2&& y_dif==y_dif_2) {return 1;}
        if(x_dif==y_dif_2&& y_dif==x_dif_2) {return 1;}
        if(x_dif==x_dif_3&& y_dif==y_dif_3) {return 1;}
        if(x_dif==y_dif_3&& y_dif==x_dif_3) {return 1;}
        else {return 0;}
//1-legitim
}

//Generiert eine Zufallszahl zwischen x und y(inklusive).
int zufallszahl (const int x,const int y){
  //const int x = 1, y = 4;
  int random;
  srand (time (NULL));
  random = (rand () % ((y + 1) - x)) + x;
  return random;
}

//Die Funktion lässt eine Figur auf auf die geschünschten Koordinaten ziehen.
void ziehen(int x, int y)
{
    spielfigur a[8]={wh1,wh2,wh3,wk,bh1,bh2,bh3,bk};    //alle Figuren sind in dem Array a angelegt
    for(int i = 0; i < 8;i++) {     //findet heraus,welche Figur ziehen will
        if(a[i].Getziehen()==1) {
            for(int j = 0; j < 8; j++) {        //findet heraus, ob eine Figur auf dem angegebenen Feld steht
                if(a[j].Getxpos()==x && a[j].Getypos()==y && a[i].Getteam()!=a[j].Getteam()) {      //steht eine gegnerische Figur auf dem Feld, wird diese gefangen genommen
                    a[j].Setgefangen(1);
                    a[j].Setxpos(a[i].Getxpos());
                    a[j].Setypos(a[i].Getypos());
                }
                else if(a[j].Getxpos()==x && a[j].Getypos()==y && a[i].Getteam()==a[j].Getteam()) { //steht eine freundliche Figur auf dem Feld, wird diese befreit, wenn der König zieht
                    if(a[i].Getkoenig()==1){
                        a[j].Setgefangen(0);
                    }
                    a[j].Setxpos(a[i].Getxpos());
                    a[j].Setypos(a[i].Getypos());
                }
            }
            a[i].bewegen(x,y);
            wh1=a[0];   //Rückgabe der Werte an die Figuren außerhalb der Funktion
            wh2=a[1];
            wh3=a[2];
            wk=a[3];
            bh1=a[4];
            bh2=a[5];
            bh3=a[6];
            bk=a[7];
        }
    }
}

//Diese Funktion lässt den vom Computer gesteuerten Spieler Züge machen
//Wenn er den gegnerischen König gefangen nehmen kann tut er das.
//Wenn nicht, nimmt er, wenn möglich, einen gegnerischen Helfer gefangen.
//Wenn auch das nicht möglich ist, macht er einen zufälligen möglichen Zug.
void computer()
{
    int a[8][8][2]={0};
    int y,x,anz =0;
    int figur=1;
    spielfigur tmp(0,0,0,0,0,0); //temporäre Spielfigur
    tmp=wh1;
    wh1=bh1;
    bh1=tmp;
    tmp=wh2;
    wh2=bh2;
    bh2=tmp;
    tmp=wh3;
    wh3=bh3;
    bh3=tmp;
    tmp=wk;
    wk=bk;
    bk=tmp;
    //Figuren Tauschen, da legitim(x,y) nur für weiß überprüft

    while (figur<5){
        y=0;
        while (y<8){
            x=0;
            while (x<8){
                switch (figur){
                    case 1:
                        wh1.Setziehen(1);
                        if (legitim(x+1,y+1)==1){
                            a[x][y][0]=1;
                            a[x][y][1]=figur;
                        }
                        wh1.Setziehen(0);
                        break;
                    case 2:
                        wh2.Setziehen(1);
                        if (legitim(x+1,y+1)==1){
                            a[x][y][0]=1;
                            a[x][y][1]=figur;
                        }
                        wh2.Setziehen(0);
                        break;
                    case 3:
                        wh3.Setziehen(1);
                        if (legitim(x+1,y+1)==1){
                            a[x][y][0]=1;
                            a[x][y][1]=figur;
                        }
                        wh3.Setziehen(0);
                        break;
                    case 4:
                        wk.Setziehen(1);
                        if (legitim(x+1,y+1)==1){
                            a[x][y][0]=1;
                            a[x][y][1]=figur;
                        }
                        wk.Setziehen(0);
                        break;
                }
                x++;
            }
            y++;
        }
        figur++;
    }//Berechnung möglicher Züge

    y=0;
    while(y<8){
        x=0;
        while(x<8){
            if(a[x][y][0]==1){
                if(x+1==bh1.Getxpos()&&y+1==bh1.Getypos()&&bh1.Getgefangen()==1){
                    a[x][y][0]=0;
                }
                if(x+1==bh2.Getxpos()&&y+1==bh2.Getypos()&&bh2.Getgefangen()==1){
                    a[x][y][0]=0;
                }
                if(x+1==bh3.Getxpos()&&y+1==bh3.Getypos()&&bh3.Getgefangen()==1){
                    a[x][y][0]=0;
                }
            }
            x++;
        }
        y++;
    }

    tmp=wh1;
    wh1=bh1;
    bh1=tmp;
    tmp=wh2;
    wh2=bh2;
    bh2=tmp;
    tmp=wh3;
    wh3=bh3;
    bh3=tmp;
    tmp=wk;
    wk=bk;
    bk=tmp;

    y=0;
    while (y<8){
        x=0;
        while(x<8){
            if (a[x][y][0]==1){
                if (x+1==wk.Getxpos()&&y+1==wk.Getypos()){ //König fangen wenn möglich
                    switch (a[x][y][1]){
                        case 1:
                            bh1.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 2:
                            bh2.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 3:
                            bh3.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 4:
                            bk.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                    }
                }else if((x+1==wh1.Getxpos()&&y+1==wh1.Getypos())||(x+1==wh2.Getxpos()&&y+1==wh2.Getypos())||(x+1==wh3.Getxpos()&&y+1==wh3.Getypos())){
                    switch (a[x][y][1]){
                        case 1:
                            bh1.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 2:
                            bh2.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 3:
                            bh3.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                        case 4:
                            bk.Setziehen(1);
                            ziehen(x+1,y+1);
                            return;
                            break;
                    }// Helfer fangen wenn möglich
                }
            }
            x++;
        }
        y++;
    }
    //Zufälliger Zug
    y=0;
    x=0;
    anz=0;
    while (y<8){
        x=0;
        while (x<8){
            if(a[x][y][0]==1){anz++;}
            x++;
        }
        y++;
    }//anz=Anzahl der möglichen Züge
    if (anz==0){bk.Setgefangen(1); return;}//Verloren, wenn kein Zug möglich
    anz=zufallszahl(1,anz);
    y=0;
    while (y<8){
        x=0;
        while (x<8){
            if(a[x][y][0]==1){anz--;}
            if (anz==0){
                switch(a[x][y][1]){
                    case 1:
                        bh1.Setziehen(1);
                        ziehen(x+1,y+1);
                        return;
                        break;
                    case 2:
                        bh2.Setziehen(1);
                        ziehen(x+1,y+1);
                        return;
                        break;
                    case 3:
                        bh3.Setziehen(1);
                        ziehen(x+1,y+1);
                        return;
                        break;
                    case 4:
                        bk.Setziehen(1);
                        ziehen(x+1,y+1);
                        return;
                        break;
                }
            }
            x++;
        }
        y++;
    }
}

//Fragt den Benutzer mit welcher Figur er auf welches Feld ziehen möchte.
int user()
{
    int xalt, yalt, xneu, yneu, figur = 0;
    cout <<"Mit welcher Figur soll gezogen werden?" <<endl;
    cout <<"Xpos= ";
    cin >>xalt;
    cout <<"Ypos= ";
    cin >> yalt;
    if ((xalt==1||xalt==2||xalt==3||xalt==4||xalt==5||xalt==6||xalt==7||xalt==8)&&(yalt==1||yalt==2||yalt==3||yalt==4||yalt==5||yalt==6||yalt==7||yalt==8)){
        if (xalt==wh1.Getxpos()&&yalt==wh1.Getypos()){
            if (wh1.Getgefangen()==1){return 0;}
            wh1.Setziehen(1);
            figur++;
        }
        if (xalt==wh2.Getxpos()&&yalt==wh2.Getypos()){
            if (wh2.Getgefangen()==1){return 0;}
            wh2.Setziehen(1);
            figur++;
        }
        if (xalt==wh3.Getxpos()&&yalt==wh3.Getypos()){
            if (wh3.Getgefangen()==1){return 0;}
            wh3.Setziehen(1);
            figur++;
        }
        if (xalt==wk.Getxpos()&&yalt==wk.Getypos()){
            wk.Setziehen(1);
            figur++;
        }
        if (figur==0){
            cout << "An dieser Position befindet sich keine Figur." << endl;
            return 0;
        }
        cout <<"Wohin soll diese Figur ziehen?" <<endl;
        cout <<"Xpos= ";
        cin >>xneu;
        cout <<"Ypos= ";
        cin >> yneu;
        if ((xneu==1||xneu==2||xneu==3||xneu==4||xneu==5||xneu==6||xneu==7||xneu==8)&&(yneu==1||yneu==2||yneu==3||yneu==4||yneu==5||yneu==6||yneu==7||yneu==8)){
            xneu = xneu*10 + yneu;
            return xneu;
        }else{
            cout << "Keine valide Eingabe" << endl;
        }
    }else{
        cout << "Keine valide Eingabe." << endl;
    }
    return 0;
}

//Beschreibungstext
void setup()
{
    cout << "-------------------------------------------" << endl;
    cout << "| Herzlich Willkommen beim DISTANZ-Spiel! |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Das Spielziel ist es den gegnerischen Koenig gefangen zu nehmen." << endl;
    cout << "Die eigenen Figuren koennen sich so bewegen, wie die jeweils anderen eigenen Figuren zueinander stehen." << endl;
    cout << "Man nimmt gegnerische Figuren gefangen, indem man sich auf ihr Feld bewegt." <<endl;
    cout << "Der Koenig kann eigene Figuren genau so wieder befreien." << endl << endl;
    cout << "Figurenlegende:" << endl;
    cout << "h - weisser Helfer" << endl << "k - weisser Koenig" << endl << "H - schwarzer Helfer" <<endl << "K - schwarzer Koenig" <<endl << "gh/gH - gefangener Helfer" << endl << "gk/K - gefangener Koenig" << endl << endl;
    spielfeld();
}

//Clear-Fkt: system("CLS");
int main()
{
    bool legitimv=0;
    int x=0;
    int y=0;
    int tmp=0;
    setup();
    while (wk.Getgefangen()==false && bk.Getgefangen()==false){
        do
        {
            tmp=user();
            x=tmp/10;
            y=tmp-x*10;
            legitimv=legitim(x,y);
            if(legitimv==0){
                cout<< "Dieser Zug stimmt leider nicht mit den Spielregeln ueberein." << endl;
            }
        }while(legitimv==0);
        ziehen(x,y);
        system("CLS");
        if(bk.Getgefangen()==1){
            Sleep(2000);
            cout <<"       ---------------------" << endl;
            cout <<"       | Du hast gewonnen! |" << endl;
            cout <<"       ---------------------" << endl << endl << endl;
            spielfeld();
            return 0;
        }
        setup();
        computer();
        Sleep(1000);
        system("CLS");
        if (wk.Getgefangen()==1){
            Sleep(2000);
            cout <<"       ---------------------" << endl;
            cout <<"       | Du hast verloren! |" << endl;
            cout <<"       ---------------------" << endl << endl << endl;
            spielfeld();
            return 0;
        }
        setup();
    }
    return 0;
}
