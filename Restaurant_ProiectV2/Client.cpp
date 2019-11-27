//
// Created by cdani on 11/20/2019.
//

#include <iostream>
#include "Client.h"
#include <string.h>


const string &Client::getNume() const {
    return nume;
}

void Client::setNume(const string &nume) {
    this->nume = nume;
}

bool Client::isAchitat() const {
    return achitat;
}

void Client::setAchitat(bool achitat) {
    this->achitat = achitat;
}

Client::Client(string nume,int varsta, int id) {
    this->nume = nume;
    this->varsta = varsta;
    clientID = id;
    achitat = false;
    consumatie = 0;

}
Client::Client() {
    this->nume = "";
    achitat = false;
    this->varsta = 0;
    clientID = 1;
    consumatie = 0;
}
Client::Client(int id) {
    this->nume = "";
    achitat = false;
    this->varsta = 0;
    clientID = id;
    consumatie = 0;
}

int Client::getConsumatie() const {
    return consumatie;
}

void Client::setConsumatie(int consumatie) {
    cout<<"==================================\n";
    this->consumatie = consumatie;
}

int Client::getVarsta() const {
    return varsta;
}

void Client::setVarsta(int varsta) {
    this->varsta = varsta;
}


int Client::getClientID() const {
    return clientID;
}

ostream &operator<<(ostream &out, const Client &client) {
    cout<<"=======================================================\n";
    cout << "nume: " << client.nume << "\nvarsta: " << client.varsta << "\nconsumatie: "
        << client.consumatie << " \nachitat: " << client.achitat<<endl;
    cout<<"=======================================================\n";
    return out;
}

istream &operator>>(istream &in, Client &client){
    string nume;
    int varsta;
    cout<<"Ce nume aveti: "; cin>>nume; cin.clear();
    cout<<"Varsta: "; cin>>varsta; cin.clear();
    client.setNume(nume);
    client.setVarsta(varsta);
    return in;
}
Client::~Client() {
    //cout<<"Se apeleaza destructorul pentru clientul: "<<getClientID()<<endl;
}

Client::Client(const Client &client) {
    this->nume = client.nume;
    this->varsta = client.varsta;
    this->consumatie = client.consumatie;
    this->achitat = client.achitat;
    //cum fac cu clientID-ul, ramane asa sa primeste un ID nou?
    //cumva cand apelez toata treaba din grupClienti sa nu mai faca clientID
    //poate cu o exceptie sau cu mostenire/functii virtuale?
    //this->setClientID(this->getClientID());
    this->clientID = client.clientID;
}
Client &Client::operator=(const Client &client) {
    this->setNume(client.nume);
    this->setVarsta(client.varsta);
    this->setConsumatie(client.consumatie);
    this->setAchitat(client.achitat);
    //this->setClientID(this->getClientID());
    this->clientID = client.clientID;
    return *this;
}
void Client::setClientID(int ID) {
    if(this->clientID == 0 || this->clientID == 1){
        cout<<"ce name o sa aibe: "; int n;
        cin>>n; cin.clear();
        this->clientID = n;
    }
    else this->clientID = ID;
}

const string &Client::getConsumatieInScris() const {
    return consumatieInScris;
}

void Client::setConsumatieInScris(const string &consumatieInScris) {
    Client::consumatieInScris = consumatieInScris;
}
