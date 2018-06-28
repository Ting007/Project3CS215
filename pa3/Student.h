#ifndef Student_H
#define Student_H
#include <string>
#include "Person.h"
using namespace std;

class Student:public Person{
public:
	/*
	default constructor set the level, GPA, major to empty string
	*/
	Student();
	/*
	constructor
	input: the student's name, birth year, level, GPA, major 
	calling the constructor Person(name, year)
	output: set the parameter to the datamember of the object
	*/
	Student(string new_name, int new_year, string new_level, double new_GPA, string new_major);
	/*
	accessor
	return the level of the student
	*/
	virtual string get_level();
	/*
	mutator
	set the level to the arg
	*/
	void set_level(string new_level);
	/*
	set the level of the student 
	by asking the user to input the string level
	*/
	void set_level();
	/*
	accessor
	return the GPA of the student
	*/
	double get_GPA();
	/*
	mutator
	set the GPA to the input
	*/
	void set_GPA(double new_GPA);
	/*
	set the student GPA
	by asking the user to input the GPA
	*/
	void set_GPA();
	/*
	accessor
	return the major of that student object
	*/
	string get_major();
	/*
	mutator
	set the major of the student to the input
	*/
	void set_major(string);
	/*
	set the major of the student
	by asking the user to input the major
	*/
	void set_major();
	/*
	print out the student information on the console
	*/
	virtual void display();

private:
	string level;
	double GPA;
	string major;
};

#endif