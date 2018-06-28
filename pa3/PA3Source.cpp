/*
name: Ting Wang
purpose:Design and implement a program to manage and display a list of persons
precondition:  asking the user for the name of a person list file.  
               provide the user with a list of possible actions, 
               then read a key to select the action. 
postcondition:  view a [P]erson, [E]mployee or [S]tudent list,
[F]ind a person, [A]dd a new person, [R]emove a person,
sa[V]e the list, save as a [N]ew file, or [Q]uit.
*/

#include <fstream>
#include <iostream>
#include <cctype>
#include "PersonList.h"
#include "Person.h"
using namespace std;

/*
asking the user to enter the name of the file
*/
void input_filename(string &filename){
	cout << "Please enter the name of the person list file.\n";
	cout << "(press ENTER for an empty list): ";
	getline(cin, filename);
	if (filename == "\n"){
		filename = "";
	}
}
/*
read the file name from the functoin input_filename()
if the filename is empty
return an empty persone list
if the filename doesn't exist
ask the user to enter an valid file name
if the filename is correct
open the corresponding file and read the file line by line 
return a person list from the file
*/
PersonList open_file(PersonList &list, fstream &in_file){
	//open the file first
	do{
		string file_name;
		input_filename(file_name);
		if (file_name.empty()){
			cout << "New person list is created. \n";
			return list;
		}
		else{
			//creat an ifstream in_file and open the file
			in_file.open(file_name);
			if (in_file.fail())
				cout << "Can't open the file or the file doesn't exist.\n";
			else{
				//read the file line by line
				string line;
				while (getline(in_file, line)){
					cout << line << endl;
					list.parsePerson(line, list);
				}
				return list;
			}
		}
	} while (in_file.fail());
}

/*
show the user the menu and ask them to input the corresponding program
*/
char menu(){
	char opt;
	cout << "You may view a [P]erson, [E]mployee or [S]tudent list, [F]ind a person, [A]dd a new person, [R]emove a person, sa[V]e the list, save as a[N]ew file, or[Q]uit.\n";
	cout << "Please enter a command: \n";
	cin >> opt;
	if (isalpha(opt)){
		opt = toupper(opt);
		if (opt == 'P' ||opt == 'E' || opt == 'S' || opt == 'F' || opt == 'A' || opt == 'R' || opt == 'V' || opt =='Q'||opt =='N'){
			cin.clear();
			cin.ignore(100, '\n');
			return opt;
		}
		else{
			cout << "Program doesn't valid;\n";
			cin.clear();
			cin.ignore(100, '\n');
			menu();
		}
	}
	else{
		cout << "Please enter a letter.\n";
		cin.clear();
		cin.ignore(100, '\n');
		menu();
	}
	
}


int main(){
	PersonList list;//creat a empty list of person
	ofstream file_out;//the file was used to save the list in function save_list()
	fstream file;//the file was used to open the input file in open_file();
	open_file(list, file);
	char choice = ' ';
	while (choice != 'Q'){
		choice = menu();
		switch (choice){
		case('P') : list.display(); break;
		case('S') : list.display_student(); break;
		case('E') : list.display_employee(); break;
		case('F') : list.find_person(); break;
		case('A') : list.add_person(); break;
		case('R') : list.remove_person(); break;
		case('V') : cout << "Saved personlist.txt \n"; file_out.open("personlist.txt"); list.save_list(file_out); break;
		case('N') : list.save_new(); break;
		}
	}

	system("pause");
	return 0;
}