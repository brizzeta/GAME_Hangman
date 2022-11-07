#include <iostream>
#include <vector>
#include "Illustration.h"
using namespace std;

class Word
{
	const char alphabet[34] = {"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЬЪЭЮЯ"}; //расшифровка
	const char key[34]      = {"ПРСТУФХЦЧШЩЫЬЪЭЮЯАБВГДЕЁЖЗИЙКЛМНО"}; //ключ для расшифровки
	const int count = 2000;                                 //количество слов в файле
	string word;                                            //выбранное слово
	string hidden_word;                                     //скрытое слово
	vector<char> letters;                                   //буквы игрока
	Illustration illustr;                                   //объект иллюстрации
	bool is_letter;								            //для проверки на повторный ввод буквы и есть ли буква в заданном слове	

public:
	Word() = default;
	void Choose();					//выбор слова из файла
	void Decrypt();					//расшифровка слова
	void F_Init_hidden_word();		//начальная инициализация скрытого слова
	void Enter();					//ввод буквы
	void Check_hidden_word();		//проверка и повторная инициализация элемента скрытого слова
	void Out_hidden_word();			//вывод скрытого слова
	void Out_letters();				//вывод введенных букв игрока
	bool Check_tent();				//проверка и вывод неверных попыток
	int Get_tent();				    //получить количество неверных попыток
	void Out_illustr();				//вывод иллюстрации
	bool Check_full_hidden_word();  //проверка на отгаданное слово
	string Get_word();              //получить слово
};

