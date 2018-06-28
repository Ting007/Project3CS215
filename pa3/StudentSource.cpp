#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(){
	Person::Person();
	level = "";
	GPA = 0.0;
	major = "";
}

Student::Student(string new_name, int new_year, string new_level, double new_GPA, string new_major){
	set_name(new_name);
	set_year_birth(new_year);
	set_type("student");
	level = new_level;
	GPA = new_GPA;
	major = new_major;
}

string Student::get_level(){
	return level;
}

void Student::set_level(string new_level){
	level = new_level;
}

void Student::set_level(){
	cin.clear();
	cin.ignore(100, '\n');
	string new_level;
	cout << "Please enter the level of the student : " << endl;
	cin >> new_level;
	if (new_level == "Freshman" || new_level == "Sophermore" || new_level == "Junior" || new_level == "Senior"){
		level = new_level;
	}
	else{
		cout << "Not a valid levle \ n";
		cin.clear();
		cin.ignore(100, '/n');
		set_level();
	}
}

double Student::get_GPA(){
	return GPA;
}

void Student::set_GPA(double new_GPA){
	GPA = new_GPA;
}

void Student::set_GPA(){
	cin.clear();
	cin.ignore(100, '\n');
	double new_GPA = 0.0;
	cout << "Please enter the GPA of this student : " << endl;
	cin >> new_GPA;
	if (new_GPA <= 4.0 && new_GPA >= 0.0){
		GPA = new_GPA;
	}
	else{
		cout << endl;
		cout << "Not a valid GPA. Out of Bound. \n";
		cin.clear();
		cin.ignore(100, '\n');
		set_GPA();
	}
}

string Student::get_major(){
	return major;
}

void Student::set_major(string new_major){
	major = new_major;
}

void Student::set_major(){
	string new_major;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Please enter the major of the student : " << endl;
	cin >> new_major;
	if (cin.fail()){
		cout << endl;
		cout << "Not a valid major. \n";
		cin.clear();
		cin.ignore(100, '\n');
		set_major();
	}
	else{
		major = new_major;
	}
}

void Student::display(){
	Person::display();
	cout << "   The student level : " << level << endl;
	cout << "   GPA : " << GPA << endl;
	cout << "   Major : " << major << endl;
}
