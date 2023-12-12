# set: unordered, unindexed collection. no duplicates allowed

utensils = {"fork", "spoon", "knife"}
dishes = {"bowl", "plate", "cup"}

# utensils.add("napkin")
# utensils.remove("fork")
# utensils.clear()

for x in utensils:
    print(x)

dishes.update(utensils)
print("")

for x in dishes:
    print(x)

dinner_table = utensils.union(dishes)
print("")

for x in dinner_table:
    print(x)
    
print("")
set1 = {"a", "b", "c", "d"}
set2 = {"c", "d", "e", "f"}
print(set1.difference(set2))
print(set1.intersection(set2))