#ifndef Employee_H
#define Employee_H
#include <string>
#include "Person.h"
using namespace std;

class Employee:public Person{
public:
	/*
	default constructor set the salary and duration to zero
	*/
	Employee();
	/*
	constructor by input the name, the year of birth, the salary, and the duration as parameters
	calling the constructor from person
	*/
	Employee(string, int, string, int);
	/*
	set the salary of the employee 
	by inputing it as a parameter
	*/
	void set_salary(string);
	/*
	set the salary of the employee 
	by asking the user to input.
	*/
	void set_salary();
	/*
	set the duratoin of the employee
	by input it as a parameter
	*/
	void set_duration(int);
	/*
	set the duration of the employee
	by asking the user to enter it 
	*/
	void set_duration();
	/*
	return the salary of the employee
	*/
	string get_salary();
	/*
	return the duration for that employee
	*/
	int get_duration();
	/*
	display all the information of that employee
	*/
	void display();

private:
	string salary;
	int duration;
};

#endif