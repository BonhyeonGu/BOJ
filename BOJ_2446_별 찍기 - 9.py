n = int(input())

space = ""
for i in range(n, 0, -1):
    line = ""
    for j in range(0, i * 2 - 1):
        line += "*"
    print(space + line)
    space += " "

space = space[:-1]
for i in range(2, n + 1):
    line = ""
    for j in range(0, i * 2 - 1):
        line += "*"
    space = space[:-1]
    print(space + line)