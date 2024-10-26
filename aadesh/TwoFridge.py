n = int(input())

minA = float("-inf")
maxA = float("inf")

set = False

cannotBeFound = False

minB = float("-inf")
maxB = float("inf")

for i in range(n):
    a, b = map(int, input().split(" "))

    if (not set):
    
        if (a <= maxA and a > minA):
            minA = a
        elif (a > maxA):
            set = True
            minB = a
            maxB = b
        
        if (b >= minA and b < maxA):
            maxA = b
        elif (b < minA):
            set = True
            minB = a
            maxB = b

    elif (not cannotBeFound):
        if (a <= maxA and a > minA):
            minA = a
        elif (a > maxA):
            cannotBeFound = True
        
        if (b >= minA and b < maxA):
            maxA = b
        elif (b < minA):
            cannotBeFound = True


if (cannotBeFound):
    print(-1)
else:
    T1 = min(minA, minB)
    T2 = max(minA, minB)

    print(T1, T2)
