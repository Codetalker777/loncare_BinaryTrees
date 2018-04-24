#pragma once
#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#include <string>
#include <iostream>
using namespace std;
class EmployeeInfo
{
private:
	int id;
	string name;
public:
	//constructor
	EmployeeInfo() {
		id = -1;
	
	}
	//constructor with 2 parameters
	EmployeeInfo(int i, string n) {
		id = i;
		name = n;

	}
	//operator overloads
	bool operator <(const EmployeeInfo& input) {
		return id < input.id;
	}

	bool operator >(const EmployeeInfo& input) {
		return id > input.id;
	}

	bool operator ==(const EmployeeInfo& input) {
		return id == input.id;
	}

	friend ostream& operator <<(ostream& out, const EmployeeInfo& input) {
		string space = "      ";
		string newline = "\n";
		out << "ID: " << input.id << space << "Name: " << input.name << newline;
		return out;
	}
	//accessor and mutator methods
	string getName() {
		return name;
	}
	void setName(string n) {
		name = n;
	}
	int getID() {
		return id;
	}
	void setID(int i) {
		id = i;
	}

};
#endif
