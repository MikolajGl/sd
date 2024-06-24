#include "lib.h"
#include "kontener.h"
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
    kolejka k;
    ifstream p1("GRA.txt");
    ifstream p2("SID.txt");
    if(!p1 && !p2)
    {
        cout<<"blad otwarcia"<<endl;
    }
    else
    {
        string line;
        string nazwisko,imie,drugie;
        int indeks;
        int ocena;
        while(getline(p1,line))
            {
            stringstream ss(line);
            ss>>nazwisko>>imie>>drugie>>indeks>>ocena;
            if(czyocena(ocena) && czyindeks(indeks))
            {
            k.dodaj(nazwisko,imie,drugie,indeks,ocena);
            }

            }
        while(getline(p2,line))
            {
            stringstream ss(line);
            ss>>nazwisko>>imie>>drugie>>indeks>>ocena;
            if(czyocena(ocena) && czyindeks(indeks))
            {
            k.dodaj(nazwisko,imie,drugie,indeks,ocena);
            }
            }
    }
    p1.close();
    p2.close();
    k.wypisz();

    ofstream of("student.txt");
    student* biegacz=k.pocz;
    while(biegacz!=nullptr)
    {
        of<<*biegacz;
        biegacz=biegacz->nast;
    }
    return 0;


}
