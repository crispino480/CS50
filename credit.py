from cs50 import get_string


#prompt user for credit card input

while True:
    s = get_string("Number: ")
    if len(s) in [13,15,16]:
        break
    else:
        print("INVALID1")
# list every second digits in the caracteres from left to right       
c =list(s)[::-2]
# sum no 1
m = -1
# sum no 2
sm = 0
# interate over the list
for ch in c:
    # convert the char to int the sum them
    m += int(ch)*2
# print(m) 
# loop through the list for digits that weren't multipied
for cr in list(s):
    if cr not in c:
        sm +=int(cr)
# sum both sum to produce outcome for last digit
checksum= m + sm      
#print(checksum)

if checksum % 10 == 0:
    if len(s) == 15 and s[0:2] in ['34','37']:
        print("AMEX")
    elif len(s) == 16 and s[0:2] in ['51','52','53','54','55'] :
         print("MASTERCARD")
    else:      
        print("VISA")
else:
    print("INVALID2")