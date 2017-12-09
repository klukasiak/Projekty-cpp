#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void rysuj_gre(char gra[4][4]);
void zeruj(char gra[4][4]);
void start(char gra[4][4], const char gracz1, const char gracz2);
void ruchPion(char gra[4][4], const char gracz, int i1, int j1, int i2, int j2);
int charNaInt(char a);
void biciePion(char gra[4][4], const char gracz, const char przeciwnik, int i1, int j1, int i2, int j2);
void ruchPoziom(char gra[4][4], const char gracz, int i1, int i2, int j1, int j2);
void biciePoziom(char gra[4][4], const char gracz, const char przeciwnik, int i1, int j1, int i2, int j2);

int main()
{
    const char GRACZ = 'c';
    const char KOMPUTER = 'b';
    char a, c;
    int b, d;
    char gra [4][4];
    zeruj(gra);
    start(gra, GRACZ, KOMPUTER);
    rysuj_gre(gra);
    while(1){
        system("clear");
        rysuj_gre(gra);
        cout<<"Podaj skad chcesz przemiescic pionek"<<endl;
        cin>>a>>b;
        cout<<"Podaj dokad chcesz przemiescic pionek"<<endl;
        cin>>c>>d;
        if(a==c){
            if(b==d-1 || b==d+1)ruchPion(gra, GRACZ, b, charNaInt(a), d, charNaInt(c));
            if((b==d+2 && b+1 == KOMPUTER) || (b==d-2 && b-1 == KOMPUTER))
                biciePion(gra, GRACZ, KOMPUTER, b, charNaInt(a), d, charNaInt(c));
        }
        if(b==d){
            if(a==c-1 || a==c+1)ruchPoziom(gra, GRACZ, b, charNaInt(a), d, charNaInt(c));
            if((a==c+2 && a+1 == KOMPUTER) || (a==c-2 && a-1 == KOMPUTER))
                biciePoziom(gra, GRACZ, KOMPUTER, b, charNaInt(a), d, charNaInt(c));
        }
    }
}


void rysuj_gre(char gra[4][4]){
    for(int i = 3; i>=0; i--){
        cout<<i<<"|";
        for(int j = 0; j<4; j++){
            cout<<setw(1)<<gra[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<"  A B C D"<<endl;
}

void zeruj(char gra[4][4]){
    for(int i = 4; i>=0; i--){
        for(int j = 0; j<4; j++){
        gra[i][j] = ' ';
        }
    }
}

void start(char gra[4][4], const char gracz1, const char gracz2){
    for(int i = 0; i<4; i++){
        gra[3][i] = gracz1;
    }

    for(int i = 0; i<4; i++){
        gra[0][i] = gracz2;
    }
}

void ruchPion(char gra[4][4], const char gracz, int i1, int j1, int i2, int j2){
    gra[i1][j1] = ' ';
    gra[i2][j2] = gracz;
}

void biciePion(char gra[4][4], const char gracz, const char przeciwnik, int i1, int j1, int i2, int j2){
    if(i1 == i2 + 2){
        gra[i1+1][j1] = ' ';
        gra[i1][j1] = ' ';
        gra[i2][j2] = gracz;
    } else{
        gra[i1-1][j1] = ' ';
        gra[i1][j1] = ' ';
        gra[i2][j2] = gracz;
    }
}

int charNaInt(char a){
    switch(a){
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
    }
}

void ruchPoziom(char gra[4][4], const char gracz, int i1, int j1, int i2, int j2){
    gra[i1][j1] = ' ';
    gra[i2][j2] = gracz;
}

void biciePoziom(char gra[4][4], const char gracz, const char przeciwnik, int i1, int j1, int i2, int j2){
    if(j1 == j2 + 2){
        gra[i1][j1+1] = ' ';
        gra[i1][j1] = ' ';
        gra[i2][j2] = gracz;
    } else{
        gra[i1][j1-1] = ' ';
        gra[i1][j1] = ' ';
        gra[i2][j2] = gracz;
    }
}

bool przegrana(char gra[4][4], const char gracz){
    int ilosc = 0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(gra[i][j]==gracz) ilosc++;
        }
    }
    cout<<gracz<<" przegral :("<<endl;
    system("pause");
    if(ilosc == 0) return 1;
    else return 0;
}

void menu(){
    cout<<"Moja gra"<<endl;
    cout<<"1. Rozpocznij gre"<<endl;
    cout<<"2. Pomoc"<<endl;
    cout<<"3. Zakoncz program"<<endl;

}

void pomoc(){
    cout<<"Gracze poruszaja sie pionkami na zmiane"<<endl;
    cout<<"Mozesz przeskakiwac pionek przeciwnika przez co "zbijasz" go z planszy"<<endl;
    cout<<"Gracz przegrywa jezeli wszystkie jego pionki zostaly zbite "<< endl;
}

void gra(char gra [4][4],){
    int koniec = 0, b,d;
    char a,c;
    while(!koniec){
        system("cls");
        rysuj_gre(gra);
        cout<<"Podaj skad chcesz przemiescic pionek"<<endl;
        cin>>a>>b;
        cout<<"Podaj dokad chcesz przemiescic pionek"<<endl;
        cin>>c>>d;
        cout<<"Podaj skad chcesz przemiescic pionek"<<endl;
        cin>>a>>b;
        cout<<"Podaj dokad chcesz przemiescic pionek"<<endl;
        cin>>c>>d;
        if(a==c){
            if(b==d-1 || b==d+1){
                ruchPion(gra, GRACZ, b, charNaInt(a), d, charNaInt(c));
            }
            if((b==d+2 && b+1 == KOMPUTER) || (b==d-2 && b-1 == KOMPUTER)){
                biciePion(gra, GRACZ, KOMPUTER, b, charNaInt(a), d, charNaInt(c));
            }
        }
        else
        if(b==d){
            if(a==c-1 || a==c+1)ruchPoziom(gra, GRACZ, b, charNaInt(a), d, charNaInt(c));
            if((a==c+2 && a+1 == KOMPUTER) || (a==c-2 && a-1 == KOMPUTER))
                biciePoziom(gra, GRACZ, KOMPUTER, b, charNaInt(a), d, charNaInt(c));
        }
    }
}
