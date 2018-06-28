#include "PersonList.h"
#include "Student.h"
#include "Employee.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

PersonList::PersonList(){

}

void PersonList::find_person(){
	string find_name;
	bool found = false;
	cin.clear();
	cout << "Person's name? ";
	getline(cin, find_name);
	if (cin.fail()){
		cout << endl;
		cout << "\n Not a valid name \n";
		cin.clear();
		cin.ignore(100, '\n');
	}
	else{
		for (int i = 0; i < person_list.size(); i++){
			if (person_list.at(i) ->get_name() == find_name){
				cout << i;
				person_list.at(i) -> display();
				found = true;
			}
		}
		if (found == false){
			cout << "Person not found !" << endl;
		}
	}
}

void PersonList::add_person(){
	Person* new_person =new Person;
	char person_type;
	cout << "[E]mployee, or [S]tudent? ";
	cin >> person_type;
	cout << endl;
	if (person_type == 'S'){
		Student* new_student = new Student;
		new_student->set_type("student");
		new_student->set_name();
		new_student->set_year_birth();
		new_student->set_level();
		new_student->set_GPA();
		new_student->set_major();
		new_person = new_student;
		person_list.push_back(new_person);
		
	}
	else if (person_type == 'E'){
		Employee* new_employee = new Employee;
		new_employee->set_type("employee");
		new_employee->set_name();
		new_employee->set_year_birth();
		new_employee->set_salary();
		new_employee->set_duration();
		new_person = new_employee;
		person_list.push_back(new_person);
	}
	else{
		cout << "Unkown command: " << person_type << endl;
		cout << endl;
		cin.clear();
		cin.ignore(100, '\n');
		add_person();
	}
}

void PersonList::remove_person(){
	int index;
	cout << "Please enter the number associated with the person : ";
	cin >> index;
	if (cin.fail()){
		cout << "\n Not a valid number\n";
		cin.clear();
		cin.ignore(100, '\n');
		remove_person();
	}
	else if (index >= person_list.size()){
		cout << "Error: Person number out of bound" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		remove_person();
	}
	else{
		person_list.erase(person_list.begin() + index);
	}
}

void PersonList::display(){
	cout << "Person list: \n";
	for (int i = 0; i < person_list.size(); i++){
		cout << i;
		person_list.at(i)->display();
		cout << endl;
	}
}
void PersonList::display_student(){
	cout << "Student list: \n";
	for (int i = 0; i < person_list.size(); i++){
		if (person_list.at(i)->get_type() == "student"){
			cout << i;
			person_list.at(i)->display();
			cout << endl;
		}
	}
}

void PersonList::display_employee(){
	cout << "Employee list: \n";
	for (int i = 0; i < person_list.size(); i++){
		if (person_list.at(i)->get_type() == "employee"){
			cout << i;
			person_list.at(i)->display();
			cout << endl;
		}
	}
}

vector<string> splitString(string input)
{
	vector<string> pieces;

	// Start of the current field
	int field_start = 0;

	// Location of the next at sign.
	int next_at;
	do {
		// Find the #.  Returns the index, or string::npos if it wasn't
		// found.
		next_at = input.find('#', field_start);

		// If it wasn't found, add the last piece.
		if (next_at == string::npos)
			pieces.push_back(input.substr(field_start));
		// Or it was found, so add this piece
		else
			pieces.push_back(input.substr(field_start, next_at - field_start));

		// The next field starts just after the # 
		field_start = next_at + 1;

		// If there was no #, we're done.
	} while (next_at != string::npos);

	return pieces;
}

int stringToInt(string str)
{
	int num;
	istringstream instr(str);
	instr >> num;
	if (instr.fail())
		throw runtime_error("invalid number " + str);

	// Check for junk after the number.
	string remaining = "junk";
	getline(instr, remaining);

	// End of file or an empty string means there was no junk.
	if (instr.eof() || remaining == "")
		return num;
	else
		throw runtime_error("garbage after number " + str);
}

// Convert a numeric string to a double.  Throws an exception if it is
// not a number.
double stringToDouble(string str)
{
	double num;
	istringstream instr(str);
	instr >> num;
	if (instr.fail())
		throw runtime_error("invalid number " + str);

	// Check for junk after the number.
	string remaining = "junk";
	getline(instr, remaining);

	// End of file or an empty string means there was no junk.
	if (instr.eof() || remaining == "")
		return num;
	else
		throw runtime_error("garbage after number " + str);
}


void PersonList::parsePerson(string line, PersonList Person_list)
{
	Person* new_person;
	vector<string> columns = splitString(line);
	if (columns.size() < 3)
		throw runtime_error("not enough columns in: " + line);

	// Columns 1-3: type, name, and year
	string type = columns[0];
	string name = columns[1];
	int year = stringToInt(columns[2]);
	if (year < 1900 || year > 2014)
		throw runtime_error("year out of range");

	if (type == "student") {
		if (columns.size() < 6)
			throw runtime_error("not enough columns in: " + line);
		string level = columns[3];
		double gpa = stringToDouble(columns[4]);
		string major = columns[5];
		if (gpa < 0.0 || gpa > 4.0)
			throw runtime_error("GPA out of range");

		// Adjust this to match your class name and parameters.
		new_person = new Student(name, year, level, gpa, major);
		person_list.push_back(new_person);
	}

	// TODO: add case for "employee"
	if (type == "employee"){
		if (columns.size() < 5)
			throw runtime_error("not enough column in: " + line);
		string salary = columns[3];
		int duration = stringToInt(columns[4]);
		if (duration < 0)
			throw runtime_error("Duration out of range");
		new_person = new Employee(name, year, salary, duration);
		person_list.push_back(new_person);
	}

	// If we got here, we didn't handle the person type.
	//throw runtime_error("unknown person type " + type);
}

void PersonList::save_list(ofstream& file){
	for (int i = 0; i < person_list.size(); i++){
		string type = person_list.at(i)->get_type();
		string name = person_list.at(i)->get_name();
		int year = person_list.at(i)->get_year_birth();
		if (type == "student"){
			string level = person_list.at(i)->get_level();
			double GPA = person_list.at(i)->get_GPA();
			string major = person_list.at(i)->get_major();
			file << type << "#" << name << "#" << year << "#" << level << "#" << GPA << "#" << major << endl;
		}
		else if (type == "employee"){
			string salary = person_list.at(i)->get_salary();
			int duration = person_list.at(i)->get_duration();
			file << type << "#" << name << "#" << year << "#" << salary<< "#" << duration << endl;
		}
		
	}

}

void PersonList::save_new(){
	ofstream out_file;
	string filename;
	cout << "Please enter a filename: ";
	cin >> filename;
	out_file.open(filename);
	save_list(out_file);
	cout << "Saved " <<filename << endl;
	cin.ignore(100, '\n');
}