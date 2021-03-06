﻿#include <iostream>

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Student
{
	char Mark[56];
	char Manuf[32];
	char Type[32];
	Date birthday;
	short Price;
	
};

using namespace std;
int main()
{
	const int N = 2;
	Student group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput Mark: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Mark, 56);

		cout << "\nIinput Manuf: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Manuf, 32);

		cout << "\nInput Type: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Type, 56);

		do
		{
			cout << "\nInput Date of Application: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].birthday.day >> group[i].birthday.month >> group[i].birthday.year;
		} while (!group[i].birthday.isCorrect());

		cout << "\nInput Price:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Price;



	}

	for (int i = 0; i < N; i++)
	{
		cout << "\nNaim: " << group[i].Mark << endl;
		cout << "\nManuf: " << group[i].Manuf << endl;
		cout << "\nDate of Application: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
		cout << "\nPrice: " << group[i].Price << endl;
		
	}



}
