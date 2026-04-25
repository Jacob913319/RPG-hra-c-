#include <iostream>
using namespace std;
void mece(){
cout<<"             |                     |                     |                     |                     |       ";
cout<<"          ___|___               ___|___               ___|___               ___|___               ___|___ \n";                                    
cout<<"           |  |                  |  |                  |  |                  |  |                  |  |    \n";                                                                                                                 
cout<<"           |  |                  |  |                  |  |                  |  |                  |  |    \n";                              
cout<<"          _|  |_                _|  |_                _|  |_                _|  |_                _|  |_    \n";                                     
cout<<"       __|  ˇˇ  |__          __|  ˇˇ  |__          __|  ˇˇ  |__          __|  ˇˇ  |__          __|  ˇˇ  |__  \n";                                        
cout<<"______|____________|________|____________|________|____________|________|____________|________|____________|_________\n";
cout<<"|           1                     2                      3                     4                     5              | \n";
cout<<"|cena     free                   500                    800                  1200                  1800             | \n";
cout<<"|sila    base+3                 base+8                 base+13              base+18               base+23           | \n";
cout<<"|                                                                                                                   | \n";
cout<<"|                                                                                                                   | \n";

}
void shopy(){
    cout<<"_______________________________________________________________________________________________________________\n";
cout<<"|   |  | |                            |                                     |                                   |\n";
cout<<"|   |  | |                            |                                     |                                   |\n";
cout<<"|   |  | |                            |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
cout<<"|                                     |                                     |                                   |\n";
}
//void vylepseni(){ 
//    cout<<"______________________________________________________________________________________________________________________\n";
//cout<<"|                                                                                                                   | \n";           
//cout<<"|                                                                                                                   |\n";
//cout<<"|    1    ZIVOTY - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<zivoty<<"----D"<<zivoty+5<<"    |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|___________________________________________________________________________________________________________________|\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|    2    UTOK- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<utok<<"----D"<<utok+3<<"      |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|___________________________________________________________________________________________________________________|\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|    3    BRNENI- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<brneni<<"----D"<<brneni+3<<"  |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|___________________________________________________________________________________________________________________|\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|    4     RYCHLOST- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "rychlost<<"----D"<<rychlost+3<<"|\n";
//cout<<"|                                                                                                                   |\n";
//cout<<"|___________________________________________________________________________________________________________________|\n";

//}
                                //dokoncit tutorialy a udelat funkční shop a pak se pustit do arény kde se bude bojovat s monstry 
                                 //pokud si clovek koupi lepsi mec tak musi kupovat vsechny za radou 









int main(){
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
    int zivoty;
    int utok;
    int brneni;
    int rychlost;
    do{
    do{
    cout<<"Na vyber mate 4 postavy:\n1-Rytir\n2-Carodej\n3-Lovec\n4-Assasin";
    cout << "\nJakou postavu chcete zobrazit: ";
    cin >> nahled;
    }while(nahled!=1&&nahled!=2&&nahled!=3&&nahled!=4);
    if(nahled==1) {
        cout<<"HP:150";
        cout<<"\nBasic utok:25";// dodelat jeste superutok ktery bude stat vice energie 
        cout<<"\nBrneni:15";
        cout<<"\nRychlost:5";
        zivoty=150;
        utok=25;
        brneni=15;
        rychlost=5;
    }else if(nahled==2){
        cout<<"HP:80";
        cout<<"\nBasic utok:45";
        cout<<"\nBrneni:2";
        cout<<"\nRychlost:10";
        zivoty=80;
        utok=45;
        brneni=2;
        rychlost=10;
    }else if(nahled==3){
        cout<<"HP:110";
        cout<<"\nUtok:30";
        cout<<"\nBrneni:7";
        cout<<"\nRychlost:15";
        zivoty=110;
        utok=30;
        brneni=7;
        rychlost=15;
    }else if(nahled==4){
        cout<<"HP:90";
        cout<<"\nUtok:55";
        cout<<"\nBrneni:4";
        cout<<"\nRychlost:25";
        zivoty=90;
        utok=55;
        brneni=4;
        rychlost=25;

    }
    cout<<"\nChcete tuto postavu pouzit? 1-ano 2-ne";
    cin>>vyber;
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
    cout<<"Vase zbran je: "<<zbran<<"\n";

    cout<<"tohle je obchod kde muzete nakupovat vylepseni pro vasi postavu a nebo lepsi vybaveni\n";
    cout<<"vlevo se da koupit lepsi vybaveni uprostre se daji koupit vylepseni postavy a v pravo je arena kde se\n";
    cout<<"uskutecni vsecny vase boje s nepratelskymi monstry\n";
    shopy();

if(nahled==1) {
    do{
    cout<<"Jdete a kupte si prvni mec kliknutim 1 vas dostane do obchodu se zbranemi;";
    cin>>volbaobchod;
    }while(volbaobchod!=1);
    do{
    mece();
    cout<<"Pred sebou vidite 5 mecu i s cenami vyberte ten nejlevnější kliknete 1: ";
    cin>>volbaobchod;
    }while(volbaobchod!=1);
    do{
    shopy();
    cout<<"Tedka si muzete jit koupit vylepseni pro vasi postavu kliknutim 2: ";
    cin>>volbaobchod;
    }while(volbaobchod!=2);
    vylepseni();                           //u stranky vylepseni je potreba vyresit to ze ty promene jeste nejsou definovane;



}// tohle je program shopu a pri koupi mece 
//do{tohle je to do
shopy();
do{
cout<<"Do jakého obchodu nebo areny chcete jit?\n1-Obchod se zbranemi\n2-Obchod s vylepsenim\n3-Arena\n";
cin>>volbaobchod;
}while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3);
if (volbaobchod==1){
    mece();
    cout<<"Chcete si koupit mec? 1-ano 2-ne";
    cin>>volbaobchod;
  //}while(volbaobchod==2);//tohle by melo byt k tomu prvnimu do{ale nechce se to propojit dodelat to ;
    if(volbaobchod==1){
        cout<<"Jaky mec si chcete koupit?";
        cin>>volbaobchod;
        if(volbaobchod==1&&penize>0){
            cout<<"Koupili jste zbran level 1";
            utok=utok+pomocnapromena1;
            pomocnapromena1=0;

        }else if(volbaobchod==2&&penize>500){
            cout<<"Koupili jste zbran level 2";
            utok=utok+pomocnapromena2;
            pomocnapromena2=0;
        }else if(volbaobchod==3&&penize>800){
            cout<<"Koupili jste zbran level 3";
            utok=utok+pomocnapromena3;
            pomocnapromena3=0;
        }else if(volbaobchod==4&&penize>1200){
            cout<<"Koupili jste zbran level 4";
            utok=utok+pomocnapromena4;
            pomocnapromena4=0;
        }else if(volbaobchod==5&&penize>1800){
            cout<<"Koupili jste zbran level 5";   
            utok=utok+pomocnapromena5;
            pomocnapromena5=0;
        }  
        if(volbaobchod==2){
            volbaobchodne=1;
        }  
    
        
    }
    if (volbaobchod==2){
        vylepseni();
    }
}
}
        
