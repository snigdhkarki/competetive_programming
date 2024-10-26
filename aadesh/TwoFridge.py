n = int(input())

minA = -100
maxA = 100

cannotBeFound = False

minB = -100
maxB = 100

intervals = []

for i in range(n):
    a, b = map(int, input().split(" "))
    intervals.append((a, b))

try:
    def find_fridge_temperatures(N, intervals):
        intervals.sort()
        
        max_start = max(interval[0] for interval in intervals)
        min_end = min(interval[1] for interval in intervals)
        
        if max_start <= min_end:
            return max_start, max_start
        
        for T1 in range(-100, 101):
            for T2 in range(T1, 101):
                if all((T1 <= interval[1] and T1 >= interval[0]) or 
                    (T2 <= interval[1] and T2 >= interval[0]) 
                    for interval in intervals):
                    return T1, T2
        
        return -1
    
    result = find_fridge_temperatures(N, intervals)

    if result == -1:
        print(-1)
    else:
        print(f"{result[0]} {result[1]}")
except:
    for i in range(n):
        if (cannotBeFound):
            break

        a, b = intervals[i]

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

