def generateSet(low, high, length):
    if (length == 1):
        return list(map(lambda x: [x], range(low, high + 1)))
    else:
        resultUntilNow = generateSet(low, high, length - 1)

        result = []

        for eachResult in resultUntilNow:


            for num in range(low, high + 1):
                another = eachResult.copy()
                another.append(num)
                    
                result.append(another)



        return result
    
def checkEq(constraint: list, givenSet: list):
    low = constraint[0]
    high = constraint[1]

    sum = 0

    for i in range(3, 3 + constraint[2]):
        sum += givenSet[constraint[i] - 1]
        if (sum > high):
            return False
        
    if (sum < low):
        return False
    else:
        return True
    

n, m = map(int, input().split(" "))

constraints = []

for i in range(m):
    constraints.append(list(map(int, input().split(" "))))


def solution(n, constraints):
    highN = max(n, *[line[1] for line in constraints])

    lowN = min(1, *[line[0] for line in constraints])

    sets = generateSet(lowN, highN, n)

    count = 0

    for eachSet in sets:
        satisfies = True
        for constraint in constraints:
            if not checkEq(constraint, eachSet):
              satisfies = False
              break

        if (satisfies):
            count += 1  

    return count


if m != 0:
    print(f"{solution(n, constraints)}")
if m == 0:
    print("infinity")


    













            
                



        


    