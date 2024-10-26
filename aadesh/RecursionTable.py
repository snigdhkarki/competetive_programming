n = int(input())
A_length, *A = map(int, input().split(" "))
B_length, *B = map(int, input().split(" "))

Amap = {}
Bmap = {}

for elem in A:
    Amap[elem] = True

for elem in B:
    Bmap[elem] = True

variations = 0

def fillTable(a: int , b: int, n: int, A = Amap, B = Bmap, N = n):
    global variations

    if (a < N):
        if (n in A or a == b):
            if (n not in B):
                fillTable(a+1, b, n+1)
        elif (n in B):
            fillTable(a, b+1, n+1)
        else:
            fillTable(a, b+1, n+1)
            fillTable(a+1, b, n+1)
    else:
        if n not in A:
            if (n != 2 * N):
                if b < N:
                    fillTable(a, b+1, n+1)
            else:
                variations = ((variations + 1) % 998244353)




fillTable(0, 0, 1)


print(variations)

