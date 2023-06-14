//funkcja szablonowa przyjmie obiekt jakiegokolwiek typu
template<typename typ>
typ dodawanie(typ a,typ b){
    return a+b;
}
template<typename typ>
typ iloczyn(typ a,typ b){
    return a*b;
}
//tworzenie tabeli typu T o wielkosci roz
template<typename T>T* stworz(int roz){
    T* wsk=new T[roz];
    return wsk;
}
//sortuj tabele typu T
template<typename T>void sortuj(T table[],int roz){
    cout<<"Sortuje tabele typu "<< typeid(T).name()<<'\n';
    sort(table,table+roz);
}
//tworzenie struktury jakiegos typu na przykladzie stosu jesli chcemy uzyc stosu dla naszych klas musimy pamietac o
// stworzeniu operatorow dla nich w naszym przypadku (klasy kompozycja1) potrzebujemy << i kompozycja1=int
template<typename T> class stos{
    T *tab;
    int rozmiar;
    public:
        int liczba_obiektow;
        stos():rozmiar(5),tab(new T[5]),liczba_obiektow(0){}
        stos(int roz):rozmiar(roz),tab(new T[roz]),liczba_obiektow(0){}
        ~stos(){delete tab;}
        void push(T parametr){
            if(liczba_obiektow<rozmiar){
                tab[liczba_obiektow]=parametr;
                liczba_obiektow++;
            }
            else{
                cout<<"Stack overflow\n";
            }
        }
        void pop(){
            if(liczba_obiektow=0){
                cout<<"Stos jest pusty\n";
            } else{
                tab[liczba_obiektow]=0;
                liczba_obiektow--;
            }
        }
        void zobacz(){
            cout<<tab[liczba_obiektow-1];
        }
        int ilosc(){
            return liczba_obiektow;
        }
        bool isempty(){
            if(liczba_obiektow=0){
                return true;
            }
            else{
                return false;
            }
        }
    };