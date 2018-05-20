#include "shoppingCart.h"
#include <iostream>
#include <string>

//product qty will be checked in inventory if requried quantity available.
//qty will deducted from inventory. product will be added to cart.
void shoppingCart::addToCart(string pid, int qty) {

	product p ;
	float discountValue, proVal, disPer, finPrice;

	if (inventory.checkQty(pid, qty)) {

		p = inventory.getItem(pid, qty);
		p.setDiscount(d.getDiscountPercentage(pid));

		disPer = d.getDiscountPercentage(pid);
		proVal = p.getPrice() * qty;
		discountValue = proVal * disPer / 100;
		finPrice = proVal - discountValue;
		p.setFinalPrice(finPrice);
		cartValue += finPrice;

		map<string, product> ::  iterator it =  productList.find(pid);

		if( it != productList.end()){
			//Operator overloaded if same product added twice. qty and price will added with old one.
			p = p + it->second;
			productList[pid] = p;
		}  else{
			productList[pid] = p;
		}
	}

}

void shoppingCart::removeFromCart(string pid, int qty) {

}

void shoppingCart::printCart() {

	map <string, product> :: iterator it = productList.begin();

	cout << "productID" << "	" << "productName" << "	" << "qty" << "	" << "price"
					<< "	" << "discount" << "	" << "finalPrice" << endl;

	for(; it != productList.end() ;it++){
		it->second.print();
	}


	cout << "====================================================================" << endl;
	cout << "				 Total Cart value   :::::  " << this->getCartValue() << endl;
	cout << "====================================================================" << endl;


}

void shoppingCart::printBill() {

	cout << "Name ::\t" << this->name << "\n" ;

	map <string, product> :: iterator it = productList.begin();

		cout << "productID" << "	" << "productName" << "	" << "qty" << "	" << "price"
						<< "	" << "discount" << "	" << "finalPrice" << endl;

		for(; it != productList.end() ;it++){
			it->second.print();
		}

		if (emp) {
			cout << "\t\t\t\t\tEmployee Discount  ::\t"
					<< (cartValue * d.getEmpDiscountPer()) / 100 << endl;
		}

		if (seniorCitizen) {
			cout << "\t\t\t\t\tSenior citizen Discount  ::\t"
					<< (cartValue * d.getSeniorDiscountPercent()) / 100 << endl;
		}

		cout << "====================================================================" << endl;
		cout << "				 Total Cart value       ::  " << this->getCartValue() << endl;
		cout << "====================================================================" << endl;
}

void shoppingCart::calculateUserDisc() {

	if (emp) {
		cartValue -= (cartValue * d.getEmpDiscountPer()) / 100;
	}

	if (seniorCitizen) {
		cartValue -= (cartValue * d.getSeniorDiscountPercent()) / 100;
	}
}
