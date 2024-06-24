#ifndef LIB_H
#define LIB_H

using namespace std;
#include <iostream>




struct student{
string nazwisko;
string imie;
string drugie;
int indeks;
int ocena;
student* nast;
student(string n,string i,string d,int in,int oc,student* N=nullptr)
{
   nazwisko=n;
   imie=i;
   drugie=d;
   indeks=in;
   ocena=oc;
   nast=N;
}
friend ostream &operator<<(ostream& os,student& t)
{
    os<<t.indeks<<";"<<t.ocena<<";"<<t.nazwisko<<";"<<t.imie[0]<<" "<<t.drugie[0]<<"."<<endl;
}

};






bool czyocena(int ocena)
{
    if(ocena>=2 && ocena <=5)
        return true;
    else
        return false;
}

bool czyindeks(int indeks)
{
    if(indeks<=200000 && indeks >=100000)
        return true;
    else
        return false;
}




#endif // LIB_H
