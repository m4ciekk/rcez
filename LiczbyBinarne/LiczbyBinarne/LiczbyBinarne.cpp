#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Liczba {
	string liczba;
	int indeks;
};

int liczZnaki(char znak, string liczba) {
	int n = 0;
	for (int i = 0; i < liczba.length(); i++) {
		if (liczba[i] == znak) n++;
	}
	return n;
}

bool czyLiczbaPodzielnaPrzezDwa(string liczba) {
	if (liczba[liczba.length() - 1] != '0') return false;
	return true;
}

bool czyLiczbaPodzielnaPrzezOsiem(string liczba) {
	if (liczba.substr(liczba.length() - 3, 3) != "000") return false;
	return true;
}

int min(vector<Liczba> v) {
	Liczba liczbaMin = v[0];

	for (int i = 1; i < v.size(); i++) {
		Liczba liczba = v[i];
		if (liczba.liczba.length() <= liczbaMin.liczba.length()) {
			for (int j = 0; j < liczba.liczba.length(); j++) {
				if (liczbaMin.liczba[j] > liczba.liczba[j]) {
					liczbaMin = liczba;
					break;
				}
			}
		}
	}
	return liczbaMin.indeks;
}

int max(vector<Liczba> v) {
	Liczba liczbaMax = v[0];

	for (int i = 1; i < v.size(); i++) {
		Liczba liczba = v[i];

		if (liczba.liczba.length() > liczbaMax.liczba.length()) {
			liczbaMax = liczba;
		}
		else if (liczba.liczba.length() == liczbaMax.liczba.length()) {
			for (int j = 0; j < liczba.liczba.length(); j++) {
				if (liczba.liczba[j] < liczbaMax.liczba[j]) {
					break;
				}
				else if (liczba.liczba[j] > liczbaMax.liczba[j]) {
					liczbaMax = liczba;
					break;
				}
			}
		}
	}
	return liczbaMax.indeks;
}

int main() {
	ifstream fin("liczby.txt");
	string liczba;
	vector<Liczba> listaLiczb;
	int n1 = 0, n2 = 0, n3 = 0;

	for (int i = 0; i < 1000; i++) {
		fin >> liczba;

		Liczba l{ liczba, i + 1 };

		int zera = liczZnaki('0', liczba);
		int jedynki = liczZnaki('1', liczba);

		if (zera > jedynki) n1++;
		if (czyLiczbaPodzielnaPrzezDwa(liczba)) n2++;
		if (czyLiczbaPodzielnaPrzezOsiem(liczba)) n3++;

		listaLiczb.push_back(l);
	}

	cout << "zad 4.1" << endl << n1 << endl;
	cout << "zad 4.2" << endl << n2 << endl << n3 << endl;
	cout << "zad 4.3" << endl << min(listaLiczb) << endl << max(listaLiczb) << endl;
}