class konstruktory{
    int x;
    int *wsk;
    int rozmiar;
public:
    //konstruktor domyslny(domniemany) - inicjalizuje sie gdy nie ma podanych parametrow przy inicjalizacji
    konstruktory():x(5),wsk(new int[10]),rozmiar(10){}
    konstruktory(int liczba,int rozmiar):x(liczba),wsk(new int[rozmiar]),rozmiar(rozmiar){}
    //konstruktor konwertujacy - konwertuje typ jakiejs zmiennej na obiekt klasy, w tym przypadku uzywa liczby calkowitej aby utworzyc obiekt klasy konstruktory
    konstruktory(int rozmiar):x(1),wsk(new int[rozmiar]),rozmiar(rozmiar){}
    //konstruktor kopiujacy - służy do tworzenia nowego obiektu na podstawie istniejącego obiektu tego samego typu oraz jesli chcemy uniknac usuniecia wskaznika dla dwoch obiektow zamiast jednego
    konstruktory(const konstruktory &oryginal){
        x=oryginal.x;
        rozmiar=oryginal.rozmiar;
        //teraz nowy stworzony obiekt ktory jest kopia oryginalu nie bedzie mial wskaznika do tej samej tablicy co oryginal(bez stworzenia kon. kop. kompilator by tak zrobil)
        wsk=new int[rozmiar];
        for(int i=0;i<rozmiar;i++){
            wsk[i]=oryginal.wsk[i];
        }
    }
    //dekonstruktor - uruchamia sie przy niszczeniu objektu klasy, powinien usuwac wszystkie wskazniki ktore tworzy klasa
    ~konstruktory(){
        delete[] wsk;
    }
    //operator przypisania
    void operator=(konstruktory &oryginal){
        x=oryginal.x;
        rozmiar=oryginal.rozmiar;
        delete[] wsk;
        wsk=new int[rozmiar];
        for(int i=0;i<rozmiar;i++){
            wsk[i]=oryginal.wsk[i];
        }
    }
    //operator [] - przydatny jesli obiekt zawiera tabele
    int & operator[](int index){
        return wsk[index];
    }
};