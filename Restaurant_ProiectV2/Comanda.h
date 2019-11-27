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
    int pretPerMasa;
    string bon;
public:
    Comanda(){
        pretPerMasa = 0;
        bon = "";
    }
    ~Comanda(){//cout<<"Comanda::Destructor";
        cout<<""; }

    const string &getBon() const;

    void setBon(const string &bon);

    int getPretPerMasa() const;

    void setPretPerMasa(int pretPerMasa);

};


#endif //RESTAURANT_PROIECTV2_COMANDA_H
