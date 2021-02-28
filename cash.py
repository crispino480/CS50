# Wiritten in Python
 # Implement a program that calculates the minimum number of coins required to give a user change.
 # Assuming that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
 # Expected outcome form the command line:
    
 #  $ ./cash
 #  Change owed: -0.41
 #  Change owed: foo
 #  Change owed: 0.41
 #               4    

from cs50 import get_float

def main():

    ipt = get_input()
    cent = int((ipt*100))
    # output coin due
    print(f"Change owed :{changeCount(cent)}")


def get_input():

    while True:
        v_input = get_float("change owed : ")
        if v_input > 0:
            break
    return v_input


def changeCount(c):
    return (c//25 + (c % 25)//10 + ((c % 25) % 10)//5 + ((c % 25) % 10) % 5 // 1)


main()
