#！/usr/bin/env python3
from urllib.request import urlopen
import ssl
import urllib
import re
 
context = ssl._create_unverified_context()
ssl._create_default_https_context = ssl._create_unverified_context

html = urlopen("https://www.bilibili.com").read().decode('utf-8')
print(html)
print(re.search("百度",html))
