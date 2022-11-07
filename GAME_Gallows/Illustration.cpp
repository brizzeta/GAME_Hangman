#include "Illustration.h"
#include <iostream>
using namespace std;

int Illustration::Get_tent()
{
	return tent;
}

//увеличение неверных попыток на 1
void Illustration::Set_tent()
{
	tent++;
}

void Illustration::Out_Illustration()
{
	switch (tent)
	{
	case 0:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 1:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 2:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |       +" << endl
			<< " |       |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 3:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |       +" << endl
			<< " |      /|" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 4:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |       +" << endl
			<< " |      /|\\" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 5:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |       +" << endl
			<< " |      /|\\" << endl
			<< " |      /" << endl
			<< " |     /" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	case 6:
		cout << " _______________" << endl
			<< " |/      |" << endl
			<< " |       O" << endl
			<< " |       +" << endl
			<< " |      /|\\" << endl
			<< " |      / \\" << endl
			<< " |     /   \\" << endl
			<< " |" << endl
			<< " |" << endl
			<< " |" << endl
			<< "---------------------" << endl << endl;
		break;
	}
}