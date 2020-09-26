#include"Score.h"
#include <conio.h>

int main()
{
	Score GameScore;
	bool quit = false;
	do
	{
		std::cout << "(a)dd, (r)emove, (d)isplay, a(v)erage or (q)uit" << std::endl;
		char response = _getch();
		std::string name;
		int score;
		switch (response)
		{
		case 'a':
			std::cout << "Enter name" << std::endl;
			std::cin >> name;
			std::cout << "Enter score" << std::endl;
			std::cin >> score;
			GameScore.AddScore(name, score);
			break;
		case 'r':
			std::cout << "Enter name" << std::endl;
			std::cin >> name;
			std::cout << GameScore.remove(name) << std::endl;
			break;
		case 'd':
			GameScore.Display();
			break;
		case 'v':
			std::cout << GameScore.GetAverage() << std::endl;
			break;
		case 'q':
			quit = true;
			break;
		default:
			break;
		}

	} while (!quit);
	return 0;
}