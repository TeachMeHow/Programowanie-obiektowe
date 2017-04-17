#pragma once

class Album
{
public:
	Album();
	~Album();
	void Getinfo();
	void Printinfo();
	void Gotodir();
private :
	int DiscNum;
	CDisc Disc;
protected:
	char path;
};

class CDisc
{
public :
	CDisc();
	~CDisc();
	int GetLength();
	void Display();
private : 
	int NumTracks;
	int Length;
	Track Item;
protected : 
	void SortAndFilter();
};

class Track
{
public:
	Track();
	~Track();
	void PlayTrack();
	void EditTrackInfo();
	void GetTrackInfo();
protected : 
	char Artist;
	char Album;
	char Genre;
	int Year;
	char Title;
	int Tracknum;
	int Duration;
};

class Compilation :
	private CDisc
{
public:
	Compilation();
	~Compilation();
private :
	char AlbumList;
	char ArtistList;
	char GenreList;
	int Years;
protected : 
	void SortAndFilter();
};

