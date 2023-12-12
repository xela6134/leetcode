# dictionary: changeable, unordered collection of unique key:value pairs
# can be updated when program is running

capitals = {
    'USA': 'Washington DC',
    'Korea': 'Seoul',
    'Australia': 'Sydney',
    'France': 'Paris'
}

print(capitals['Korea'])        # Less safe, encounters error when nonexistent key is called
print(capitals.get('China'))    # Much safer method

print(capitals.keys())
print(capitals.values())
print(capitals.items())

for key, value in capitals.items():
    print(key, value)

print('')
capitals.update({'Germany': 'Berlin'})
capitals.update({'USA': 'New York'})
capitals.pop('Australia')
for key, value in capitals.items():
    print(key, value)
