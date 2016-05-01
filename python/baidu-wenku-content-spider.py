# encoding: utf-8
import urllib
import sys
from codecs import decode
from codecs import encode
from urllib.request import urlopen
from bs4 import BeautifulSoup

if __name__ == '__main__':
    str_url = str(sys.argv[1])
    nPage = int(sys.argv[2])

    page = 1
    complexUrl = str("%s%d%s"%(str_url+"?pn=",page,"&pu=usm@0,sz@224_220,ta@iphone___3_537"))
    str_headers = {'User-Agent':'Mozilla/5.0 (Windows NT 100.1; WOW64; rv:29.0) Gecko/20160101 Firefox/49.0'}
    while(1):
        req = urllib.request.Request(url=complexUrl, headers=str_headers);

        try:
            html = urllib.request.urlopen(req)
        except urllib.error.HTTPError as e:
            print ("%s"%e);
            exit();

        utfHtml = html.read().decode("utf-8","ignore")
        gbkHtml = utfHtml.encode("gbk","ignore")
        bsObj = BeautifulSoup(gbkHtml, "html.parser",from_encoding="gbk");

        mainBsObj = bsObj.find("div",{"class":"content bgcolor1"})
        textList = mainBsObj.findAll("p",{"class":"txt"})
        for strTxt in textList:
            print("%s"%strTxt.get_text())
        if page >= nPage:
            break
        else:
            page = page + 1
        complexUrl = str("%s%d%s"%(str_url+"?pn=",page,"&pu=usm@0,sz@224_220,ta@iphone___3_537"))
