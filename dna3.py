# Implement a program that identifies a person based on their DNA, per the below.
# $ python dna.py databases/large.csv sequences/5.txt
# Lavender

import csv
from cs50 import get_string
from sys import argv


def main():

    # validate the argument count
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)


    # open the csv and read it to a dictionary
    csv_file = open(argv[1],"r")
    csv_reader = csv.reader(csv_file)

    # open the sequence and read it to a string
    sequence_txt = open(argv[2],"r")
    sequence = sequence_txt.read()

    # keep count of value data(str) from the csv file

    for row in csv_reader:
        csv_list = row
    csv_list.pop(0)

    people = {}
    for items in csv_list:
        people[items]=1

    for rows in sequence:
        str_table = row

    print(people)
    print(str_table)

    #print(str_name)
    #print(csv_list)
    csv_file.close()


main()