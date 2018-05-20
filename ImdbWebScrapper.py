import sys
from requests import get
from bs4 import BeautifulSoup


#python ImdbWebScrapper.py movieName
#

movie_name = sys.argv[1];

baseUrl = "https://www.imdb.com"
search = "/find?q="
urlAttr = "&s=tt&ref_=fn_tt_pop"

url = baseUrl+ search + movie_name + urlAttr;

print url

response = get(url)
html_soup = BeautifulSoup(response.text, 'html.parser')
type(html_soup)

movieWithURL = {};
movieList = {};
movie_containers = html_soup.find_all('td', class_ = 'result_text')

i=0
for td in movie_containers:
		movieName = td.text #Get movie name
		movieLink = td.find('a').attrs['href'] #Get movie Url
		i=i+1
		movieList[i]=movieName
		movieWithURL[movieName] = movieLink;
		
i=0
while (i < 20 and i < len(movieList)):    
	i=i+1
	print str(i)+". " + movieList[i]
	
	
print "Please select any number from above results"
choice = int(input())

movieName= movieList[choice]
url = baseUrl + movieWithURL[movieName]
 
response = get(url)
html_soup = BeautifulSoup(response.text, 'html.parser')
type(html_soup)

rating = html_soup.find_all('div', class_ = 'ratingValue')

score = ""
for score in rating:
	print "Rating of " + movieName + " is " + score.find('strong').attrs['title']

  
