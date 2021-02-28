# This program is Written in C
# The designed program prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, 
# MasterCard, or Visa card number, per the definitions of each’s format herein. 
# The program then output program’s last line of output  AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
# Expected output fromt the command line: 
#      $ ./credit
#      Number:  4003600000000014
#      VISA


from cs50 import get_string


#prompt user for credit card input

while True:
    s = get_string("Number: ")
    if len(s) in [10,13,15,16]:
        break
    else:
        print("INVALID")
        
# reverse the user entry and list every digit
cc =list(s)[::-1]
# remove the very first digit from the list
cc.remove(cc[0])
# list every second digits in the caracteres from left to right
c = cc[::2]
# sum list c, *2
m = 0
# sum list c
m2 = 0
# sum list(s)
total = 0
# sum no 2
sm = 0
ct = 0
# sum digits higher that 10
ns = 0

# interate over the list
for cf in c:
    # sum each character in c
    m2 +=int(cf)


for ch in c:

    # append c with product digits
    ct = int(ch)*2
    if ct < 10:
        # represent the sum of each character after multiply by 2.
        m += ct
    if ct >=10:
        # print(f"is: {ct}")
        ns += int(str(ct)[0])+int(str(ct)[1])
m+=ns



# loop through the list for digits that weren't multipied
for cr in list(s):
    total += int(cr)
sm = total - m2
# sum both sum to produce outcome for last digit
checksum= m + sm
print(checksum)



if checksum % 10 == 0:
    if len(s) == 15 and s[0:2] in ['34','37']:
        print("AMEX")
    elif len(s) == 16 and s[0:2] in ['51','52','53','54','55'] :
         print("MASTERCARD")
    else:
        print("VISA")
else:
    print("INVALID")
