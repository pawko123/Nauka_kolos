class liczba{
    int x;
    static int statyczna;
public:
    liczba(int x):x(x){}
    liczba():x(5){}
    int getx(){return x;}
    void setx(int x){this->x=x;}
    //przypisanie
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
    //przeladowanie operatora
    liczba operator+(int number){
        return liczba(this->x+number);
    }
    friend liczba operator+(int number,liczba& number2){
        liczba temp=number2+number;
        return temp;
    }
    //operatory logiczne == > < itp
    bool operator==(liczba& parametr){
        if(this->x==parametr.x){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool operator<(liczba& parametr){
        if(this->x<parametr.x){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool operator>(liczba& parametr){
        if(this->x>parametr.x){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool operator<=(liczba& parametr){
        if(this->x<=parametr.x){
            return 1;
        }
        else{
            return 0;
        }
    }
    //itd
    //operatory += *=
    void operator+=(liczba& parametr){
        this->x+=parametr.x;
    }
    void operator*=(liczba& parametr){
        this->x*=parametr.x;
    }
    //pre i post inkrementacja/dekrementacja ( aby miec dekrementacje zmieniamy ++ na --
    liczba operator++(){
        this->x++;
        return *this;
   }
    liczba operator++(int) {
        liczba temp = *this;
        ++*this;
        return temp;
    }
    //operator () ,jesli chcemy zeby strukture wywolac jak funkcje
    int operator()(int i){
        statyczna+=i;
        return statyczna;
    }
    int operator()(int i,int j){
        statyczna=i+j;
        return statyczna;
    }
    int operator()(char znak){
        statyczna=znak;
        return statyczna;
    }
    //operatory << >>
    friend ostream& operator<<(ostream& out,const liczba parametr){
        out<<parametr.x;
        return out;
    }
    friend istream& operator>>(istream& in,liczba &parametr){
        in>>parametr.x;
        return in;
    }
};
