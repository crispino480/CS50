# a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula

from cs50 import get_string
from cs50 import get_float

def main():

    # To get user input
    s = userInput()
    print(f"{s}")
    lt = float(lettercount(s))
    print(f"{lt}")
    w = float(wordcount(s))
    print(f"{w}")
    st = float(sentencecount(s))
    print(f"{st}")

    L = (lt*100/w)
    print(f"{L}")

    Si = (st*100/w)
    print(f"{Si}")
    index = int((0.0588*L - 0.296*Si - 15.8))
    print(f"{index}")
    if index < 1 :
        print(" Before Grade 1")

    elif index >= 16:
        print(" Grade 16+")
    else :
        print(f" Grade {index}")




# this function count the number of sentences in a text
def sentencecount(t):
    counts=1
    i=0
    for i in range(len(t)):
        if t[i] in ['.','!','?']:
            counts +=counts
    return counts-1


# this function count the number of words in a sentence
def wordcount(t):
    countw=1
    i=0
    for i in range(len(t)):
        if t[i] in [' ']:
            # count letters
            countw += countw
    return  countw



# this function count the number of letters in a sentence
def lettercount(t):
    countl=1
    i=0
    for i in range(len(t)):
        # check if the input is a letter
        if t[i].isalpha():
            # count letters
            countl+= countl
    return countl-1



# function to prompt for user input, return its value
def userInput():
    ipt = get_string (" Enter your text: ")
    return ipt



main()