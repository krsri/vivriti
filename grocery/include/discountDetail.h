#ifndef _DISCOUNT_H
#define _DISCOUNT_H

#include <string>
#include "inventory.h"

extern inventoryDetails inventory;

using namespace std;

class discountDetail {
public:


	discountDetail(){
		empDiscountPer = 0;
		seniorDiscountPercent =0;
	}

	// Add category discount details.
	 void addCategory(string, float );
	 void addProduct(string , float); // Add product level discount details.
	 float getDiscountPercentage(string pid); // Will check product and return %. else will check in category
	 void printDiscountDetails();
	 void setUserDiscount(string, float); // Set employee and senior citizen discount details.

	float getEmpDiscountPer() const {
		return empDiscountPer;
	}

	float getSeniorDiscountPercent() const {
		return seniorDiscountPercent;
	}

private:
	 map<string , float> product;
	 map<string , float> categoryDiscount;
	 float empDiscountPer, seniorDiscountPercent;

};

#endif
