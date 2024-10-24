testCases = int(input())

for eachCase in range(testCases):
    n, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))

    a.sort()
    
    b  = list(set(a))


    mem = {}

    for slot in a:
        if (slot not in mem):
            mem[slot] = 1
        else:
            mem[slot] += 1


    count = 0

    runs = 0

    index = 0

    while k > 0:
        if (n >= k or (n * b[index]) >= k):
            count += k
            k = 0
        else:
            count += (n * b[index])
            k -= (n * b[index])
            runs += b[index]
            n -= mem[b[index]]
            count += mem[b[index]]
            index += 1

    
    print(count)

    # print("\n", eachCase, ") Output -> ", count)
