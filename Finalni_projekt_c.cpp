#include <iostream>
#include <random>//pro generování random čísel
#include <string> //je to proto abych mohl rozdělit string pro vypsání postavyček
#include <thread> //je to pro to aby program chvíli čekal
#include <chrono> 
using namespace std;
int vyberobrazupostavy;
string nepratelezobrazeni[16];
string postavyzoobrazeni[4];
int zivotymax;
int uroven;
int randomcislo;
int dvojbojvyberutoku;
int nepritel=0;
int energie=16;
int energiemax=16;
int superutok;
int brneniuziti=2;
int zivoty;
int pomocnapromena1=3;
int pomocnapromena2=5;
int pomocnapromena3=10;
int pomocnapromena4=15;
int pomocnapromena5=20;
int penize=500;
string jmenopostavy;
string zbran;
int nahled;
int vyber;
int volbaobchod;
int volbaobchodne=0; //pokud v shopu clovek zvoli ze nechce neco nakupovat bude to tam jako volbaobcodne =1 a nakonci vseho bude do while volbaobcod==1
string jmenonepritele[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Upir","Zombik","Obr","Vampir","Drak","Minotaur","Mumie","Kobold","Ork","Troll","Ascendrax"};
string jmenonepriteledvojboj[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Papir","Zombik","Obr","Vampir","Drak","Piditoraur","Mumie","Kobold","Ork","Troll","Ascendrax"};
string jmenonepriteletrojboj[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Upir","Zombik","Obr","Vampir","Drak","Sinotaur","Mumie","Kobold","Ork","Troll","Ascendrax"};
int polezivotynepritel[16] = {400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1200};
int polezivotyprodvojboj[16] = {400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1200};
int polezivotyprotrojboj[16] = {400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1200};
int polezivotynepritelmax[16] = {400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1200};
int poleutoknepritel[16] = {10,15,20,25,25,35,40,45,50,55,60,65,70,75,80,85};
int polesuperutoknepritel[16] = {20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170};
int poleodmenanepritel[16] = {110,150,190,230,270,310,350,390,430,470,510,550,590,630,670,710};
int levelmece=0;
int utok;
int brneni;
int rychlost;
int cenazivoty=100;
int cenautok=100;
int cenarychlost=100;
int cenaenergie=100;
void bojtri(){
cout<<"________________________________________________________________________________________________________________________________\n\n";

cout<<"         "<<jmenopostavy<<"                                                                     "<<jmenonepritele[nepritel]<<"  a  "<<jmenonepriteledvojboj[nepritel]<<"  a  "<<jmenonepriteletrojboj[nepritel]<<"                        \n";
cout<<"_________________________________________________________________________________________________________________________________\n";
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(0, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(0, 21)<<endl;                            
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(16, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(22, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(31, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(43, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(46, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(64, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(61, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(85, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(76, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(106, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(91, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(127, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(106, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(148, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(121, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(169, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(136, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(190, 21)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(151, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(211, 21)<<endl;
cout<<"_________________________________________________________________________________________________________________________________\n\n";

cout<<"          "<<zivoty<<"                                                                         "<<polezivotynepritel[nepritel]<<"  a  "<<polezivotyprodvojboj[nepritel]<<"  a  "<<polezivotyprotrojboj[nepritel]<<"           \n";
cout<<"_________________________________________________________________________________________________________________________________\n";

    

}  
void bojdva(){
cout<<"________________________________________________________________________________________________________________________________\n\n";

cout<<"         "<<jmenopostavy<<"                                                                     "<<jmenonepritele[nepritel]<<"  a  "<<jmenonepriteledvojboj[nepritel]<<"                        \n";
cout<<"_________________________________________________________________________________________________________________________________\n";
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(0, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(0, 15)<<endl;                            
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(16, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(16, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(31, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(31, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(46, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(46, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(61, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(61, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(76, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(76, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(91, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(91, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(106, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(106, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(121, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(121, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(136, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(136, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(151, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(151, 15)<<endl;
cout<<"_________________________________________________________________________________________________________________________________\n\n";

cout<<"          "<<zivoty<<"                                                                         "<<polezivotynepritel[nepritel]<<"  a  "<<polezivotyprodvojboj[nepritel]<<"           \n";
cout<<"_________________________________________________________________________________________________________________________________\n";

    

}  
void boj(){
 cout<<"________________________________________________________________________________________________________________________________\n\n";

cout<<"         "<<jmenopostavy<<"                                                                      "<<jmenonepritele[nepritel]<<"                        \n";
cout<<"_________________________________________________________________________________________________________________________________\n";
         cout<<"     ";             cout << postavyzoobrazeni[vyberobrazupostavy].substr(0, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(0, 15)<<endl;                            
         cout<<"     ";               cout << postavyzoobrazeni[vyberobrazupostavy].substr(16, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(16, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(31, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(31, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(46, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(46, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(61, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(61, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(76, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(76, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(91, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(91, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(106, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(106, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(121, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(121, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(136, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(136, 15)<<endl;
         cout<<"     ";                 cout << postavyzoobrazeni[vyberobrazupostavy].substr(151, 15);cout<<"                                                             ";cout<<nepratelezobrazeni[nepritel].substr(151, 15)<<endl;
cout<<"_________________________________________________________________________________________________________________________________\n\n";

cout<<"          "<<zivoty<<"                                                                         "<<polezivotynepritel[nepritel]<<"          \n";
cout<<"_________________________________________________________________________________________________________________________________\n";

    
} 
void mece(){
cout<<R"(            ||                    ||                    ||                    ||                    ||               )"<<endl;
cout<<R"(          __||___               __||___               __||___               __||___               __||___            )"<<endl;                                    
cout<<R"(           |  |                  |  |                  |  |                  |  |                  |  |              )"<<endl;                                                                                                                 
cout<<R"(           |  |                  |  |                  |  |                  |  |                  |  |              )"<<endl;                              
cout<<R"(          _|  |_                _|  |_                _|  |_                _|  |_                _|  |_             )"<<endl;                                     
cout<<R"(       __|  \/  |__          __|  \/  |__          __|  \/  |__          __|  \/  |__          __|  \/  |__          )"<<endl;                                        
cout<<R"(______|____________|________|____________|________|____________|________|____________|________|____________|_________)"<<endl;
cout<<R"(|           1                     2                      3                     4                     5              |)"<<endl;
cout<<R"(|cena     free                   500                    800                  1200                  1800             |)"<<endl;
cout<<R"(|sila    base+3                 base+8                 base+13              base+18               base+23           |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;

}
void shopy(){
    cout<<"______________________________________________________________________________________________________________\n";
cout<<R"(|       .  .  ___   ___  ___         |.    ..  ..   ___  _   __ ___      / |      _    __   ___        _       |)"<<endl;
cout<<R"(|       |\/| |___  /    |___         | \  /  \/ |  |___ |_| /_ |___ |\ | | |     /_\  |__| |___ |\ |  /_\      |)"<<endl;
cout<<R"(|       |  | |___  \___ |___         |  \/   |  |__|___ |   __/|___ | \| | |    /   \ |  \ |___ | \| /   \     |)"<<endl;
cout<<R"(|              __/|\__               |               __/|\__               |          _______________          |)"<<endl;
cout<<R"(|          ___/*******\___           |           ___/*******\___           |       __/. . * . . . . .\__       |)"<<endl;
cout<<R"(|         /_______________\          |          /_______________\          |    __/..*:::::::::::::::::.\__    |)"<<endl;
cout<<R"(|    ||       | *   * |        ||    |     /\       | *   * |       /\     | __/...*::######@###%######:::.\__ |)"<<endl;
cout<<R"(|  __||____   | \___/ |      __||___ |   _/  \_     | \___/ |     _/  \_   |/...:*:##@%%%%%@%%#%%%@%%@####:::.\|)"<<endl;
cout<<R"(|   |  |       ~~~~~~~        |  |   |  /_    _\     ~~~~~~~     /_    _\  |.:::##@%%%@@@@@@%#@#@%%#@@%%##\:::.|)"<<endl;
cout<<R"(|  _|  |_ ____/|     |\____  _|  |_  |    |  |  ____/|     |\____  |  |    |*::/##%%%#@%@\_-----_/@@@%%%##@:::*|)"<<endl;
cout<<R"(|_|__\/__|_____|_____|______|__\/__|_|____|__|_______|_____|_______|__|____|.:::##@%@%@@@ _\_*_/_ @%#%@%##%:::.|)"<<endl;
cout<<R"(|   |....|\....\      /..../|....|   |    |####|\####\      /####/|####|   |.:::%##%%%@%#/*******\#@@%%%@##:::.|)"<<endl;
cout<<R"(|   |****| \****\    /****/ |****|   |    |@@@@| \@@@@\    /@@@@/ |@@@@|   |*::/###%%@#@%@@%@@@@@%@@%@%%## :::.|)"<<endl;
cout<<R"(|   |::::|  \::::\  /::::/  |::::|   |    |%%%%|  \%%%%\  /%%%%/  |%%%%|   |.:::###%%%%%@%%@%%%#%%%@#%%##@ :::.|)"<<endl;
cout<<R"(|   |%%%%|   \%%%%\/%%%%/   |%%%%|   |    |::::|   \::::\/::::/   |::::|   |.::::::#%##%###@##%###@#%#\:::::...|)"<<endl;
cout<<R"(|   |@@@@|    \@@@@@@@@/    |@@@@|   |    |****|    \********/    |****|   |\__...:*::::::::::::::::::::..* __/|)"<<endl;
cout<<R"(|   |####|     \######/     |####|   |    |....|     \....../     |....|   |   \__.........*.............__/   |)"<<endl;
cout<<R"(|___|____|______\____/______|____|___|____|____|______\____/______|____|___|______\_____________________/______|)"<<endl;
}
void vylepseni(){ 
    uroven=((cenazivoty+cenautok+cenaenergie+cenarychlost)/100)/3;
    cout<<"___________________________________________UROVEN: "<<uroven<<" ___________________________________________________________________________________"<<endl;
cout<<R"(|                                                                                                                   | )"<<endl;           
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    1    ZIVOTY - - -)"<<zivoty<<R"(---->)"<<zivoty+5<<R"(- - - - - - - - - - - -cena:)"<<cenazivoty<<R"(                                       |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    2    UTOK - - - -)"<<utok<<R"(---->)"<<utok+3<<R"(- - - - - - - - - - - - - -cena:)"<<cenautok<<R"(                                         |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    3    ENERGIE- - -)"<<energie<<R"(---->)"<<energie+5<<R"(- - - - - - - - - - - -cena:)"<<cenaenergie<<R"(                                    |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    4     RYCHLOST- )"<<rychlost<<R"(---->)"<<rychlost+3<<R"(- - - - - - - - - - - -cena:)"<<cenarychlost<<R"(                                 |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;

}








random_device rd;
mt19937 gen(rd());//toto je pro generování random čísel
int main(){
    uniform_int_distribution<> sance(1, 100);//toto je také pro generování random čísel
    uniform_int_distribution<> boss(5, 20);
    nepratelezobrazeni[0]="                                                                  .~.           (o~o)           )_(                                                                                                                  ";
    nepratelezobrazeni[1]=R"(                                                    _             [_]            /|\             |             / \                                                                                               )";
    nepratelezobrazeni[2]=R"(                                                   ###           (# #)          {###}           | |           ##|##                                                                                    )";
    nepratelezobrazeni[3]=R"(                                                  /^^^\         (>* *<)         \vvv/           }|{           /   \                                                                                                   )";
    //miniboss
    nepratelezobrazeni[4]=R"(                                   _/|\_         ( o.o )        |=###=|         \ | /          _| |_         |_| |_|                                                                                       )";
    //dvojboj
    nepratelezobrazeni[5]=R"(                                                   /|\___        ( V| . |       |__|___|        | ||||        _| ||||                                                                                                   )";
    nepratelezobrazeni[6]=R"(                                                  ,---.         (  ._.)        |  |T|          \_| /           | |                                                                                            )";
    nepratelezobrazeni[7]=R"(                                    ___           /o o\         / === \       |  ||| |        \_| |_/        /|   |\                                                                                          )";
    nepratelezobrazeni[8]=R"(                                                   /|\           ( V V)         |_|_|           | |           _| |_                                                                                                         )";
    //miniboss
    nepratelezobrazeni[9]=R"(                                  /\   /\       (  o_o  )       \ === /        |{||||}|       | |  | |       |_|  |_|                                                                                       )";
    //trojboj ma 21na radek 
    nepratelezobrazeni[10]=R"(                                                               /Y\    /y\    /Y\  (>o_o<)(>._.<)(>._.<)|=###=||=##=| |=##=|  \ | /  \|/    \|/    _|_|_  _|_    _|_                                                          )";
    nepratelezobrazeni[11]=R"(                                                  .--.          (>~ <)         |~~~~|          \  /            \/                                                                                                           )";
    nepratelezobrazeni[12]=R"(                                                   .-.           (o.o)           |^|            /|\                                                                                                                                                )";
    nepratelezobrazeni[13]=R"(                                                   ___           /o O\         |=###=|         \ | /           |_|                                                                                                                                 )";
    nepratelezobrazeni[14]=R"(                                                   ___           /@ @\         /=###=\        |  |  |        |__|__|                                                                                                                               )";
    //boss
    nepratelezobrazeni[15]=R"(   .-"""-.      /  * *  \     |  (o_o)  |    |  \___/  |     \ ||||| /      |_|||||_|     |  |||  |     /| .|.|. |\    |||||||||      |__|_|__|       |_| |_|                                                                                   )";
    postavyzoobrazeni[0]=R"(                                                   [+]           (o_o)          ]|+|[          /| |\         |_| |_|                                                                                                                               )";
    postavyzoobrazeni[1]=R"(                                                   /^\           (*.*)           )|(            /|\           (_|_)                                                                                                                                   )";
    postavyzoobrazeni[2]=R"(                                                  _,,,_          (^-^)          /|o|\           | |           /| |\                                                                                                                           )";
    postavyzoobrazeni[3]=R"(                                                  .,o,.          (>.<)          |}|{|           \|/           _/|\_                                                                                                                    )";
    do{
    do{
    cout<<"Na vyber mate 4 postavy:\n1-Rytir\n2-Carodej\n3-Lovec\n4-Assasin";
    cout << "\nJakou postavu chcete zobrazit: ";
    cin >> nahled;
    }while(nahled!=1&&nahled!=2&&nahled!=3&&nahled!=4);
    if(nahled==1) {
        cout<<"HP:150";
        cout<<"\nBasic utok:35";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:5";
        cout<<"\nSuper utok:36";
        zivotymax=150;
        zivoty=150;
        utok=35;
        superutok=2*utok;
        brneni=15;
        rychlost=5;
    }else if(nahled==2){
        cout<<"HP:80";
        cout<<"\nBasic utok:56";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:10";
        cout<<"\nSuper utok:64";
        zivotymax=80;
        zivoty=80;
        utok=56;
        superutok=2*utok;
        brneni=2;
        rychlost=10;
    }else if(nahled==3){
        cout<<"HP:110";
        cout<<"\nUtok:41";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:15";
        cout<<"\nSuper utok:60";
        zivoty=110;
        zivotymax=110;
        utok=41;
        superutok=2*utok;
        brneni=7;
        rychlost=15;
    }else if(nahled==4){
        cout<<"HP:90";
        cout<<"\nUtok:65";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:25";
        cout<<"\nSuper utok:110";
        zivoty=90;
        zivotymax=90;   
        utok=57;
        superutok=2*utok;
        brneni=4;
        rychlost=25;

    }
    cout<<"\nChcete tuto postavu pouzit? 1-ano 2-ne";
    cin>>vyber;
    vyberobrazupostavy=nahled-1;
    }while(vyber!=1);
    if(nahled==1) {
        jmenopostavy="Rytir";
    }else if(nahled==2){
        jmenopostavy="Carodej";
    }else if(nahled==3){
        jmenopostavy="Lovec";
    }else if(nahled==4){
        jmenopostavy="Assasin";
    }
    cout<<"\nVybrali jste postavu: "<<jmenopostavy<<"\n";
    cout<<"Vase staty jsou:\nZivoty: "<<zivoty<<"\nUtok: "<<utok<<"\nBrneni: "<<brneni<<"\nRychlost: "<<rychlost<<"\n";
    cout<<"Vase penize jsou: "<<penize<<"\n";

    cout<<"tohle je obchod kde muzete nakupovat vylepseni pro vasi postavu a nebo lepsi vybaveni, zbrane kupujte poporade \n";
    cout<<"vlevo se da koupit lepsi vybaveni uprostre se daji koupit vylepseni postavy a v pravo je arena kde se\n";
    cout<<"uskutecni vsecny vase boje s nepratelskymi monstry\n";

do{
shopy();
do{
cout<<"Do jakeho obchodu nebo areny chcete jit?\n1-Obchod se zbranemi\n2-Obchod s vylepsenim\n3-Arena\n";
cin>>volbaobchod;
}while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3);
if (volbaobchod==1){
    mece();

    do{
    cout<<"Vase penize jsou: "<<penize<<"\n";
    cout<<"Jaky mec si chcete koupit? \nvas level mece je "<<levelmece+1<<" \n6- nechci kupovat zadny\nVas vyber: ";
    cin>>volbaobchod;
    }while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3&&volbaobchod!=4&&volbaobchod!=5&&volbaobchod!=6);
     if(volbaobchod==1&&penize>=0){
        cout<<"Koupili jste zbran level 1\n";
        utok=utok+pomocnapromena1;
        pomocnapromena1=0;
        superutok=2*utok;
        penize=penize-0;    

    }else if(volbaobchod==2&&penize>=500&&levelmece==0){
        cout<<"Koupili jste zbran level 2\n";
        utok=utok+pomocnapromena2;
        pomocnapromena2=0;
        penize=penize-500;
        levelmece=1;
        superutok=2*utok;
    }else if(volbaobchod==3&&penize>=800&&levelmece==1){
        cout<<"Koupili jste zbran level 3\n";
        utok=utok+pomocnapromena3;
        pomocnapromena3=0;
        penize=penize-800;
        levelmece=2;
        superutok=2*utok;   
    }else if(volbaobchod==4&&penize>=1200&&levelmece==2){
        cout<<"Koupili jste zbran level 4\n";
        utok=utok+pomocnapromena4;
        pomocnapromena4=0;
        penize=penize-1200;
        levelmece=3;
        superutok=2*utok;
    }else if(volbaobchod==5&&penize>=1800&&levelmece==3){
        cout<<"Koupili jste zbran level 5\n";   
        utok=utok+pomocnapromena5;
        pomocnapromena5=0;
        penize=penize-1800;
        levelmece=4;
        superutok=2*utok;
    }  
    if(volbaobchod==6){
        volbaobchodne=1;
    }  
    
}else if(volbaobchod==2){
    vylepseni();
    do{
    cout<<"vase penize jsou: "<<penize<<"\n";
    cout<<"jake vylepseni si chcete koupit pro vasi postavu?\n1-Zivoty\n2-Utok\n3-Brneni\n4-Rychlost\n5-Nechci nic kupovat\n";
    cin>>volbaobchod;
    }while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3&&volbaobchod!=4&&volbaobchod!=5);
    if(volbaobchod==1&&penize>=cenazivoty){
        cout<<"Koupili jste vylepseni zivotu";
        zivoty=zivoty+5;
        zivotymax=zivotymax+5;
        penize=penize-cenazivoty;
        cenazivoty=cenazivoty+100;
    }else if(volbaobchod==2&&penize>=cenautok){
        cout<<"Koupili jste vylepseni utoku";
        utok=utok+3;
        penize=penize-cenautok;
        cenautok=cenautok+100;
        superutok=2*utok;
    }else if(volbaobchod==3&&penize>=cenaenergie){
        cout<<"Koupili jste vylepseni energie";
        energiemax=energiemax+5;
        energie=energiemax;
        penize=penize-cenaenergie;
        cenaenergie=cenaenergie+100;
    }else if(volbaobchod==4&&penize>=cenarychlost){
        cout<<"Koupili jste vylepseni rychlosti";
        rychlost=rychlost+3;
        penize=penize-cenarychlost;
        cenarychlost=cenarychlost+100;
    }else if(volbaobchod==5){
        volbaobchodne=1;
    }
}else if(volbaobchod==3){

    cout<<"Vytejte v arene.\n";
    cout<<"Budou taby probihat boje s neprately, pokud vyhrajete ziskate penize ale pokud prohrajete je pro vas game over\n";
    cout<<"a budete muset zacit hru odznova.\n";
    cout<<"------------------------------------------------\n";
    cout<<"------------------------------------------------\n";
    cout<<"Staty vaseho "<<nepritel+1<<" nepritele:\n";
    cout<<"Zivoty: "<<polezivotynepritel[nepritel]<<"\nUtok: "<<poleutoknepritel[nepritel]<<"\nSuper utok: "<<polesuperutoknepritel[nepritel]<<"\nOdmena: "<<poleodmenanepritel[nepritel]<<"\n";
    cout<<"------------------------------------------------\n";
    cout<<"------------------------------------------------\n";
    cout<<"Vase staty jsou:\nZivoty: "<<zivoty<<"\nUtok: "<<utok<<"\nBrneni: "<<brneni<<"\nRychlost: "<<rychlost<<"\nEnergie: "<<energie<<"\n"<<"Uroven: "<<uroven<<"\n";
    cout<<"------------------------------------------------\n";
    cout<<"------------------------------------------------\n";
    cout<<"Chcete spustit boj s nepritelem? 1-ano 2-ne";
    cin>>volbaobchod;
    if(volbaobchod==1&&nepritel!=4&&nepritel!=9&&nepritel!=15&&nepritel!=5&&nepritel!=10){
        cout<<"Boj se spustil.\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        do{
        boj();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"vase energie je: "<<energie<<"\n";  
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            energie=energie-1;
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                 //udelat aby mi to pridv     
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                
            }


        }else if(volbaobchod==2&&energie>=3){
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            energie=energie-3;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                         
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                
            }

        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
        if(volbaobchod!=3){
            zivoty=zivotymax;
            nepritel=nepritel+1;
            energie=energiemax;

        }else if (volbaobchod==3){
            zivoty=zivotymax;
            polezivotynepritel[nepritel]=polezivotynepritelmax[nepritel];
            energie=energiemax;
        }
    }else if(volbaobchod==1&&nepritel==4||nepritel==9){
        cout<<"boj se spustil.\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Vas protivník je mini-boss nebo boss tim padem zacina on a je o neco silnejsi nez ostatni nepratele\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        boj();
        randomcislo=sance(gen);
        if(randomcislo<=rychlost){
            boj();
            this_thread::sleep_for(chrono::milliseconds(500));
            cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
        }else if(randomcislo>rychlost){
        boj();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        zivoty=zivoty-poleutoknepritel[nepritel];
        }
        do{
        boj();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"vase energie je: "<<energie<<"\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            boj();
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            energie=energie-1;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                       
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==2&&energie>=3){
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            boj();
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            energie=energie-3;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                     cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(500));
                     zivoty=zivoty-poleutoknepritel[nepritel];                                
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
        if(volbaobchod!=3){
            zivoty=zivotymax;
            nepritel=nepritel+1;
            energie=energiemax;
        }else if (volbaobchod==3){
            zivoty=zivotymax;
            polezivotynepritel[nepritel]=polezivotynepritelmax[nepritel];
            energie=energiemax;
        }


    }else if(nepritel==5){
        cout<<"Boj se spustil.\n";
        do{
        bojdva();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"vase energie je: "<<energie<<"\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            cout<<"na jakeho nepritele chcete zautocit: \n1-"<<jmenonepritele[nepritel]<<" 2-"<<jmenonepriteledvojboj[nepritel]<<"\n";
            cin>>volbaobchod;
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            energie=energie-1;
            if(volbaobchod==1){
                polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            }else if(volbaobchod==2){
                polezivotyprodvojboj[nepritel]=polezivotyprodvojboj[nepritel]-utok;
            }
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                    //udelat aby mi to pridv     
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0&&polezivotyprodvojboj[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }


        }else if(volbaobchod==2&&energie>=3){
            bojdva();
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            polezivotyprodvojboj[nepritel]=polezivotyprodvojboj[nepritel]-superutok;
            energie=energie-3;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";   
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                         
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
        if(volbaobchod!=3){
            zivoty=zivotymax;
            nepritel=nepritel+1;
            energie=energiemax;
        }else if (volbaobchod==3){
            zivoty=zivotymax;
            energie=energiemax;
            polezivotynepritel[nepritel]=polezivotynepritelmax[nepritel];
        }

    }else if(nepritel==10){
        cout<<"Boj se spustil.\n";
        do{
        bojtri();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"vase energie je: "<<energie<<"\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            cout<<"na jakeho nepritele chcete zautocit: \n1-"<<jmenonepritele[nepritel]<<" 2-"<<jmenonepriteledvojboj[nepritel]<<" 3-"<<jmenonepriteletrojboj[nepritel]<<"\n";
            cin>>volbaobchod;
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            energie=energie-1;
            if(volbaobchod==1){
                polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            }else if(volbaobchod==2){
                polezivotyprodvojboj[nepritel]=polezivotyprodvojboj[nepritel]-utok;
            }else if(volbaobchod==3){
                polezivotyprotrojboj[nepritel]=polezivotyprotrojboj[nepritel]-utok;
            }
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                     
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprotrojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"\nProhrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0&&polezivotyprodvojboj[nepritel]<=0&&polezivotyprotrojboj[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }


        }else if(volbaobchod==2&&energie>=3){;
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            polezivotyprodvojboj[nepritel]=polezivotyprodvojboj[nepritel]-superutok;
            polezivotyprotrojboj[nepritel]=polezivotyprotrojboj[nepritel]-superutok;
            energie=energie-3;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";   
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                         
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotyprotrojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0&&polezivotyprodvojboj[nepritel]<=0&&polezivotyprotrojboj[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
        if(volbaobchod!=3){
            zivoty=zivotymax;
            nepritel=nepritel+1;
            energie=energiemax;
        }else if (volbaobchod==3){
            zivoty=zivotymax;
            polezivotynepritel[nepritel]=polezivotynepritelmax[nepritel];
            energie=energiemax;
        }

    }else if(volbaobchod==1&&nepritel==15){
        cout<<"boj se spustil.\n";
        cout<<"Vas protivník je mini-boss nebo boss tim padem zacina on a je o neco silnejsi nez ostatni nepratele\n";
        boj();
        randomcislo=sance(gen);
        if(randomcislo<=rychlost){
            boj();
            this_thread::sleep_for(chrono::milliseconds(500));
            cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
        }else if(randomcislo>rychlost){
            boj();
            this_thread::sleep_for(chrono::milliseconds(500));
            int utokboss=0;
            utokboss=0;
            for(int i=0;i<uroven;i++){
                utokboss=utokboss+boss(gen);
            }
            cout<<"nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            zivoty=zivoty-utokboss;
        }
        do{
        boj();
        cout<<"vase energie je: "<<energie<<"\n";
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            energie=energie-1;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    int utokboss=0;
                    for(int i=0;i<uroven;i++){
                        utokboss=utokboss+boss(gen);
                    }
                    cout<<"Nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-utokboss;                                       
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==2&&energie>=3){
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(500));
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            energie=energie-3;
            if(polezivotynepritel[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    int utokboss=0;
                    for(int i=0;i<uroven;i++){
                        utokboss=utokboss+boss(gen);
                    }
                    cout<<"Nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    zivoty=zivoty-utokboss;
                    if(zivoty<=0){
                        cout<<"Prohrali jste a je konec hry\n";
                        return 0;
                    }
                }
            }else if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
            }

        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
        if(volbaobchod!=3){
            zivoty=zivotymax;
            nepritel=nepritel+1;
            energie=energiemax;
        }else if (volbaobchod==3){
            zivoty=zivotymax;
            polezivotynepritel[nepritel]=polezivotynepritelmax[nepritel];
            energie=energiemax;
        }


    }

       
    
}
}while(zivoty>0&&nepritel<16);
cout<<"Gratulujeme, porazili jste vsechny nepratele a vyhrali jste hru\n";
}

        //pridavani energie ukazovani enrgie a cim vetsi rychlost tim vetsi moznost na uhnuti pred 
        //nepritelem a kdyz tam budou dva neprateletak to dodelat a vymislet k cemu bude brneni a grafiku
        //kdyz tam budou dva tak udelat dalsi if k tomu jak jsou bossove a mini bosove tak za ne udelak kdyz tam bude treba
        //nepritel 5 a nebo 10 tak tam udelat misto jednich zivotu dva a super utok bude pridavat oboum a budu si
        //muset vybrat na jakeho chci utocit a v stringu jen misto jendoho jmena tam dam dva hned za sebe

