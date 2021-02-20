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
    vector <int> nd;
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
};

int main()
{
    vector <studentas> grupe;
    const char tarpas = ' ';
    const int tarpai = 15;
    int KiekSt = 0;
    string SkMet;
    string Rand;

    cout << "Iveskite studentu skaiciu grupeje: ";
    cin >> KiekSt;

    cout << "\nAr norite generuoti atsitiktinius pazymius? \n";
    cout << "y - taip , n - ne:";
Pazymiai:   
    cin >> Rand;
    if (Rand == "y"||Rand=="Y"||Rand=="n"||Rand=="N") {}
    else {
        cout << "Klaida. Veskite 'y' arba 'n': ";
        goto Pazymiai;
    };



    grupe.reserve(KiekSt);
    for (int i = 0; i < KiekSt; i++) {
        studentas stud;
        cout << "\nIveskite " << i + 1 << " studento varda ir pavarde: \n";
        cin >> stud.Vardas >> stud.Pavarde;
        if (Rand == "y") {
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
            stud.n = rand() % 20 + 1;
            stud.nd.reserve(stud.n);
            for (int j = 0; j < stud.n; j++) {
                int random;
                random = rand() % 10 + 1;
                cout << random << " ";
                stud.vid = stud.vid + (float)random;
                stud.nd.push_back(random);
            }
            cout << endl;
            stud.egz = rand() % 10 + 1;
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << stud.egz << endl;
        }
        else {//rankinis pazymiu ivedimas
            cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
            int null = 1;
            while (null != 0) {
                int paz;
                cin >> paz;
                if (paz > 0 && paz < 11) {
                    stud.vid = stud.vid + (float)paz;
                    stud.nd.push_back(paz);
                    stud.n++;
                    stud.nd.reserve(stud.n);
                }

                else if (paz == 0) {
                    null = 0;
                    cout << "Ivedete " << stud.n << " pazymius)" << endl;
                }
                else {
                    cout << "Klaida. Veskite pazymius nuo 1 iki 10. Noredami uzbaigti iveskite 0." <<endl;
                };
            }
            cout << "\n Iveskite " << i + 1 << " studento egzamino ivertinima: ";
            cin >> stud.egz;
        }

        cout << "\nKoks galutinio balo skaicivimo metodas taikomas siam studentui? \n";
        cout << "m - mediana , v - vidurkis: ";

        

    metod:
        cin >> SkMet;
        if (SkMet == "m" || SkMet == "M") {
            sort(stud.nd.begin(), stud.nd.end());
            if (stud.n % 2 != 0) stud.galutinis = (float)stud.nd.at(stud.n / 2);
            else {
                int med;
                med = stud.nd.at((stud.n - 1) / 2) + stud.nd.at(stud.n / 2);
                stud.galutinis = (float)med / 2.0;
            }
        }
        else if (SkMet == "v" || SkMet == "V") {
            stud.galutinis = stud.vid / (float)stud.n;
            stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
        }
        else {
            cout << "Klaida. Veskite 'v' arba 'm': ";
            goto metod;
        }
        grupe.push_back(stud);
        stud.nd.clear();
    }

    cout << endl;
    cout << left << setw(tarpai) << setfill(tarpas) << "Vardas";
    cout << left << setw(tarpai) << setfill(tarpas) << "Pavarde";
    cout << internal << setw(tarpai) << setfill(tarpas) << "Galutinis (Med/Vid)" << endl;
    cout << string(tarpai + tarpai + tarpai + tarpai, '-') << endl;

    for (auto& tt : grupe) {
        cout << left << setw(tarpai) << setfill(tarpas) << tt.Vardas;
        cout << left << setw(tarpai) << setfill(tarpas) << tt.Pavarde;
        cout << internal << setw(tarpai) << setfill(tarpas) << fixed << setprecision(2) << tt.galutinis << endl;
    };



    grupe.clear();
    cout << endl << "Noredami uzbaigti iveskite 0" << endl;
    cin >> Rand;
    return(0);
};
