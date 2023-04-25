import string
import time

def check(a : string , b : string , indexa : int , indexb : int , result1) -> int:
    if indexa == 0 or indexb == 0: #当两序列有一个序列遍历结束时返回0
        return 0
    elif a[indexa-1] == b[indexb-1]: #当两序列此时元素相等时返回1+下一步递归
        if a[indexa-1] not in result1:
            result1 += a[indexa-1]
        return 1 + check(a,b,indexa - 1,indexb - 1,result1)
    else: #当两元素不相等时，选取两序列下一元素返回值的最大值
        return max(check(a,b,indexa - 1,indexb,result1),check(a,b,indexa,indexb - 1,result1))

def main() -> None :
    a , b = input().split()
    result1 = []
    s = ""
    ans = check(a,b,len(a),len(b),result1)
    for i in range(len(result1)):
        s += result1[i]
    print(ans)
    print(s)

if __name__ == '__main__':
    start = time.time()
    main()
    end = time.time()
    print("run time is",end - start)