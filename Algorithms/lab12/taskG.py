r = open("knapsack.in", "r")
n, m = list(map(int, r.readline().split()))
mass = list(map(int, r.readline().split()))
r.close()
arr = [0 for i in range(n + 1)]
arr[0] = 1
for i in range(m):
    for j in range(n, mass[i] - 1, -1):
        if arr[j - mass[i]] == 1:
            arr[j] = 1
 
g = open("knapsack.out", "w")
for i in range(n, -1, -1):
    if arr[i]:
        g.write(str(i))
        break
g.close()