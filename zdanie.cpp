#include <iostream>
#include<vector>
using namespace std;




class Litera{
    char li;
public:
    Litera(char li)
    {
        this->li=li;
    }
    char getZnak(){return li;}
    virtual ~Litera(){}


};

class A : public Litera{
public:
    A() : Litera('A'){}
    ~A(){cout<<"~A";}
    };

class B : public Litera{
public:
    B() : Litera('B'){}
    ~B(){cout<<"~B";}
};

class C : public Litera{
public:
    C() : Litera('C'){}
    ~C(){cout<<"~C";}
};

class Slowo{
vector <Litera*> tab;
public:
    Slowo()=default;
    Slowo& operator<<(Litera* li)
    {
    tab.push_back(li);
    }

    friend ostream& operator<<(ostream& os,Slowo& sl)
    {
        os<<endl;
        for(int i=0;i<sl.tab.size();i++)
        {
            os<<sl.tab[i]->getZnak();
        }
        os<<endl;
        return os;
    }
    Litera*& operator[](int index)
    {
        delete tab[index];
        return tab[index];
    }

    Slowo& operator--()
    {
        delete tab[0];
        for(int i=0;i<tab.size();i++)
        {
            tab[i]=tab[i+1];
        }
        delete tab[tab.size()];
        tab.pop_back();
    }
    ~Slowo(){
    for(int i=0;i<tab.size();i++)
    {
        delete tab[i];
    }
    tab.clear();
    }
    Slowo& operator==(Slowo& other)
    {
    for (int i = 0; i < tab.size(); ++i) {
    delete tab[i];
    }
    tab.clear();

    for (int j=0;j<other.tab.size();j++)
    {
        tab.push_back(new Litera(*other.tab[j]));
    }
    }

};

int main()
{
Slowo S;
S<<new A;
S<<new B;
S<<new C;
cout<<S;
S[1]=new A;
cout<<S;
--S;
Slowo S1;
S1=S;
cout<<S;
cout<<S1;
return 0;
}

