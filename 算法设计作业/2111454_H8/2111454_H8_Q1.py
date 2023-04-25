import time

def main() -> None:
    result1 = ""
    start = time.time()
    a , b = input().split()
    ans = [[0 for _ in range(len(a)+1)] for _ in range(len(b)+1)]
    for i in range(1,len(b)+1):
        for j in range(1,len(a)+1):
            if a[j-1] == b[i-1]:
                ans[i][j] = 1 + ans[i-1][j-1]
                if a[j-1] not in result1:
                    result1 += a[j-1]
            else:
                ans[i][j] = max(ans[i-1][j],ans[i][j-1])
    result = max(max(ans))
    print(result)
    print(result1)
    end = time.time()
    print("run time is",end - start)

if __name__ == '__main__':
    main()