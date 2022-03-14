#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

#include "Categorie.h"
#include "Maglie.h"
#include "Pantaloni.h"
#include "Oggetto.h"
#include "carrello.h"
carrello::carrello(vector<Oggetto*>& v4) {
    //cout<<"siamo nel carrello"<<endl; stampe di controllo
    //cout<<"lunghezza carrello 2: "<<v4.size()<<endl;


    for (int j = 0; j < v4.size(); j++) {
        string d;
        carr.push_back(v4[j]);
        d=v4[j]->getprezzo();
        int b;
        b=stoi(d);
        prezzi.push_back(b);
        s=s+b;
    }
    //cin>>s; fino a qui arriva
}


void carrello::stampa(){//la funzione la chiama, ma è prima il problema

    for(int j=0;j<carr.size();j++)
    {
        string d;
        cout<<"prodotto n "<<j+1<<":"<<endl;
        carr[j]->stampaog();//questo impazzisce
        cout<<endl;

    }
}
void carrello::rimuovi() {
    int a, b, c;
    c = carr.size();
    cout << "1-conferma" << endl;
    cout << "2-elimina un elemento dal carrello" << endl;
    cin >> b;
    while (b == 2) {
        cout << "digita l'elemento che vuoi rimuovere dal carrello" << endl;
        cin >> a;
        while (a > carr.size() ) {
            cout << "nessun elemento del carrello corrisponde a " << a << " , inserire un valore valido" << endl;
            cin >> a;
        }
        if (c > 1) {
            carr.erase(carr.begin() + (a - 1));
            s=s-prezzi[a-1];

            stampa();
            cout << "1-conferma ordine" << endl;
            cout << "2-elimina un altro elemento" << endl;
            cin >> b;
            c--;
        } else {
            if (c = 1) {
                cout << "Attenzione. Nel carrello è rimasto un unico elemento. Proseguire? " << endl;
                cout << "1-lascia l'ultimo elemento" << endl;
                cout << "2-elimina ultimo elemento" << endl;
                carr.erase(carr.begin() + (a - 1));
                prezzi.erase(prezzi.begin()+(a-1));
            } else {
                cout << "carrello vuoto, non è possibile rimuovere altri elementi" << endl;
            }
        }

    }
}
int carrello::somma(){
    return s;
}
vector<Oggetto *> carrello::getcarrello()
{
    return carr;
}
