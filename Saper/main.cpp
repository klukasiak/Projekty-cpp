#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct pole{
    int wartosc[9][9];
    bool odkryte[9][9];
    bool flaga[9][9];
};

void rysuj_plansze(pole gra);
void dodaj_gwiazdki(pole &gra);
int stringToInt();
int intToInput();
void odkryj(int i, int j, pole &gra);
void zerowanie(pole &gra);
void menu();
void pomoc();
void zacznijGre(const int GWIAZDKI, pole &gra);
int przegrana(const int GWIAZDKI, pole gra);
int wygrana(pole gra);

int main()
{
    pole gra;
    int wyjscie = 0, n;
    const int GWIAZDKI = 35;
    while(!wyjscie){
        menu();
        cin.clear();
        cin>>n;
        switch(n){
            case 1:
                system("cls");
                zacznijGre(GWIAZDKI, gra);
                break;
            case 2:
                system("cls");
                pomoc();
                break;
            case 3:
                wyjscie = 1;
                break;
        }
    }

    return 0;
}

void rysuj_plansze(pole gra){
    cout<<"  ABCDEFGHI "<<endl;
    cout<<" +---------+"<<endl;
    for(int i = 0; i<9; i++){
        cout<<i<<"|";
        for(int j = 0; j<9; j++){
            if(gra.odkryte[i][j] == false){
                if(gra.flaga[i][j] == true) cout<<"F";
                else cout<<"#";
            }
            else if(gra.wartosc[i][j] == 9) cout<<"*";
            else cout<<gra.wartosc[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<" +---------+"<<endl;
}

void dodaj_gwiazdki(const int GWIAZDKI, pole &gra){
    int dodane = 0;
    srand(time(0));
    while(dodane<GWIAZDKI){
        int i = rand()%9;
        int j = rand()%9;
        if(gra.wartosc[j][i]!=9 && gra.odkryte[j][i] == false){
            gra.wartosc[j][i] = 9;
            dodane++;
            for (int k = -1; k<2; k++){
                for (int l = -1; l<2; l++){
                    if ((j+l)<0 || (i+k)<0 ) continue; //wyjdz bo krawedz
                    if ((j+l)>8 || (i+k)>8 ) continue; //wyjdz bo krawedz

                    if (gra.wartosc[j+l][i+k]==9) continue; //wyjdz bo mina
                    gra.wartosc[j+l][i+k]++; //zwieksz o 1
                }
            }
        }
    }
}

int stringToInt(){
    string input;
    do{
        cin.clear();
        cin>>input;
        if(input == "A"){
            return 0;
        } else if(input == "B"){
            return 1;
        } else if(input == "C"){
            return 2;
        } else if(input == "D"){
            return 3;
        } else if(input == "E"){
            return 4;
        } else if(input == "F"){
            return 5;
        } else if(input == "G"){
            return 6;
        } else if(input == "H"){
            return 7;
        } else if(input == "I"){
            return 8;
        }  else cout<<"Zly input, podaj jeszcze raz"<<endl;
    } while(input != "A" || input != "B" || input != "C" || input != "D" || input != "E" || input != "F" || input != "G" || input != "H" || input != "I");
}

int intToInput(){
    int input;
    do{
        cin.clear();
        cin>>input;
    }while(input < 0 || input > 8);
    return input;
}

void odkryj(int i, int j, pole &gra){
    if(gra.flaga[i][j] == false){
        gra.flaga[i][j] = true;
    } else if(gra.odkryte[i][j] == false){
        gra.odkryte[i][j] = true;
    } else cout<<"Taki ruch juz wykonano"<<endl;
}

void zerowanie(pole &gra){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            gra.wartosc[i][j] = 0;
            gra.flaga[i][j] = false;
            gra.odkryte[i][j] = false;
        }
    }
}

void menu(){
    cout<<"     WITAJ W GRZE POSZUKIWANIE GWIAZDEK           "<<endl;
    cout<<"     wybierz jedna z opcji:    "<<endl<<endl;
    cout<<"1. Rozpocznij gre"<<endl;
    cout<<"2. Pomoc"<<endl;
    cout<<"3. Wyjdz z gry"<<endl;
}

void pomoc(){
    cout<<"Gra polega na odkrywaniu kolejnych pol"<<endl;
    cout<<"Trafiajac na gwiazdke przegrywasz gre"<<endl;
    cout<<"Po wybraniu pola wpisujesz je w formacie DUZALITERA <enter>  liczba np::"<<endl<<"A"<<endl<<"3"<<endl;
    cout<<"Pole wybrane po raz pierwszy zostaje oflagowane(podejrzewasz ze jest tam gwiazdka)"<<endl;
    cout<<"Jezeli chcesz odkryc pole musisz wpisac je jeszcze raz"<<endl<<endl;
}

void zacznijGre(const int GWIAZDKI, pole &gra){
    int stan = 0, a, b;
    zerowanie(gra);
    rysuj_plansze(gra);
    cout<<"Od ktorego pola chcesz zaczac"<<endl;
    a = stringToInt();
    cin>>b;
    odkryj(b, a, gra);
    odkryj(b, a, gra);
    dodaj_gwiazdki(GWIAZDKI, gra);
    odkryj(b, a, gra);
    odkryj(b, a, gra);
    system("cls");
    while(!stan){
        system("cls");
        rysuj_plansze(gra);
        cout<<"Podaj ktore miejsce chcesz teraz odkryc: "<<endl;
        int dobrze = 0;
        while(!dobrze){
            a = stringToInt();
            cin>>b;
            if(b>=0 || b<=8) dobrze = 1;
        }
        odkryj(b, a, gra);
        stan = przegrana(GWIAZDKI, gra);
    }

}

int przegrana(const int GWIAZDKI, pole gra){
    int odkryte = 0;
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(gra.odkryte[i][j] == true && gra.wartosc[i][j] == 9){
                system("cls");
                rysuj_plansze(gra);
                cout<<"Przegrales :("<<endl;
                system("pause");
                return 1;
            }
            if(gra.odkryte[i][j] == true) odkryte++;
        }
    }
    if(odkryte == 81 - GWIAZDKI){
        cout<<"Wygrales :)"<<endl;
        system("pause");
        return 1;
    } else return 0;
}
