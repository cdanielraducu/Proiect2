//
// Created by cdani on 11/26/2019.
//

#include "Restaurant.h"



using namespace std;


ostream&operator<<(ostream &out, Restaurant &r){
    for(unsigned int i{0};i<r.Mese.size(); i++){
        out<<r.Mese[i];
    }
    return out;
}
istream&operator>>(istream &in, Restaurant &r){
    cout<<"Cate mese are restaurantul: "; int n; in>>n;
    r.setNrMese(n);
    for(int i{0}; i<r.getNrMese(); i++){
        cout<<"Cate locuri are masa: "<<i+1<<" - ";
        Masa masa;
        int nLocuri; in>>nLocuri;
        masa.setLocuri(nLocuri);
        masa.setId(i+1);
        masa.setRezervat(false);
       masa.setRezervatToGrupID(0);
        r.Mese.push_back(masa);

    }

    r.setNrChelneri(n);
    for(int i{0}; i<r.getNrChelneri(); i++){
        Chelner chelner(i+1);
        r.Chelneri.push_back(chelner);
    }
    return in;

}
Restaurant::~Restaurant() {
    //cout<<"Destructor pentru restaurant!\n";
}


int Restaurant::getNrMese() const {
    return nrMese;
}

void Restaurant::setNrMese(int nrMese) {
    Restaurant::nrMese = nrMese;
}

Restaurant::Restaurant(string nume, int nrMese, int nrChelneri) {
    this->numeRestaurant = std::move(nume);
    this->nrMese = nrMese;
    for(int i{0}; i<nrMese; i++){
        cout<<"\nCate locuri are masa: "<<i+1<< " - ";
        Masa masa;
        int nrLoc;
        cin>>nrLoc; cin.clear();
        masa.setId(i+1);
        masa.setLocuri(nrLoc);
        masa.setRezervat(false);
        masa.setRezervatToGrupID(0);
        Mese.push_back(masa);
    }
    this->nrChelneri = nrChelneri;
    for(int i{0}; i<nrChelneri; i++){
        Chelner chelner(i+1);
        Chelneri.push_back(chelner);
    }
}

Restaurant::Restaurant() {
    numeRestaurant = "";
    nrMese = 0;
}

const vector<Masa> &Restaurant::getMese() const {
    return Mese;
}

void Restaurant::setMese(const vector<Masa> &mese) {
    Mese = mese;
}

const string &Restaurant::getNumeRestaurant() const {
    return numeRestaurant;
}

void Restaurant::setNumeRestaurant(const string &numeRestaurant) {
    Restaurant::numeRestaurant = numeRestaurant;
}

const vector<Chelner> &Restaurant::getChelneri() const {
    return Chelneri;
}

int Restaurant::getNrChelneri() const {
    return nrChelneri;
}

void Restaurant::setNrChelneri(int nrChelneri) {
    Restaurant::nrChelneri = nrChelneri;
}

const string &Restaurant::getBonPerClient() const {
    return bonPerClient;
}

void Restaurant::setBonPerClient(const string &bonPerClient) {
    Restaurant::bonPerClient = bonPerClient;
}





