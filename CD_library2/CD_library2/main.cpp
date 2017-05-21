#include "myheader.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77

vector<Album> Library;
int main();
void Explore();
int main()
{
	//Menu
	int choice(0);
	while (choice != 4+48)
	{
		cout << "Menu \n(1)Explore \n(2)Add \n(3)Edit last entry \n(4)Exit\n";
		switch (choice = _getch())
		{
		case 1 + 48: system("CLS"); 
			if (!Library.empty()) Explore();
			else {
				cout << "Library empty!\nPress any key...";
				_getch();
			}
				break;
		case 2 + 48: system("CLS"); 
			Library.push_back(Album());
			Library.back().NewInfo(); 
			system("CLS");
			break;
		case 3 + 48: system("CLS"); 
			if (!Library.empty())
			{
				Library.back().ShowDisc();
				"\nPress any key...";
				_getch();
			}
			else {
				cout << "Library empty!\nPress any key...";
				_getch();
			}
				break;
		}
		system("CLS");
	}

	return 0;
}
void Explore()
{
	int choice(0);
	vector<Album>::iterator it;
	cout << "Explore\n"
		<< "(1) Show all\n"
		<< "(2) Show filtered\n"
		<< "(3) Search\n"
		<< "\n(<-) Go back\n";
	while (choice != KEY_LEFT)
	{
		choice = 0;
		switch (choice = _getch())
		{
			// 48 - 57 are ASCII for 0 - 9
		case 1+48: system("CLS"); for (it = Library.begin(); it < Library.end(); it++)
		{
			std::cout << "Entry " << it - Library.begin() + 1 << ":\n";
			it->PrintInfo();
		}; 
				 std::cout << "Total of " << counter<Album>::entries_alive 
					 <<" entries.\n\n(0) Go back\n"
					 << "Enter index of an entry you want to see: \n";
						 std::cin >> choice;
						 if (choice > 0 && choice <= Library.size())
						 {
							 system("CLS");
							 Library[choice - 1].ShowDisc();

						 }
						 choice = KEY_LEFT;


				
		break;
		case 2+48: break;
		case 3+48: break;
		}
	}
	system("CLS");

}
