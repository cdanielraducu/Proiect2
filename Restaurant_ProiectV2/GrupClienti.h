//
// Created by cdani on 11/24/2019.
//

#ifndef RESTAURANT_PROIECTV2_GRUPCLIENTI_H
#define RESTAURANT_PROIECTV2_GRUPCLIENTI_H


#include <vector>
#include <iostream>
#include "Client.h"
#include "Comanda.h"

class GrupClienti : public Client,public Comanda{
protected:
    int grupID;
    int nr_clienti;
    Comanda comanda;

    vector<Client> grupClient;
    vector<Comanda> comandaClient;
    int okAvetiRezervataMasa;
public:
    explicit GrupClienti(int nr_clienti, int id);
    GrupClienti(int id);
    GrupClienti();
    ~GrupClienti();

    int getNrClienti() const;

    void setNrClienti(int nrClienti);

    int getGrupID() const;

    void setGrupId(int grupId);

    int getOkAvetiRezervataMasa() const;

    void setOkAvetiRezervataMasa(int okAvetiRezervataMasa);

    const vector<Client> &getGrupClient() const;

    const vector<Comanda> &getComandaClient() const;

    const Comanda &getComanda() const;


    friend ostream &operator<<(ostream &out, const GrupClienti &grup);
    friend istream &operator>>(istream &in, GrupClienti &grup);\
    GrupClienti &operator=(const GrupClienti &grup);
    GrupClienti(const GrupClienti &grup);

    void addClientLaGrup(const Client& client);

    bool callChelner() const{
        return true;
    }
    void AchitarePentru(int index,bool tip){
        grupClient[index].setAchitat(tip);
    }
    void ConsumatiePentru(int index, int cat){

        comandaClient[index].setPretPerMasa(cat);

        comanda.setPretPerMasa(cat);
    }
    void BonConsumatiePentru(int index, string s){
        comandaClient[index].setBon(s);
    }
    void ConsumatiePentruGrup(int cat){
        comanda.setPretPerMasa(cat);
    }
    void BonConsumatiePentruGrup(string s){
        comanda.setBon(s);
    }

};


#endif //RESTAURANT_PROIECTV2_GRUPCLIENTI_H
