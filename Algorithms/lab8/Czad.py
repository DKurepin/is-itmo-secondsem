r = open("input.txt", "r")
n, m = map(int, r.readline().split()) 
arr = [[0] * (n+1) for i in range(n+1)]
for i in range(m):
    f, k = map(int, r.readline().split()) 
    arr[f][k] += 1
 
g = open("output.txt", "w")
counter = 0
for i in range(1, n+1):
    for j in range(1, n+1):
        if (i == j and arr[i][j] >= 2):
            counter += 1
        if (i != j) and (arr[i][j] >= 2):
            counter += 1
        if (i != j) and (arr[i][j] == arr[j][i] > 0):
            counter += 1

if counter > 0:
    g.write(str("YES"))
else:
    g.write(str("NO"))
g.close()
