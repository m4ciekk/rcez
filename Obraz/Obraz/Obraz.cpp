#include <iostream>

using namespace std;

void obroc(char obraz[1000][1000], int n, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			cout << obraz[j][i];
		}
		cout << endl;
	}
}

int main() {

	char obraz[1000][1000];
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> obraz[i][j];
		}
	}

	obroc(obraz, n, m);

	return 0;
}