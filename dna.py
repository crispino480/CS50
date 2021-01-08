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

    # open the sequence and read it to string
    sequence_txt = open(argv[2],"r")
    seq_reader = sequence_txt.read()



    # reference an empty list (list1) and dictionary (value_str)
    value_str = {}
    list1 = []
    # read in the dictionary fiednames(str name) and assign the maximum STR count
    for each_strg in csv_reader.fieldnames[1:]:
        value_str[each_strg] = max_length_string(seq_reader, each_strg)


    # compare the value of the STR max read from the sequence to
    # people STR from the CSV and print the person name if there is a match
    for row in csv_reader:
        if all(value_str[each_str] == int(row[each_str]) for each_str in value_str):
           print(row["name"])
           csv_file.close()
           return
    print("No match")
    csv_file.close()

# this function return the longest sequence of STR
def max_length_string(seq, subseq):
    length1 = 0
    # length of a subsequence
    l2 = len(subseq)
    # length of a sequence
    l1 = len(seq)
    #iterate over the sequence length
    for x in range(l1):
        # count STR when a match is found
        counter = 0
        while True:
            i = x + l2 * counter
            j = i + l2
            # check and count if the subsequence read from i to j match the STR
            if seq[i:j] == subseq:
                counter += 1
            else:

                break
        # return the maximum read
        length1 = max(length1, counter)


    return length1


main()

