#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {


	//Varijable kojima testiramo algoritam
	const int N = 1;
	const int brojUzoraka = 100;

	int brojevi[N];

	//Punjenje polja brojeva
	for (int i = 0; i < N; i++)
	{
		brojevi[i] = i;

	}


	//Maknuo iz polja na mjestu koje je generiralo broj 42 i pomocu srand automatski generirali mjesto u polju di ce biti broj 42
	brojevi[42] = 43;


	srand(time(nullptr));
	int izgeneriranoMjestoBroja = rand() % (N - 0 + 1) + 0;

	brojevi[izgeneriranoMjestoBroja] = 42;


	double rezultatiUzorka[brojUzoraka];
	int brojOperacija[brojUzoraka];

	//Jos jedna for petlja radi dobivanja veceg uzorka------jedan prolazak kroz oba dvije petlje vremenski traje 447 nanosekundi
	for (int g = 0; g < brojUzoraka; g++)
	{

		brojOperacija[g] = 2;//Zbog prve inicijalizacije

		auto begin = chrono::high_resolution_clock::now();
		//Zadatak
		for (int i = 0; i < N; i++) {
			if (brojevi[i] == 42) {
				brojOperacija[g] ++;
				break;
			}
			brojOperacija[g] += 3;
		}

		for (int i = 0; i < N; i++) {
			if (brojevi[i] == 42) {
				brojOperacija[g] ++;
				break;
			}
			brojOperacija[g] += 3;

		}

		auto end = chrono::high_resolution_clock::now();

		rezultatiUzorka[g] = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

		std::cout << "Trajanje u nanosekundama: " << rezultatiUzorka[g] << "   Broj operacija: " << brojOperacija[g] << endl;
	}

	//Racunanje average,min i max
	double average, min, max;
	double sumaUzoraka = 0;
	double sumaOperacija = 0;
	min = rezultatiUzorka[0];
	max = rezultatiUzorka[0];

	double brojOperacijaProsjek;
	double	minOperacija = 0;
	double	maxOperacija = 0;

	for (int i = 0; i < brojUzoraka; i++)
	{
		sumaUzoraka += rezultatiUzorka[i];
		sumaOperacija += brojOperacija[i];

		if (min > rezultatiUzorka[i])
		{
			min = rezultatiUzorka[i];
		}

		if (max < rezultatiUzorka[i])
		{
			max = rezultatiUzorka[i];
		}
		if (minOperacija > brojOperacija[i])
		{
			minOperacija = brojOperacija[i];
		}

		if (maxOperacija < brojOperacija[i])
		{
			maxOperacija = brojOperacija[i];
		}
	}


	average = sumaUzoraka / brojUzoraka;
	brojOperacijaProsjek = sumaOperacija / brojUzoraka;

	cout << "\nIzgenerirano mjesto na kojem je broj 42: " << izgeneriranoMjestoBroja << endl;
	cout << "\n\n\n";
	cout << "Vrijeme" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Prosjek: " << average;
	cout << "   Min: " << min << "   Max: " << max << "\n\n\n\n";

	cout << "Broj operacija" << endl;
	cout << "-------------------------" << endl;
	cout << "Prosjecan broj operacija: " << brojOperacijaProsjek << endl << endl;
	cout << "   Najbolji slucaj: " << minOperacija << "   Najgori slucaj: " << maxOperacija << "\n\n\n\n";




	return 0;
}