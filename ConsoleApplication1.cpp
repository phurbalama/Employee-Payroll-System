#include <iostream>
#include "stdafx.h"
#include <fstream>
#include "Payroll.h"
#include <string>

using namespace std;

int main()
{
	string filename = "data.dat";
	
	
	int size =readfile(filename); //readfile function reads the file and returns size of the file
	
	Payroll *record; // creating pointer array for Payroll class;
	record = new Payroll[size];//creating dynamic array 
	
	cout << "Payroll Program to calculate Wage and Sort the Wages in Descending Order\n";
	send(record, filename);//sends all the input of file to record;
	output(record, size); //output function that outputs value of all the records;
	cout << "After sorting \n";
    sort(record, size); // sorts all the records using sort function 
	output(record, size);

	system("pause");
	return 0;
}