#include "Word.h"
#include <fstream>
#include <ctime>
#include <Windows.h>

//выбор слова из файла
void Word::Choose()
{
	ifstream file("words.txt");
	int ind = 0;
	setlocale(0, "");

	srand(time(0));
	int rand_word = 1 + rand() % (count);  //от 1 до 2000

	if (!file)
	{
		cerr << "ОШИБКА! words.txt невозможно открыть." << endl;
		exit(1);
	}

	while (!file.eof())
	{
		file >> word;
		if (rand_word == ind + 1) {
			break;
		}
		ind++;
	}
	file.close();
}

//расшифровка слова
void Word::Decrypt()
{
	for (int k = 0; k < word.length(); k++)
	{
		for (int j = 0; j < 33; j++)
		{
			if (word[k] == key[j]) {
				word[k] = alphabet[j];
				break;
			}
		}
	}
}

//начальная инициализация скрытого слова
void Word::F_Init_hidden_word()
{
	hidden_word = word;
	for (int i = 0; i < word.length(); i++)
	{
		hidden_word[i] = '_';
	}
}

//ввод буквы
void Word::Enter()
{
	SetConsoleCP(1251);          //для ввода и вывода русских букв
	SetConsoleOutputCP(1251);

	cout << "Введите букву: ";
	char a;
	cin >> a;

	//проверка на ввод повторной буквы
	is_letter = false;
	if (letters.size() > 0) {
		for (char i : letters)
		{
			if (a == i)
			{
				is_letter = true;
			}
		}
	}
	if (!is_letter)
	{
		letters.push_back(a);
	}	
}

//проверка и повторная инициализация элемента скрытого слова
void Word::Check_hidden_word()
{		
	for (int i = 0; i < word.length(); i++)
	{
		if (letters.back() == word[i])
		{
			hidden_word[i] = word[i];
			is_letter = true;
		}		
	}
	if (!is_letter)
	{
		illustr.Set_tent();
	}
}

//вывод скрытого слова
void Word::Out_hidden_word()
{
	cout << "\t";
	for (int i = 0; i < hidden_word.length(); i++)
	{
		cout << hidden_word[i] << " ";
	}
	cout << endl << endl << endl;
}

//вывод введенных букв игрока
void Word::Out_letters()
{
	cout << endl << "Введённые буквы: ";
	if (letters.size() > 0)
	{
		for (char i : letters)
		{
			cout << i << " ";
		}
	}
	cout << endl << endl;
}

//проверка и вывод неверных попыток
bool Word::Check_tent()
{
	if (illustr.Get_tent() < 6)
	{
		cout << "Неверных попыток: " << illustr.Get_tent();
		cout << endl << endl << endl;
		return 1;
	}
	else return 0;
}

//получить количество неверных попыток
int Word::Get_tent()
{
	return illustr.Get_tent();
}

//вывод иллюстрации
void Word::Out_illustr()
{
	illustr.Out_Illustration();
}

//проверка на отгаданное слово
bool Word::Check_full_hidden_word()
{
	if (hidden_word == word)
	{
		return 1;
	}
	else return 0;
}

//получить слово
string Word::Get_word()
{
	return word;
}