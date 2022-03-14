#ifndef PAYPAL_H
#define PAYPAL_H

#include "Metpagamento.h"
#include <string>
#include "Account.h"
#include "Oggetto.h"
#include <vector>
class Paypal : public Metpagamento {

public:
    Paypal();

    virtual void printmail(Account *, int *, vector<Oggetto*> &  ) const;

private:
    string emailpp;
    string passwordpp;
    string Name;
    string Surname;
    string Mail;
    string Ispedizione;

};


#endif
