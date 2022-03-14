#include <iostream>
#include <string>
#include <vector>

#include "Menu.h"
#include "Registrazione.h"
#include "Accesso.h"
#include "Carta.h"
#include "Paypal.h"
#include "Account.h"
#include "Menusel.h"
#include "carrello.h"
#include "Oggetto.h"
using namespace std;

int main() {

    //variabile usata per salvare le risposte dell'utente
    int global = 0;
    int aiuto = 0;
    string azione1=" ";
    string azione2=" ";
    int uno;
    int due;


    cout << "Benvenuto nel negozio online!" << endl;
    cout << endl;
    cout << "Digita 'A' per accedere" << endl;
    cout << "Nuovo cliente? Digita 'R' per registrarti" << endl;
    cout << "Digita 'C' per sfogliare il catalogo " << endl;
    cin >> azione1;
    system("cls");

    while (azione1 != "A" and azione1 != "R" and azione1 != "C"){
        cout << "Carattere non valido! Digita nuovamente" << endl;
        cin >> azione1;
        system("cls");
    }

    if (azione1 == "A") {
        Accesso accesso(&uno, &global);
    }
    if (azione1 == "R") {
        Registrazione registrazione(&uno, &global);
    }


    Menu m;
    vector<Oggetto*> v4;
    int rispo;
    Menusel men;
    Oggetto* ogge;
    vector<string> vettore{"Intero catalogo", "Per categoria"};
    string r="c";
    while((r=="C")||r=="c") {
        rispo = men.sel(vettore, " Vuoi vedere l'intero catalogo o sfogliarlo per categoria?");
        system("cls");
        if (rispo == 0) {
            ogge = m.tutto();
            if (ogge != NULL) {
                v4.push_back(ogge);
                 //stampa vuota qui
                cout << endl;
                //cout<<"e fino a qui ci siamo"<<endl;
            }
        }
        else {
            ogge = m.parte();
            if (ogge != NULL) {
                v4.push_back(ogge);
                //ogge è l'indirizzo di memoria
            }
        }
        cout << "Premere c per continuare o t per terminare gli acquisti" << endl;
        cin >> r;
        while ((r != "C") and (r != "c") and (r != "T") and (r != "t")) {
            cout << "carattere non valido inserire di nuovo" << endl;
            cin >> r;
        }
    }
    carrello carre(v4);
    carre.stampa();
    carre.rimuovi();
    int z=carre.somma();
    cout<<"Totale="<<z<<"$"<<endl;
v4=carre.getcarrello();
    if (global == 1) {
        aiuto = 1;
        cout << "Per procedere con il pagamento, ti invitiamo ad accedere o registrarti!" << endl;
        cout << "Digita 'A' per accedere" << endl;
        cout << "Nuovo cliente? Digita 'R' per registrarti" << endl;
        cin >> azione2;

        int b=0;
        do {
            if(b>0){
                cout << "Carattere non valido! Digita nuovamente" << endl;
                cin >> azione2;}
            b++;
        } while (azione2 != "A" and azione2 != "R");
        if (azione2 == "A")
            Accesso accesso(&uno,&global);
        if (azione2 == "R")
            Registrazione registrazione(&uno,&global);
    }

    Account account(&uno,&global,&azione1,&azione2);

    string d;
    cout << "E' possibile effettuare il pagamento tramite carta, carta prepagata o Paypal" << endl;
    cout << "Digita 'C' per procedere con la carta" << endl;
    cout << "Digita 'P' per procedere con PayPal" << endl;
    cin >> d;

    int c=0;
    do {
        if(c>0){
            cout << "Carattere non valido! Digita nuovamente" << endl;
            cin >> d;}
        c++;
   } while (d != "C" and d != "P");
    if (d == "C") { Carta carta;
        carta.printmail(&account, &z, v4);
    }
    if (d == "P"){
        Paypal paypal;
        paypal.printmail(&account, &z, v4);
    }

    void logout(); {
        cout << "Vuoi fare il logout? Digita Si o No" << endl;
        string risposta;
        cin >> risposta;
        if (risposta == "Si") {
            account.~Account();
            global = 0;
        }
    }
    return 0;
}