//
// Created by cdani on 11/25/2019.
//

#ifndef RESTAURANT_PROIECTV2_COMANDA_H
#define RESTAURANT_PROIECTV2_COMANDA_H

#include <string>

using  namespace std;
#include <iostream>

class Comanda{
protected:
    int pret{0};
    string bon{""};
public:
    Comanda(){
        pret = 0;
        bon = "";
    }
    ~Comanda(){//cout<<"Comanda::Destructor";
        cout<<""; }

    const string &getBon() const;

    void setBon(const string &bon);

    int getPret() const;

    void setPret(int pretPerMasa);

};


#endif //RESTAURANT_PROIECTV2_COMANDA_H
