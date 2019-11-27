#include <iostream>
#include "GrupClienti.h"
#include "Restaurant.h"

class Management: public GrupClienti{
    vector<GrupClienti> grups;
    Restaurant restaurant;
    int nrGrupuri;

public:
    Management(int nrGrupuri){
        restaurant.setNumeRestaurant("La Daniel");
        cout<<"Construim restaurantul...\n";
        cin>>restaurant;
        this->nrGrupuri = nrGrupuri;
        cout<<"Vin clientii..\n";
        for(int i{0}; i<nrGrupuri; i++){
            cout<<"Pentru grupul: "<<i+1<<endl;
            GrupClienti grupNou(i+1); cin>>grupNou;
            grups.push_back(grupNou);
        }
    }
    Management(){
        restaurant.setNumeRestaurant("La Daniel");
        cout<<"Construim restaurantul...\n";
        cin>>restaurant;
    }
    const vector<GrupClienti> &getGrups() const {
        return grups;
    }

    const Restaurant &getRestaurant() const {
        return restaurant;
    }

    int getNrGrupuri() const {
        return nrGrupuri;
    }


    void setNrGrupuri(int nrGrupuri) {
        Management::nrGrupuri = nrGrupuri;
    }

    friend ostream &operator<<(ostream &out, const Management &man){
        cout<<"Restaurantul are urmatorele grupuri: \n";
        for(int i{0}; i<man.nrGrupuri; i++){
            out<<man.getGrups()[i];
        }
        return out;
    }
    friend istream &operator>>(istream &in, Management &man){
        cout<<"Cate grupuri au venit?\n"; int n; in>>n;
        man.setNrGrupuri(n);
        cout<<"Vin clientii..\n";
        for(int i{0}; i<man.getNrGrupuri(); i++){
            cout<<"Pentru grupul: "<<i+1<<endl;
            GrupClienti grupNou(i+1); in>>grupNou;
            man.grups.push_back(grupNou);
        }
        return in;
    }
    void setOkGrupulAreRezervataMasa(int indexGrup,int masaLibera){
        grups[indexGrup].setOkAvetiRezervataMasa(masaLibera);
    }
    void setConsumatiePentru(int indexGrup,int indexClient, int cat){

        grups[indexGrup].ConsumatiePentru(indexClient,cat);
    }
    void setBonConsumatiePentru(int indexGrup, int indexClient, string s){
        grups[indexGrup].BonConsumatiePentru(indexClient,s);
    }
    void setConsumatiePentruGrup(int indexGrup, int cat){
        grups[indexGrup].ConsumatiePentruGrup(cat);
    }
    void setBonConsumatiePentruGrup(int indexGrup, string s){
        grups[indexGrup].BonConsumatiePentruGrup(s);
    }
    void SetAchitarePentru(int indexGrup, int indexClient, bool tip){
        grups[indexGrup].AchitarePentru(indexClient, tip);
    }
    void cheamaChelnerGrupul(const GrupClienti &grup) {
        int saVinaChelnerul = 0;
        cout<<"Sa vina chelnerul?\n";
        cout<<"1 - Da\n";
        cout<<"2 - Nu\n";
        cin>>saVinaChelnerul; cin.clear();
        bool quit = true;
        while (quit) {
            switch(saVinaChelnerul) {
                case 1: {
                    if (!restaurant.getChelneri()[grup.getGrupID()].canServe()) {
                        int masaLibera = restaurant.masaLibera();
                        setOkGrupulAreRezervataMasa(grup.getGrupID(),
                                                    masaLibera); // seteaza grupului masa care a fost libera

                        restaurant.seteazaMasaChelnerClientiReservati(grup.getGrupID(),
                                                                      true); // seteaza Chelnerului, ca Clientii pe care i-a primit acum sunt rezervati la o masa (true)
                        restaurant.seteazaMasaRezervatPentruGrupClientID(masaLibera - 1, grup.getGrupID(),
                                                                         true); //seteaza Mesei Libera, grupul care s-a asezat la ea // seteaza Masa Libera ca fiind ocupata;
                    } else {
                        if (restaurant.getChelneri()[grup.getGrupID()].canServe()) {
                            for (int i{0}; i < grup.getNrClienti(); i++) {
                                int ceAreSistemulDeFacut{0};
                                ceAreSistemulDeFacut = restaurant.canServeEachClient(
                                        grup.getGrupClient()[i].ceVreauSaFac()); // ceAreSistemulDeFacut e si cat are de platit un client

                                if(ceAreSistemulDeFacut == -100){
                                    cout<<"Vreti nota de plata pentru dumneavoastra sau pentru toata lumea?\n";
                                    cout<<"1 - Dumneavoastra\n";
                                    cout<<"2 - Toata lumea\n";
                                    cout<<"0 - Mai vrei sa astepti\n";
                                    int decizie{0};
                                    cin>>decizie; cin.clear();
                                    if(decizie == 1) {
                                        cout << "Nota de plata pentru clientul: "
                                             << grup.getGrupClient()[i].getClientID() << " este: ";
                                        cout<<grup.getGrupClient()[i].getConsumatie()<<" de lei\n";
                                        //PRESUPUNEM CA ARE CU CE SA ACHITE
                                        SetAchitarePentru(grup.getGrupID(),i,true);
                                        cout<<"Ai achitat!\n";
                                    } else if(decizie == 2){
                                        for(int j{0}; j<grup.getNrClienti(); j++){
                                            cout << "Nota de plata pentru clientul: "
                                                 << grup.getGrupClient()[i].getClientID() << " este: ";
                                            cout<<grup.getGrupClient()[i].getConsumatie()<<" de lei\n";
                                            //PRESUPUNEM CA ARE CU CE SA ACHITE
                                            SetAchitarePentru(grup.getGrupID(),i,true);
                                            cout<<"Tot grupul a achitat!\n";

                                        }
                                        break;
                                    }
                                } else if(ceAreSistemulDeFacut == -1){
                                    cout<<"Nu mai ai ce sa faci, pleaca de aici!\n";
                                    break;
                                } else {
                                    setConsumatiePentru(grup.getGrupID(), i, ceAreSistemulDeFacut);// pt client consumatie
                                    setBonConsumatiePentru(grup.getGrupID(), i,
                                                           restaurant.getBonPerClient()); // pt client bon

                                    setConsumatiePentruGrup(grup.getGrupID(), ceAreSistemulDeFacut);// pt grup
                                    setBonConsumatiePentruGrup(grup.getGrupID(), restaurant.getBonPerClient());// pt grup
                                }
                            }
                            cout<<"\nClientii din grupul: "<<grup.getGrupID()<<" au fost serviti!\n";
                        }
                    }
                    break;
                }
                case 2: {
                    cout<<"Chelnerul nu mai vine...\n";
                    quit = false;
                    break;
                }
                default: {
                    cout<<"Nu ai ales una dintre cele 2 optiuni: 1/2\n";
                    break;
                }
            }
        }
    }

};

using namespace std;

//daca cineva ar introduce un nr de grupuri negativ
void f(){throw Management(-1);}


int main() {

    GrupClienti grup1;
    cin>>grup1;
    grup1.ConsumatiePentru(0,10);
    cout<<grup1.getGrupClient()[0].getConsumatie();
    /*Management management;
    cin >> management;
    cin.clear();
    cout << management.getRestaurant().getChelneri()[1].getId();
    cout << management;
    //nu stiu de ce mi se blocheaza dupa primul client

    //verificare daca inregistrat bine grupurile
//    for(int i{0};i<management.getNrGrupuri();i++){
//        cout<<management.getGrups()[i].getGrupID()<<endl;
//    }
//    for (int i{0}; i < management.getGrups()[0].getNrClienti(); i++) {
//    management.getGrups()[0].getComandaClient()[i].getPretPerMasa();
//}
   management.setConsumatiePentru(0,0,10);




    management.cheamaChelnerGrupul(management.getGrups()[0]);
    //eroare imi da in clasa Comanda.cpp la setPretPerMasa, nu are NICI UN SENS de ce mi-ar da eroare acolo


*/
    //exceptia
//    try{
//        f();
//    } catch (Management) { cout<<"management";}
    return 0;
}