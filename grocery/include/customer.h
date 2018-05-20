#ifndef CUST_H
#define CUST_H


#include <string>
#include <iostream>
#include <cstring>


using namespace std;

class customer  {

private:
	string custID, name, address, sex,contact;
	int age;
	bool employee;
	public:
	void setAddress(const string& address) {
		this->address = address;
	}

	int getAge() const {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setContact(const string& contact) {
		this->contact = contact;
	}

	const string& getCustId() const {
		return custID;
	}

	void setCustId(const string& custId) {
		custID = custId;
	}

	bool isEmployee() const {
		return employee;
	}

	void setEmployee(string employee) {

		if (strcmp(employee.c_str(), "yes") == 0)
			this->employee = true;
		else
			this->employee = false;

	}

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}

	void setSex(const string& sex) {
		this->sex = sex;
	}
};
#endif
