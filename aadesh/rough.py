# def generateSet(low, high, length):
#     if (length == 1):
#         return list(map(lambda x: [x], range(low, high + 1)))
#     else:
#         resultUntilNow = generateSet(low, high, length - 1)

#         result = []

#         for eachResult in resultUntilNow:


#             for num in range(low, high + 1):
#                 another = eachResult.copy()
#                 another.append(num)
                    
#                 result.append(another)



#         return result
    
# print(generateSet(1, 8, 4))

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

N = int(input())
intervals = [list(map(int, input().split())) for _ in range(N)]

result = find_fridge_temperatures(N, intervals)

if result == -1:
    print(-1)
else:
    print(f"{result[0]} {result[1]}")