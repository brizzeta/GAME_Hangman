#include "Word.h"

class Play
{
	Word word;
	time_t Time;
public:
	Play() = default;
	void Game();        //последовательность игры
	void Start();       //заголовок игры
	void Start_time();  //фиксирование начального времени
	void End_time();    //рассчет потраченного времени
};