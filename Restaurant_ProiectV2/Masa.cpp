//
// Created by cdani on 11/26/2019.
//

#include "Masa.h"
using namespace std;

Masa::Masa(int id, int locuri) {
    this->id = id;
    this->locuri = locuri;
    this->rezervat = false;
    this->rezervatToGRUPID = 0;
}

Masa::Masa() {
    this->id = 0;
    this->locuri = 0;
    this->rezervat = false;
    this->rezervatToGRUPID = 0;
}
Masa::~Masa() {
    //cout<<"Destructor pentru masa:"<<this->getId()<<endl;
}

ostream&operator<<(ostream &out, Masa &m){
    out<<"Masa #"<<m.getId()<<" are "<<m.getLocuri()<<" locuri!\n";
    return out;
}

istream&operator>>(istream &in, Masa &m){
    int id;
    int nrL;
    cout<<"A cata masa este asta: "; cin>>id; cin.clear();
    cout<<"Cate locuri are: "; cin>>nrL; cin.clear();
    m.setId(id);
    m.setLocuri(nrL);
    m.setRezervat(false);
    m.rezervatToGRUPID = 0;
    return in;
}

bool Masa::isRezervat() const {
    return rezervat;
}

void Masa::setRezervat(bool rezervat) {
    Masa::rezervat = rezervat;
}

void Masa::setLocuri(int locuri) {
    Masa::locuri = locuri;
}

int Masa::getLocuri() const {
    return locuri;
}

void Masa::setId(int id) {
    Masa::id = id;
}

int Masa::getId() const {
    return id;
}
