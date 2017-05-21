#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Track.h"
class Disc
{

public:
	Disc();
	Disc(const Disc &obj);
	virtual ~Disc();
	//erase and enter new data
	virtual void NewInfo();
	//print label
	virtual void Label();
	//prints labels for all the tracks
	virtual void Display();

private:
	//disc variable
	std::string artist, albumtitle, genre;
	//disc variable
	int year;
	// update tracks with current album info
	void RefreshTrackInfo();
protected:
	//shoud it be updated in the constructor?
	//number of tracks on the disc/compilation - updated with refresh methods
	int numtracks;
	//TODO implement function summing up all durations - add to label?
	int totalduration;
	//container for tracks
	std::vector<Track> Item;

};

