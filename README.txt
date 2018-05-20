# vivriti

Self Checkout billing system.
-----------------------------

Program contains two mode Admin and customer.

Admin can manage store discounts, 
check sales report and inventory details.

Admin can give discout based on product level using product id, based on category level. and also set employee, senior citizen discounts.

*product level discounts will get more priority.
Eg: if whole chips category can avail 40%, incase admin give 50% for 101 (lays)  . Then lays alone will be given 50% discount.

Custormer can check store promotion, can place order, view previous transactions.



PS:
Inventory and customer details are stored in the CSV file.
Please enter user from CSV file. new user not handled.
Authentication not handled.

Run :

check product and customer csv file path in main file.

make run 


IMDB scraper
------------
Requirements:
	 apt-get install python-bs4 
	 
Run:

python ImdbWebScrapper.py movieName

	
