//
// Created by cdani on 11/24/2019.
//

#include "GrupClienti.h"
#include <vector>



GrupClienti::GrupClienti(int nr_clienti, int id) {
    this->nr_clienti = nr_clienti;

    grupID = id;
    okAvetiRezervataMasa = 0;
    for(int i{0}; i<nr_clienti; i++) {
        Client clientNou(i+1);
        Comanda comandaNoua;
        cin>>clientNou; cin.clear();
        grupClient.push_back(clientNou);
        comandaClient.push_back(comandaNoua);
    }
}

GrupClienti::GrupClienti(int id) {

    grupID = id;
    nr_clienti = 0;
    okAvetiRezervataMasa = 0;
}

int GrupClienti::getNrClienti() const {
    return nr_clienti;
}
void GrupClienti::setNrClienti(int nrClienti) {
    nr_clienti = nrClienti;
}

int GrupClienti::getGrupID() const {
    return grupID;
}

ostream &operator<<(ostream &out, const GrupClienti &grup) {
    cout<<"Grupul: "<<grup.getGrupID()<<endl;
    for(int i{0}; i<grup.getNrClienti(); i++){
        cout<<"Pentru clientul: "<<grup.grupClient[i].getClientID()<<endl;
        cout<<grup.grupClient[i];
    }
    return out;
}
GrupClienti::~GrupClienti() = default;

istream &operator>>(istream &in, GrupClienti &grup) {
    cout<<"Cate persoane sunteti: "; int n; cin>>n; cin.clear();
    grup.setNrClienti(n);
    for(int i{0}; i<grup.getNrClienti(); i++){
        Client clientNou(i+1);
        Comanda comandaNoua;
        cin>>clientNou; cin.clear();
        grup.addClientLaGrup(clientNou);
        grup.comandaClient.push_back(comandaNoua);
    }

    return in;
}

GrupClienti::GrupClienti(const GrupClienti &grup) {
    this->setNrClienti(grup.getNrClienti());
    grupID = grup.getGrupID();
    this->grupClient.clear();
    //sterge bine tot, clear-ul?
    for(int i{0}; i <this->getNrClienti(); i++) {
        this->addClientLaGrup(grup.grupClient[i]);
    }
}

GrupClienti& GrupClienti::operator=(const GrupClienti &grup) {
    this->setNrClienti(grup.getNrClienti());
    this->grupClient.clear();
    for(int i{0}; i<this->getNrClienti(); i++) {
        this->addClientLaGrup(grup.grupClient[i]);
    }
    return *this;
}

void GrupClienti::addClientLaGrup(const Client& client) {
    grupClient.push_back(client);
}

int GrupClienti::getOkAvetiRezervataMasa() const {
    return okAvetiRezervataMasa;
}

void GrupClienti::setOkAvetiRezervataMasa(int okAvetiRezervataMasa) {
    GrupClienti::okAvetiRezervataMasa = okAvetiRezervataMasa;
}

const vector<Client> &GrupClienti::getGrupClient() const {
    return grupClient;
}

const vector<Comanda> &GrupClienti::getComandaClient() const {
    return comandaClient;
}

const Comanda &GrupClienti::getComanda() const {
    return comanda;
}


void GrupClienti::setGrupId(int grupId) {
    grupID = grupId;
}

GrupClienti::GrupClienti() {
    grupID = 0;
    nr_clienti = 0;
    okAvetiRezervataMasa = 0;
}




