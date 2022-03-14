#ifndef CARTA_H
#define CARTA_H

#include "Metpagamento.h"
#include "Account.h"
#include <string>
#include "Oggetto.h"
#include <vector>

class Carta : public Metpagamento {

public:
    Carta();

    virtual void printmail(Account *, int *, vector<Oggetto*> &) const;

private:
    string numerocarta;
    string datascadenza;
    string codice;

};


#endif