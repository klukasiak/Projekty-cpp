#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void printGame(char game[4][4]);
void move(char game[4][4], int input);
void change (char game[4][4], int i, int j);
int winning (char game[4][4]);
void newGame(char game[4][4]);
void random(char game[4][4]);
void printMenu();
void printInfo();

int main()
{
    char game[4][4] = {{'A', 'B', 'C', 'D'},
                      {'E', 'F', 'G', 'H'},
                      {'I', 'J', 'K', 'L'},
                      {'M', 'N', 'O', 'P'}};
    int end = 0, input;
    while(!end){
        printMenu();
        cin>>input;
        switch(input){
            case 1:
                newGame(game);
                break;
            case 2:
                printInfo();
                break;
            case 3:
                end = 1;
                break;
        }
    }
    return 0;
}

void printGame(char game[4][4]){
    cout<<".-------.-------.-------.-------."<<endl;
    for(int i = 0; i<4; i++){
        cout<<"|";
        for(int j = 0; j<4; j++){
            cout<<game[i][j]<<"      |";
        }
        cout<<endl<<"|";
        for(int j = 0; j<4; j++){
            cout<<"      "<<game[i][j]<<"|";
        }
        cout<<endl;
        if(i==0) cout<<"+-------1-------+-------2-------+";
        if(i==1) cout<<"+-------+-------5-------+-------+";
        if(i==2) cout<<"+-------3-------+-------4-------+";
        if(i==3) cout<<"'-------'-------'-------'-------'"<<endl;
        cout<<endl;
    }

}

void move(char game[4][4], int input){
    switch(input){
        case 1:
            change(game, 0, 0);
            break;
        case 2:
            change(game, 0, 2);
            break;
        case 3:
            change(game, 2, 0);
            break;
        case 4:
            change(game, 2, 2);
            break;
        case 5:
            change(game, 1, 1);
            break;
    }
}

void change (char game[4][4], int i, int j){
    char buf;
    buf = game[i][j];
    game[i][j] = game[i+1][j];
    game[i+1][j] = game[i+1][j+1];
    game[i+1][j+1] = game [i][j+1];
    game[i][j+1] = buf;
}

int winning (char game[4][4]){
    char test = 'A';
    bool win = true;

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(test != game[i][j]) win = false;
            test++;
        }
    }

    if(win){
        system("cls");
        printGame(game);
        cout<<"Wygrales! Gratulacje!"<<endl;
        system("pause");
        return 1;
    }
    return 0;
}

void random(char game[4][4]){
    srand(time(0));
    int const RANDOMISE = 1;
    for(int i = 0; i<RANDOMISE; i++) move(game, rand()%5+1);
}

void newGame(char game[4][4]){
    int win = 0, input;
    random(game);
    while(!win){
        system("cls");
        printGame(game);
        cout<<"Podaj ktora czescia chcesz poruszyc: "<<endl;
        bool available = false;
        while(!available){
            cin.clear();
            cin>>input;
            if(input>5 || input<0) cout<<"Niepoprawna cwiartka podaj jeszcze raz"<<endl;
            else available = true;
        }
        move(game, input);
        win = winning(game);
    }
}

void printMenu(){
    cout<<"===================="<<endl;
    cout<<"Witaj w grze puzzle:"<<endl;
    cout<<"1. Wystartuj gre"<<endl;
    cout<<"2. Informacje o grze"<<endl;
    cout<<"3. Zakoncz gre"<<endl;
}

void printInfo(){
    cout<<"Gra polega na poprawnym ulozeniu alfabetu w odpowiedniej kolejnosci"<<endl;
    cout<<"Uzywajac klawiszy 1,2,3,4,5 poruszasz odpowiednimi kwadratami planszy"<<endl;
}
