r = open("input.txt", "r")
n, m = map(int, r.readline().split()) 
arr = [[0] * (n+1) for i in range(n+1)]
for i in range(m):
    f, k = map(int, r.readline().split()) 
    arr[f][k] = 1

g = open("output.txt", "w")
for i in range(1, n+1):
    for j in range(1, n+1):
        g.write(str(arr[i][j]) + " ")
    g.write(str('\n'))
g.close()

    
