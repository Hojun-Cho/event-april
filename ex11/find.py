import json
import typing
import urllib.error
import urllib.parse
import urllib.request
from urllib.parse import urlencode
from urllib.request import Request, urlopen

def invoke(name):
    url = "https://pokeapi.co/api/v2/ability/"+str(name) +"/"
    request = urllib.request.Request(url)

    request.add_header('User-Agent',"chojasdf")

    data = urllib.request.urlopen(request).read()
    return data

result1 = invoke(input())
print(result1)
