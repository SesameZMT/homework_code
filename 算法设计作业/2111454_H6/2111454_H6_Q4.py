def sort(n,interger): #冒泡排序
    t = 0
    for i in range(n):
        for j in range(i+1,n):
            if interger[i] > interger[j]:
                temp = interger[j]
                interger[j] = interger[i]
                interger[i] = temp
                t += 1 #发生一次交换t加一
    return t #返回发生了多少次交换

def main():
    #输入
    n = int(input())
    half =int(n/2)
    interger = input()
    interger = interger.split()
    interger1 = []
    interger2 = []
    ans = []
    for i in range(0,half):
        interger1.append(int(interger[i]))
        interger2.append(int(interger[i+half]))
        
    #分治后分别进行排序
    t = 0
    t += sort(len(interger1),interger1)
    t += sort(len(interger2),interger2)
    #将两有序数组进行拼接后排序
    ans = interger1 + interger2 
    t += sort(n,ans)
    print(t)

if __name__ == '__main__':
    main()    