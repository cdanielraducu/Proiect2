//
// Created by cdani on 11/25/2019.
//

#include "Comanda.h"


const string &Comanda::getBon() const {
    return bon;
}

void Comanda::setBon(const string &bonMasa) {
    this->bon += bonMasa;
}

int Comanda::getPret() const {

    return pret;

}

void Comanda::setPret(int pret) {

    this->pret = pret;
    cout<<"aaaaaaaaaaaaaaaaaaaa\n";
}
