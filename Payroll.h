#include <iostream>

using namespace std;

class Payroll
{

private:
	string name;
	int id;
	int hourlyRate;
	int hoursWorked;
	int wage;
public:
	Payroll(string, int, int, int);
	Payroll();
	void set(string, int, int, int);
	void set(string, int, int, int, int);
	void setName(string a) {name = a;};
	void setId(int a) {id = a;};
	void setHourlyRate(int a) {hourlyRate = a;};
	void setHoursWorked(int a) {hoursWorked = a;}
	void setWage(int a) { wage = a; }
	string getName() { return name; }
	int getId() { return id; }
	int getHourlyRate() { return hourlyRate; }
	int getHoursWorked() {return hoursWorked;}
	int getWage() { return wage; }
	void calculateWage();
	void input();
	void output();
	
};
void sort(Payroll record[], int& num);
void output(Payroll record[],int& num);
int readfile(string& filename);
void send(Payroll record[],string& filename);