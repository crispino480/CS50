from cs50 import get_string

while True:
    s = get_string("Number: ")
    if len(s) in [13,15,16]:
        break
    else:
        print("INVALID")
# list every second digits in the caracteres from left to right       
c =list(s)[::-2]
del list(s)[::-2]
e =list(s)-c
print(c)
print(e)