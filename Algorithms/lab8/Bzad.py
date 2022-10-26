r = open("input.txt", "r")
n = int(r.readline())
arr = []
g = open("output.txt", "w")
for i in range(n):
    m = list(map(int, r.readline().split()))
    arr.append(m)
flag = True
for i in range(n):
    if arr[i][i] != 0:
        g.write(str("NO"))
        flag = False
        break
    for j in range(i+1, n):
        if arr[i][j] != arr[j][i]:
            g.write(str("NO"))
            flag = False
            break
if flag == True:
    g.write(str("YES"))
g.close()




        
