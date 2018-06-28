#ifndef PersonList_H
#define PersonList_H
#include <vector>
#include <fstream>
#include <string>
#include "Person.h"
using namespace std;

class PersonList:public Person{
public:
	/*
	constructor to generate a empty vector of people
	*/
	PersonList();
	
	/*
	find the person in the person list
	asking the user to input the name of the person
	return the information of the person from the person list
	*/
	void find_person();
	/*
	add a new person to the person list
	create a new person
	asking the user to input the type of person first employee or student
	calling the correspoding function 
	add the new person to the vector
	*/
	void add_person();
	/*
	remove a person from the person list
	by entering the number associated with the person
	find the right record and remove the record from the person list
	*/
	void remove_person();
	/*
	display all the information for each single person in the list
	*/
	virtual void display();
	/*
	display all the information for each student in the list
	*/
	void display_student();
	/*
	display all the information for each employee in the list
	*/
	void display_employee();
	/*
	convert the line from the file 
	into to information to each type of person
	*/
	void parsePerson(string line, PersonList);
	/*
	save the list into the file
	*/
	void save_list(ofstream&);
	/*
	save the list into an new file
	*/
	void save_new();
private:
	vector<Person*> person_list;
};

#endif