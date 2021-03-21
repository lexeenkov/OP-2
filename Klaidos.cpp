#include "Klaidos.h"

void skaitymoKlaidos(int& duomuo) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true);
}

void skaitymoKlaidosPaz(int& duomuo, int n) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
            else if (duomuo > 10) throw runtime_error("Ivestas pazymys virsija 10\n");
            else if (duomuo < 0) throw runtime_error("Pazymys negali buti neigiamas\n");
            else if (duomuo == 0 && n == 0) throw runtime_error("Privalote ivesti bent viena pazymi\n");
            else if (duomuo == 0 && n == -1) throw runtime_error("Egzamino pazymys negali buti lygus 0\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true || duomuo > 10 || duomuo < 0 || (duomuo == 0 && n == 0) || (duomuo == 0 && n == -1));
}

void skaitymoKlaidosStud(int& duomuo) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
            else if (duomuo <= 0) throw runtime_error("Studentu skaicius negali buti neigiamas arba lygus 0\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true || duomuo <= 0);
}

