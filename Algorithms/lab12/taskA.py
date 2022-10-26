n = int(input())
arr = list(map(int, input().split()))
Max = 1
ID = 0
b = [0] * n
c = [0] * n
for i in range(0,n):
    c[i] = 1
    b[i] = -1
    for j in range(0,i):
        if arr[j] < arr[i] and c[j]+1 > c[i]:
            c[i] = c[j] + 1
            b[i] = j
             
pos = 0
length = c[0]
for i in range(0, n):
    if c[i] > length:
        pos = i
        length = c[i]
 
res = []
while pos != -1:
    res.append(arr[pos])
    pos = b[pos]
     
print(len(res))
print(*(reversed(res)))