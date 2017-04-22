#include "Student.h"

CStudent::CStudent()
{
	przedmioty = NULL;
}

CStudent::~CStudent()
{

	delete [] przedmioty;
}


void CStudent::nowe_dane()
{	
	
	cout <<  "Wprowadz: \nImie: ";
	cin >> imie;
	cout << "\nNazwisko: ";
	cin >> nazwisko;
	cout << "\nNumer albumu: ";
	cin >> nr_albumu;
	cout << "\nSrednia: ";
	cin >> srednia;
	cout << "\nIle przedmiotow?: ";
	cin >> N;
	przedmioty = new string[N];
	for (size_t i = 0; i < N; i++)
	{
		cout << "\nPrzedmiot " << i + 1 << ": ";
		cin >> *(przedmioty + i);
	}
	cout << endl << endl;
}


void CStudent::wyswietl()
{
	cout << "\nImie: " << imie << "\nNazwisko: " << nazwisko << "\nNumer albumu: " << nr_albumu
		<< "\nSrednia: " << srednia << "\nPrzedmioty: ";
	if (N != 0)
	{
		for (size_t i = 0; i < N; i++)
		{
			cout << endl << '(' << i + 1 << ") " << *(przedmioty + i);
		}
	}
	else cout << endl << "brak przedmiotow";
	cout << endl << endl;
}


void CStudent::zapis()
{
}


ostream & operator<<(ostream & output, CStudent & input)
{
	output << "Imie: " << input.imie << endl << "Nazwisko: " << input.nazwisko << endl << "Numer albumu: " << input.nr_albumu
		<< endl << "Srednia: " << input.srednia << endl << "Przedmioty: " << endl;
	if (input.N != 0)
	{
		for (size_t i = 0; i < input.N; i++)
		{
			output << '(' << i + 1 << ") " << *(input.przedmioty + i) << endl;
		}
	}
	else output << "brak przedmiotow" << endl;
	output << endl;
	return output;
}