
#include "header.h"

int main()
{
    vector <studentas> grupe;
    int StudSkai = 0;
    int VidArMed = 0;
    int AutoGen = 0;
    int Ivedimas = 0;
    int Testavimas = 0;
    string txtname;

    cout << " Ar norite testuoti programa? \n";
    cout << "(0 - ne / 1 - taip): ";
    cin >> Testavimas;
    skaitymoKlaidos(Testavimas);

    cout << "\n Galutinio balo skaiciavimui naudoti vidurki ar mediana? \n";
    cout << "(0 - vidurkis / 1 - mediana): ";
    cin >> VidArMed;
    skaitymoKlaidos(VidArMed);

    if (Testavimas == 1) {
        test("studentai1000", 1000, StudSkai, VidArMed);
        if (remove("studentai1000.txt") == 0) remove("studentai1000.txt");

        test("studentai10000", 10000, StudSkai, VidArMed);
        if (remove("studentai10000.txt") == 0) remove("studentai10000.txt");

        test("studentai100000", 100000, StudSkai, VidArMed);
        if (remove("studentai100000.txt") == 0) remove("studentai100000.txt");

        test("studentai1000000", 1000000, StudSkai, VidArMed);
        if (remove("studentai1000000.txt") == 0) remove("studentai1000000.txt");

        test("studentai10000000", 10000000, StudSkai, VidArMed);
        if (remove("studentai10000000.txt") == 0) remove("studentai10000000.txt");
    }
    else {
        cout << "\n Ar norite nuskiatyti duomenys is failo?\n";
        cout << "(0 - ne / 1 - taip): ";
        cin >> Ivedimas;
        skaitymoKlaidos(Ivedimas);

        if (Ivedimas == 1) {
            cout << "\n Iveskite tekstinio failo pavadinima (be .txt):" << endl;
            cin >> txtname;
            nuskaitymas(txtname, grupe, StudSkai, VidArMed);
        }
        else {
            cout << "\n Ar norite automatikskai generuoti pazymius?\n";
            cout << "(0 - ne / 1 - taip): ";
            cin >> AutoGen;
            skaitymoKlaidos(AutoGen);

            cout << "\n Iveskite studentu skaiciu: ";
            cin >> StudSkai;
            skaitymoKlaidosStud(StudSkai);

            grupe.reserve(StudSkai);
            ivedimas(grupe, StudSkai, VidArMed, AutoGen);
        }

        int isvesti = 0;
        cout << "\n Ar norite duomenys isvesti i ekrana? \n(0 - ne / 1 - taip): ";
        cin >> isvesti;
        if (isvesti == 0) {
            return 0;
        };

        isvedimas(grupe, VidArMed);
        vector <studentas> grupe1;
        vector <studentas> grupe2;
        padalinimas(grupe, grupe1, grupe2);
        if (remove("neislaike.txt") == 0) remove("neislaike.txt");
        if (remove("islaike.txt") == 0) remove("islaike.txt");
        if (!grupe1.empty()) irasymas("neislaike.txt", grupe1, VidArMed);
        if (!grupe2.empty()) irasymas("islaike.txt", grupe2, VidArMed);
        grupe1.clear();
        grupe2.clear();
        grupe.clear();
    }
    return(0);
}
