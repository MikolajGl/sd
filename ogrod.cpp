#include <iostream>

using namespace std;

class Roslina{
int wysokosc;
char rs;
public:
    Roslina(int wysokosc,char rs)
    {
    this->wysokosc=wysokosc;
    this->rs=rs;
    }
char getZnak(){return rs;}
int getWys(){return wysokosc;}
virtual ~Roslina(){}
};

class Kwiat : public Roslina
{
public:
    Kwiat(int wysokosc) : Roslina(wysokosc,'K'){}
~Kwiat(){cout<<"o usunieto"<<endl;}
};

class Krzew : public Roslina
{
string opis;
public:
    Krzew(int wysokosc,string opis="jeb") : Roslina(wysokosc,'M'){this->opis=opis;}
~Krzew(){cout<<"K "<<opis<<"usnieto"<<endl;}
};

class Ogrod{
int x;
int y;
Roslina*** tab;
public:
    Ogrod(int x,int y)
    {
        this->x=x;
        this->y=y;
        tab=new Roslina**[x];
        for(int i=0;i<x;i++)
        {
            tab[i]=new Roslina*[y];
            for(int j=0;j<y;j++)
            {
               tab[i][j]=nullptr;
            }
        }
    }
    friend ostream& operator<<(ostream& os,Ogrod& Og)
    {
       for(int i=0;i<Og.x;i++)
        {
            for(int j=0;j<Og.y;j++)
            {
               if(Og.tab[i][j]==nullptr)
               {
                   os<<"W";
               }
               else
               {
                   os<<Og.tab[i][j]->getZnak();
               }
            }
            os<<endl;
        }
        os<<endl;
        return os;
    }
    void wstaw(int x,int y,Roslina* ros)
    {
        tab[x][y]=ros;
    }
    void operator>>(int wys)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
               if(tab[i][j]!=nullptr&& tab[i][j]->getWys()>wys)
               {
                   tab[i][j]=nullptr;
               }
            }
        }
    }
~Ogrod(){
 for(int i=0;i<x;i++)
        {
            delete[]tab[i];
        }
        delete[] tab;
    cout<<"ogrod wyjebany"<<endl;
}
void operator=(Ogrod& other)
{
for(int i=0;i<x;i++)
{
        delete[]tab[i];
}
delete[] tab;

int x=other.x;
int y=other.y;
tab=new Roslina**[x];
for(int i=0;i<x;i++)
{
    tab[i]=new Roslina*[y];
}
for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
               if(other.tab[i][j]!=nullptr)
               {
                   tab[i][j]=other.tab[i][j];
               }
            }
            }

}
};


int main()
{
    Ogrod O(7,7);
    Ogrod O2(7,7);
    Roslina* r1=new Kwiat(50);
    Roslina* r2=new Krzew(150,"Krzew1");
    Roslina* r3=new Krzew(177,"Krzew2");

    O.wstaw(3,5,r1);
    O.wstaw(5,6,r2);
    O.wstaw(2,6,r3);
    O.wstaw(2,1,r3);
    cout<<O;
    O>>150;
    cout<<O;
    O2=O;
    cout<<O2;
    delete r1;
    delete r2;
    delete r3;


}
