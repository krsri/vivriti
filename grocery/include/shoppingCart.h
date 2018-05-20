#ifndef SHOPINCART_H
#define SHOPINCART_H

#include <vector>
#include <map>
#include <cstring>

#include "product.h"
#include "inventory.h"
#include "discountDetail.h"
#include "customer.h"

extern inventoryDetails inventory;
extern discountDetail d;
extern map< string, customer > customerList;

using namespace std;

class shoppingCart
{
private:

	string custID, name;
	bool emp, seniorCitizen;
	float cartValue;

	map<string, product> productList;

public:

	shoppingCart() {
		cartValue = 0;
	}

	void addToCart(string pid,int qty);
	void removeFromCart(string pid, int qty);

	void printCart();
	void printBill();
	void calculateUserDisc();

	float getCartValue() const {
		return cartValue;
	}

	void setCustId(const string& custId) {
		custID = custId;
	}

	const string& getCustId() const {
		return custID;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}

	bool isEmp() const {
		return emp;
	}

	void setEmp(bool emp) {
		this->emp = emp;
	}

	bool isSeniorCitizen() const {
		return seniorCitizen;
	}

	void setSeniorCitizen(int age) {
		if (age >= 60)
			this->seniorCitizen = true;
		else
			this->seniorCitizen = false;

	}

	void setCartValue(float cartValue) {
		this->cartValue += cartValue;
	}
};


#endif
