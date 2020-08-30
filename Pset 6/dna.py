import csv
from sys import argv

#checking correct length of command line arguement
if len(argv) != 3:
    print(" Usage: python dna.py data.csv sequence.txt")
    exit(1)

#receiving input from command line arguement argv[1]: csv file argv[2]: sequences
#opening csv file
# opening file to read into memory
with open(argv[1], "r") as csvfile:
    reader = csv.reader(csvfile)
    # creating empty dict
    largedata = []
    for row in reader:
        largedata.append(row)

#opening sequences to read into memory
with open(argv[2], "r") as file:
    sqfile = file.readlines()

#converting file to string
s = str(sqfile)

#DNA STR Group database
dna_database_large = {"AGATC": 0,
                "TTTTTTCT": 0,
                "AATG": 0,
                "TCTAG": 0,
                "GATA": 0,
                "TATC": 0,
                "GAAA": 0,
                "TCTG": 0 }
    
dna_database_small = {"AGATC": 0,
                 "AATG": 0,
                 "TATC":0 }

#computing longest runs of STR repeats for each STR
if argv[1] == "databases/small.csv":
    dna_database = dna_database_small
elif argv[1] == "databases/large.csv":
    dna_database = dna_database_large

for keys in dna_database:
    longest_run = 0
    current_run = 0
    size = len(keys)
    n = 0
    while n < len(s):
        if s[n : n + size] == keys:
            current_run += 1
            if n + size < len(s):
                n = n + size
            continue
        else: #when there is no more STR matches
            if current_run > longest_run:
                longest_run = current_run
                current_run = 0
            else: #current run is smaller than longest run
                current_run = 0
        n += 1
    dna_database[keys] = longest_run

#creating new dna_list for comparison
dna_list = []
for entry in dna_database:
    dna_list.append(dna_database.get(entry))

#creating new database list for comparison
del largedata[0:1] #removing names, and nucleotide titles

#removing names as making it as a seperate list
name_list = []
for row in largedata:
    name_list.append([row[0]])

for row in largedata:
    del row[0]

#converting str values to int

# data_list, name_list and dna_list to work on
i = 0
positive = True
while i < len(largedata):
    if data_list[i] == dna_list:
        positive = True
        break
    elif data_list[i] != dna_list:
        i += 1
        positive = False

if positive == True:
    print("".join(name_list[i]))

if positive == False:
    print("No match")
