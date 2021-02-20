#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h> 

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::internal;
using std::left;

using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::sort;

struct studentas {
    string Vardas = "";
    string Pavarde = "";
    int nd[20];
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
};

int main()
{
    const char tarpas = ' ';
    const int tarpai = 15;
    int KiekSt = 0;
    string SkMet;
    string Rand;

    cout << "Iveskite studentu skaiciu grupeje: ";
    cin >> KiekSt;
    studentas* grupe = new studentas[KiekSt];
    cout << "\nAr norite generuoti atsitiktinius pazymius? \n";
    cout << "y - taip , n - ne:";
Pazymiai:
    cin >> Rand;
    if (Rand == "y" || Rand == "Y" || Rand == "n" || Rand == "N") {}
    else {
        cout << "Klaida. Veskite 'y' arba 'n': ";
        goto Pazymiai;
    };



   
    for (int i = 0; i < KiekSt; i++) {
        cout << "\nIveskite " << i + 1 << " studento varda ir pavarde: \n";
        cin >> grupe[i].Vardas >> grupe[i].Pavarde;
        if (Rand == "y") {
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
            grupe[i].n = rand() % 20 + 1;
            for (int j = 0; j < grupe[i].n; j++) {
                grupe[i].nd[j] = rand() % 10 + 1;
                cout << grupe[i].nd[j] << " ";
                grupe[i].vid = grupe[i].vid + (float)grupe[i].nd[j];

            }
            cout << endl;
            grupe[i].egz = rand() % 10 + 1;
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << grupe[i].egz << endl;
        }
        else {//rankinis pazymiu ivedimas
            cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius iveskite 0\n";
            int null = 1;
            while (null != 0) {

                cin >> grupe[i].nd[grupe[i].n];

                if (grupe[i].nd[grupe[i].n] > 0 && grupe[i].nd[grupe[i].n] < 11) {

                    grupe[i].vid = grupe[i].vid + (float)grupe[i].nd[grupe[i].n];
                    grupe[i].n++;
                }



                


                else if (grupe[i].nd[grupe[i].n] == 0) {
                    null = 0;
                    cout << "Ivedete " << grupe[i].n << " pazymi(-ius)" << endl;
                }
                else {
                    cout << "Klaida. Veskite pazymius nuo 1 iki 10. Noredami uzbaigti iveskite 0." << endl;
                };
            }
            cout << "\n Iveskite " << i + 1 << " studento egzamino ivertinima: ";
            cin >> grupe[i].egz;
        }

        cout << "\nKoks galutinio balo skaicivimo metodas taikomas siam studentui? \n";
        cout << "m - mediana , v - vidurkis: ";



    metod:
        cin >> SkMet;
        if (SkMet == "m" || SkMet == "M") {
            sort(grupe[i].nd, grupe[i].nd + grupe[i].n);
            if (grupe[i].n % 2 != 0) {
                grupe[i].galutinis = (float)grupe[i].nd[grupe[i].n / 2];
            }
            else {
                int med;
                med = grupe[i].nd[(grupe[i].n - 1) / 2] + grupe[i].nd[grupe[i].n / 2];
                grupe[i].galutinis = (float)med / 2.0;
            }

        }
        else if (SkMet == "v" || SkMet == "V") {
            grupe[i].galutinis = grupe[i].vid / (float)grupe[i].n;
            grupe[i].galutinis = grupe[i].galutinis * 0.4 + (float)grupe[i].egz * 0.6;
        }
        else {
            cout << "Klaida. Veskite 'v' arba 'm': ";
            goto metod;
        }
    }

    cout << endl;
    cout << left << setw(tarpai) << setfill(tarpas) << "Vardas";
    cout << left << setw(tarpai) << setfill(tarpas) << "Pavarde";
    cout << internal << setw(tarpai) << setfill(tarpas) << "Galutinis (Med/Vid)" << endl;
    cout << string(tarpai + tarpai + tarpai + tarpai, '-') << endl;

    for (int i = 0; i < KiekSt; i++) {
        cout << left << setw(tarpai) << setfill(tarpas) << grupe[i].Vardas;
        cout << left << setw(tarpai) << setfill(tarpas) << grupe[i].Pavarde;
        cout << internal << setw(tarpai) << setfill(tarpas) << fixed << setprecision(2) << grupe[i].galutinis << endl;
    };



    cout << endl << "Noredami uzbaigti iveskite 0" << endl;
    cin >> Rand;
    return(0);
}

