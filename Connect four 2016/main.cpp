#include <iostream>  //POP 2016-12-12 projekt 1 £ukasiak Krystian EiT 5 Code::Blocks 16.01
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

char tab [6][7];




void rysuj_plansze()
{
    for( int i = 0; i < 6; i++ )
    { cout << " +-----+-----+-----+-----+-----+-----+-----+" << endl;
        cout << " |";
            for( int j = 0; j < 7; j++ )
            {
                    cout<<tab[i][j]<<tab[i][j]<<tab[i][j]<<tab[i][j]<<tab[i][j]<<"|";
            }
        cout << endl;
        cout<<" |";
        for(int j=0; j<7; j++)
        {
                cout<<tab[i][j]<<tab[i][j]<<tab[i][j]<<tab[i][j]<<tab[i][j]<<"|";
        }
        cout<<endl;
    }
    cout << " +-----+-----+-----+-----+-----+-----+-----+" << endl;
    cout << "    1     2     3     4     5     6     7" << endl;
    cout << endl << endl;
}
char wstawianie(char gracz)
{
    float wybor;
    int z=1;
    cout<<"Podaj kolumne do wrzucenia pionka: " << endl;
    cin.clear();
    cin>>wybor;
    while(z!=0)
    {
    if(wybor==1)
    {
        int i=5;
        while(tab[i][0]=='#'||tab[i][0]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;
                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][0]=gracz;
            }

    }
    else if(wybor==2)
    {
        int i=5;
        while(tab[i][1]=='#'||tab[i][1]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][1]=gracz;
            }

    }
    else if(wybor==3)
    {
        int i=5;
        while(tab[i][2]=='#'||tab[i][2]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][2]=gracz;
            }
    }
    else if(wybor==4)
    {
        int i=5;
        while(tab[i][3]=='#'||tab[i][3]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][3]=gracz;
            }
    }
    else if(wybor==5)
    {
        int i=5;
        while(tab[i][4]=='#'||tab[i][4]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
         if(i>-1)
            {
                z=0;
                tab[i][4]=gracz;
            }
    }
    else if(wybor==6)
    {
        int i=5;
        while(tab[i][5]=='#'||tab[i][5]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][5]=gracz;
            }
    }
    else if(wybor==7)
    {
        int i=5;
        while(tab[i][6]=='#'||tab[i][6]=='O')
            {
                i--;
                if(i==-1)
                    {
                        cout<<"Kolumna pelna. Podaj inna kolumne: ";
                        cin.clear();
                        cin>>wybor;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][6]=gracz;
            }
    }
    else
    {
        cin.clear();
        cout<<endl;
        cout<<"Zly wybor. Podaj inna liczbe!"<<endl;
        cin>>wybor;
        z=1;

    }
    }
system("cls");
}

char wstawianie_komputer(char gracz)
{
    int wybor;
    int z=1;
    srand(time(NULL));
    wybor=(rand() % 7 ) + 1;
    while(z!=0)
    {
    if(wybor==1)
    {
        int i=5;
        while(tab[i][0]=='#'||tab[i][0]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;
                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][0]=gracz;
            }

    }
    else if(wybor==2)
    {
        int i=5;
        while(tab[i][1]=='#'||tab[i][1]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][1]=gracz;
            }

    }
    else if(wybor==3)
    {
        int i=5;
        while(tab[i][2]=='#'||tab[i][2]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][2]=gracz;
            }
    }
    else if(wybor==4)
    {
        int i=5;
        while(tab[i][3]=='#'||tab[i][3]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][3]=gracz;
            }
    }
    else if(wybor==5)
    {
        int i=5;
        while(tab[i][4]=='#'||tab[i][4]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
         if(i>-1)
            {
                z=0;
                tab[i][4]=gracz;
            }
    }
    else if(wybor==6)
    {
        int i=5;
        while(tab[i][5]=='#'||tab[i][5]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][5]=gracz;
            }
    }
    else if(wybor==7)
    {
        int i=5;
        while(tab[i][6]=='#'||tab[i][6]=='O')
            {
                i--;
                if(i==-1)
                    {
                        wybor=(rand() % 7 ) + 1;
                        z=1;

                    }
            }
        if(i>-1)
            {
                z=0;
                tab[i][6]=gracz;
            }
    }
    else
    {
        wybor=(rand() % 7 ) + 1;
        z=1;

    }
    }
system("cls");
}

int wygranax(int n)
{
    n=0;
    	for( int i = 6; i >= 1; --i )
	{

		for( int j = 7; j >= 1; --j )
		{

			if( tab[i][j] == 'X'     &&
				tab[i-1][j-1] == 'X' &&
				tab[i-2][j-2] == 'X' &&
				tab[i-3][j-3] == 'X' )
			{
				n=4;
			}


			if( tab[i][j] == 'X'   &&
				tab[i][j-1] == 'X' &&
				tab[i][j-2] == 'X' &&
				tab[i][j-3] == 'X' )
			{
				n=4;
			}

			if( tab[i][j] == 'X'   &&
				tab[i-1][j] == 'X' &&
				tab[i-2][j] == 'X' &&
				tab[i-3][j] == 'X' )
			{
				n=4;
			}

			if( tab[i][j] == 'X'     &&
				tab[i-1][j+1] == 'X' &&
				tab[i-2][j+2] == 'X' &&
				tab[i-3][j+3] == 'X' )
			{
				n=4;
			}

			if ( tab[i][j] == 'X'   &&
				 tab[i][j+1] == 'X' &&
				 tab[i][j+2] == 'X' &&
				 tab[i][j+3] == 'X' )
			{
				n=4;
			}
		}

	}

return n;
}

int wygranao(int n)
{
n=0;
    	for( int i = 6; i >= 1; --i )
	{

		for( int j = 7; j >= 1; --j )
		{

			if( tab[i][j] == 'O'     &&
				tab[i-1][j-1] == 'O' &&
				tab[i-2][j-2] == 'O' &&
				tab[i-3][j-3] == 'O' )
			{
				n=4;
			}


			if( tab[i][j] == 'O'   &&
				tab[i][j-1] == 'O' &&
				tab[i][j-2] == 'O' &&
				tab[i][j-3] == 'O' )
			{
				n=4;
			}

			if( tab[i][j] == 'O'   &&
				tab[i-1][j] == 'O' &&
				tab[i-2][j] == 'O' &&
				tab[i-3][j] == 'O' )
			{
				n=4;
			}

			if( tab[i][j] == 'O'     &&
				tab[i-1][j+1] == 'O' &&
				tab[i-2][j+2] == 'O' &&
				tab[i-3][j+3] == 'O' )
			{
				n=4;
			}

			if ( tab[i][j] == 'O'   &&
				 tab[i][j+1] == 'O' &&
				 tab[i][j+2] == 'O' &&
				 tab[i][j+3] == 'O' )
			{
				n=4;
			}
		}

	}

return n;
}

int remis(int n)
{
    int licznik1=0;
    int z=0;
    for(int i=0; i<7; i++)
    {
        for(int j=5; j>-1; j--)
        {
            if(tab[j][i]=='O'||tab[j][i]=='#')
            {
                licznik1++;

            }
            else
            {
                licznik1=0;
            }
        }
        if(licznik1==6) z++;
        licznik1=0;
    }
    if(z==7)
    {
        cout<<"Remis!"<<endl;
        system("pause");
        n=4;
    }
    return n;

}
void menu()
{
    cout<<"================"<<endl;
    cout<<"Gra Connect Four"<<endl;
    cout<<"================"<<endl;
    cout<<"Wybierz jedna z opcji: "<<endl;
    cout<<"1. Nowa gra"<<endl;
    cout<<"2. O autorze"<<endl;
    cout<<"3. Zakoncz gre"<<endl<<endl;

}
int autor(int n)
{
    cout<<"Program wykonal Krystian Lukasiak"<<endl;
    cout<<"Wszelkie prawa zastrzezone :)"<<endl<<endl;
    return 1;
}
void czysc()
{
    for( int i = 0; i < 6; i++ )
    {
        for( int j = 0; j < 7; j++ )
        {
            tab[i][j]=0;
        }
    }
}
int main()
{

struct gracz
{
    char g1='O';
    char g2='#';
};
float wybor;
int n;
gracz gracze;
menu();

cout<<endl<<endl;

    while(n!=0)
    {
        system("cls");
        menu();
        cin.clear();
        cin>>wybor;
        if(wybor==1)
            {
                while(n!=0)
            {
                system("cls");
                rysuj_plansze();
                wstawianie(gracze.g1);
                if(wygranao(n)==4)
                {
                    system("cls");
                    cout<<"Wygrywa gracz! :)"<<endl;
                    system("pause");
                    czysc();
                    break;
                }
                if(remis(n)==4)
                      {
                    system("cls");
                    cout<<"Remis!"<<endl;
                    system("pause");
                    czysc();
                    break;
                }
                rysuj_plansze();
                wstawianie_komputer(gracze.g2);
                if(wygranax(n)==4)
                {
                    system("cls");
                    cout<<"Wygrywa komputer!"<<endl;
                    system("pause");
                    czysc();
                    break;
                }
                if(remis(n)==4)
                    {
                    system("cls");
                    cout<<"Remis!"<<endl;
                    system("pause");
                    czysc();
                    break;
                }
            }
            }
        else if(wybor==2)
            {
                n=autor(n);
                Sleep(3000);
                menu();
            }
        else if(wybor==3)
            {
                return 0;
            }
        else
        {
            cin.clear();
            cout<<"Zle wybrana opcja. Sproboj jeszcze raz."<<endl;
            system("pause");
        }
    }



    return 0;
}
