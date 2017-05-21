#include "Compilation.h"
#include <conio.h>

Compilation::Compilation()
{
	numtracks = 0;
}

Compilation::Compilation(const Compilation & obj)
{
	numtracks = obj.numtracks;
	Item = obj.Item;
	artists = obj.artists;
	albums = obj.albums;
	genres = obj.genres;
	years = obj.years;

}


Compilation::~Compilation()
{
}

void Compilation::Display()
{
	Label();
	std::cout << std::endl;
	std::vector<Track>::iterator it = Item.begin();
	for (it; it < Item.end(); it++)
	{
		std::cout << it - Item.begin() + 1 << ". "; it->Extended_Label(); std::cout << std::endl;
	}

}
void Compilation::NewInfo()
{
	Item.clear();
	std::cout << "How many tracks do you want to add? : ";
	std::cin >> numtracks;
	//numtracks = 2;
	std::cout << std::endl;
	for (int i = 0; i < numtracks; i++)
	{
		Item.push_back(Track());
	}
	for (int i = 0; i < numtracks; i++)
	{
		Item[i].NewInfo();
	}
	RefreshInfo();
}
void Compilation::Label()
{
	std::cout << "  " << artists.size() << " artist/s\n"
		<< "  " << albums.size() << " album/s\n"
		<< "  Years: " << years << std::endl
		<< "  " << genres.size() << " genre/s"
		<< std::endl;	
}

void Compilation::RefreshInfo()
{
	size_t i, j;
	int min, max;
	std::stringstream  ss;
	if (!Item.empty())
	{ 
		artists.push_back(Item[0].artist);
		albums.push_back(Item[0].album);
		genres.push_back(Item[0].genre);
		
		for (i = 0; i < albums.size(); i++){
			for (j = i + 1; j < Item.size(); j++) {
				if (albums[i] != Item[j].album) albums.push_back(Item[j].album);
			}}
		for (i = 0; i < artists.size(); i++) {
			for (j = i + 1; j < Item.size(); j++) {
				if (artists[i] != Item[j].artist) artists.push_back(Item[j].artist);
			}
		}
		for (i = 0; i < genres.size(); i++) {
			for (j = i + 1; j < Item.size(); j++) {
				if (genres[i] != Item[j].genre) genres.push_back(Item[j].genre);
			}
		}
		max = min = Item[0].year;
		for (i = 1; i < Item.size(); i++) {
			if (Item[i].year > max) max = Item[i].year;
			else if (Item[i].year < min) min = Item[i].year;
		}
		ss << min << " - " << max;
		years = ss.str();
		numtracks = Item.size();
	}
	else {
		years = "unknown - unknown";
		numtracks = 0;
	}
	
}
