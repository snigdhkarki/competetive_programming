n = int(input())

minA = float("-inf")
maxA = float("inf")

cannotBeFound = False

minB = float("-inf")
maxB = float("inf")

for i in range(n):
    if (cannotBeFound):
        break

    a, b = map(int, input().split(" "))

    checkB = False

    if (a >= minA and a <= maxA):
        minA = a
    elif (a > maxA):
        checkB = True


    if (b <= maxA and b >= minA):
        maxA = b
    elif (b < minA):
        checkB = True

    if (checkB):
        if (a >= minB and a <= maxB):
            minB = a
        elif (a > maxB):
            cannotBeFound = True


        if (b <= maxB and b >= minB):
            maxB = b
        elif (b < minB):
            cannotBeFound = True

if (cannotBeFound):
    print(-1)
else:
    T1 = min(minA, minB)
    T2 = max(minA, minB)

    print(T1, T2)