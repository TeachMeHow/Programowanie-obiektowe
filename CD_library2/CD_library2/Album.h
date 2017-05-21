#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "counter.h"
#include "Disc.h"
#include "Compilation.h"
#include <conio.h>
class Album : counter<Album>
{
public:
	Album();
	Album(const Album &obj);
	~Album();
	//Displays disc labels
	void PrintInfo();
	//Asks which disc on album do you want to see and calls its Display() function
	void ShowDisc();
	//Specifies album adress on a hard drive
	void SetPath();
	//Asks for data on album, erases old
	void NewInfo();
	//open in windows explorer
	void GotoDir();
private:
	//path to the hard drive location
	std::string path; 
	//number of standard single artist releases
	int DiscNum;
	//number of compilation discs
	int MixNum;
	//container of standard single artist releases
	std::vector<Disc> Normal;
	//container of compilation discs
	std::vector<Compilation> Mix;


};

