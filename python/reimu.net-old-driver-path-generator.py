import urllib
from urllib.request import urlopen
from bs4 import BeautifulSoup

str_url = str(input("Input URL: "));

if (len(str_url) == 0):
    exit();

str_headers = {'User-Agent':'Mozilla/5.0 (Windows NT 100.1; WOW64; rv:29.0) Gecko/20160101 Firefox/49.0'}

try:
    req = urllib.request.Request(url=str_url, headers=str_headers);
except urllib.error.HTTPError as e:
    print ("%s"%e);
    exit();
try:
    html = urllib.request.urlopen(req)
except urllib.error.HTTPError as e:
    print ("%s"%e);
    exit();

bsObj = BeautifulSoup(html.read(), "html.parser");

print(bsObj.pre);
