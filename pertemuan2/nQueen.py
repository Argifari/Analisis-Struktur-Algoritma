
N = int(input())

posQueen = []
for i in range(N):
    posQueen.append(-1)

row = 0

while (row >= 0) :
    isFound = False

    for column in range(posQueen[row] + 1,N):
        isSafe = True

        for i in range(row):
            isDiagonal = abs(posQueen[i] - column) == abs(i - row)
            if (isDiagonal or posQueen[i] == column) :
                isSafe = False
                break
        if (isSafe):
            posQueen[row] = column
            isFound = True
            break
    if isFound :
        if row == N - 1 :
            break
        else :
            row += 1
            posQueen[row] = -1
    else :
        row -= 1
if row == N - 1:
    for i in range(N):
        for j in range(N):
            if j == posQueen[i]:
                print("Q",end="")
            else :
                print(".",end="")
        print("\n",end="")
else :
    print('Kerajaan tidak dapat dilindungi!')
