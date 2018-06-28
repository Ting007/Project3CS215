#include "Employee.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Employee::Employee(){
	salary = "";
	duration = 0;
}

Employee::Employee(string new_name, int new_year, string new_salary, int new_duration){
	Person::Person(new_name, new_year, "employee");
	set_name(new_name);
	set_year_birth(new_year);
	set_type("employee");
	salary = new_salary;
	duration = new_duration;
}

int Employee::get_duration(){
	return duration;
}

string Employee::get_salary(){
	return salary;
}

void Employee::set_duration(int new_duration){
	duration = new_duration;
}

void Employee::set_duration(){
	int new_duration = 0;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Please enter the duration for this employee : " << endl;
	cin >> new_duration;
	if (cin.fail()|| new_duration < 0){
		cout << "\n Input is not a positive integer.\n";
		cin.clear();
		cin.ignore(100, '\n');
		set_duration();
	}
	else{
		duration = new_duration;
	}
}

void Employee::set_salary(string new_salary){
	salary = new_salary;
}

void Employee::set_salary(){
	int new_salary;
	cin.clear();
	cin.ignore(100, '\n'); cin.clear();
	cout << "Please enter the salary for this employee : " << endl;
	cin >> new_salary;
	if (cin.fail()){
		cout << "\n Input is not a integer.\n";
		cin.clear();
		cin.ignore(100, '\n');
		set_salary();
	}
	else{
		ostringstream strm;
		strm << new_salary;
		string salary_temp = strm.str();
		int len = salary_temp.length();
		salary = salary_temp.substr(0, len-3) + "," + salary_temp.substr(len-3, 3);
	}
}

void Employee::display(){
	Person::display();
	cout << "   Salary : " << salary << " Dollars"<< endl;
	cout << "   Duration : " << duration << " months" << endl;
}