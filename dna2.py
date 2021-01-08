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
    csv_reader = csv.DictReader(csv_file)

    # open the sequence and read it to a string
    sequence_txt = open(argv[2],"r")
    seq_reader = sequence_txt.read()

    # keep count of value data(str) from the csv file

    # reference an empty dictionary
    value_str = {}
    list_str = []

    for each_str in csv_reader.fieldnames[1:]:

        list_str = [list_str for list_str in csv_reader][1:]
        print(list_str)
    csv_file.close()


main()