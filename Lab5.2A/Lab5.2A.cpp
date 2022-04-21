// Lab5.2A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Обчислити кількість кожної з оцінок «5», «4», «3» з фізики
Обчислити кількість студентів, які отримали і з фізики і з математики оцінки «4» або «5»
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та екноміка", " Фізика та інформатика", "Трудове навчання" };

struct Student {
	char prizv[64];
	unsigned kurs;
	Specialty specialty;
	unsigned gradePhys;
	unsigned gradeMath;
	unsigned gradeInf;
};


void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	Student student;
	char ch;
	int specialty;
	do {

		cout << "Прізвище: ";
		cin >> student.prizv;
		cout << "Курс: "; cin >> student.kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> student.gradePhys;
		cout << "Оцінка з математики: "; cin >> student.gradeMath;
		cout << "Оцінка з інформатики: "; cin >> student.gradeInf;
		cout << endl;
		if (!f.write((char*)&student, sizeof(Student))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	cout << "========================================================================================================================================" << endl;
	cout << "|  No  |    Прізвище    |  Курс  |      Спеціальність      |   Оцінка з фізкики   |   Оцінка з математики   |   Оцінка з інформатики   |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

	ifstream f(fName, ios::binary);
	Student student;
	int i = 1;
	while (f.read((char*)&student, sizeof(Student))) {
		cout << "| " << setw(3) << right << i++ << "  ";
		cout << "| " << setw(15) << left << student.prizv
			<< "|   " << setw(3) << right << student.kurs << "  "
			<< "| " << setw(24) << left << specialtyStr[student.specialty]
			<< "| " << setw(20) << right << student.gradePhys << " "
			<< "| " << setw(23) << right << student.gradeMath << " "
			<< "| " << setw(24) << right << student.gradeInf << " "
			<< "|" << endl;
	}
	cout << "========================================================================================================================================" << endl;
	cout << endl;

}




int physStat5(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int fiveCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&student, sizeof(Student))) {

		if (student.gradePhys == 5) {
			fiveCount++;
		}

	}
	return fiveCount;
}

int physStat4(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int  fourCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}
	while (f.read((char*)&student, sizeof(Student))) {

		if (student.gradePhys == 4) {
			fourCount++;
		}
	}
	return fourCount;
}

int physStat3(const char* fName) {
	ifstream f(fName, ios::binary);
	Student student;
	int  threeCount = 0;
	if (!f)
	{
		cerr << "Error writing file '" << fName << "'" << endl;
		return 0;
	}

	while (f.read((char*)&student, sizeof(Student))) {

		if (student.gradePhys == 3) {
			threeCount++;
		}
	}
	return threeCount;
}


int goodMathPhys(const char* fName) {
	int n = 0;
	ifstream f(fName, ios::binary);
	Student student;
	while (f.read((char*)&student, sizeof(Student))) {
		if ((student.gradeMath == 4 || student.gradeMath == 5) && (student.gradePhys == 4 || student.gradePhys == 5))
			n++;

	}
	return n;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	char f[6] = "f.dat";
	int menuItem;

	do
	{
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - ввести дані у файл" << endl;
		cout << " [2] - вивести дані на екран" << endl;
		cout << " [3] - кількість кожної з оцінок «5», «4», «3» з математики" << endl;
		cout << " [4] - вивести прізвища студентів, які отримали і з фізики і з математики оцінку «5» " << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			Create(f);
			break;
		case 2:

			Print(f);
			break;
		case 3:
			cout << "Кількість 5 за фізику: " << physStat5(f) << endl;
			cout << "Кількість 4 за фізику: " << physStat4(f) << endl;
			cout << "Кількість 3 за фізику: " << physStat3(f) << endl;
			break;
		case 4:
			cout << "Кількість учнів 4 або 5 з фізики та метематики " << goodMathPhys(f) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число  - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}



