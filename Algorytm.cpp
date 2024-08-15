// Metoda Połowienia do Znajdowania Miejsc Zerowych Funkcji
#include <iostream>
#include <cmath>

using namespace std;

// Definicja przykładowej funkcji
double funkcjaZapotrzebowania(double x) {
    return x*x*x - 2*x - 5; // x^3 - 2x - 5
}

// Implementacja metody połowienia, która służy do znajdowania miejsc zerowych funkcji
double metodaPolowienia(double a, double b, double epsilon) {
    if (funkcjaZapotrzebowania(a) * funkcjaZapotrzebowania(b) >= 0) {
        cout << "Funkcja nie zmienia znaku na przedziale - metoda połowienia może nie działać poprawnie.\n"; // Informacja o możliwym błędzie
        return NAN; // Zwraca NaN jeśli metoda nie może być stosowana
    }
    
    double c = a;
    while ((b - a) / 2.0 > epsilon) {
        c = (a + b) / 2.0;
        if (funkcjaZapotrzebowania(c) == 0) {
            // Jeśli wartość funkcji w środku przedziału jest zerem, to znaleźliśmy miejsce zerowe
            return c;
        } else if (funkcjaZapotrzebowania(c) * funkcjaZapotrzebowania(a) < 0) {
            b = c; // Kontynuacja w lewej połowie przedziału
        } else {
            a = c; // Kontynuacja w prawej połowie przedziału
        }
    }
    return c; / Zwraca przybliżoną wartość miejsca zerowego
}

int main() {
    double start = 1;
    double end = 3
    double tolerancja = 0.01;
    double miejsceZerowe = metodaPolowienia(start, end, tolerancja);
    if (!isnan(miejsceZerowe)) {
        cout << "Znalezione miejsce zerowe: " << miejsceZerowe << endl; // Wypisanie wyniku
    }
    return 0;
}