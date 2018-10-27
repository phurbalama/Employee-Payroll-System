#include "stdafx.h"
#include <iostream>
#include "Payroll.h"
#include <string>
#include <fstream>

using namespace std;

Payroll::Payroll(string name, int id, int hourlyRate, int hoursWorked)
{
	this->name = name;
	this->id = id;
	this->hourlyRate = hourlyRate;
	this->hoursWorked = hoursWorked;

}
Payroll::Payroll()
{
	name = " ";
	id = 0;
	hourlyRate = 0;
	hoursWorked = 0;
}
void Payroll::set(string name, int id , int hourlyRate, int hoursWorked)
{
	this->name = name;
	this->id = id;
	this->hourlyRate=hourlyRate;
	this->hoursWorked = hoursWorked;
}
void Payroll::set(string name, int id, int hourlyRate, int hoursWorked,int wage)
{
	this->name = name;
	this->id = id;
	this->hourlyRate = hourlyRate;
	this->hoursWorked = hoursWorked;
	this->wage = wage;
}

void Payroll::input()
{
	cout << "Enter your name : ";
		getline(cin, name);
		cout << "Enter your ID number : ";
		cin >> id;
		cout << "Enter your Hourly Rate: ";
		cin >> hourlyRate;
		cout << "Enter your Hours worked : ";
		cin >> hoursWorked;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
void Payroll::output()
{
	cout << name << "   " << id << "     " << hourlyRate << "     " << hoursWorked << "       " << getWage()<< endl;
}
void Payroll::calculateWage()
{
	wage = hourlyRate * hoursWorked;
}

void output(Payroll record[],int& num)
{
	cout << "\nName       Id      Rate      Hours      Wage";
	cout << "\n===========================================\n";
	for (int i = 0; i< num; i++) {
		record[i].calculateWage();
		record[i].output(); 
		cout << endl;
	}
}
void sort(Payroll record[],int& num)
{
	string a;
	int b;
	int c;
	int d;
	int e;
	
	
	int swapp;

	//using bubble sort to sort the value in descending order
	for (int i = 0; i<num - 1; i++)
	{
		swapp = 0;
		for (int j = 0; j<(num - i) - 1; j++)
		{
			if (record[j].getWage()<record[j + 1].getWage()) //checks if the wages are sorted
			{
				//sorts wages in descending order
				a = record[j].getName();
				b= record[j].getId();
				c= record[j].getHourlyRate();
				d= record[j].getHoursWorked();
				e= record[j].getWage();
				//sorts wages in descending order
				record[j].set(record[j + 1].getName(), record[j + 1].getId(), record[j + 1].getHourlyRate(), 
					           record[j + 1].getHoursWorked(), record[j + 1].getWage());
				
				record[j + 1].set(a, b, c, d, e);
			
				
				swapp = 1;

			}

		}
		if (swapp == 0)
		{
			break;
		}

	}

}
int readfile(string& filename)
{
	int size = 0;
	string line;
	ifstream in;
	in.open(filename);
	if (in.fail())//if the file fails to open it outputs error message
	{
		cerr << "The file could not be opened \n";
		cerr << "The Path was not found. \n";
		system("pause");

	}
	else
	{

		while (!in.eof())
		{


			getline(in, line);
			size++; //creating count for each line in the text file
		}

	}
	
	return size;
	
}
void send(Payroll record[],string& filename)
{
	
	int i = 0;
	string name;
	int id;
	int hourlyRate;
	int hoursWorked;
	ifstream in;
	in.open(filename); //opening file path


	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> name >> id >> hourlyRate >> hoursWorked;
			//inputs all the data in the class of array
			record[i].set(name, id, hourlyRate, hoursWorked);
			i++;
			
		}
		in.close();
	}
	//return Payroll(name,id,hourlyRate,hoursWorked);
}