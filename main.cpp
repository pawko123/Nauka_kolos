#include<iostream>
#include"wskazniki.cpp"
#include"konstruktory.cpp"
#include"statyczne.cpp"
#include "operatory.cpp"
#include "kompozycja.cpp"
#include "dziedziczenie.cpp"
#include "szablony.cpp"
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
//    cout<<++licz;
//    cout<<licz++;
//    cout<<licz;
    cout<<licz(6)<<'\n';
    cout<<licz(7,2)<<'\n';
    cout<<licz('z')<<'\n';
    /*dziedziczenie
     kompozycja2 tab(3);
    cout<<tab;*/
    // przy przypisywaniu wartosci funkcji pochodnych mozna przypisac tylko objekty klasy pochodnej do klasy oryginalnej,
    //na odwrot nie mozna
    //py=&x; tak nie wolno!! poniewaz obiekt py jest wskaznikiem na klase Y ktora jest pochodna klasy X ktorej obiektem jest x
    px=&y;
    //wywola sie funkcja f() klasy Y poniewaz funkcja f() w klasie X ma wartosc virtual wiec kompilator patrzy czy w Y znajduje sie ta
    // funkcja i ja znajduje, jakby w funkcji Y nie bylo funkcji f() to program wywolalby funkcje f() klasy y
    //przez to funkcje wirtualne nakladaja dodatkowy czas podczas wykonywania programu, poniewaz wykonuja pozne wiazanie
    px->f();
    //funkcja f1() nie ma virtual wiec zawsze wykona sie funkcja klasy wskaznika- px jest X* wiec wywola X.f1(), a py jest Y* wiec wywola Y.f1()
    px->f1();
    py=&z;
    py->f();
    py->f1();
    B b(6,1);
    C c(2,5,2);
    wypisz(b);
    wypisz(c);
    //przy tworzeniu obiektu wskaznika na klase bazowa wykona nam sie kontruktor klasy bazowej i pochodnej
    //a przy usunieciu wskaznika dzieki destruktorowi wirtualnemu wywola sie dekonstruktor bazowy i pochodny
    //jakbysmy usuneli virtual ze wskaznika wywolalby sie tylko dekostruktor funkcji bazowej co byloby problemem
    //gdyby funkcja pochodna posiadal tablice lub jakis inny wskaznik
    bazowa* dekonstruktor = new pochodna;
    delete dekonstruktor;
    cout<<dodawanie(4.2,5.3)<<'\n';
    cout<<dodawanie(4,5)<<'\n';
    cout<<dodawanie('0','1')<<'\n';
   // char *tablica_znakow=stworz<char>(5);
    float tablica_zp[]={3.4,2.2,3.1,5.2,1.1};
    sortuj(tablica_zp,sizeof(tablica_zp)/sizeof (float));
    cout<<tablica_zp[0]<<'\n';
    cout<<tablica_zp[1]<<'\n';
    cout<<tablica_zp[2]<<'\n';
    //jak widac funkcje te dzialaja dla int,float i char oraz innych ktore mozna posortowac
    /*int *tablica_int=stworz<int>(10);
    sortuj(tablica_int,sizeof(*tablica_int)/sizeof (int));
    cout<<tablica_int[0]<<'\n';
    cout<<tablica_int[1]<<'\n';
    cout<<tablica_int[2]<<'\n';
     */
    //tworzenie stosu i wywolanie funkcji
    stos<int> stosik;
    stosik.push(4);
    stosik.push(5);
    cout<<stosik.ilosc()<<'\n';
    stos<kompozycja1> stos_klasy(4);
    stos_klasy.push(kompozycja1(4,3));
    stos_klasy.zobacz();
    return 0;
}
