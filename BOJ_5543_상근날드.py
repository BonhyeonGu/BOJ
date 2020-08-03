a = []
b = []
minSet = 2001
for i in range(0, 3):
    a.append(int(input()))
for i in range(0, 2):
    b.append(int(input()))
for i in range(0, 3):
    if a[i] + b[0] > a[i] + b[1]:
        c = a[i] + b[1] - 50
    else:
        c = a[i] + b[0] - 50
    if c < minSet:
        minSet = c
print(minSet)