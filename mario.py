
#Write, in a file called mario.py in ~/pset6/mario/less/, 
#a program that recreates the half-pyramid using hashes (#) for blocks


from cs50 import get_int

height = get_int("Height: ")

while height < 1 or height > 8:

    height = get_int("Height: ")
    
for i in range(height) :

    for j in range(height+1) :
        if j >= height-i :
            print("#",end="")
        else:
             print(" ",end="")
    print()
   

