from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 1 <= height and height <= 8:
        break

for j in range(1, height+1):
    print(' '*(height-j)+'#'*j+' '*2 + '#'*j)

