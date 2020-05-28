#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void player();
void logic();
void ballLogic();
void robot();
void board();
void leaderboard();

bool AI=false;

    bool working=true;
    int H=10;// x a hg
    int L=30;// y b lg

    int random;
    int last=0;
    int Playerhit=0;

    bool ball=false;
    int xball=H/2;
    int yball=L/2;
    int direction;

    int xpress;
    int ypress;
    int turn;

///-----------------
    int HP=10;
    int a=H-3;
    int b=3;
    int power=1;
    int shield=0;

    int pH=0;
    int pL=L;
    int ammo=0;

///-----------------
    int HP1=10;
    int za=3;
    int zb=L-3;
    int power1=1;
    int shield1=0;

    int pH1=0;
    int pL1=0;
    int ammo1=0;


///========
int walk=1;


int main(){
    srand(time(0));

    turn=rand()%2;
    direction=1+rand()%8;

    cout<<"When the game starts press \"H\" for Help."<<endl;
    system("pause");

    while(working){

        system("cls");

        board();

        if(AI)robot();

        if(ball)ballLogic();

        logic();

        player();
    }

    leaderboard();


    return 0;
    }



void board(){

      for(int hg=0;hg<=H;hg++){

        for(int lg=0;lg<=L;lg++){

            if((lg==0||lg==L)&&(hg==0||hg==H))cout<<"o";
            else if(lg==0||lg==L)cout<<"|";

            //------------------ P1
            else if(a==hg&&b==lg)cout<<"X";
            else if(a-1==hg&&b==lg)cout<<"\\";
            else if(a==hg&&b+1==lg)cout<<">";
            else if(a+1==hg&&b==lg)cout<<"/";
            else if(a==hg&&b-1==lg)cout<<":";

            //------------------ P2
            else if(za==hg&&zb==lg)cout<<"X";
            else if(za-1==hg&&zb==lg)cout<<"/";
            else if(za==hg&&zb-1==lg)cout<<"<";
            else if(za+1==hg&&zb==lg)cout<<"\\";
            else if(za==hg&&zb+1==lg)cout<<":";

            //------------------ P1
            else if(power==1&&pH==hg&&pL==lg)cout<<"}";
            else if(power==1&&pH==hg&&pL-1==lg)cout<<"-";

            else if(shield>=1&&a-1==hg&&b+1==lg)cout<<")";
            else if(shield>=1&&a+1==hg&&b+1==lg)cout<<")";

            else if(power==2&&(pH-1==hg&&pL-1==lg))cout<<">";
            else if(power==2&&(pH==hg&&pL==lg))cout<<"}";
            else if(power==2&&(pH+1==hg&&pL-1==lg))cout<<">";
            else if(power==2&&((pH-1==hg||pH+1==hg)&&pL-2==lg||(pH==hg&&pL-1==lg)))cout<<"~";

            else if(power==3&&pH==hg&&pL==lg)cout<<">";
            else if(power==3&&pH==hg&&pL-1==lg)cout<<"=";
            else if(power==3&&pH==hg&&pL-2==lg)cout<<":";
            else if(power==3&&pH==hg&&pL-3==lg)cout<<"=";
            else if(power==3&&pH==hg&&pL-4==lg)cout<<"]";

            //------------------ P2
            else if(power1==1&&pH1==hg&&pL1==lg)cout<<"{";
            else if(power1==1&&pH1==hg&&pL1+1==lg)cout<<"-";

            else if(shield1>=1&&za-1==hg&&zb-1==lg)cout<<"(";
            else if(shield1>=1&&za+1==hg&&zb-1==lg)cout<<"(";

            else if(power1==2&&(pH1-1==hg&&pL1+1==lg))cout<<"<";
            else if(power1==2&&(pH1==hg&&pL1==lg))cout<<"{";
            else if(power1==2&&(pH1+1==hg&&pL1+1==lg))cout<<"<";
            else if(power1==2&&((pH1-1==hg||pH1+1==hg)&&pL1+2==lg||(pH1==hg&&pL1+1==lg)))cout<<"~";

            else if(power1==3&&pH1==hg&&pL1==lg)cout<<"<";
            else if(power1==3&&pH1==hg&&pL1+1==lg)cout<<"=";
            else if(power1==3&&pH1==hg&&pL1+2==lg)cout<<":";
            else if(power1==3&&pH1==hg&&pL1+3==lg)cout<<"=";
            else if(power1==3&&pH1==hg&&pL1+4==lg)cout<<"[";



            else if(ball&&xball==hg&&yball==lg)cout<<"O";
            else if(ball&&(2*L/3-3==lg||L/3+3==lg))cout<<".";

            else if(ball==false&&xpress==hg&&ypress==lg)cout<<"#";

            else if((hg==H||hg==0)&&lg%2==1)cout<<"=";
            else if((hg==H||hg==0)&&lg%2==0)cout<<"-";
            else cout<<" ";

            }
         if(hg==1) cout<<" P1 HP:"<<HP;
         if(hg==2) cout<<" P2 HP:"<<HP1;
         if(hg==4){cout<<" P1 ammo:";if(ammo>0)cout<<ammo;else cout<<"~";}
         if(hg==5){cout<<" P2 ammo:";if(ammo1>0)cout<<ammo1;else cout<<"~";}

         if(hg==7&&power!=1){cout<<" P1 power:";if(power==2)cout<<"T. Shot";if(power==3)cout<<"Rocket";}
         if(hg==8&&power1!=1){cout<<" P2 power:";if(power1==2)cout<<"T. Shot";if(power1==3)cout<<"Rocket";}

         cout<<endl;
        }

}




void robot(){

int rmove=rand()%40;
int rdir=rand()%3;



if(rmove==1&&(zb>L-L/4-1))zb--;
else if(rmove==2&&zb!=L-1)zb++;

if(za==2)walk=1;
if(za==H-2)walk=2;

if     (za==H/2&&walk==1&&rdir==1)walk=2;
else if(za==H/2&&walk==2&&rdir==1)walk=1;

if(zb<L-3&&(rand()%40==1))zb++;

if(walk==1)za++;
if(walk==2)za--;


if(pL1<0&&power1==1){pH1=za;pL1=zb-3;}
else if(pL1<0){pH1=za;pL1=zb-3;ammo1--;}


}


void logic(){


int ballhit=0;
    Playerhit=0;

        if(HP<=0||HP1<=0)working=false;

        if(ammo<=0&&pL>L-1)power=1;
        if(ammo1<=0&&pL1<1)power1=1;

        if(turn==1){ypress=L-2;xpress=H-2;}
        else       {ypress=2;  xpress=2;}

        if(power==1) pL +=2;
        if(power1==1)pL1-=2;

        if(power==2) pL +=2;
        if(power1==2)pL1-=2;

        if(power==3) pL +=3;
        if(power1==3)pL1-=3;


    switch(power){
            case 1:
                if((pH==za||pH==za-1||pH==za+1)&&(pL==zb||pL-1==zb))Playerhit=1;
                if(ball&&pH==xball&&(pL==yball||pL-1==yball||pL+1==yball))ballhit=1;
            break;
            case 2:
                if(((pH-1==za||pH==za||pH+1==za)||(pH-1==za-1||pH==za-1||pH+1==za-1)||(pH-1==za+1||pH==za+1||pH+1==za+1))&&(pL==zb||pL-1==zb||pL-2==zb))Playerhit=1;
                if(ball&&(pH-1==xball||pH==xball||pH+1==xball)&&(pL==yball||pL-1==yball||pL-2==yball))ballhit=1;
            break;
            case 3:
                if((pH==za||pH==za-1||pH==za+1)&&(pL==zb||pL-1==zb||pL-2==zb||pL-3==zb||pL-4==zb))Playerhit=1;
                if(ball&&pH==xball&&(pL==yball||pL-1==yball||pL-2==yball||pL-3==yball||pL-4==yball))ballhit=1;
            break;
            }

    switch(power1){
            case 1:
                if((pH1==a||pH1==a-1||pH1==a+1)&&(pL1==b||pL1+1==b))Playerhit=2;
                if(ball&&pH1==xball&&(pL1==yball||pL1+1==yball||pL1-1==yball))ballhit=2;
            break;
            case 2:
                if(((pH1-1==a||pH1==a||pH1+1==a)||(pH1-1==a-1||pH1==a-1||pH1+1==a-1)||(pH1-1==a+1||pH1==a+1||pH1+1==a+1))&&(pL1==b||pL1+1==b||pL1+2==b))Playerhit=2;
                if(ball&&(pH1-1==xball||pH1==xball||pH1+1==xball)&&(pL1==yball||pL1+1==yball||pL1+2==yball))ballhit=2;
            break;
            case 3:
                if((pH1==a||pH1==a-1||pH1==a+1)&&(pL1==b||pL1+1==b||pL1+2==b||pL1+3==b||pL1+4==b))Playerhit=2;
                if(ball&&pH1==xball&&(pL1==yball||pL1+1==yball||pL1+2==yball||pL1+3==yball||pL1+4==yball))ballhit=2;
            break;
            }


            if (ballhit==1){
                random=1+rand()%3;while(random==last)random=1+rand()%3;
                    pL=L+5;ball=false;xball=H/2;yball=L/2;
                    if(random==1){shield+=2;last=1;}
                    if(random==2){power=2;ammo+=7;last=2;}
                    if(random==3){power=3;ammo+=7;last=3;}
                    }
            else if(ballhit==2){
                random=1+rand()%3;while(random==last)random=1+rand()%3;
                    pL1=-5;ball=false;xball=H/2;yball=L/2;
                    if(random==1){shield1+=2;last=1;}
                    if(random==2){power1=2;ammo1+=7;last=2;}
                    if(random==3){power1=3;ammo1+=7;last=3;}
                    }

            if(Playerhit==1){
                pL=L+5;if(shield1>=1)shield1--;else HP1--;}
            else if(Playerhit==2){
                pL1=-5;if(shield>=1)shield--;else HP--;}


            if(ball==false&&(xpress==a&&ypress==b||xpress==za&&ypress==zb)){if(turn==1)turn=0;else turn=1;ball=true;}

}



void ballLogic(){

            if(yball<L/3+3||yball>2*L/3-3)yball=L/2;

            if(xball<=1){random=1+rand()%3;switch(random){
                    case 1:direction=3;break;
                    case 2:direction=5;break;
                    case 3:direction=8;break;
                    }}
            else if(xball>=H-1){random=1+rand()%3;switch(random){
                    case 1:direction=1;break;
                    case 2:direction=4;break;
                    case 3:direction=6;break;
                    }}
            else if(yball<=L/3+3){random=1+rand()%3;switch(random){
                    case 1:direction=6;break;
                    case 2:direction=7;break;
                    case 3:direction=8;break;
                    }}
            else if(yball>=2*L/3-3){random=1+rand()%3;switch(random){
                    case 1:direction=1;break;
                    case 2:direction=2;break;
                    case 3:direction=3;break;
                    }}

            switch (direction){
            case 1:xball--;yball--;break;
            case 2:yball--;     break;
            case 3:xball++;yball--;break;
            case 4:xball--;     break;
            case 5:xball++;     break;
            case 6:xball--;yball++;break;
            case 7:yball++;     break;
            case 8:xball++;yball++;break;}
}

void player(){

 if(_kbhit()){
    switch(_getch()){
        case 'w':if(a!=2)a--;
            break;
        case 'a':if(b!=1)b--;
            break;
        case 's':if(a!=H-2)a++;
            break;
        case 'd':if(b<L/4+1)b++;
            break;
        case 'e':if(pL>L&&power==1){pH=a;pL=b+3;}
                 else if(pL>L&&power!=1){pH=a;pL=b+3;ammo--;}
            break;

        case 'i':if(za!=2&&AI==false)za--;
            break;
        case 'j':if(zb>L-L/4-1&&AI==false)zb--;
            break;
        case 'k':if(za!=H-2&&AI==false)za++;
            break;
        case 'l':if(zb!=L-1&&AI==false)zb++;
            break;
        case 'o':if(pL1<0&&power1==1&&AI==false){pH1=za;pL1=zb-3;}
                 else if(pL1<0&&AI==false){pH1=za;pL1=zb-3;ammo1--;}
            break;

        case 'h':
                cout<<"     Controls"<<endl;
                cout<<"P1: Use 'WASD' to move and 'E' to fire."<<endl;
                cout<<"P2: Use 'IJKL' to move and 'O' to fire.\n"<<endl;
                cout<<"     Game info"<<endl;
                cout<<"-Step on the Pressure Plate('#') to activate the Ball."<<endl;
                cout<<"-The one who shots the Ball first gets a Power Up."<<endl;
                cout<<"-The Power Ups are: Shield , Triple shot , Rocket."<<endl;
                cout<<"-Power Ups that shoot need AMMO."<<endl;
                cout<<"-The game ends when one of the players reaches 0 HP.\n"<<endl;
                cout<<" To activate the ROBOT press '='"<<endl;
                cout<<endl;system("pause");
                           system("cls");
            break;

        case '=':if(AI)AI=false;else AI=true;HP1=10;
            break;

               }
        }
}

void leaderboard(){

    fstream board;
    string name;

cout<<"  _____ _____ _______ _____"<<endl;
cout<<" |  ___ |___| |  |  | |____"<<endl;
cout<<" |____| |   | |  |  | |____"<<endl;
cout<<"  ____  _    _ _____ ______ "<<endl;
cout<<" |    |  \\  /  |____ |____/ "<<endl;
cout<<" |____|   \\/   |____ |   \\_\n\n"<<endl;

    if(AI==false||(AI==true&&HP>HP1)){cout<<"Winner's name is: ";getline(cin,name);}

    string sentence_select;
    int file_cont;

    if(AI==false||(AI==true&&HP>HP1))file_cont=1;else file_cont=0;

    board.open("leaderlist.txt");
    while(board>>sentence_select)file_cont++;
    board.close();


    string file_list[file_cont];

    if(AI==false||(AI==true&&HP>HP1))file_list[0]=name;

    if(AI==false||(AI==true&&HP>HP1))file_cont=1;else file_cont=0;

    board.open("leaderlist.txt");
    while(getline(board,sentence_select))file_list[file_cont++]=sentence_select;
    board.close();

    board.open("leaderlist.txt");
    for(int file_loop=0;file_loop<file_cont;file_loop+=1)board<<file_list[file_loop]<<endl;
    board.close();


    cout<<"\n     Hall of Fame:\n"<<endl;
    for(int j=0;j<file_cont;j+=1)cout<<"-Player: "<<file_list[j]<<endl;


    cout<<"\n\nPress \"X\" to close."<<endl;
    string stop;

    do {if(_kbhit())if(_getch()=='x')stop="x";}while(stop!="x");

}

