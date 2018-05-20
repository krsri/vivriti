#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "product.h"
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <cstring>

using namespace std;

class inventoryDetails  {

public:
	void addToInventory(string id, product p);
	void printList();
	int checkQty(string pid, int qty);
	product getItem(string productID, int qty );
	void putItem(string productID, int qty);
	void printCategory();
	string getCategoryName( int );
	string getCategoryName(string pid);

	int categoryCount();
	friend class shoppingCart;

private:
	set<string> categoryList;
	map<string, product> inventoryList;

};

#endif
