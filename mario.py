# Write, in a file called mario.py in ~/pset6/mario/more/,
# recreate pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. 
# Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.
      #  #
     ##  ##
    ###  ###
   ####  ####

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
