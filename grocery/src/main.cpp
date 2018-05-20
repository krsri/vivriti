#include <helper.h>
#include <product.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "inventory.h"
#include "discountDetail.h"
#include "shoppingCart.h"
#include "customer.h"
#include "transactions.h"

using namespace std;

transactions trans;
inventoryDetails inventory;
discountDetail d;

map< string, customer > customerList;

//Function load stock details from the CSV file to in memory.
void loadStock() {

	Helper helper;
//	ifstream infile("C:/workspace/grocery/products.csv");
	ifstream infile("/mnt/c/workspace/vivriti/grocery/products.csv");
	string line;
	std::getline(infile, line); // Skipping header
	while (std::getline(infile, line)) {
		vector<string> productDetail;
		helper.split(line, ",", productDetail);

		product p ;
		p.setProductId(productDetail[0]);
		p.setProductName(productDetail[1]);
		p.setQty(atof(productDetail[2].c_str()));
		p.setPrice(atof(productDetail[3].c_str()));
		p.setSubcategory(productDetail[4]);
		p.setCategory(productDetail[5]);
		p.setBrand(productDetail[6]);

		inventory.addToInventory(productDetail[0] , p);

	}
}

//Fucntion to load customer details from CSV file.
void loadCustomer(){
	Helper helper;
//		ifstream infile("C:/workspace/grocery/customer.csv");
		ifstream infile("/mnt/c/workspace/vivriti/grocery/customer.csv");

		string line;
		std::getline(infile, line); // Skipping header
		while (std::getline(infile, line)) {
			vector<string> custDetail;
			helper.split(line, ",", custDetail);

			customer c ;
			 c.setCustId(custDetail[0]);
			 c.setName(custDetail[1]);
			 c.setAge(atoi(custDetail[2].c_str()));
			 c.setSex(custDetail[3]);
			 c.setEmployee(custDetail[4]);
			 c.setAddress(custDetail[6]);
			 c.setContact(custDetail[7]);

			 customerList [custDetail[0]] = c;

		}
}

void admin()
{

	while (1) {
		cout << "Welcome to admin" << endl;
		cout << "1. Manage Discount." << endl;
		cout << "2. Check sales Report." << endl;
		cout << "3. view inventory." << endl;

		int choice;
		cout << "=-=-=-=-=-=-= Enter -1 to exit =-=-=-=-=-=-=" << endl;
		cin >> choice;

		if(choice == -1)
			break;

		switch (choice) {
		case 1:
			addDiscountDetails(); // Manage discount
			break;
		case 2:
			trans.viewTransaction(); // View all the transaction and total sales
			break;
		case 3:
			inventory.printList();
			break;
		default:
			cout << "Select valid option.";
		}
	}
}

void userFucntions(){

	string custID;
	int choice;


	cout << "\n\n";
	cout << "Welcome Enter your customer id." << endl;
	cin >> custID;

	customer cust = customerList[custID];


	cout << "\n\nWelcome " << cust.getName()
			<< "\n\nPlease select from the below option \n";


	while (1) {

		shoppingCart sc; // Shopping cart object for each transaction.

		//Adding custormer details for discount purpose.
		sc.setCustId(custID);
		sc.setName(cust.getName());
		sc.setEmp(cust.isEmployee());
		sc.setSeniorCitizen(cust.getAge());


		cout << "1. View store promotions." << endl;
		cout << "2. Place order." << endl;
		cout << "3. View transactions." << endl;

		cout << "========= Enter -1 to exit ============ \n\n";

		cin >> choice;

		if (choice == -1)
			break;

		switch (choice) {
		case 1:

			//Print all the store discount details.
			d.printDiscountDetails();
			break;
		case 2:

			//Perform product addition to cart
			addTocart(sc);
			sc.calculateUserDisc();// Calculate employee and senior discount in the over all bill.
			sc.printBill(); // Print bill
			trans.addTransaction(sc); // Added to transaction will be used by admin or user in future.
			break;
		case 3:
			trans.viewTransaction(custID); // Will show all previouds transaction for particular user.
			break;
		default:
			cout << "Select valid option.";
		}
	}

}

int main() {
	loadStock();
	loadCustomer();

	cout << "*********** INVENTORY ************\n\n";
	inventory.printList();

	int userSelection;

	cout << "------------- Welcome -----------" << endl;

	while (1) {

		cout << "Please select \n\n1. Admin. \n"
				<< "2. Customer\n \n-1 to exit.\n";
		cin >> userSelection;

		if (userSelection == -1)
			break;

		switch (userSelection) {
		case 1:
			admin();
			break;
		case 2:
			userFucntions();
			break;
		}

	}



}
