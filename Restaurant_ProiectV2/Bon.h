//
// Created by cdani on 11/27/2019.
//

#ifndef RESTAURANT_PROIECTV2_BON_H
#define RESTAURANT_PROIECTV2_BON_H
#include "Comanda.h"

class Bon : public Comanda.h{
    protected;
    virtual string bon;
public:
    virtual void getBon(){return bon;}
    virtual ~Bon(){cout<<"Bon::Destructor";}
};
//VOIAM SA MA FOLOSESC DE CLASA ASTA LA AFISAREA COMENZII, DAR N-AM MAI AVUT TIMP

#endif //RESTAURANT_PROIECTV2_BON_H
