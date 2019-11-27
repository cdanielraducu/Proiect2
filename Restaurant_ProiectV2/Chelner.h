//
// Created by cdani on 11/25/2019.
//

#ifndef RESTAURANT_PROIECTV2_CHELNER_H
#define RESTAURANT_PROIECTV2_CHELNER_H

#include <string>
#include <utility>
#include <iostream>
#include "Comanda.h"


using namespace std;

class Chelner: public Comanda{
protected:
    int id;

protected:
    bool amClientiRezervati;
public:
    explicit Chelner(int id){
        this->id = std::move(id);
        this->amClientiRezervati = false;
    }
    Chelner() {
        this->id = 0;
        amClientiRezervati = false;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Chelner::id = id;
    }

    bool isAmClientiRezervati() const {
        return amClientiRezervati;
    }

    void setAmClientiRezervati(bool amClientiRezervati)  {
        Chelner::amClientiRezervati = amClientiRezervati;
    }



    bool canServe() const {
        if(amClientiRezervati){
            cout<<"Clientii pot comanda\n";
            //daca nu au inca o masa rezervata atunci ii punem la una prin Restaurant

            return true;
        } else {
            cout<<"Clientii nu au nici o masa rezervata, deci le punem una!\n";
            return false; // asta le pune o masa
        }
    }

};


#endif //RESTAURANT_PROIECTV2_CHELNER_H
