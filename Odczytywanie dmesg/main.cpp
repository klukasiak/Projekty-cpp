#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
    string buffer;
    int i = 0;
    fstream plikInput("dmesg.txt", ios::in);
    if(!plikInput) {
        cout << "Plik wejsciowy nie otwarty \n";
        return 1;
    }
    fstream plikOutput("wynik.txt", ios::out);
    if(!plikOutput) {
        cout << "Plik wyjsciowy nie otwarty \n";
        return 1;
    }

    while(!plikInput.eof()){
        getline(plikInput, buffer);
        if(!(string::npos == buffer.find("Linux version"))){
            plikOutput<<"Wersja jadra systemu Linux:";
            plikOutput<<buffer.substr(buffer.find("version ") + 7, 17)<<endl;
        }
        if(!(string::npos == buffer.find("gcc version"))){
            plikOutput<<"Wersja kompilatora:";
            plikOutput<<buffer.substr(buffer.find("gcc version ") + 11,7)<<endl;
        }
        if(!(string::npos == buffer.find("DMI: "))){
            plikOutput<<"Kod producenta:";
            plikOutput<<buffer.substr(buffer.find("DMI: ") + 5, buffer.length())<<endl;
        }
        if(!(string::npos == buffer.find("LOWMEM"))){
            plikOutput<<"Ilosc pamieci bezposrednio mapowanej na przestrzen adresowa jadra:";
            plikOutput<<buffer.substr(buffer.find("LOWMEM") - 7,6)<<endl;
        }
        if(!(string::npos == buffer.find("Kernel command line:"))){
            plikOutput<<"Linia polecen jadra:";
            plikOutput<<buffer.substr(buffer.find("line: ") + 6, buffer.length())<<endl;
        }
        if(!(string::npos == buffer.find("kernel code"))){
            plikOutput<<"Ilosc pamieci zajmowanej przez kod jadra: ";
            plikOutput<<buffer.substr(buffer.find("kernel code") - 6, 5)<<endl;
        }
        if(!(string::npos == buffer.find("mounted filesystem"))){
            if(i<1){
                plikOutput<<"partycje EXT 4:"<<endl;
                plikOutput<<setw(10)<<"czas"<<setw(10)<<"partycja"<<endl; 
                i++;
            }
            plikOutput<<setw(10)<<buffer.substr(buffer.find("EXT4-fs") - 13, 10);
            plikOutput<<setw(10)<<buffer.substr(buffer.find("sda"), 4)<<endl;;
        }
    }
    plikInput.close();
    plikOutput.close();
}
