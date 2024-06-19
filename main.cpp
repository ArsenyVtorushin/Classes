#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

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
		std::cout << "\n*****************************************************************";

		std::cout << std::left << std::setw(45) << "\n* ��� � �������: "    << std::setw(20) << std::right << name
		 << std::left << std::setw(45) << "\n* ���� (� �����): "            << std::setw(20) << std::right << experience
		 << std::left << std::setw(45) << "\n* ������� ��������: "          << std::setw(20) << std::right << wagesPerHour
		 << std::left << std::setw(45) << "\n* ���-�� ������������ �����: " << std::setw(20) << std::right << hoursInAll
		 << std::left << std::setw(45) << "\n* �������� ��������: "         << std::setw(20) << std::right << wagesInAll
		 <<	std::left << std::setw(45) << "\n* ������: "                    << std::setw(20) << std::right << award;

		std::cout << "\n*****************************************************************\n\n";
	}

	void OutputToFile()
	{
		std::ofstream outputFile;
		outputFile.open("file.txt", std::ofstream::app);

		if (!outputFile.is_open())
		{
			std::cerr << "\nError output\n";
		}
		else
		{
			outputFile << std::left << std::setw(45) << "\n��� � �������: "      << std::setw(20) << std::right << name
				<< std::left << std::setw(45) << "\n���� (� �����): "            << std::setw(20) << std::right << experience
				<< std::left << std::setw(45) << "\n������� ��������: "          << std::setw(20) << std::right << wagesPerHour
				<< std::left << std::setw(45) << "\n���-�� ������������ �����: " << std::setw(20) << std::right << hoursInAll
				<< std::left << std::setw(45) << "\n�������� ��������: "         << std::setw(20) << std::right << wagesInAll
				<< std::left << std::setw(45) << "\n������: "                    << std::setw(20) << std::right << award << "\n";
		}

		outputFile.close();
	}

private:

	std::string name;
	float experience;
	int wagesPerHour;
	float hoursInAll;
	int wagesInAll;
	int award;

	void WagesInAll()
	{
		wagesInAll = wagesPerHour * hoursInAll;
	}

	void Award()
	{
		if (experience > 1 && experience < 3)
		{
			award = wagesInAll / 100 * 5;
		}
		else if (experience >= 3 && experience < 5)
		{
			award = wagesInAll / 100 * 8;
		}
		else if (experience >= 5)
		{
			award = wagesInAll / 100 * 15;
		}
	}
};

void Start(Worker& worker);
void ReadFromFileAndPrint();
void ClearFileBeforeStart();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ClearFileBeforeStart();

	Worker first;
	Start(first);

	Worker second;
	Start(second);

	Worker third;
	Start(third);

	ReadFromFileAndPrint();

	return 0;
}

void Start(Worker& worker)
{
	worker.FillWorker();

	char choice;
	do
	{
		std::cout << "\n1 - ��������\n2 - �����\n";
		std::cin >> choice;
	} while (choice < 49 || choice > 50);

	if (choice == '1')
	{
		worker.Print();
	}

	worker.OutputToFile();
	std::cin.ignore(3200, '\n');
}

void ReadFromFileAndPrint()
{
	std::cout << "\n\n - ����: -\n";

	std::ifstream inputFile;
	inputFile.open("file.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "\nError input\n";
	}
	else
	{
		char sym;
		
		while (inputFile.get(sym))
		{
			std::cout << sym;
		}
	}

	inputFile.close();
}

void ClearFileBeforeStart()
{
	std::ofstream file;

	file.open("file.txt");

	if (!file.is_open())
	{
		std::cerr << "error";
	}
	else
	{
		file << "";
	}

	file.close();
}