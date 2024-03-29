#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string Zeros(int first, int second)
{
	int l = first - second; //licznik
	string how_much = "";
	for (int i = 0; i < l; i++)
	{
		how_much += '0';
	}
	return how_much;
}
string ConvertFromSymbolic(string text)
{
	int next = 0;
	string Show_answer = "";
	bool comma = false;
	int ni = text.length();
	for (int i = 0; i<ni; i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			Show_answer += text[i];
			if (comma == true)
			{
				next++;
			}
		}
		else if (text[i] == '.')
		{
			comma = true;
		}
		else if (text[i] == 'B')
		{
			if (comma == false)
			{
				Show_answer += Zeros(9, 0);
			}
			else
			{
				Show_answer += Zeros(9, next);
			}
		}
		else if (text[i] == 'M')
		{
			if (comma == false)
			{
				Show_answer += Zeros(6, 0);
			}
			else
			{
			Show_answer += Zeros(6, next);
			}
		}	
		else if (text[i] == 'T')
		{
			if (comma == false)
			{
				Show_answer += Zeros(12, 0);
			}
			else
			{
				Show_answer += Zeros(6, next);
			}
		}
	}
	return Show_answer;
}

int main()
{
	std::cout << ConvertFromSymbolic("4M") << std::endl;
	std::cout << ConvertFromSymbolic("54T") << std::endl;
	std::cout << ConvertFromSymbolic(" 5.434B") << std::endl;
	system("pause");
}
