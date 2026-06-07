#include <iostream>
#include <random>//pro generování random čísel
#include <string> //je to proto abych mohl rozdělit string pro vypsání postavyček
#include <thread> //je to pro to aby program chvíli čekal
#include <chrono> 
//_____________________________________Zahrajte si to v VS Code_________________________________________________________ 
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
int pomocnapromena1=7;
int pomocnapromena2=14;
int pomocnapromena3=21;
int pomocnapromena4=28;
int pomocnapromena5=35;
int penize=500;
string jmenopostavy;
string zbran;
int nahled;
int vyber;
int volbaobchod;
int volbaobchodne=0; 
string jmenonepritele[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Upir","Zombik","Obr","Vampir","Drak","Minotaur","Mumie","Kobold","Ork","Troll","Ascendrax"};
string jmenonepriteledvojboj[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Papir","Zombik","Obr","Vampir","Drak","Piditoraur","Mumie","Kobold","Ork","Troll","Ascendrax"};
string jmenonepriteletrojboj[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Upir","Zombik","Obr","Vampir","Drak","Sinotaur","Mumie","Kobold","Ork","Troll","Ascendrax"};
int polezivotynepritel[16] = {485,540,595,650,654,710,700,780,725,775,750,795,810,830,850,1000};
int polezivotyprodvojboj[16] = {485,540,595,650,654,710,700,780,725,775,750,795,810,830,850,1000};
int polezivotyprotrojboj[16] = {485,540,595,650,654,710,700,780,725,775,750,795,810,830,850,1000};
//int polezivotyprodvojboj[16] = {400,450,500,550,550,600,650,660,705,705,750,795,810,830,850,1000};ted to fungovalo
int polezivotynepritelmax[16] = {485,540,595,650,654,710,700,780,725,775,750,795,810,830,850,1000};
int poleutoknepritel[16] = {10,15,20,23,20,23,27,31,35,39,43,47,48,50,53,57};
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
void gameover(){
   cout<<R"(                                                                                )"<<endl;
     cout<<R"(                                                                                )"<<endl;
cout<<R"(    ####   #####  ## ##  #####    #####  #   #  #####  #####                   )"<<endl;
cout<<R"(   #       #   #  ## ##  #        #   #  #   #  #      #   #                  )"<<endl;
cout<<R"(   # ###   #####  # # #  ###      #   #  #   #  ###    ####                   )"<<endl;
cout<<R"(   #   #   #   #  #   #  #        #   #   # #   #      # #                    )"<<endl;
cout<<R"(    ####   #   #  #   #  #####    #####    #    #####  #   #                   )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                            /~\                                                 )"<<endl;
cout<<R"(                           | RIP |                                              )"<<endl;
cout<<R"(                           |     |                                              )"<<endl;
cout<<R"(                         __|_____|__                                            )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(            Padli jste v boji... Vase dobrodruzstvi zde konci.                 )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
}
void gamewon(){
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(       #         #  ###  ##    #  ##    #  #####  ####                          )"<<endl;
cout<<R"(       #         #   #   # #   #  # #   #  #      #   #                         )"<<endl;
cout<<R"(        #   #   #    #   #  #  #  #  #  #  ###    ####                          )"<<endl;
cout<<R"(         # # # #     #   #   # #  #   # #  #      # #                           )"<<endl;
cout<<R"(          #   #     ###  #    ##  #    ##  #####  #  #                          )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(    ####   #####  ## ##  #####   #   # #   #  #####  ##    #                    )"<<endl;
cout<<R"(   #       #   #  ## ##  #       #   # #   #  #   #  # #   #                    )"<<endl;
cout<<R"(   # ###   #####  # # #  ###      #   #   #   #   #  #  #  #                    )"<<endl;
cout<<R"(   #   #   #   #  #   #  #         # # # #    #   #  #   # #                    )"<<endl;
cout<<R"(    ####   #   #  #   #  #####      #   #     #####  #    ##                    )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(              *        *        *        *        *        *                    )"<<endl;
cout<<R"(           \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/ \o/                      )"<<endl;
cout<<R"(            |   |   |   |   |   |   |   |   |   |   |   |                       )"<<endl;
cout<<R"(           / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \                      )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(          Gratulujeme! Porazili jste vsechny nepratele a zachranili svet!       )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;
cout<<R"(                                                                                )"<<endl;                            
}
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
cout<<R"(|cena     free                   500                    600                  650                  700             |)"<<endl;
cout<<R"(|sila    base+7                 base+14                 base+21              base+28              base+35           |)"<<endl;
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
    cout<<"___________________________________________UROVEN: "<<uroven<<" ____________________________________________________"<<endl;
cout<<R"(|                                                                                                                   | )"<<endl;           
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    1    ZIVOTY - - -)"<<zivoty<<R"(---->)"<<zivoty+12<<R"(- - - - - - - - - - - -cena:)"<<cenazivoty<<R"(                            )"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    2    UTOK - - - -)"<<utok<<R"(---->)"<<utok+5<<R"(- - - - - - - - - - - - - -cena:)"<<cenautok<<R"(                                  )"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    3    ENERGIE- - -)"<<energie<<R"(---->)"<<energie+2<<R"(- - - - - - - - - - - -cena:)"<<cenaenergie<<R"(                           )"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|    4     RYCHLOST- )"<<rychlost<<R"(---->)"<<rychlost+3<<R"(- - - - - - - - - - - -cena:)"<<cenarychlost<<R"(                            )"<<endl;
cout<<R"(|                                                                                                                   |)"<<endl;
cout<<R"(|___________________________________________________________________________________________________________________|)"<<endl;

}








random_device rd;
mt19937 gen(rd());//toto je pro generování random čísel
int main(){
    //nepritel=nepritel+11;
    //penize=penize+110+150+190+230+270+310+350+390+430+470+510;
    cout<<"Vitejte ve hre!\nVteto hre budete se svym hrdinou bojovat proti nepratelum.\nCeka vas 16 nepratelz toho jsou 2 minibossove, jeden boj s dvema neprateli a jeden boj proti 3 nepratelum.\n";
    cout<<"Nakonec se utkate s bossem Ascendraxem. Kazdy nepritel bude silnejsi nez ten predchozi \na dostanete za nej i lepsi odmenu.";
    cout<<"vas hrdina bude mit 4 atributy: zivoty, utok, energie a rychlost.\nKazdy atribut muzete vylepsovat a tim se vam zvysi uroven a budete mit lepsi sanci na vitezstvi.\n";
    cout<<"rychlos znaci jakou mate sanci na to ze se vyhnete utoku nepratele, enrgie se pouziva pro utok a superutok,\nzivoty jsou vase zdraví a utok je kolik poskozeni udelate neprateli.\n";
    cout<<"po kazdem boji budete moci nastivit obchody s vylepsenim a nakoupit lepsi zbran nebo vylepsit sve atributy.\n";
    cout<<"Pri koupi mecu si je kupujte od 1 do 5 pokud mate 1 a koupite si 3 nepujde to.";
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
        cout<<"HP:160";
        cout<<"\nBasic utok:35";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:5";
        cout<<"\nSuper utok:70";
        zivotymax=160;
        zivoty=160;
        utok=35;
        superutok=2*utok;
        energie=16;
        rychlost=5;
    }else if(nahled==2){
        cout<<"HP:95";
        cout<<"\nBasic utok:50";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:10";
        cout<<"\nSuper utok:100";
        zivotymax=95;
        zivoty=95;
        utok=50;
        superutok=2*utok;
        energie=16;
        rychlost=10;
    }else if(nahled==3){
        cout<<"HP:125";
        cout<<"\nUtok:42";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:15";
        cout<<"\nSuper utok:84";
        zivoty=125;
        zivotymax=125;
        utok=42;
        superutok=2*utok;
        energie=16;
        rychlost=15;
    }else if(nahled==4){
        cout<<"HP:100";
        cout<<"\nUtok:47";
        cout<<"\nEnergie:16";
        cout<<"\nRychlost:18";
        cout<<"\nSuper utok:94";
        zivoty=100;
        zivotymax=100;   
        utok=47;
        superutok=2*utok;
        energie=16;
        rychlost=18;

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
    }else if(volbaobchod==3&&penize>=600&&levelmece==1){
        cout<<"Koupili jste zbran level 3\n";
        utok=utok+pomocnapromena3;
        pomocnapromena3=0;
        penize=penize-600;
        levelmece=2;
        superutok=2*utok;   
    }else if(volbaobchod==4&&penize>=650&&levelmece==2){
        cout<<"Koupili jste zbran level 4\n";
        utok=utok+pomocnapromena4;
        pomocnapromena4=0;
        penize=penize-650;
        levelmece=3;
        superutok=2*utok;
    }else if(volbaobchod==5&&penize>=700&&levelmece==3){
        cout<<"Koupili jste zbran level 5\n";   
        utok=utok+pomocnapromena5;
        pomocnapromena5=0;
        penize=penize-700;
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
        zivoty=zivoty+12;
        zivotymax=zivotymax+12;
        penize=penize-cenazivoty;
        cenazivoty=cenazivoty+100;
    }else if(volbaobchod==2&&penize>=cenautok){
        cout<<"Koupili jste vylepseni utoku";
        utok=utok+5;
        penize=penize-cenautok;
        cenautok=cenautok+100;
        superutok=2*utok;
    }else if(volbaobchod==3&&penize>=cenaenergie){
        cout<<"Koupili jste vylepseni energie";
        energiemax=energiemax+2;
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
    if(nepritel!=15){
        cout<<"Zivoty: "<<polezivotynepritel[nepritel]<<"\nUtok: "<<poleutoknepritel[nepritel]<<"\nOdmena: "<<poleodmenanepritel[nepritel]<<"\n";
    }else if (nepritel==15){
        cout<<"Zivoty: "<<polezivotynepritel[nepritel]<<"\nUtok:? \nOdmena: "<<poleodmenanepritel[nepritel]<<"\n";
    }
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                 //udelat aby mi to pridv     
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                         
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
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
    }else if(volbaobchod==1&&(nepritel==4||nepritel==9)){
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
            this_thread::sleep_for(chrono::milliseconds(1500));
        }else if(randomcislo>rychlost){
        boj();
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
        this_thread::sleep_for(chrono::milliseconds(1500));
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                       
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                     cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(500));
                     zivoty=zivoty-poleutoknepritel[nepritel];                                
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
            do{
            cout<<"na jakeho nepritele chcete zautocit: \n1-"<<jmenonepritele[nepritel]<<" 2-"<<jmenonepriteledvojboj[nepritel]<<"\n";
            cin>>volbaobchod;
            }while(volbaobchod!=1&&volbaobchod!=2);
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                    //udelat aby mi to pridv     
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
                    this_thread::sleep_for(chrono::milliseconds(1500));  
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                         
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojdva();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
            do{
            cout<<"na jakeho nepritele chcete zautocit: \n1-"<<jmenonepritele[nepritel]<<" 2-"<<jmenonepriteledvojboj[nepritel]<<" 3-"<<jmenonepriteletrojboj[nepritel]<<"\n";
            cin>>volbaobchod;
            }while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3);
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                     
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprotrojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];                                         
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprodvojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
                        return 0;
                    }
                }
            }else if(polezivotyprotrojboj[nepritel]>0){
                randomcislo=sance(gen);
                if(randomcislo<=rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel zautocil ale minul vas a neudelal vam zadne skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    bojtri();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout<<"Nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-poleutoknepritel[nepritel];
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
            this_thread::sleep_for(chrono::milliseconds(1500));
        }else if(randomcislo>rychlost){
            boj();
            this_thread::sleep_for(chrono::milliseconds(500));
            int utokboss=0;
            utokboss=0;
            for(int i=0;i<uroven;i++){
                utokboss=utokboss+boss(gen);
            }
            cout<<"nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
            this_thread::sleep_for(chrono::milliseconds(1500));
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    int utokboss=0;
                    for(int i=0;i<uroven;i++){
                        utokboss=utokboss+boss(gen);
                    }
                    cout<<"Nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-utokboss;                                       
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }else if(randomcislo>rychlost){
                    boj();
                    this_thread::sleep_for(chrono::milliseconds(500));
                    int utokboss=0;
                    for(int i=0;i<uroven;i++){
                        utokboss=utokboss+boss(gen);
                    }
                    cout<<"Nepritel na vas zautocil a udelal vam "<<utokboss<<" skody\n";
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    zivoty=zivoty-utokboss;
                    if(zivoty<=0){
                        gameover();
                        return 0;
                    }else if(zivoty>0&&energie<=0){
                        cout<<"Umreli ste na vycerpani\n";
                        gameover();
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
cout<<"\n\nGratulujeme, porazili jste vsechny nepratele a vyhrali jste hru\n";
gamewon();
}

