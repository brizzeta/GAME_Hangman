#pragma once
class Illustration
{
	int tent;
public:
	Illustration() = default;
	void Out_Illustration();
	int Get_tent();
	void Set_tent();     //увеличение неверных попыток на 1
};