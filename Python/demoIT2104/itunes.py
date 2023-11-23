import requests

response = requests.get("https://itunes.apple.com/search?entity=song&limit=20&term=sb19")

o = response.json()
for result in o["results"]:
    print(result["trackName"])
