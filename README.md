# OP-2
Objektinio Programavimo antroji užduotis


Programa leidžia vartuotojui įvesti grupės studentų duomenis ir pažymius, vėliau suskaičiuoja galutinį įvertinimą ir grupės rezultatus pateikia lentelėje. Pažymiai gali būti generuojami atsitiktinai. Galutiniam balui skaičiuoti galima naudoti aritmetinio vidurkio ar medianos metodą.

V0.1.1 Pažymiai yra saugomi vektoriuose. Studentai sukurti per struct. Atsitiktiniai pažymiai realizuoti "senoviniu" budu.

V0.2.0 Yra galimybe nuskaityti studentus iš fail'o. Sukurtos funkcijos klaidoms atskiruose failuose. Naudojami Header failai.

V0.3.0 Funkcijos yra laikomos Header faile. Nors tai jau buvo realizuota V0.2.

V0.4.0 Realizuota testavimo galimybė. Tačiau ar dėl kodo problemų , ar dėl silpnos sistemos , ilgų failų nuskaitymas uztrunka neįtikėtinai daug laiko.

Benchmark'as:

Failo is 1000 irasu (namu darbu skaicius: 12) kurimas uztruko: 0.443503 s
1000 irasu nuskaitymas is failo uztruko: 0.123835 s
1000 studentu rusiavimas i dvi grupes/kategorijas uztruko: 0.022658 s
1000 irasu neislaikiusiu studentu isvedimas i nauja faila uztruko: 0.115613 s
1000 irasu islaikiusiu studentu isvedimas i nauja faila uztruko: 0.186439 s

1000 irasu testo laikas: 0.898007 s

Failo is 10000 irasu (namu darbu skaicius: 8) kurimas uztruko: 3.94698 s
10000 irasu nuskaitymas is failo uztruko: 1.07178 s
10000 studentu rusiavimas i dvi grupes/kategorijas uztruko: 0.237321 s
10000 irasu neislaikiusiu studentu isvedimas i nauja faila uztruko: 1.53477 s
10000 irasu islaikiusiu studentu isvedimas i nauja faila uztruko: 2.55605 s

10000 irasu testo laikas: 9.35154 s

Failo is 100000 irasu (namu darbu skaicius: 8) kurimas uztruko: 40.8754 s
100000 irasu nuskaitymas is failo uztruko: 11.9219 s
100000 studentu rusiavimas i dvi grupes/kategorijas uztruko: 2.14634 s
100000 irasu neislaikiusiu studentu isvedimas i nauja faila uztruko: 20.2553 s
100000 irasu islaikiusiu studentu isvedimas i nauja faila uztruko: 30.9756 s

100000 irasu testo laikas: 106.181 s

Failo is 1000000 irasu (namu darbu skaicius: 2) kurimas uztruko: 317.04 s
1000000 irasu nuskaitymas is failo uztruko: 73.1041 s
1000000 studentu rusiavimas i dvi grupes/kategorijas uztruko: 22.3043 s
1000000 irasu neislaikiusiu studentu isvedimas i nauja faila uztruko: 230.574 s
1000000 irasu islaikiusiu studentu isvedimas i nauja faila uztruko: 359.663 s

1000000 irasu testo laikas: 1002.69 s

Instrukcija:
???
