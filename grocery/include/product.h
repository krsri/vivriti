#ifndef PRODUCTS_H_
#define PRODUCTS_H_

#include <string>
#include <iostream>

using namespace std;

class product  {
private:
	string productID, productName, brand, category, subcategory;
	float price, qty, discount, finalPrice;
public:

	product(){
		discount = 0;
		finalPrice = 0;
		price = 0;
	}
 	float getFinalPrice()const {
		return finalPrice;
	}
	float getPrice() const {
		return price;
	}

	void setPrice(float price) {
		this->price = price;
	}

	const string& getProductId() const {
		return productID;
	}

	void setProductId(const string& productId) {
		productID = productId;
	}

	const string& getProductName() const {
		return productName;
	}

	void setProductName(const string& productName) {
		this->productName = productName;
	}

	float getQty() const {
		return qty;
	}

	void setQty(float qty) {
		this->qty = qty;
	}

	const string& getBrand() const {
		return brand;
	}

	void setBrand(const string& brand) {
		this->brand = brand;
	}

	void setCategory(const string& category) {
		this->category = category;
	}

	const string& getSubcategory() const {
		return subcategory;
	}

	void setSubcategory(const string& subcategory) {
		this->subcategory = subcategory;
	}

	void setDiscount(float discount) {
		this->discount = discount;
	}

	void setFinalPrice(float finalPrice) {
			this->finalPrice = finalPrice;
		}


	//If same product added twice in the cart this will add new addtional qty with old. to avoid repeted entry.
	product operator +(product const &obj) {

		product res = *this;
		res.price = this->price +  obj.getPrice();
		res.finalPrice = this->finalPrice + obj.getFinalPrice();
		res.qty = this->qty + obj.getQty();

		return res;
	}

	void print() {
		cout << productID << "		" << productName << "		" << qty << "	" << price
				<< "	" << discount << "		" << finalPrice << endl;

	}

	void printInventory() {
		cout << productID << "\t" << productName << "\t" << qty << "\t" << price << "\n\n";
	}

};

#endif
