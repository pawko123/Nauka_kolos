int dodaj(int a,int b){
    return a+b;
}
int odejmij(int a,int b){
    return a-b;
}
int mnozenie(int a,int b){
    return a*b;
}
int dzielenie(int a,int b){
    return a/b;
}
/*funkcja wynik ktora wskaznikiem odwoluje sie do jakiejkolwiek funkcji ktora ma dwa parametry int, jesli chcielibysmy wskaznik do funkcji ktora
 jako parametry przujmuje 2 chary i int i zwraca void to zapisujemy void(*wsk)(int,char,char) 
 */
int wynik(int a,int b,int(*wsk)(int,int)){
    int w=(wsk)(a,b);
    return w;
}