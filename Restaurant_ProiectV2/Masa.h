//
// Created by cdani on 11/26/2019.
//

#ifndef RESTAURANT_PROIECTV2_MASA_H
#define RESTAURANT_PROIECTV2_MASA_H

using namespace std;
#include <iostream>

class Masa {
protected:

    int id;
    int locuri;
    bool rezervat;
    int rezervatToGRUPID;

public:
    Masa(int id, int locuri);
    Masa();

    ~Masa();
    friend ostream&operator<<(ostream&, Masa&);
    friend istream&operator>>(istream&, Masa&);
    //nu are sens sa fac si = pt MASA si nici copy constructorul



public:
    int getId() const;

    void setId(int id);

    int getLocuri() const;

    void setLocuri(int locuri);

    bool isRezervat() const;

    void setRezervat(bool rezervat);

    int getRezervatToGrupID() const {
        return rezervatToGRUPID;
    }

    void setRezervatToGrupID(int x){
        this->rezervatToGRUPID = x;
    }

};


#endif //RESTAURANT_PROIECTV2_MASA_H
