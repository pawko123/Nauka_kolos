#include<iostream>
using namespace std;
#include"wskazniki.cpp"
#include"konstruktory.cpp"
#include"statyczne.cpp"
#include "operatory.cpp"
#include "kompozycja.cpp"
#include "dziedziczenie.cpp"
#include "szablony.cpp"
namespace wskazniki{
    void pokaz_wsk_funkcji() {
        int x = 5;
        int y = 4;
        //w miejscu wskaznika do funkcji dajemy jej nazwe
        cout << wynik(x, y, dodaj) << endl;
        cout << wynik(x, y, odejmij) << endl;
        cout << wynik(x, y, mnozenie) << endl;
        cout << wynik(x, y, dzielenie) << endl;
        //tablica wskaznikow do funkcji
        int (*funkcje[4])(int, int);
        funkcje[0] = dodaj;
        funkcje[1] = odejmij;
        funkcje[2] = mnozenie;
        funkcje[3] = dzielenie;
        int wynik = funkcje[2](5, 2);
        cout << wynik << '\n';

    }
    void pokaz_wsk(){
        //wskaznik na stala int, wskazanie na normalnego int tez dziala ¯\_(ツ)_/¯, nie mozna tylko przypisac innej wartosci
        //za pomoca wskaznika
        int test=2;
        const int *p;
        p=&test;
        cout<<*p;
        //p=4 - tak nie mozna bo int jest staly
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
    }
}
namespace statyczne{
    void pokaz_statyczne(){
        statyczna static1;
        statyczna static2;
        cout<<statyczna::wypisz()<<endl;
    }
}
namespace konwersja{
    void pokaz_konwersja(){
        //funkcja konwertujaca to taka co zmienia typ zmiennej, przykladem takiej jest to_string lub float char itp,funkcja
        //ktora przyjmuje wartosc 1 typu i zmienia go na drugi
        int liczba2=4124131;
        int liczba=123;
        char znak=char(liczba);
        string napis= to_string(liczba2);
        cout<<float(liczba2)/float(100000)<<'\n';
        cout<<znak<<'\n';
    }
}
namespace rozne_konstruktory{
    void pokaz_konstruktory(){
        konstruktory operator1;
        konstruktory operator2(5,12);
        konstruktory operator3(5);
        konstruktory operator4(operator1);
        //zobacz w debugger czy sa takie same
        operator4=operator2;
    }
}
namespace uzycie_operatorow{
    void pokaz_operatory(){
        liczba licz;
        cout<<++licz;
        cout<<licz++;
        cout<<licz;
        cout<<licz(6)<<'\n';
        cout<<licz(7,2)<<'\n';
        cout<<licz('z')<<'\n';
        //sprobuj inne operatory
    }
}
namespace kompozycje{
    void pokaz_kompozycje(){
        kompozycja2 tab(3);
        cout<<tab;
    }
}
namespace dziedziczenie{
    void wywolywanie_funkcji(){
        // przy przypisywaniu wartosci funkcji pochodnych mozna przypisac tylko objekty klasy pochodnej do klasy bazowej,
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
    }
    void polimorfizm(){
        B b(6,1);
        C c(2,5,2);
        wypisz(b);
        wypisz(c);
    }
    void dekonstruktor_wirtualny(){
        //przy tworzeniu obiektu wskaznika na klase bazowa wykona nam sie kontruktor klasy bazowej i pochodnej
        //a przy usunieciu wskaznika dzieki destruktorowi wirtualnemu wywola sie dekonstruktor bazowy i pochodny
        //jakbysmy usuneli virtual ze wskaznika wywolalby sie tylko dekostruktor funkcji bazowej co byloby problemem
        //gdyby funkcja pochodna posiadal tablice lub jakis inny wskaznik
        bazowa* dekonstruktor = new pochodna;
        delete dekonstruktor;
    }
}
namespace szablony{
    void funkcje_szablonowe(){
        //cout<<dodawanie(4.2,5.3)<<'\n';
        //cout<<dodawanie(4,5)<<'\n';
        //cout<<dodawanie('0','1')<<'\n';
        float tablica_zp[]={3.4,2.2,3.1,5.2,1.1};
        sortuj(tablica_zp,sizeof(tablica_zp)/sizeof(float) );
        cout<<tablica_zp[0]<<'\n';
        cout<<tablica_zp[1]<<'\n';
        cout<<tablica_zp[2]<<'\n';
        cout<<tablica_zp[3]<<'\n';
        cout<<tablica_zp[4]<<'\n';
        //jak widac funkcje te dzialaja dla int,float i char oraz innych ktore mozna posortowac
        int *tablica_int=stworz<int>(10);
        sortuj(tablica_int,sizeof(*tablica_int)/sizeof (int));
        }
        void klasa_szablonowa(){
            //tworzenie stosu i wywolanie funkcji
            stos<int> stosik;
            stosik.push(4);
            stosik.push(5);
            cout<<stosik.ilosc()<<'\n';
            stos<kompozycja1> stos_klasy(4);
            stos_klasy.push(kompozycja1(4,3));
            stos_klasy.zobacz();
            stos_klasy.pop();
            stos_klasy.zobacz();
        }
        void klasa_szablonowa_z_dziedziczeniem(){
            klasa_bazowa<int> dziedziczenie(14);
            dziedziczenie.wyswietl();
            klasa_bazowa<int>*dziedziczenie2=new klasa_pochodna<int>(6);
            dziedziczenie2->wyswietl();
            klasa_pochodna<int> dziedziczenie3(7);
            dziedziczenie=dziedziczenie3;
            dziedziczenie.wyswietl();
        }
    }
    int statyczna::y=1;
    int liczba::statyczna=0;
    int main(){
        //zeby zobaczyc wyniki odkomentuj odpowiednie funkcje
        //wskazniki::pokaz_wsk();
        //wskazniki::pokaz_wsk_funkcji();
        //statyczne::pokaz_statyczne();
        //konwersja::pokaz_konwersja();
        //rozne_konstruktory::pokaz_konstruktory();
        //uzycie_operatorow::pokaz_operatory();
        //w tej funkcji musisz przypisac wartosci
        //kompozycje::pokaz_kompozycje();
        //dziedziczenie::wywolywanie_funkcji();
        //dziedziczenie::polimorfizm();
        //dziedziczenie::dekonstruktor_wirtualny();
        //szablony::funkcje_szablonowe();
        //szablony::klasa_szablonowa();
        //szablony::klasa_szablonowa_z_dziedziczeniem();
        return 0;
}
