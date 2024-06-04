#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

class Worker
{
public:

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

	void Print()
	{
		FillWorker();

		std::cout << "\n******************************************************";

		std::cout << std::left << std::setw(45) << "\n* ��� � �������: " << std::right << name 
		 << std::left << std::setw(45) << "\n* ���� (� �����): "            << std::right << experience 
		 << std::left << std::setw(45) << "\n* ������� ��������: "          << std::right << wagesPerHour 
		 << std::left << std::setw(45) << "\n* ���-�� ������������ �����: " << std::right << hoursInAll 
		 << std::left << std::setw(45) << "\n* �������� ��������: "         << std::right << salary 
		 <<	std::left << std::setw(45) << "\n* ������: "                    << std::right << award;

		std::cout << "\n******************************************************\n";
	}

private:

	std::string name;
	float experience;
	int wagesPerHour;
	float hoursInAll;
	int salary;
	int award;

	void WagesInAll()
	{
		salary = wagesPerHour * hoursInAll;
	}

	void Award()
	{
		if (experience > 1 && experience < 3)
		{
			award = salary / 100 * 5;
		}
		else if (experience >= 3 && experience < 5)
		{
			award = salary / 100 * 8;
		}
		else if (experience >= 5)
		{
			award = salary / 100 * 15;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker First;
	First.Print();

	return 0;
}