import urllib.request,urllib.parse,urllib.error
import xml.etree.ElementTree as ET
sum=0
url = "http://py4e-data.dr-chuck.net/comments_570227.xml"
xml = urllib.request.urlopen(url).read()
tree = ET.fromstring(xml)
counts =  tree.findall('.//count')
for count in counts:
    sum += int(count.text)
print("Sum:" + str(sum))