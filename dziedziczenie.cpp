class A{
protected:
    int a;
public:
    A(int num1):a(num1){}
    //tworzenie klasy abstrakcyjnej
    virtual void wypisz()=0;
};
class B:public A{
protected:
    int b;
public:
    B(int num1,int num2):b(num2), A(num1){}
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
