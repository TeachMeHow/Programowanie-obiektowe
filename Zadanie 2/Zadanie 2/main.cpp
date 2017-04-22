#include "Student.h"
#include <algorithm>
#include <cstdio> // memcpy()
#include <fstream> // ofstream, ios

CStudent* Student;
size_t blocksize = sizeof(CStudent);
size_t K = 0;
ofstream studentfile ("studentfile.txt", ios::out | ios::trunc);
int Menu()
{
	
	int wybor = 0;
	while (wybor != 4) 
	{
		cout << "\nMenu\n\n1. Dodaj nowego studenta\n2. Wyswietl spis studentow\n3. Zapisz do pliku\n4. Wyjdz z programu";
		cin >> wybor;
		cout << endl;
		switch (wybor) {
		case 1:
			CStudent *tempStudent;
			tempStudent = new CStudent[++K];
			for (size_t i = 0; i < K - 1; i++)
			{
				*(tempStudent + i) = *(Student+i); //wywolywany jest konstruktor kopiujacy (domyslny!)
			}

			delete[] Student;
			Student = tempStudent;
			Student[K - 1].nowe_dane();
			break;

		case 2:
			for (size_t i = 0; i < K; i++)
			{
				cout << endl << "Student " << i + 1 << ':' << endl;
				(Student + i)->wyswietl();
			}
			break;

			//TODO: po dodaniu studenta operacja wyswietlania zwraca blad, FIX - zwiazane ze string w tab dynamicznej, xstring_insert.h - plik ktory otwiera sie po bledzie

		case 3:
			if (studentfile.is_open())
			{
				for (size_t i = 0; i < K; i++)
				{
					studentfile << "Student " << i+1 << ": " << endl << Student[i];
				}
			}
			
			return 0; break;

		case 4: return 1;
		default: break;
		}
	}
}
int main()
{
	cout << "Podaj liczbe studentow :\n";
	cin >> K;
	Student = new CStudent[K];
	for (size_t i= 0; i < K; i++){
		Student[i].nowe_dane();
	}
	
	while(!Menu());
	studentfile.close();
	delete[] Student;
	return 0;
}