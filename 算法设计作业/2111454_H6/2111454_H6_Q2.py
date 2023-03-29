def add(k:int,way): #对所有已有节点的路径进行累加
    for i in range(k):
        way[i] += 1
    return way

def main():
    #输入
    num = int(input())
    way = [0 for _ in range(num)]
    frequency1 = input()
    frequency = frequency1.split()
    temp = frequency1.split()

    #计算全部频率
    fre = 0 
    for i in range(num):
        fre += int(temp[i])

    k = 0 #记录有几个元素已经在霍夫曼树中
    while len(frequency) != 1: #当frequency中只有一个元素时结束
        #取序列中的最小两个数
        a = min(frequency)
        frequency.remove(a)
        b = min(frequency)
        frequency.remove(b)

        if a in temp and b in temp and a != b: #当两数都在序列中且两数不相等时,k加2
            k += 2
            way = add(k,way)
            frequency.append(a+b)
        elif (a in temp and b not in temp) or (a not in temp and b in temp) or (a in temp and b in temp and a != b):
            #当两数有一个在序列中或两数相等且在序列中时,k加1
            k += 1
            way = add(k,way)
            frequency.append(a+b)
        else: #当两数都不在序列中时,k不增加
            way = add(k,way)
            frequency.append(a+b)

    ans = 0
    for i in range(num):
        ans += way[i] * (int(temp[i])/fre)
    print(ans)

if __name__ == '__main__':
    main()