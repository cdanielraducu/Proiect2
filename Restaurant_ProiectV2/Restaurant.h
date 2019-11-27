//
// Created by cdani on 11/26/2019.
//

#ifndef RESTAURANT_PROIECTV2_RESTAURANT_H
#define RESTAURANT_PROIECTV2_RESTAURANT_H


#include "Masa.h"
#include "Chelner.h"
#include <utility>
#include <vector>
#include <string>


class Restaurant: public Masa, public Chelner {
private:
        vector<Masa> Mese;
        vector<Chelner> Chelneri;
        string numeRestaurant;
        int nrMese;
        int nrChelneri;
    string bonPerClient;

public:

        Restaurant();
        Restaurant(string nume, int nrMese, int nrChelneri);
        ~Restaurant();
        friend ostream&operator<<(ostream &, Restaurant &);
        friend istream&operator>>(istream &, Restaurant &);


    const string &getBonPerClient() const;

    void setBonPerClient(const string &bonPerClient);

    int getNrMese() const;

    void setNrMese(int nrMese);

    const vector<Masa> &getMese() const;

    void setMese(const vector<Masa> &mese);

    const string &getNumeRestaurant() const;

    void setNumeRestaurant(const string &numeRestaurant);

    const vector<Chelner> &getChelneri() const;

    int getNrChelneri() const;

    void setNrChelneri(int nrChelneri);

    void seteazaMasaChelnerClientiReservati(int i, bool tip){
        Chelneri[i].setAmClientiRezervati(tip);
    }
    void seteazaMasaRezervatPentruGrupClientID(int indexMasa,int indexGrup, bool tip){
        Mese[indexMasa].setRezervat(tip);
        Mese[indexMasa].setRezervatToGrupID(indexGrup);
    }

    Masa iteratorMese(int i) {
        for(int j{0}; j<nrMese; j++) {
            if (Mese[i].getId() == i + 1) {
                return Mese[i];
            }
        }
        cout<<"nu am gasit masa cautata!\n";
    }

    int masaLibera(){
        //cum facem rezervarea pentru grup
        //ne folosim de main//aici o sa returnam ceva daca putem sa rezervam o masa
        // si in main asignam id-ul mesei grupului // si apoi ii punem mesei grupul care a fost rezervat
        for(int i{0}; i<nrMese ;i++){
            if(!isRezervat()){
                return Mese[i].getId(); // se poate rezerva masa ID;
            }
        }
        return 0; // nu se poate rezerva nici o masa
    }

    int canServeEachClient(int x){

        switch(x) {
            case 1: {
                //            cout<<"Ce doriti?\n";
//            cout<<"5 - Meniul cu de toate\n";
//            cout<<"1 - Doar De baut?\n";
//            cout<<"2 - Doar Ciorba?\n";
//            cout<<"3 - Doar Fel principal?\n";
//            cout<<"4 - Doar Desert?\n";
//            cout<<"0 - Nu mai vreau nimic\n";
                int adaugareLaTotal{0};
                adaugareLaTotal = menu(5);

                return adaugareLaTotal;
                break;
            }
            case 2: {
//                cout<<"Uite nota de plata...\n";
                return -100;
                break;
            }
            case -1: {
                return -1;
                break;
            }
            default: {
                cout<<"Nimic";
                break;
            }
        }
        return -1000;
    }

public:
    int menu_bautura(bool ce_facem, string *bon){
        int pret_bautura_total{0};
        if(!ce_facem){
            return 0;
        } else {
            cout<<"Ce doriti?\n";
            cout<<"vin\nbere\napa\n";
            string r; std::cin>>r; cin.clear();
            string pahar_sticla = "pahar \nsticla\n";
            string multumesc = "Multumesc!\n";
            if(r == "Vin" || r == "vin" || r == "VIN") {
                *bon +="vin ";
                cout<<pahar_sticla;
                cout<<"Pahar - 150ml (20 lei)\n Sticla - 700ml (75 lei)\n";
                string r2; std::cin >> r2; cin.clear();
                if(r2 == "Pahar" || r2 == "pahar" || r2 == "PAHAR") {
                    *bon +="la pahar - 20 lei";
                    pret_bautura_total+=20;
                }else if(r2 == "Sticla" || r2 == "sticla" || r2 == "STICLA") {
                    *bon +="la sticla - 75 lei";
                    pret_bautura_total +=75;
                }
                cout<<multumesc;
            } else if(r == "Bere" || r == "bere" || r == "BERE") {
                *bon +="bere ";
                cout<<pahar_sticla;
                cout<<"Pahar - 500ml (8 lei)\nSticla - 330ml (10 lei)\n";
                string r3; std::cin >> r3; cin.clear();
                if(r3 == "Pahar" || r3 == "pahar" || r3 == "PAHAR") {
                    *bon +="la pahar - 8 lei";
                    pret_bautura_total +=8;
                } else if(r3 == "Sticla" || r3 == "sticla" || r3 == "STICLA") {
                    *bon +="la sticla - 10 lei";
                    pret_bautura_total +=10;
                }
                cout<<multumesc;
            } else if(r == "Apa" || r == "apa" || r == "APA"){
                *bon +="apa ";
                cout<<pahar_sticla;
                cout<<"Pahar - 300ml (5 lei)\nSticla - 500ml (7 lei)\n";
                string r4; std::cin >> r4; cin.clear();
                if(r4 == "Pahar" || r4 == "pahar" || r4 == "PAHAR") {
                    *bon +="la pahar - 5 lei";
                    pret_bautura_total +=5;
                } else if(r4 == "Sticla" || r4 == "sticla" || r4 == "STICLA") {
                    *bon +="la sticla - 7 lei";
                    pret_bautura_total +=7;
                }
                cout<<multumesc;
            }
            *bon +="\n";
            return pret_bautura_total;
        }
    }

    int menu_ciorba (bool ce_facem, string *bon){
        int pret_ciorba_total{0};
        if(!ce_facem){
            return 0;
        } else {
            cout<<"De care?\n";
            cout<<"Burta(10 lei)\nLegume(12 lei)\n";
            string raspuns;
            std::cin>>raspuns; cin.clear();
            if(raspuns == "Burta" || raspuns == "burta" || raspuns == "BURTA") {
                *bon +="ciorba de burta ";
                cout<<"Cu smantana(+2 lei)\nFara smantana(+0 lei)?\nAlegeti: cu/fara\n";
                string raspuns2; std::cin>>raspuns2; cin.clear();
                if(raspuns2 == "Cu" || raspuns2 == "cu" || raspuns2 == "CU") {
                    *bon += "cu smantana";
                    cout<<"Cu ardei(+2 lei)\nFara ardei(+0 lei)\nAlegeti: cu/fara\n";
                    string raspuns10; std::cin>>raspuns10; cin.clear();
                    if(raspuns10 == "Cu" || raspuns10 == "cu" || raspuns10 == "CU") {
                        *bon += "cu ardei - 14 lei";
                        pret_ciorba_total +=14;
                    } else if(raspuns10 =="Fara" || raspuns10 == "fara" || raspuns10 == "FARA") {
                        *bon += "fara ardei - 12 lei";
                        pret_ciorba_total +=12;
                    }
                } else if(raspuns2 =="Fara" || raspuns2 == "fara" || raspuns2 == "FARA") {
                    *bon += "fara smantana";
                    cout<<"Cu ardei(+2 lei)\nFara ardei(+0 lei)\nAlegeti: cu/fara\n";
                    string raspuns11; std::cin>>raspuns11; cin.clear();
                    if(raspuns11 == "Cu" || raspuns11 == "cu" || raspuns11 == "CU") {
                        *bon += "cu ardei - 12 lei";
                        pret_ciorba_total +=12;
                    } else if(raspuns11 =="Fara" || raspuns11 == "fara" || raspuns11 == "FARA") {
                        *bon += "fara ardei - 10 lei";
                        pret_ciorba_total +=10;
                    }
                }
            } else if(raspuns == "Legume" || raspuns == "legume" || raspuns == "LEGUME"){
                *bon += "Ciorba de legume ";
                cout<<"Cu smantana(+2 lei)\nFara smantana(+0 lei)?\nAlegeti: cu/fara\n";
                string raspuns2; std::cin>>raspuns2; cin.clear();
                if(raspuns2 == "Cu" || raspuns2 == "cu" || raspuns2 == "CU") {
                    *bon += "cu smantana";
                    cout<<"Cu ardei(+2 lei)\nFara ardei(+0 lei)\nAlegeti: cu/fara\n";
                    string raspuns3; std::cin>>raspuns3; cin.clear();
                    if(raspuns2 == "Cu" || raspuns2 == "cu" || raspuns2 == "CU") {
                        *bon += "cu ardei - 16 lei";
                        pret_ciorba_total +=16;
                    } else if(raspuns2 =="Fara" || raspuns2 == "fara" || raspuns2 == "FARA") {
                        *bon += "fara ardei - 14 lei";
                        pret_ciorba_total +=14;
                    }
                } else if(raspuns2 =="Fara" || raspuns2 == "fara" || raspuns2 == "FARA") {
                    *bon += "fara smantana";
                    cout<<"Cu ardei(+2 lei)\nFara ardei(+0 lei)\nAlegeti: cu/fara\n";
                    string raspuns3; std::cin>>raspuns3; cin.clear();
                    if(raspuns2 == "Cu" || raspuns2 == "cu" || raspuns2 == "CU") {
                        *bon += "cu ardei - 14 lei";
                        pret_ciorba_total +=14;
                    } else if(raspuns2 =="Fara" || raspuns2 == "fara" || raspuns2 == "FARA") {
                        *bon += "fara ardei - 12 lei";
                        pret_ciorba_total +=12;
                    }
                }
            }
            *bon += "\n";
            return pret_ciorba_total;
        }
    }

    int menu_fel_principal(bool ce_facem, string *bon){
        int pret_felPrincipal_total{0};
        if(!ce_facem){
            return 0;
        } else {
            cout<<"Ce anume doriti la felul principal?\n";
            cout<<"Ceva de pui\nCeva de vita\nAlegeti: pui/vita\n";// Frigarui sau Tocana - 100g\n";
            //Chateaubriand sau Stroganoff - 100g\n";
            string raspuns; std::cin>>raspuns; cin.clear();
            if(raspuns == "Pui" || raspuns == "pui" || raspuns == "PUI") {
                *bon +="Ceva de pui: ";
                cout << "Frigarui (23 lei)\nTocana (21 lei)\n";
                string raspuns2;
                std::cin >> raspuns2; cin.clear();
                if (raspuns2 == "Frigarui" || raspuns2 == "frigarui" || raspuns2 == "FRIGARUI") {
                    *bon +=" frigarui - 23 lei";
                    pret_felPrincipal_total += 23;
                } else if (raspuns2 == "Tocana" || raspuns2 == "tocana" || raspuns2 == "TOCANA") {
                    *bon += " tocana - 21";
                    pret_felPrincipal_total += 21;
                }
            } else if(raspuns == "Vita" || raspuns == "vita" || raspuns == "VITA") {
                *bon +="Ceva de vita: ";
                cout<<"Chateaubriand (31 lei)\n Stroganof(29 lei)\n";
                string raspuns2; std::cin>>raspuns2; cin.clear();
                if (raspuns2 == "Chateaubriand" || raspuns2 == "chateaubriand" || raspuns2 == "CHATEAUBRIAND") {
                    *bon +=" Chateaubriand - 31 lei";
                    pret_felPrincipal_total +=31;
                } else if (raspuns2 == "Stroganoff" || raspuns2 == "STROGANOF" || raspuns2 == "stroganof") {
                    *bon +=" Stroganoff - 29 lei";
                    pret_felPrincipal_total +=29;
                }
            }
            // CAND FAC BONU sa SEPAR IN 2 FUNCTII DIFERITE FELUL PRINCIPAL DE GARNITURA
            cout<<"Cu ce garnitura?\n";
            cout<<"Cartofi (7-8 lei)\nOrez FAIN (9 lei)\nAlegeti: cartofi/orez\n";
            string raspuns2; std::cin>>raspuns2; cin.clear();
            if(raspuns2 == "Cartofi" || raspuns2 == "cartofi" || raspuns2 == "CARTOFI"){
                *bon += "\t + \t cartofi ";
                cout<<"Ce fel de cartofi?\n";
                cout<<"Piure(7 lei)\nPrajiti(8 lei)\n";
                string raspuns3; std::cin>>raspuns3; cin.clear();
                if(raspuns3 == "Prajiti" || raspuns3 == "prajiti" || raspuns3 == "PRAJITI") {
                    *bon += "prajiti - 8 lei";
                    pret_felPrincipal_total +=8;
                } else if(raspuns3 == "Piure" || raspuns3 == "piure" || raspuns3 == "PIURE"){
                    *bon += "piure - 7 lei";
                    pret_felPrincipal_total +=7;
                }
            } else if(raspuns2 == "Orez" || raspuns2 == "orez" || raspuns2 == "OREZ"){
                *bon += "Orez FAIN - 9 lei";
                pret_felPrincipal_total +=9;
            }
            *bon += "\n";
            return pret_felPrincipal_total;
        }
    }

    int menu_desert(bool ce_facem, string *bon){
        int pret_desert_total{0};
        if(!ce_facem){
            return 0;
        } else {
            cout<<"Ce desert?\n";
            cout<<"Inghetata (12 lei - 3 cupe)\nTort? (15 lei - 300 gr)\n";
            string raspuns;
            cin>>raspuns; cin.clear();

            if(raspuns == "Inghetata" || raspuns == "inghetata" || raspuns == "INGHETATA") {
                *bon +="Inghetata cu 3 cupe - 12 lei ";

                pret_desert_total +=12;
            } else if(raspuns == "Tort" || raspuns == "tort" || raspuns == "TORT"){
                *bon +="Tort - 15 lei ";
                pret_desert_total +=15;
            }
        }
        *bon += "\n";
        return pret_desert_total;
    }

    int menu(int comanda) {
        bool quit = true;
        int add_pret1{0};
        int add_pret2{0};
        int add_pret3{0};
        int add_pret4{0};
        int add_pretTotal{0};
        while(quit){
            switch(comanda){
//                case 1:{
//                    add_pret1 = menu_bautura(1,"");
//                    break;
//                }
//                case 2:{
//                    add_pret2 = menu_ciorba(1,"");
//                    break;
//                }
//                case 3:{
//                    add_pret3 = menu_fel_principal(1,"");
//                    break;
//                }
//                case 4:{
//                    add_pret4 = menu_desert(1,"");
//                    break;
//                }
                case 0: {
                    //nu s-a hotarat inca
                    quit = false;
                    break;
                }
                case 5: {
                    bonPerClient = "";
                    cout<<"De baut va aduc ceva?\n";
                    string raspuns1; std::cin>>raspuns1; cin.clear();
                    add_pret1 = menu_bautura(raspuns1 == "da" || raspuns1 == "Da" || raspuns1 == "DA", &bonPerClient);

                    cout<<"Doriti ciorba?\n";
                    string raspuns2; std::cin>>raspuns2; cin.clear();
                    add_pret2 = menu_ciorba(raspuns2 == "da" || raspuns2 == "Da" || raspuns2 == "DA", &bonPerClient);

                    cout<<"Fel principal doriti?\n";
                    string raspuns3; std::cin >> raspuns3; cin.clear();
                    add_pret3 = menu_fel_principal(raspuns3 == "da" || raspuns3 == "Da" || raspuns3 == "DA", &bonPerClient);

                    cout<<"Desert doriti?\n";
                    string raspuns4; std::cin >> raspuns4; cin.clear();
                    add_pret4 = menu_desert(raspuns4 == "da" || raspuns4 == "Da" || raspuns4 == "DA", &bonPerClient);

                    return add_pret1+add_pret2+add_pret3+add_pret4;
                    //break;

                }
                default:{
                    // nimic deocamdata
                    break;
                }
            }
        }
        add_pretTotal = add_pret1+add_pret2+add_pret3+add_pret4;
        return add_pretTotal;
    }



};


#endif //RESTAURANT_PROIECTV2_RESTAURANT_H
