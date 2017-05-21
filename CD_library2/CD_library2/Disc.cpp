#include "Disc.h"



Disc::Disc()
{
	numtracks = 0;
}

Disc::Disc(const Disc & obj)
{
	artist = obj.artist;
	albumtitle = obj.albumtitle;
	year = obj.year;
	genre = obj.genre;
	Item = obj.Item;
	numtracks = obj.numtracks;

}


Disc::~Disc()
{
}

void Disc::NewInfo()
{
	Item.clear();
	std::cout << "Artist: ";
	std::cin >> artist;
	//artist = "Sweeeg";
	std::cout << "\nAlbum Title: ";
	std::cin >> albumtitle;
	//albumtitle = "PbeaCH";
	std::cout << "\nYear: ";
	std::cin>> year;
	//year = 2017;
	std::cout << "\nGenre: ";
	std::cin >> genre;
	//genre = "Rock";
	std::cout << std::endl;
	int choice(0);
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
		//without ++ operator
		/*std::cout << "Title: ";
		std::cin >> Item[i].title;
		//title = "BigB";
		std::cout << "Duration (in seconds): ";
		std::cin >> Item[i].duration;
		//duration = 150;
		std::cout << std::endl;
		*/
		++Item[i];
	}
	RefreshTrackInfo();
	
}

void Disc::Label()
{
	std::cout << std::setfill('.') << std::setw(13) << std::left << "  Artist:" << artist
		<< std::setw(14) << std::left << "\n  Title:" << albumtitle
		<< std::setw(14) << std::left << "\n  Year:" << year
		<< std::setw(14) << std::left << "\n  Genre:" << genre
		<< std::endl;
}

void Disc::Display()
{
	Label();
	std::cout << std::endl;
	std::vector<Track>::iterator it = Item.begin();
	for (it; it < Item.end(); it++)
	{
		std::cout << it - Item.begin() + 1 << ". "; it->Basic_Label(); std::cout << std::endl;
	}

}




void Disc::RefreshTrackInfo()
{
	std::vector<Track>::iterator it;
	for (it = Item.begin(); it < Item.end(); it++)
	{
		it->album = albumtitle;
		it->artist = artist;
		it->genre = genre;
		it->year = year;
	}
	numtracks = Item.size();
}
