#include "lib.h"


struct kolejka{
student* pocz=nullptr;
public:
void dodaj(string n,string i,string d,int in,int oc);
void wypisz();
};


void kolejka::dodaj(string n,string i,string d,int in,int oc)
{
    student* nowy=new student(n,i,d,in,oc);
    student* biegacz=nullptr;
    student* pom=nullptr;
    if(pocz==nullptr || pocz->indeks < in)
    {
        nowy->nast=pocz;
        pocz=nowy;
    }
    else
    {
        while(biegacz!=nullptr && biegacz->indeks >= in)
        {
            pom=biegacz;
            biegacz=biegacz->nast;
        }
        pom->nast=nowy;
        nowy->nast=biegacz;
    }
}

void kolejka::wypisz()
{
    student* biegacz=pocz;
    while(biegacz!=nullptr)
    {
        cout<<biegacz->imie;
        cout<<*biegacz;
        biegacz=biegacz->nast;
    }
}
