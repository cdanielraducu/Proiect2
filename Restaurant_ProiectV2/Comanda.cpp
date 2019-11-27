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

int Comanda::getPretPerMasa() const {
    return pretPerMasa;
}

void Comanda::setPretPerMasa(int pret) {

    this->pretPerMasa = pret;
    cout<<"aaaaaaaaaaaaaaaaaaaa\n";
}
