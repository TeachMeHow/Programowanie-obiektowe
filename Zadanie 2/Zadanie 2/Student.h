#pragma once
#include <iostream>
#include <string>
using namespace std;
class CStudent
{
public:
	CStudent();
	~CStudent();
	
protected:
	string imie;
	string nazwisko;
	int nr_albumu;
	double srednia;
	string* przedmioty;
	size_t N;
	
public:
	void nowe_dane();
	void wyswietl();
	void zapis();
	friend ostream &operator<<(ostream &output, CStudent &input);
};

