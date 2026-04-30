#include <iostream>
using namespace std;
int nepritel=0;
int energie=10;
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
string jmenonepritele[16]={"Slizoun","Kostlivec","Golem","Vlkodlak","Demon","Upir","Zombik","Obr","Vampir","Drak","Minotaur","Mumie","Kobold","Ork","Troll","Ghoul"};
int polezivotynepritel[16] = {100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};
int poleutoknepritel[16] = {10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85};
int polesuperutoknepritel[16] = {20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170};
int poleodmenanepritel[16] = {110,150,190,230,270,310,350,390,430,470,510,550,590,630,670,710};
int levelmece=0;
int utok;
int brneni;
int rychlost;
int cenazivoty=100;
int cenautok=100;
int cenabrneni=100;
int cenarychlost=100;    
void boj(){
 cout<<"________________________________________________________________________________________________________________________________\n\n";

cout<<"         "<<jmenopostavy<<"                                                         "<<jmenonepritele[nepritel]<<"                        \n";
cout<<"_________________________________________________________________________________________________________________________________\n\n\n\n\n\n\n\n\n\n\n";











cout<<"_________________________________________________________________________________________________________________________________\n\n";

cout<<"        "<<zivoty<<"                                                                 "<<polezivotynepritel[nepritel]<<"          \n";
cout<<"_________________________________________________________________________________________________________________________________";

    
} 
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
void vylepseni(){ 
    cout<<"______________________________________________________________________________________________________________________\n";
cout<<"|                                                                                                                   | \n";           
cout<<"|                                                                                                                   |\n";
cout<<"|    1    ZIVOTY - - -"<<zivoty<<"----D"<<zivoty+5<<"- - - - - - - - - - - -cena:"<<cenazivoty<<"                  |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|___________________________________________________________________________________________________________________|\n";
cout<<"|                                                                                                                   |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|    2    UTOK - - - -"<<utok<<"----D"<<utok+3<<"- - - - - - - - - - - - - -cena:"<<cenautok<<"                     |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|___________________________________________________________________________________________________________________|\n";
cout<<"|                                                                                                                   |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|    3    BRNENI- - -"<<brneni<<"----D"<<brneni+3<<"- - - - - - - - - - - -cena:"<<cenabrneni<<"                    |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|___________________________________________________________________________________________________________________|\n";
cout<<"|                                                                                                                   |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|    4     RYCHLOST- "<<rychlost<<"----D"<<rychlost+3<<"- - - - - - - - - - - -cena:"<<cenarychlost<<"              |\n";
cout<<"|                                                                                                                   |\n";
cout<<"|___________________________________________________________________________________________________________________|\n";

}
                                //dokoncit tutorialy a udelat funkční shop a pak se pustit do arény kde se bude bojovat s monstry 
                                 //pokud si clovek koupi lepsi mec tak musi kupovat vsechny za radou 









int main(){
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
        cout<<"\nSuper utok:50";
        zivoty=150;
        utok=25;
        superutok=2*utok;
        brneni=15;
        rychlost=5;
    }else if(nahled==2){
        cout<<"HP:80";
        cout<<"\nBasic utok:45";
        cout<<"\nBrneni:2";
        cout<<"\nRychlost:10";
        cout<<"\nSuper utok:90";
        zivoty=80;
        utok=45;
        superutok=2*utok;
        brneni=2;
        rychlost=10;
    }else if(nahled==3){
        cout<<"HP:110";
        cout<<"\nUtok:30";
        cout<<"\nBrneni:7";
        cout<<"\nRychlost:15";
        cout<<"\nSuper utok:60";
        zivoty=110;
        utok=30;
        superutok=2*utok;
        brneni=7;
        rychlost=15;
    }else if(nahled==4){
        cout<<"HP:90";
        cout<<"\nUtok:55";
        cout<<"\nBrneni:4";
        cout<<"\nRychlost:25";
        cout<<"\nSuper utok:110";
        zivoty=90;
        utok=55;
        superutok=2*utok;
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
    cout<<"Vase staty jsou:\nZivoty: "<<zivoty<<"\nUtok: "<<utok<<"\nBrneni: "<<brneni<<"\nRychlost: "<<rychlost<<"\n";
    cout<<"Vase penize jsou: "<<penize<<"\n";

    cout<<"tohle je obchod kde muzete nakupovat vylepseni pro vasi postavu a nebo lepsi vybaveni, zbrane kupujte poporade \n";
    cout<<"vlevo se da koupit lepsi vybaveni uprostre se daji koupit vylepseni postavy a v pravo je arena kde se\n";
    cout<<"uskutecni vsecny vase boje s nepratelskymi monstry\n";
    //shopy();

//if(nahled==1) {
  //  do{
    //cout<<"Jdete a kupte si prvni mec kliknutim 1 vas dostane do obchodu se zbranemi;";
    //cin>>volbaobchod;
    //}while(volbaobchod!=1);
    //do{
    //mece();
    //cout<<"Pred sebou vidite 5 mecu i s cenami vyberte ten nejlevnější kliknete 1: ";
    //cin>>volbaobchod;
    //}while(volbaobchod!=1);
    //do{
    //shopy();
    //cout<<"Tedka si muzete jit koupit vylepseni pro vasi postavu kliknutim 2: ";
    //cin>>volbaobchod;
    //}while(volbaobchod!=2);
    //vylepseni();                           //u stranky vylepseni je potreba vyresit to ze ty promene jeste nejsou definovane;



// tohle je program shopu a pri koupi mece 
//do{tohle je to do
shopy();
do{
cout<<"Do jakého obchodu nebo areny chcete jit?\n1-Obchod se zbranemi\n2-Obchod s vylepsenim\n3-Arena\n";
cin>>volbaobchod;
}while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3);
if (volbaobchod==1){
    mece();

    do{
    cout<<"Jaky mec si chcete koupit?\nvas level mece je "<<levelmece<<" \n6- nechci kupovat zadny";
    cin>>volbaobchod;
    }while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3&&volbaobchod!=4&&volbaobchod!=5&&volbaobchod!=6);
     if(volbaobchod==1&&penize>=0){
        cout<<"Koupili jste zbran level 1";
        utok=utok+pomocnapromena1;
        pomocnapromena1=0;
        superutok=2*utok;
        penize=penize-0;    

    }else if(volbaobchod==2&&penize>=500&&levelmece==0){
        cout<<"Koupili jste zbran level 2";
        utok=utok+pomocnapromena2;
        pomocnapromena2=0;
        penize=penize-500;
        levelmece=1;
        superutok=2*utok;
    }else if(volbaobchod==3&&penize>=800&&levelmece==1){
        cout<<"Koupili jste zbran level 3";
        utok=utok+pomocnapromena3;
        pomocnapromena3=0;
        penize=penize-800;
        levelmece=2;
        superutok=2*utok;   
    }else if(volbaobchod==4&&penize>=1200&&levelmece==2){
        cout<<"Koupili jste zbran level 4";
        utok=utok+pomocnapromena4;
        pomocnapromena4=0;
        penize=penize-1200;
        levelmece=3;
        superutok=2*utok;
    }else if(volbaobchod==5&&penize>=1800&&levelmece==3){
        cout<<"Koupili jste zbran level 5";   
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
    cout<<"jake vylepseni si chcete koupit pro vasi postavu?\n1-Zivoty\n2-Utok\n3-Brneni\n4-Rychlost\n5-Nechci nic kupovat\n";
    cin>>volbaobchod;
    }while(volbaobchod!=1&&volbaobchod!=2&&volbaobchod!=3&&volbaobchod!=4&&volbaobchod!=5);
    if(volbaobchod==1&&penize>=cenazivoty){
        cout<<"Koupili jste vylepseni zivotu";
        zivoty=zivoty+5;
        penize=penize-cenazivoty;
        cenazivoty=cenazivoty+100;
    }else if(volbaobchod==2&&penize>=cenautok){
        cout<<"Koupili jste vylepseni utoku";
        utok=utok+3;
        penize=penize-cenautok;
        cenautok=cenautok+100;
        superutok=2*utok;
    }else if(volbaobchod==3&&penize>=cenabrneni){
        cout<<"Koupili jste vylepseni brneni";
        brneni=brneni+3;
        penize=penize-cenabrneni;
        cenabrneni=cenabrneni+100;
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
    cout<<"Staty vaseho nepritele:\n";
    cout<<"Zivoty: "<<polezivotynepritel[nepritel]<<"\nUtok: "<<poleutoknepritel[nepritel]<<"\nSuper utok: "<<polesuperutoknepritel[nepritel]<<"\nOdmena: "<<poleodmenanepritel[nepritel]<<"\n";
    cout<<"Chcete spustit boj s nepritelem? 1-ano 2-ne";
    cin>>volbaobchod;
    if(volbaobchod==1&&nepritel!=4&&nepritel!=9&&nepritel!=15){
        cout<<"Boj se spustil.\n";
        do{
        boj();
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                nepritel=nepritel+1;
            }else if(polezivotynepritel[nepritel]>0){
                cout<<"Nepritel vam zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                zivoty=zivoty-poleutoknepritel[nepritel];
                energie=energie-1;
                if(zivoty<=0){
                    cout<<"Prohrali jste a je konec hry\n";
                    return 0;
                }
            }
        }else if(volbaobchod==2&&energie>=3){
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                nepritel=nepritel+1;
            }else if(polezivotynepritel[nepritel]>0){
                cout<<"Nepritel vam zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                zivoty=zivoty-poleutoknepritel[nepritel];
                energie=energie-3;
                if(zivoty<=0){
                    cout<<"Prohrali jste a je konec hry\n";
                    return 0;
                }
            }
        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);
    }else if(volbaobchod==1&&nepritel==4||nepritel==9||nepritel==15){
        cout<<"boj se spustil.\n";
        cout<<"Vas protivník je mini-boss nebo boss tim padem zacina on a je o neco silnejsi nez ostatni nepratele\n";
        boj();
        cout<<"nepritel na vas zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
        zivoty=zivoty-poleutoknepritel[nepritel];
        do{
        cout<<"Zadejte co chcete udelat:\n1-Basic utok-1energie\n2-Super utok-3energie\n3-Utek\n";
        cin>>volbaobchod;
        if(volbaobchod==1&&energie >=1){
            cout<<"Zautocili jste basic utokem a udelali jste "<<utok<<" skody\n";
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-utok;
            if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                nepritel=nepritel+1;
            }else if(polezivotynepritel[nepritel]>0){
                cout<<"Nepritel vam zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                zivoty=zivoty-poleutoknepritel[nepritel];
                energie=energie-1;
                if(zivoty<=0){
                    cout<<"Prohrali jste a je konec hry\n";
                    return 0;
                }
            }
        }else if(volbaobchod==2&&energie>=3){
            cout<<"Zautocili jste super utokem a udelali jste "<<superutok<<" skody\n";
            polezivotynepritel[nepritel]=polezivotynepritel[nepritel]-superutok;
            if(polezivotynepritel[nepritel]<=0){
                cout<<"Vyhrali jste boj a ziskali jste "<<poleodmenanepritel[nepritel]<<" penize\n";
                penize=penize+poleodmenanepritel[nepritel];
                
            }else if(polezivotynepritel[nepritel]>0){
                cout<<"Nepritel vam zautocil a udelal vam "<<poleutoknepritel[nepritel]<<" skody\n";
                zivoty=zivoty-poleutoknepritel[nepritel];
                energie=energie-3;
                if(zivoty<=0){
                    cout<<"Prohrali jste a je konec hry\n";
                    return 0;
                }
            }
        }else if(volbaobchod==3){
            cout<<"Utekli jste z boje\n";
            volbaobchod=3;
        }
        }while(volbaobchod!=3&&polezivotynepritel[nepritel]>0&&zivoty>0);


    }

       
    
}
}

        
