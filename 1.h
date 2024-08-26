#ifndef LIB_H
#define LIB_H
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
void usun(float k);
};

void sznur::wpisz(int a)
{

    wezel* nowy=new wezel(a);
    wezel* biegacz=pocz;
    wezel* pom=nullptr;
    if(pocz == nullptr || a <= pocz->dane )
    {
        nowy->nast=pocz;
        pocz=nowy;
    }
    else
    {
        while(biegacz != nullptr && a >= biegacz->dane)
        {
            pom=biegacz;
            biegacz=biegacz->nast;
        }
        pom->nast=nowy;
        nowy->nast=biegacz;
    }
}

void sznur::usun(float k)
{
    wezel* biegacz=pocz;
    wezel* pom=nullptr;
    wezel* kill=nullptr;
    while(biegacz!=nullptr && biegacz->nast!=nullptr && biegacz->nast->nast!=nullptr)
    {
        int a=biegacz->dane;
        int b=biegacz->nast->dane;
        int c=biegacz->nast->nast->dane;
        float srednia=(a+b+c)/3;
        if(k > srednia)
        {
            if(pocz==biegacz)
            {
                for(int i=0;i<3;i++)
                {
                    if(i==0)
                    {
                        kill=pocz;
                        pocz=pocz->nast;
                        biegacz=pocz;
                        delete kill;
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
                    if(i==0)
                    {
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
        else
        {
            if(pocz==biegacz)
            {
                for(int i=0;i<3;i++)
                {
                    if(i==0){
                    biegacz=biegacz->nast;
                    }
                    else{
                        kill=biegacz;
                        biegacz=biegacz->nast;
                        delete kill;
                        if(i==2)
                        {
                            pocz->nast=biegacz;
                        }
                    }
                }
                pom=pocz;
            }
            else
            {
                pom->nast=biegacz;
                for(int i=0;i<3;i++)
                {
                    if(i==0){
                    pom=biegacz;
                    biegacz=biegacz->nast;
                    }
                    else{
                        kill=biegacz;
                        biegacz=biegacz->nast;
                        delete kill;
                    if(i==2)
                        {
                            pom->nast=biegacz;
                        }
                    }

                }
            }
            }
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

#endif // LIB_H
