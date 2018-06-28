#ifndef Person_H
#define Person_H
#include <string>
using namespace std;

class Person{
public:
	/*
	default constructor set the name and year of birth to empty string;
	*/
	Person();
	/*
	constructor to set the name and year of birth to the argument
	*/
	Person(string, int, string);
	/*
	accseeor 
	return the name of the person
	*/
	string get_name();
	/*
	mutator
	input: the name of the person
	set the input to the name of the person
	*/
	void set_name(string);
	/*
	set the name of the person
	by asking the user to input the name
	*/
	void set_name();
	/*
	accessor
	return the year of birth for the object
	*/
	int get_year_birth();
	/*
	mutator
	input: the year of birth for that object person
	set input as the year of birth for the person
	*/
	void set_year_birth(int);
	/*
	set the year of birth
	by asking the user to input the year
	*/
	void set_year_birth();
	/*
	return the type of the person student or employee
	*/
	string get_type();
	/*
	set the type of the person
	by user input
	*/
	void set_type();
	/*
	set type of the person by pass parameter
	*/
	void set_type(string);
	/*
	print out the name and year of birth for the specific person
	*/
	virtual void display();
	/*
	return the level of the student
	*/
	virtual string get_level();
	/*
	return the GPA of the student
	*/
	virtual double get_GPA();
	/*
	return the major of the person
	*/
	virtual string get_major();
	/*
	return the duration of a employee
	overridden in the subclass employee
	*/
	virtual int get_duration();
	/*
	return the salary of the employee
	overriden in the subclass employee
	*/
	virtual string get_salary();

private:
	string name;
	int year_birth;
	string type;
};
#endif