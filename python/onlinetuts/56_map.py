store = [
    ("shirt", 20.00),
    ("pants", 25.00),
    ("jacket", 50.50),
    ("socks", 10.00)
]

# lambda functions can also change data like the following
to_krw = lambda data: (data[0], data[1] * 867)

store_krw = list(map(to_krw, store))
for i in store_krw:
    print(i)