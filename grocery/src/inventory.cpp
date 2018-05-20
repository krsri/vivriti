#include "inventory.h"

product inventoryDetails::getItem(string pid, int qty ) {

	inventoryList[pid].setQty(inventoryList[pid].getQty() - qty);
	product p = inventoryList[pid];
	p.setQty(qty);
	return p;

}

void inventoryDetails::putItem(string productID, int qty) {

	inventoryList[productID].setQty(inventoryList[productID].getQty() + qty);

}

void inventoryDetails::addToInventory(string id, product p) {
	inventoryList[id] = p;
}

void inventoryDetails::printList() {

	map<string, product> :: iterator it = inventoryList.begin();

	cout << "productID\t" <<  "productName\t" <<  	"Available qty\t" << "price\t" << "\n\n";

	for( ; it != inventoryList.end(); it++){
		it->second.printInventory();
	}
}

int inventoryDetails::checkQty(string pid, int qty) {

//	cout << "Check Qty :::  " << pid << "  ::::::::   " << inventoryList[pid].getQty();

	if( inventoryList[pid].getQty() >= qty)
		return 1;
	else{
		if(inventoryList[pid].getQty() > 0){

		cout << "Request qty not available. Available qty in the store ::  " << inventoryList[pid].getQty() <<endl;
		cout << "Please modify ur cart or proceed with next item." << endl;

		cout << "Please press 1 to contine. \n";	
		int a;
		while(a != 1)
			cin >> a;
	
		}
		return 0;
	}

}

void inventoryDetails::printCategory() {
	map<string, product> :: iterator it = inventoryList.begin();

	for (; it != inventoryList.end(); it++) {
		categoryList.insert(it->second.getSubcategory());
	}

	set<string>::iterator sit  = categoryList.begin();
	int i = 1;
	  for (; sit != categoryList.end(); sit++) {
	      cout << i++ << ". " << *sit << endl;
	  }
}


string inventoryDetails::getCategoryName(int index) {
	set<string>::iterator it = categoryList.begin();
	advance(it, index);
	return *it;
}


string inventoryDetails::getCategoryName(string pid) {
	map<string, product> :: iterator it = inventoryList.find(pid);

	if(it != inventoryList.end()){
		return it->second.getSubcategory();
	}

	return "";

}


int inventoryDetails::categoryCount() {
	return categoryList.size();
}
