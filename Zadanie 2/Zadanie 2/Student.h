#pragma once
#include <iostream> // std::cin, std::cout
#include <string> //string
using namespace std;
class CStudent
{
protected:
	string imie;
	string nazwisko;
	int nr_albumu;
	double srednia;
	size_t N;
public:
	string* przedmioty;
public:
	CStudent();
	//CStudent(const CStudent &obj);
	~CStudent();

	void nowe_dane();
	void wyswietl();
	friend ostream &operator<<(ostream &output, CStudent &input);
};

