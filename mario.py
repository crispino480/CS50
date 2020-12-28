from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 1 <= height and height <= 8:
        break

for i in range(height):
    # print space and charater # from left to right
    for j in range(height+1):
        if j >= height-i:
            print("#", end="")
        else:
            print(" ", end="")
    print()