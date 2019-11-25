cases = int(input())

while cases > 0:

    arr = [[0 for i in range(10)],[0 for j in range(10)]]
    cnt = [[0 for i in range(10)],[0 for j in range(10)]]
    num = [0 for i in range(510)]

    n, m = input().split()
    n = int(n)
    m = int(m)

    for i in range(m):
        tmp = input()
        num[i+1] = int(tmp, 2)

    print(arr[m-1][m-1])
    print(arr.size)
    for i in range(m):
        arr[i][i] = num[i]
        cnt[i][i] = 1

    flag = False
    for i in range(1, m+1):
        for j in range(i+1, m+1):

            if j+1 > m+1:
                break


            arr[j][j+1] = arr[j+1][j] & arr[j][j-1]
            cnt[j][j+1] = cnt[j+1][j] + cnt[j][j-1] -1
            if arr[j][j+1] == 2 ** (n-1):
                flag = True
                break

        if flag:
            break


    print(cnt)


    cases-=1
