#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

class Worker
{
public:

	std::string name;
	float experience;
	int wagesPerHour;
	float hoursInAll;
	int salary;
	int award;

	void FillWorker()
	{
		std::cout << "��� � �������: ";
		std::getline(std::cin, name);
		std::cout << "���� (� �����): ";
		std::cin >> experience;
		std::cout << "������� ��������: ";
		std::cin >> wagesPerHour;
		std::cout << "���-�� ������������ �����: ";
		std::cin >> hoursInAll;

		WagesInAll();
		Award();
	}

	void WagesInAll()
	{
		salary = wagesPerHour * hoursInAll;
		std::cout << "\n��������: " << salary;
	}

	void Award()
	{
		if (experience > 1 && experience < 3)
		{
			award = salary / 100 * 5;
		}
		else if (experience > 3 && experience < 5)
		{
			award = salary / 100 * 8;
		}
		else if (experience > 5)
		{
			award = salary / 100 * 15;
		}

		std::cout << "\n������: " << award << "\n\n";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker First;
	First.FillWorker();

	return 0;
}