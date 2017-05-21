#pragma once
#include "Disc.h"
#include <algorithm>
#include <sstream>
class Compilation :
	public Disc
{
public:
	Compilation();
	Compilation(const Compilation &obj);
	~Compilation();
	//erase and enter new data
	void NewInfo();
	//prints labels for all the tracks
	void Display();
	//print label
	void Label();
private:
	//takes data from tracks and fills compilation variables
	void RefreshInfo();
	//compilation variable
	std::vector<std::string> artists, albums, genres; 
	//year span (first - last)
	std::string years;
};

