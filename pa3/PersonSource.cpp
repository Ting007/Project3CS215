#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(){
	name = "";
	year_birth = 0;
	type = "";
}
Person::Person(string Pname, int Pyear_birth, string Ptype){
	name = Pname;
	year_birth = Pyear_birth;
	type = Ptype;
}

string Person::get_name(){
	return name;
}

void Person::set_name(string new_name){
	name = new_name;
}

void Person::set_name(){
	string new_name;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Please enter the name: \n" ;
	getline(cin,new_name);
	if (cin.fail()){
		cout << endl;
		cout << "Input is not a valid name. \n";
		cin.clear();
		cin.ignore(100, '\n');
		set_name();
	}
	else{
		name = new_name;
	}
}

int Person::get_year_birth(){
	return year_birth;
}

void Person::set_year_birth(int new_year){
	year_birth = new_year;
}

void Person::set_year_birth(){
	int new_year;
	cin.clear();
	cout << "Please enter the year of birth : " << endl;
	cin >> new_year;
	if (new_year >= 1900 && new_year <= 2014){
		year_birth = new_year;
	}
	else{
		cout << endl;
		cout << "The year of birth is not valid. \n";
		cout << "The year of birth is out of bound. \n";
		cin.clear();
		cin.ignore(100, '\n');
		set_year_birth();
	}
}

string Person::get_type(){
	return type;
}

void Person::set_type(){
	char new_type;
	bool flag = false;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "[E]mployee, or [S]tudent? ";
	cin >> new_type;
	if (new_type == 'S') {
		type = "student";
		flag = true;
	}
	else if (new_type == 'E') { 
		flag = true;
		type = "employee"; }
	else{
		cout << "Error: type doesn't match." << endl;
		cout << "Please enter E for employee, S for student \n";
		set_type();
	}
}

void Person::set_type(string new_type){
	type = new_type;
}

void Person::display(){
	cout << ". "<<name << " :" << endl;
	cout << "   Year of birth : " << year_birth << endl;
}

string Person::get_level(){
	return "";
}

double Person::get_GPA(){
	return 0.00;
}

string Person::get_major(){
	return "";
}

int Person::get_duration(){
	return 0;
}

string Person::get_salary(){
	return "";
}