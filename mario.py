# Written in Python, in a file called mario.py in ~/pset6/mario/more/,
# a program that recreates these half-pyramids using hashes (#) for blocks
#  Expected output from the command line:
#  $ ./mario
#   Height: 4
#    #  #
#   ##  ##
#  ###  ###
# ####  ####

from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 1 <= height and height <= 8:
        break

for i in range(1, height+1):
    # print space and charater # from left to right
    for j in range(1, height+1):
        if j > height - i:

            print("#", end="")
        else:
            print(" ", end="")

    print("  ", end="")
    # print the right part of the pyramid after the double space
    for k in range(1, height+1):
        if i < k:
            print("", end="")
        else:
            print("#",  end="")
    print()
