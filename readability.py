# This program is written in Python
# It implements a program that computes the approximate grade level needed to comprehend some text.
# This program is written in C
# The Algorythm used in the program is base on the readability test is the Coleman-Liau index
# Expected Outcome from the command line:
#    $ ./readability
#    Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
#    Grade 3

from cs50 import get_string
from cs50 import get_float


def main():

    # To get user input
    s = userInput()
    lt = round(float(lettercount(s)))
    w = round(float(wordcount(s)))
    st = round(float(sentencecount(s)))

    L = (lt*100/w)
    Si = (st*100/w)

    index = round((0.0588*L - 0.296*Si - 15.8))

    if index < 1:
        print(" Before Grade 1")

    elif index >= 16:
        print(" Grade 16+")
    else:
        print(f" Grade {index}")


# this function count the number of sentences in a text
def sentencecount(t):
    counts = 0
    for each_character in list(t):
        if each_character in ['.', '!', '?']:
            counts = counts + 1

    return counts


# this function count the number of words in a sentence
def wordcount(t):
    countw = 1
    for each_character in list(t):
        if each_character in [' ']:
            # count letters
            countw = countw + 1
    return countw


# this function count the number of letters in a sentence
def lettercount(t):
    countl = 0

    for i in range(len(t)):
        # check if the input is a letter
        if t[i].isalpha():
            # count letters
            countl = countl+1
    return countl


# function to prompt for user input, return its value
def userInput():
    ipt = get_string(" Enter your text: ")
    return ipt


main()
