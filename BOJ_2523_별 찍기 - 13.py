n = int(input())
for i in range(0, n):
    line = ""
    for j in range(0, i + 1):
        line += "*"
    print(line)

for i in range(n - 1, 0, -1):
    line = ""
    for j in range(0, i):
        line += "*"
    print(line)