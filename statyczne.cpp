#include <iostream>
using namespace std;
class statyczna{
    int x;
    //zmienna statyczna jest jedna dla calej klasy wszystkie obiekty je dziela
    static int y;
public:
    statyczna(){
        x=2;
        funkcja_statyczna();
    }
    ~statyczna(){
        x/=2;
    }
    //funkcji statycznej mozna uzywac tylko ze statycznymi zmiennymi tej klasy i parametrami(jesli istnieja), nie przyjmuje ona wskaznika *this
    void static funkcja_statyczna(){
        y*=2;
        cout<<y<<endl;
    }
    int static wypisz(){
        return y;
    }
};