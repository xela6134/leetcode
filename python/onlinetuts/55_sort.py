# sort() method = used with lists
# sort() function = used with iterables

students = ["Spongebob", "Squidward", "Mr. Krabs", "Sandy", "Patrick"]
students.sort(reverse=True)

for i in students:
    print(i)
print()

newstudents = ("Neville", "Draco", "Hermione", "Harry", "Ron")
sorted_newstudents = sorted(newstudents)    # tuples cannot be modified

for i in sorted_newstudents:
    print(i)
print()

grades = [
    ("Minji", "DN", 77),
    ("Hanni", "HD", 92),
    ("Danielle", "CR", 74),
    ("Haerin", "CR", 71),
    ("Hyein", "DN", 81)
]
grade = lambda grades: grades[2]
grades.sort(key=grade, reverse=True)

for i in grades:
    print(i)