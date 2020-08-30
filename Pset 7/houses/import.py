import csv
from sys import argv
from cs50 import SQL

#check for correct command line arguement
if len(argv) != 2:
    print("Usage: python <filename>.csv")
    exit()

#correct command line arguement
#database for file characters.csv for SQL
db = SQL("sqlite:///students.db")

#opening characters.csv
with open(argv[1], "r") as csvfile:
    #reading file
    reader = csv.DictReader(csvfile, delimiter = ",")
    for row in reader:
        #splitting name of student into first, middle and last
        name = row["name"].split()

        if len(name) == 3:
            db.execute("INSERT INTO students(first , middle , last, house , birth ) VALUES(?, ?, ?, ?, ?)", name[0], name[1], name[2], row["house"], row["birth"])
        elif len(name) ==2: #no middle name
            db.execute("INSERT INTO students(first , middle , last , house , birth ) VALUES(?, ?, ?, ?, ?)", name[0], None, name[1], row["house"], row["birth"])
