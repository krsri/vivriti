#include "transactions.h"

void transactions::viewTransaction() {

	map<string, vector<shoppingCart> >::iterator it = this->begin();

	for (; it != this->end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			it->second.at(i).printBill();
		}
	}

	cout << "====================================================================" << endl;
	cout << "				   Total Sales   :::::  " << totalSales  ;
	cout << "====================================================================" << endl;


}

void transactions::viewTransaction(string userID) {
	map<string, vector<shoppingCart> > :: iterator it = this->find(userID);

	if(it != this->end()){
		for(int i = 0 ; i < it->second.size(); i++){
			it->second.at(i).printBill();
		}
	}else{
		cout << "No Transaction made till date. Please place new order Happy shopping. \n\n";
	}
}

void transactions::addTransaction(shoppingCart sc) {

	map<string, vector<shoppingCart> > :: iterator it = this->find(sc.getCustId());

	totalSales += sc.getCartValue();

	if( it != this->end()){
		it->second.push_back(sc);
	}else{
		vector<shoppingCart> v ;
		v.push_back(sc);
		this->insert(make_pair(sc.getCustId(),v));
 	}
}
