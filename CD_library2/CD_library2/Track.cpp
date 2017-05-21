#include "Track.h"



Track::Track()
{
	duration = 0;
	year = 0;
}



Track::Track(const Track & obj)
{
	artist = obj.artist;
	album = obj.album;
	year = obj.year;
	genre = obj.genre;
	duration = obj.duration;
	title = obj.title;
}


Track::~Track()
{
}

void Track::Basic_Label()
{
	int minutes = (duration / 60) % 60;
	int seconds = duration % 60;
	std::cout << std::setfill('.') << std::setw(30) << std::left << title << minutes << ':'
		<< std::right << std::setfill('0') << std::setw(2) << seconds ;
}

void Track::Extended_Label()
{
	
	int minutes = (duration / 60) % 60;
	int seconds = duration % 60;
	std::cout << std::setfill('.') << std::setw(30) << std::left << title << minutes << ':'
		<< std::right << std::setfill('0') << std::setw(2) << seconds;
	std::cout << std::endl << artist << " - " << album << " (" << year << ")";
}

void Track::NewInfo()
{
	std::cout << "Title: ";
	std::cin >> title;
	//title = "Bigbooty";
	std::cout << "Artist: ";
	std::cin >> artist;
	//artist = "YoloSwag";
	std::cout << "Album: ";
	std::cin >> album;
	//album = "PbeaCH";
	std::cout << "Year: ";
	std::cin >> year;
	//year = 2017;
	std::cout << "Duration (in seconds): ";
	std::cin >> duration;
	//duration = 150;
	std::cout << "Genre: ";
	std::cin >> genre;
	//genre = "Rock";
	std::cout << std::endl;

}

Track Track::operator++()
{
	std::cout << "Title: ";
	std::cin >> title;
	std::cout << "Duration (in seconds): ";
	std::cin >> duration;
	std::cout << std::endl;
	return Track();
}
