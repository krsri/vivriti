#ifndef TRANS_H_
#define TRANS_H_

#include <shoppingCart.h>
#include <map>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

class transactions: public map<string, vector <shoppingCart> > {

	private:
		float totalSales;

	public:
		void viewTransaction();
		void viewTransaction(string userID);
		void addTransaction(shoppingCart sc);
};

#endif
