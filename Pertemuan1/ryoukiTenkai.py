# Muhammad Firdaus Argifari
# 24060124130107


SA, X, Y, N = map(int,(input().split()))
HP = [int(i) for i in input().split()]
t = int(input())

totalSA = SA + t*X
totalDebuff = Y*t

for i in range(N) :
    HP[i] -= totalDebuff + totalSA

isAllDeath = True
for i in HP :
    if (i > 0) :
        isAllDeath = False
        break
if (isAllDeath):
    print("WIN")
else :
    print("LOSE")
        