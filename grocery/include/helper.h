#include <stddef.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "inventory.h"
#include "discountDetail.h"
#include "shoppingCart.h"

extern discountDetail d;
extern inventoryDetails inventory;
using namespace std;

class Helper {

public:
	void split(string & data, string pattern, vector<string> & list) {
		// Will hold non matched tokens.
		string tmp;
		// Will hold the partial matches.
		string tmpPattern;

		for (size_t i = 0, j = 0; i < data.length(); i++) {

			if (data[i] == pattern[j]) {
				tmpPattern.append(&data[i], 1);
				j++;

				if (j == pattern.length()) {
					list.push_back(tmp);

					tmp.clear();
					tmpPattern.clear();

					j = 0;
				}

			} else {

				if (tmpPattern.length() > 0) {
					tmp.append(tmpPattern);
					tmpPattern.clear();
				}

				// Checking again whether it is the start of the next match,
				// if it is, then appending to tmpPattern.
				if (j > 0 && data[i] == pattern[0]) {
					tmpPattern.append(&data[i], 1);
					j = 1;
				} else {
					tmp.append(&data[i], 1);
				}
			}
		}

		if (tmpPattern.length() > 0)
			tmp.append(tmpPattern);

		if (tmp.length() > 0)
			list.push_back(tmp);
	}
};

void addDiscountDetails() {

	int  choice;
	int category;
	float percentage;
	string categoryName, pid;
	system("clear");

	while (1) {
		cout << "Please select the discount type. " << endl;
		cout << "1. Discount for particular product." << endl;
		cout << "2. Discount for the product category." << endl;
		cout << "3. Enable Employee Discount." << endl;
		cout << "4. Enable Senior citizen discount." << endl;
		cout << "Enter -1 to exit" << endl;

		cin >> choice;

		if (choice == -1)
			break;

		switch (choice) {
		case 1:
			cout << "Enter product id." << endl;
			cin >> pid;

			cout << "Enter percentage." << endl;
			cin >> percentage;

			d.addProduct(pid, percentage);
			d.printDiscountDetails();

			break;
		case 2:
			inventory.printCategory();

			cout << "Enter category name " << endl;
			cin >> category;
			if (category > (inventory.categoryCount() + 1)) {
				cout << "Kindly select from the above category list." << endl;
				cin >> category;
			}
			cout << "Enter percentage." << endl;
			cin >> percentage;

			categoryName = inventory.getCategoryName(category - 1);

			d.addCategory(categoryName, percentage);
			d.printDiscountDetails();
			break;

		case 3:
			cout << "Enter percentage for employee discount." << endl;
			cin >> percentage;

			d.setUserDiscount("employee", percentage);
			break;

		case 4:
			cout << "Enter percentage for senior citizen discount." << endl;
			cin >> percentage;

			d.setUserDiscount("senior", percentage);
		}

	}
}


void addTocart(shoppingCart &sc) {

	string pid;
	int qty;

	inventory.printList();
	while (1) {

		cout << "\nEnter product ID to purchase. -1 to generate bill." << endl;
		cin >> pid;

		if (strcmp(pid.c_str(), "-1") == 0)
			break;

		cout << "Enter Quantity" << endl;
		cin >> qty;

		if (qty == -1)
			break;

		sc.addToCart(pid, qty);
		
		cout << "\n\n\n ============ITEMS IN THE CART==============\n";
		sc.printCart();

		inventory.printList();
	}


}
