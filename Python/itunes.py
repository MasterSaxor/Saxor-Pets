import requests
import sys

response = requests.get("https://itunes.apple.com/search?entity=song&limit=50&term=westlife")

o = response.json()

for result in o["results"]:
    print(result["trackName"])