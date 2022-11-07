#include "Play.h"
#include <conio.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE text;

//последовательность игры
void Play::Game() 
{
	text = GetStdHandle(STD_OUTPUT_HANDLE);

	word.Choose();              //выбор слова из файла
	word.Decrypt();             //расшифровка слова
	word.F_Init_hidden_word();  //начальная инициализация скрытого слова
	Start();                    //заголовок игры
	Start_time();               //фиксирование начального времени	

	while (word.Check_tent() && !word.Check_full_hidden_word())
	{
		cout << "Неверных попыток: " << word.Get_tent();  //вывод попыток
		cout << endl << endl << endl;
		word.Out_hidden_word();                           //вывод скрытого слова
		word.Out_illustr();                               //вывод иллюстрации
		word.Out_letters();                               //вывод введенных букв игрока
		word.Enter();                                     //ввод буквы
		word.Check_hidden_word();                         //проверка и повторная инициализация элемента скрытого слова
		system("cls");
	}

	cout << "Неверных попыток: " << word.Get_tent();      //вывод попыток
	cout << endl << endl << endl;
	cout << "Загаданное слово: " << word.Get_word();
	cout << endl << endl << endl;
	word.Out_illustr();                                   //вывод иллюстрации
	word.Out_letters();                                   //вывод введенных букв игрока

	if (word.Check_full_hidden_word())
	{
		SetConsoleTextAttribute(text, 2);
		cout << "ВЫ ВЫИГРАЛИ!";
	}
	else
	{
		SetConsoleTextAttribute(text, 4);
		cout << "ВЫ ПРОИГРАЛИ!";
	}
	SetConsoleTextAttribute(text, 15);
	cout << endl << endl;
	End_time();
	_getch();
	system("cls");
}


//заголовок игры
void Play::Start()
{
	cout << "-----------------------------------Play game----------------------------------" << endl
		 << "                  _   _                  ___  ___                             " << endl
		 << "                 | | | |                 |  \\/  |                            " << endl
		 << "                 | |_| | __ _ _ __   __ _| .  . | __ _ _ __                   " << endl
		 << "                 |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\               " << endl
		 << "                 | | | | (_| | | | | (_| | |  | | (_| | | | |                 " << endl
		 << "                 \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|            " << endl
		 << "                                     __/ |                                    " << endl
		 << "                                    |___/                                     " << endl << endl
		 << "----------------------------Press Enter to continue---------------------------" << endl;
	
	_getch();
	system("cls");
}

//фиксирование начального времени
void Play::Start_time()
{
	time(&Time);
}

//рассчет потраченного времени
void Play::End_time()
{
	time_t start = Time;
	time(&Time);
	Time -= start;

	int s = Time, m, h = 0;
	m = s / 60;
	h = s / 60 / 60;
	cout << "Время: " << h << ":" << m << ":" << s % 60 << endl;
}