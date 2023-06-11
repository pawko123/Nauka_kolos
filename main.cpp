#include<iostream>
#include"wskazniki.cpp"
#include"konstruktory.cpp"
#include"statyczne.cpp"
#include "operatory.cpp"
#include "kompozycja.cpp"
#include "dziedziczenie.cpp"
using namespace std;
int statyczna::y=1;
int liczba::statyczna=0;
int main(){
    /*int x=5;
    int y=4;
    //w miejscu wskaznika do funkcji dajemy jej nazwe
    cout<<wynik(x,y,dodaj)<<endl;
    cout<<wynik(x,y,odejmij)<<endl;
    cout<<wynik(x,y,mnozenie)<<endl;
    cout<<wynik(x,y,dzielenie)<<endl;
     */
    //wskaznik na stala int, wskazanie na normalnego int tez dziala ¯\_(ツ)_/¯
    const int *p;
    const int stala1=4;
    const int stala2=5;
    //wartosc wzkaznika nie jest stala wiec mozna ja zmienic
    p=&stala1;
    cout<<*p<<endl;
    p=&stala2;
    cout<<*p<<endl;
    //staly wskazik na int ktorego nie bedzie mozna zmienic
    int liczba=6;
    int * const p2=&liczba;
    cout<<*p2<<endl;
    //staly wskaznik na stalego int
    const int * const p3=&stala2;
    cout<<*p3<<endl;
    /*
     roznica pomiedzy wskaznikiem a tablica
     wskaznik-wskazuje na adres innej zmiennej, mozna mu dynamicznie zaalokowac pamieci
     tablica-jest zbiorem objektow tego samego typu przechowywanych w jednym ciagu,i po tym jak sie ja stworzy nie mozna adresu zmienic,
     mozna odwolywac sie do jej elementow za pomoca indeksow,rozmiar jest ustalany w czasie kompilacji
     */
    statyczna static1;
    statyczna static2;
    cout<<statyczna::wypisz()<<endl;
    /*
    //funkcja konwertujaca to taka co zmienia typ zmiennej, przykladem takiej jest to_string lub float char itp
    int liczba2=4124131;
    char znak=(char)liczba;
    string napis= to_string(liczba2);
    cout<<(float)liczba2/float(100000);
    cout<<znak;
*/
    konstruktory operator1;
    konstruktory operator2(5,12);
    konstruktory operator3(5);
    konstruktory operator4(operator1);
    operator4=operator2;
    class liczba licz;
    cout<<licz(6)<<'\n';
    cout<<licz(7,2)<<'\n';
    cout<<licz('z')<<'\n';
    kompozycja2 tab(3);
    cout<<tab;
    return 0;
}
