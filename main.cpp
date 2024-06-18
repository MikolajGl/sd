#include <iostream>

using namespace std;

struct sznur{
struct wezel{
int dane;
wezel* nast;
wezel(int d,wezel *n=nullptr)
{
    dane=d;
    nast=n;
}
};
wezel* pocz=nullptr;
public:
void wpisz(int a);
void wypisz();
void usun(int m,int n);
};

/*void sznur::wpisz(int a)
{
wezel* nowy=new wezel(a);
wezel* biegacz=pocz;
wezel* pom=nullptr;
if(pocz==nullptr || a >= pocz->dane)
{
    nowy->nast=pocz;
    pocz=nowy;
}
else
{
    while(biegacz!=nullptr && a <= biegacz->dane)
    {
        pom=biegacz;
        biegacz=biegacz->nast;
    }
    pom->nast=nowy;
    nowy->nast=biegacz;
}
}*/

void sznur::wpisz(int a)
{
wezel* nowy=new wezel(a);
wezel* biegacz=pocz;
wezel* pom=nullptr;
if(pocz==nullptr)
{
    pocz=nowy;
}
else
{
while(biegacz->nast!=nullptr)
{
biegacz=biegacz->nast;
}
biegacz->nast=nowy;
}
}

void sznur::wypisz()
{
    wezel* biegacz=pocz;
    while(biegacz!=nullptr)
    {
        cout<<biegacz->dane<<" ";
        biegacz=biegacz->nast;
    }
}

/*void sznur::usun()
{
wezel* biegacz=pocz;
wezel* pom=nullptr;
wezel* kill=nullptr;
int x=0;
while(biegacz!=nullptr && biegacz->nast!=nullptr && biegacz->nast->nast!=nullptr)
{
int a=biegacz->dane;
int b=biegacz->nast->dane;
int c=biegacz->nast->nast->dane;
if(a==b && b==c && c==a)
{
    for(int i=0;i<3;i++){
    pom=biegacz;
    biegacz=biegacz->nast;
    }
}
else
{
    if(a<=c && a<=b)
    {
        x=a;
    }
    if(b<=a && b<=c)
    {
        x=b;
    }
    if(c<=a && c<=b)
    {
        x=c;
    }
    if(pocz==biegacz)
    {
    for(int i=0;i<3;i++)
    {
    if(biegacz->dane > x ){
    if(pocz==biegacz)
    {
    kill=pocz;
    pocz=pocz->nast;
    delete kill;
    biegacz=pocz;
    }
    else
    {
    kill=biegacz;
    biegacz=biegacz->nast;
    pom->nast=biegacz;
    delete kill;
    }
    }
    else
    {
    pom=biegacz;
    biegacz=biegacz->nast;
    }
    }
    }
    else
    {
    for(int i=0;i<3;i++)
    {
    if(biegacz->dane > x){
    kill=biegacz;
    biegacz=biegacz->nast;
    pom->nast=biegacz;
    delete kill;
    }
    else
    {
    pom=biegacz;
    biegacz=biegacz->nast;
    }
    }
    }
}

}

}*/


void sznur::usun(int m,int n)
{
wezel* biegacz=pocz;
wezel* pom=nullptr;
wezel* kill=nullptr;
while(biegacz!=nullptr)
{
    if(pocz==biegacz)
    {
    for(int i=0;i<m;i++)
    {
        if(pocz!=nullptr)
        {
            kill=pocz;
            pocz=pocz->nast;
            delete kill;
            biegacz=pocz;
        }
    }
    while(biegacz!=nullptr && biegacz->nast!=nullptr)
    {
            if(biegacz->dane == biegacz->nast->dane && biegacz->dane > n)
                {
                    for(int i=0;i<2;i++)
                    {
                    pom=biegacz;
                    biegacz=biegacz->nast;
                   }
                   break;
                }
                else
                {
                biegacz=biegacz->nast;
                }
    }
}
else
{
for(int i=0;i<m;i++)
    {
        if(biegacz!=nullptr)
        {
            kill=biegacz;
            biegacz=biegacz->nast;
            delete kill;
        }
    }
    pom->nast=biegacz;
    while(biegacz!=nullptr && biegacz->nast!=nullptr)
    {
            if(biegacz->dane == biegacz->nast->dane && biegacz->dane > n)
                {
                    for(int i=0;i<2;i++)
                    {
                    pom=biegacz;
                    biegacz=biegacz->nast;
                    }
                    break;
                }
                else
                {
                biegacz=biegacz->nast;
                }
    }
}
}
}






int main()
{
    sznur s1;
    /*s1.wpisz(7);
    s1.wpisz(2);
    s1.wpisz(1);
    s1.wpisz(1);
    s1.wpisz(2);
    s1.wpisz(2);
    s1.wpisz(7);
    s1.wpisz(2);
    s1.wpisz(1);
    s1.wpisz(1);
    s1.wpisz(2);
    s1.wpisz(2);
    s1.wypisz();*/
    s1.wpisz(2);
    s1.wpisz(1);
    s1.wpisz(1);
    s1.usun(3,1);
    s1.wypisz();

    return 0;
}
