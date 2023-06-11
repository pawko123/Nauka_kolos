class A{
protected:
    int a;
public:
    A(int num1):a(num1){}
    //tworzenie klasy abstrakcyjnej, slowo virtual oznacza ze w klasie pochodnej istnieje funkcja ktora nadpisuje funkcje klasy oryginalnej
    virtual void wypisz()=0;
};
class B:public A{
protected:
    int b;
public:
    B(int num1,int num2):b(num2), A(num1){}
    //override oznacza ze funkcja z klasy wyzszej jest nadpisywana
    virtual void wypisz() override{
        cout<<this->a<<' '<<this->b<<'\n';
    }
};
class C:public B{
private:
    int c;
public:
    C(int num1,int num2,int num3):c(num3), B(num1,num2){}
    void wypisz() override{
        cout<<this->a<<' '<<this->b<<' '<<this->c<<'\n';
    }
};
//funkcja globalna ktora przyjmuje klase A lub jej pochodne i wywoluje ich funkcje zaleznie od klasy obiektu
void wypisz(A &klasa){
    klasa.wypisz();
}
class X{
public:
    void virtual f(){
        cout<<"funkcja f() klasy X\n";
    };
    void f1(){
        cout<<"funkcja f1() klasy X\n";
    };
}x,*px;
class Y:public X{
public:
    void f(){
        cout<<"funkcja f() klasy Y\n";
    }
    void f1(){
        cout<<"funkcja f1() klasy Y\n";
    }
}y,*py;
class Z:public Y{
public:
    void f(){
        cout<<"funkcja f() klasy Z\n";
    }
    void f1(){
        cout<<"funkcja f1() klasy Z\n";
    }
}z,*pz;
//destruktory wirtualne
//destruktor wirtualny zapewnia ze bedzie wywolany dekontruktor funkcji pochodnych
class bazowa {
public:
    bazowa(){cout << "bazowa()\n";}
    virtual ~bazowa() {cout << "~bazowa()\n"; }
};
class pochodna : public bazowa {
public:
    pochodna(){cout<<"pochodna()\n";}
    ~pochodna() {cout << "~pochodna()\n";}
};

