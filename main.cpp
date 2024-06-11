#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

class Worker
{
public:

	void Start()
	{
		int choice;
	
		FillWorker();
		std::cout << "\n1 - Показать\n2 - Выход\n";
		std::cin >> choice;

		if (choice == 1)
		{
			Print();
		}
	}

	void FillWorker()
	{
		std::cout << "Имя и фамилия: ";
		std::getline(std::cin, name);
		std::cout << "Стаж (в годах): ";
		std::cin >> experience;
		std::cout << "Часовая зарплата: ";
		std::cin >> wagesPerHour;
		std::cout << "Кол-во отработанных часов: ";
		std::cin >> hoursInAll;

		WagesInAll();
		Award();
	}

	void Print()
	{
		std::cout << "\n******************************************************";

		std::cout << std::left << std::setw(45) << "\n* Имя и фамилия: "    << std::right << name 
		 << std::left << std::setw(45) << "\n* Стаж (в годах): "            << std::right << experience 
		 << std::left << std::setw(45) << "\n* Часовая зарплата: "          << std::right << wagesPerHour 
		 << std::left << std::setw(45) << "\n* Кол-во отработанных часов: " << std::right << hoursInAll 
		 << std::left << std::setw(45) << "\n* Итоговая зарплата: "         << std::right << salary 
		 <<	std::left << std::setw(45) << "\n* Премия: "                    << std::right << award;

		std::cout << "\n******************************************************\n";
	}

	void OutputToFile()
	{
		file.open("file.txt", std::ofstream::app);

		

		file.close();
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
	First.Start();

	Worker Second;
	Second.Start();

	Worker Third;
	Third.Start();

	return 0;
}