# TODO
from cs50 import SQL
import csv
from sys import argv

#checking for correct command line arguement
if len(argv) != 2:
    #checking for correct house name
    if argv[1] != "Slytherin" or argv[1] != "Ravenclaw" or  argv[1] !="Hufflepuff" or argv[1] != "Gryffindor":
        print("Usage: python roster.py <housename>")


#database for file characters.csv for SQL
db = SQL("sqlite:///students.db")

result = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last ASC ", argv[1])

for row in result:
    #checking for presence of middle name
    if row["middle"] == None:         #no middle name present
        print(row["first"] + " " + row["last"] + ", born " +  str(row["birth"]))
    else:                             #middle name present
         print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " +  str(row["birth"]))
