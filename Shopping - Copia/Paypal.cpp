#include <iostream>
#include <string>
using namespace std;


#include "Paypal.h"
#include "Account.h"
#include "Oggetto.h"
#include <vector>

Paypal::Paypal() {
    cout << "Inserire email e password di Paypal, premendo invio" << endl;
    cin >> emailpp;
    cin >> passwordpp;
}

void Paypal::printmail(Account *account, int *z, vector<Oggetto*> &v4) const {
    cout << "Gentile " << account->getName() << " " << account->getSurname() << "," << endl;
    cout << endl;
    cout << "Tramite questa mail vogliamo confermarle l'ordine dei seguenti articoli:" << endl;   //prova a mandarla davvero, sfrutta getmail!!!
     for (int i = 0; i < v4.size(); i++) {
         v4[i]->stampaog();
     }

    cout << "Per un totale di " <<z<< "che sara' addebitato sul conto Paypal relativo all'username " << emailpp << "." << endl;
    cout << "Gli articoli saranno spediti all'indirizzo di consegna: "  << endl;


}
