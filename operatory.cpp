class liczba{
    int x;
public:
    liczba(int x):x(x){}
    int getx(){return x;}
    void setx(int x){this->x=x;}
    void operator=(const liczba &oryginal){
        this->x=oryginal.x;
    }
    //operatory + - / *
    liczba operator+(liczba &parametr){
        return liczba(x+parametr.x);
    }
    liczba operator-(liczba &parametr){
        return liczba(x-parametr.x);
    }
    liczba operator/(liczba &parametr){
        return liczba(x/parametr.x);
    }
    liczba operator*(liczba &parametr){
        return liczba(x*parametr.x);
    }
    //operatory logiczne == > < itp
};
