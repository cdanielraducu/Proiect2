//
// Created by cdani on 11/20/2019.
//

#ifndef RESTAURANT_PROIECT_CLIENT_H
#define RESTAURANT_PROIECT_CLIENT_H
using namespace std;
#include <string>
#include <ostream>

class Client {
protected:
    int clientID{0};
    string nume;
    int varsta;
    int consumatie{0};
    string consumatieInScris;
    bool achitat;


public:
    explicit Client(string nume,int varsta,int id);
    friend ostream &operator<<(ostream &out, const Client &client);
    friend istream &operator>>(istream &in, Client &client);
    Client &operator=(const Client &client);
    Client(const Client &client);
    Client();
    explicit Client(int id);
    virtual ~Client();
    int getConsumatie() const;
    void setConsumatie(int consumatie);

    const string &getConsumatieInScris() const;

    void setConsumatieInScris(const string &consumatieInScris);

    const string &getNume() const;
    void setNume(const string &nume);

    bool isAchitat() const;
    void setAchitat(bool achitat);

    int getVarsta() const;
    void setVarsta(int varsta);

    int getClientID() const;
    void setClientID(int ID);

    int ceVreauSaFac() const {
        int x{0};

        if(isAchitat()){
            cout<<"Clientul: "<<clientID<<endl;
            cout << "Ce vreau sa fac?\n";
            cout << "-1 - Am achitat deja\n";
            cin >> x; cin.clear();
        } else {
            cout<<"Clientul: "<<clientID;
            cout << "Ce vreau sa fac?\n";
            cout << "1 - Vreau sa comand\n";
            cout << "2 - Vrem sa achit pentru mine\n";
            cin >> x; cin.clear();
        }
        return x;
    }
};


#endif //RESTAURANT_PROIECT_CLIENT_H
