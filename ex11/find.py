import requests
import json

def fuck(name):
    url = f"https://pokeapi.co/api/v2/pokemon/{name}/"
    r = requests.get(url)
    return json.loads(r.text)

sex = input('Enter the name of a Pokemon: ').lower()

print('Name:', sex.capitalize())
print(f'Abilities:')

for dick in fuck(sex)['abilities']:
    seokyeol = dick['ability']['name'].capitalize()
    print(f'- {seokyeol}')

