#pragma once
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
//#include "Disc.h"
//don't uncomment! doesn't compile
class Track
{
public:
	Track();
	Track(const Track &obj);
	~Track();
	//basic info
	void Basic_Label();
	//more detailed info
	void Extended_Label();
	//erases data and enters new one
	void NewInfo();
	//adds title and duration to track info
	//TODO OPERATOR OVERLOADING! YAY!
	Track operator++();
	/*
	Those friendships are needed because usage in Disc and Compilation classes differs very much and would require
	incomprehensible methods with a lot of arguments
	*/
	//TODO find a solution for that ^
	friend class Disc;
	friend class Compilation;
private:
	//track variable
	std::string artist, album , genre, title;
	//duration in seconds
	int duration;
	//TODO remove this comment!!!!
	int year;
};


