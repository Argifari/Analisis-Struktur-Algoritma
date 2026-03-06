
N, K = map(int, input().split())

result = []
blockPita = [0]*N

def placeBit(iterator, remainK) :
    if iterator == N:
        if remainK == 0 :
            result.append(blockPita[:])
        return 
    else:
        if remainK > (N-iterator+1) // 2: 
            return 
        
        blockPita[iterator] = 0
        placeBit(iterator+1,remainK)


        isSafe = (iterator == 0 or blockPita[iterator-1] == 0)
        if isSafe and remainK > 0:
            blockPita[iterator] = 1
            placeBit(iterator+1,remainK-1)
            blockPita[iterator] = 0

placeBit(0,K)

if result == []:
    print(-1)
else :
    for i in result:
        for j in i:
            print(j,end=" ")
        print()