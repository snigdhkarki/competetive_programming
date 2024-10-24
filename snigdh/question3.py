# import logging
# logging.basicConfig(filename='logfilename.log', filemode='a')
# logging.debug('---------------------------start------------------------')

from functools import cmp_to_key

class Pair:
    def __init__(self, left, right):
        self.l = left  
        self.r = right    
    def l(self):
        return self.l    
    def r(self):
        return self.r

def comp(a, b):
    sum = 0
    if (a.l>b.l):
        sum += 1
    if (a.l>b.r):
        sum +=1
    if (a.r>b.l):
        sum +=1
    if (a.r>b.r):
        sum +=1
    sum1 = 0

    if (b.l>a.l):
        sum1+= 1
    if (b.l>a.r):
        sum1+=1
    if (b.r>a.l):
        sum1+=1
    if (b.r>a.r):
        sum1+=1
    if sum1>sum:
        return -1
    elif sum1 == sum:
        return 0
    else:
        return 1    
   


if __name__ == "__main__":

    sorted_arrs = []
    b = int(input())
    for _ in range(b):
        d = []
        a = int(input())
        for i in range(a):
            a, b = map(int, input().split())
            d.append(Pair(a,b))
        sorted_arr = sorted(d, key=cmp_to_key(comp))
        sorted_arrs.append(sorted_arr)

    for sorted_arr in sorted_arrs: 
        for pair in sorted_arr:
            print(pair.l, end = ' ')
            print(pair.r, end = ' ')
        print("")