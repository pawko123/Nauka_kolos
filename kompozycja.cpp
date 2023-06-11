class kompozycja1{
public:
    int x,y;
    kompozycja1(int i,int j):x(i),y(j){}
    kompozycja1():x(0),y(0){}
    friend ostream &operator<<(ostream& out,kompozycja1& parametr){
        out<<parametr.x<<' '<<parametr.y<<'\n';
        return out;
    }
    friend istream &operator>>(istream& in,kompozycja1& parametr){
        in>>parametr.x;
        in>>parametr.y;
        return in;
    }
};
class kompozycja2{
public:
    int rozmiar;
    kompozycja1 *tablica;
    kompozycja2(int roz):rozmiar(roz){
        tablica=new kompozycja1[roz];
        for(int i=0;i<roz;i++){
            cin>>tablica[i];
        }
    }
    void operator[](int index){
        cout<<tablica[index];
    }
    friend ostream &operator<<(ostream& out,kompozycja2 &parametr){
        for(int i=0;i<parametr.rozmiar;i++){
            out<<parametr.tablica[i];
        }
        return out;
    }
};