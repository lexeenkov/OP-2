
#include "Header.h"

int main()
{
    vector <studentas> grupe;
    int StudSkai = 0;
    int VidArMed = 0;
    int AutoGen = 0;
    int Ivedimas = 0;
    string txtname;


    cout << " Galutinio balo skaiciavimui naudoti vidurki ar mediana? \n";
    cout << "(0 - vidurkis / 1 - mediana): ";
    cin >> VidArMed;
    skaitymoKlaidos(VidArMed);

  
        cout << "\n Ar norite nuskaityti duomenys is failo? \n";
        cout << "(0 - ne / 1 - taip): ";
        cin >> Ivedimas;
        skaitymoKlaidos(Ivedimas);

        if (Ivedimas == 1) {
            cout << "\n \n Iveskite tekstinio failo pavadinima (su .txt):" << endl;
            cin >> txtname;
            nuskaitymas(txtname, grupe, StudSkai, VidArMed);
        }
        else {
            cout << "\n Ar norite, kad studento balai butu generuojami automatiskai? \n";
            cout << "(0 - ne / 1 - taip): ";
            cin >> AutoGen;
            skaitymoKlaidos(AutoGen);

            cout << "\n \n Iveskite studentu skaiciu: ";
            cin >> StudSkai;
            skaitymoKlaidosStud(StudSkai);

            grupe.reserve(StudSkai);
            ivedimas(grupe, StudSkai, VidArMed, AutoGen);
        }

        isvedimas(grupe, VidArMed); 
        grupe.clear();
    return(0);
}
