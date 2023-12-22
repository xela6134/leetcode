# filtering

friends = [
    ("Valorant", 19),
    ("Koala", 22),
    ("Plane", 20),
    ("Hitler", 30),
    ("Nonchopsticks Asian", 21),
    ("Big Turkish Dude", 20),
    ("Anime Addict", 18),
    ("The postgrad", 26),
    ("Gigachad", 21)
]

agefilter = lambda data: data[1] >= 21
agesort = lambda data: data[1]
older = list(filter(agefilter, friends))
older = sorted(older, key=agesort)

for i in older:
    print(i)