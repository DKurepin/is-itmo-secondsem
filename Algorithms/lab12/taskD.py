def knightMove(x, y, n, m, arr):
    if x < 1 or y < 1 or x > n or y > m:
        return 0
    if x == 1 and y == 1:
        return 1
    if arr[x][y] != -1:
        return arr[x][y]
    arr[x][y] = ((knightMove(x-2, y-1, n, m,arr) + knightMove(x-2, y+1, n, m,arr)
                 + knightMove(x-1, y-2, n, m,arr) +
                  knightMove(x+1, y-2, n, m,arr)))
    return arr[x][y]
 
 
 
r = open("knight2.in", "r")
n, m = map(int, r.readline().split())
r.close
arr = [[-1] * (m + 1) for i in range(n+1)]
arr[1][1] = 1
g = open("knight2.out", "w")
num = str(knightMove(n, m, n, m, arr))
g.write(num)
g.close()