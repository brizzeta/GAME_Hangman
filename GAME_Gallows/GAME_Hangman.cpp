#include "Play.h"
#include <string>
using namespace std;

int main()
{
    string answ = "Да";
    while(answ == "Да")
    {
        Play a;
        a.Game();
        a.~Play();
        cout << "Сыграть заново? ";
        cin >> answ;
        system("cls");
    }
}