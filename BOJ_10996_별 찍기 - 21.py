def first(c):
    if c % 2 == 1:
        c += 1
    c = c // 2 - 1
    
    line = "*"
    for i in range(0, c):
        line += " *"
    print(line)

def seconde(c):
    if c % 2 == 1:
        c -= 1
    c = c // 2 - 1

    line = " *"
    for i in range(0, c):
        line += " *"
    print(line)

c = int(input())
if c == 1 :
    print("*")

else:
    for i in range(0, c):
        first(c)
        seconde(c)