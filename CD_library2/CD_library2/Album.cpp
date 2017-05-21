#include "Album.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77

Album::Album()
{
}


Album::Album(const Album & obj)
{
	path = obj.path;
	Normal = obj.Normal;
	Mix = obj.Mix;
}


Album::~Album()
{
}


void Album::PrintInfo()
{
	std::vector<Disc>::iterator di;
	std::vector<Compilation>::iterator ci;
	int i = 1;
	//Prints all the labels for discs/compilations - iterating
	for (di = Normal.begin(), i; di < Normal.end(); i++, di++)
	{
		std::cout << "> CD " << di-Normal.begin()+1  << ':' << "\n";
		di->Label();
	}
	for (ci = Mix.begin(), i; ci < Mix.end(); i++, ci++)
	{
		std::cout << "> Mix " << ci-Mix.begin() + 1 << ':' << "\n";
		ci->Label();
	}
	//TODO print total number of tracks and length
	std::cout << std::endl;
}


void Album::ShowDisc()
{
	size_t i = 0, choice = 0;
	if (!Normal.empty())
	{
		std::cout << ">>CD 1:\n";
		Normal[0].Display();
	}
	else if (!Mix.empty())
	{
		std::cout << "Mix 1:\n";
		Mix[0].Display();
	}
	
	if (!Mix.empty() || !Normal.empty())
	{
		std::cout << "\n(0) Go back\nNext (->)\n";
		while (choice != 48)
		{
			choice = _getch();
			system("CLS");
			//TODO it appears twice for the first time!
			if (i > 1) { if (choice == KEY_LEFT) --i; };
			if (i <= Normal.size() + Mix.size()-1) { if (choice == KEY_RIGHT) ++i; };
			if (i > 0 && i <= Normal.size()) {
				std::cout << ">>CD " << i << ":\n";
				Normal[i - 1].Display();
			}
			else if (i > Normal.size() && i <= Normal.size() + Mix.size())
			{
				std::cout << ">>Mix " << i - Normal.size() << ":\n";
				Mix[i - Normal.size() - 1].Display();
			}
			std::cout << "\n\n(0) Go back\n(<-) Previous ... Next (->)\n";
		}
	}
	else if(Mix.empty() && Normal.empty()) std::cout << "Nothing to show!\nPress any key...";
	_getch();
}

void Album::SetPath()
{
	std::getline(std::cin, path);
}

void Album::NewInfo()
{
	Normal.clear();
	Mix.clear();
	//number of standard single artist releases
	int DiscNum = -1;
	//number of compilation discs
	int MixNum = -1;
	std::cout << "Entry " << counter<Album>::entries_alive << std::endl
		<< "Number of normal disks: ";
		std::cin >> DiscNum;
		//TODO Uncomment after test!
		//DiscNum = 2;
	std::cout << "\nNumber of compilations/mixes/bonus discs: ";	
		std::cin >> MixNum;
		//MixNum = 2;
	std::cout << std::endl;
	for (int i = 0; i < DiscNum; i++)
	{
		Normal.push_back(Disc());
	}
	
	
	for (int i = 0; i < MixNum; i++)
	{
		Mix.push_back(Compilation());
	}
	for (int i = 0; i < DiscNum; i++)
	{
		system("CLS");
		std::cout << ">> CD " << i + 1 << " info:\n";
		Normal[i].NewInfo();
	}
	for (int i = 0; i < MixNum; i++)
	{
		system("CLS");
		std::cout << ">> Mix " << i + 1 << " info:\n";
		Mix[i].NewInfo();
	}
	std::cout << "Press any key...";
	_getch();
}


void Album::GotoDir()
{
	path = "c:\\";
	std::string _path = "explorer " + path;
	const char* command = _path.c_str();
	system(command);
}
