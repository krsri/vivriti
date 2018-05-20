#include "discountDetail.h"


void discountDetail::addProduct(string pid, float discount) {
	product[pid] = discount;
}

void discountDetail::addCategory(string category, float discount) {
	categoryDiscount[category] = discount;
}

float discountDetail::getDiscountPercentage(string  pid) {

	map<string, float>::iterator pit = product.find(pid);
	string catName = "";

	if (pit != product.end())
		return pit->second;

	catName = inventory.getCategoryName(pid);
	return ( strcmp(catName.c_str(), "" ) == 0 ) ? 0 : categoryDiscount[catName] ;

}

void discountDetail::printDiscountDetails() {

	map<string, float>::iterator pit = product.begin();

	cout << " ProductID / Category Name \t  Discount Percentage\n";
	cout << "===================================================================\n";

	for(; pit!=product.end() ;pit++)
		cout << pit->first << "\t\t\t" << pit->second << endl;

	map<string, float>::iterator cit = categoryDiscount.begin();
	for(; cit!=categoryDiscount.end() ;cit++)
		cout << cit->first << "\t\t\t" << cit->second << endl;


	if(empDiscountPer > 0)
		cout << "Avail Employee Discount :::\t" << empDiscountPer << "%\n";

	if(seniorDiscountPercent > 0)
		cout << "Avail senior citizen discount :::\t" << seniorDiscountPercent << "% on over all bill\n\n\n";

	cout << "===================================================================\n";


}

void discountDetail::setUserDiscount(string type, float per) {

	if(strcmp(type.c_str(), "employee") == 0)
		empDiscountPer = per;

	if(strcmp(type.c_str(), "senior") == 0)
		seniorDiscountPercent = per;

}
