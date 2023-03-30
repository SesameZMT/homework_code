def sort(n,interger): #冒泡排序
    for i in range(n):
        for j in range(i+1,n):
            if interger[i] > interger[j]:
                temp = interger[j]
                interger[j] = interger[i]
                interger[i] = temp

def main():
    #输入
    n = int(input())

    #分治为两个小问题分别冒泡
    half =int(n/2)
    interger = input()
    interger = interger.split()
    interger1 = []
    interger2 = []
    ans = []
    for i in range(0,half): 
        interger1.append(int(interger[i]))
        interger2.append(int(interger[i+half]))
    sort(len(interger1),interger1)
    sort(len(interger2),interger2)

    index1 = 0
    index2 = 0
    #合并问题
    while len(ans) != n: #当ans中元素个数与n相等时结束
        """
        具体思想是由于两个数组都为有序,则从头开始进行判断,将每次比较之后较小的数放入答案
        """
        if index1 == half and index2 < half: #当第一个有序数组取完第二个未取完,直接将第二个有序数组剩余部分全部放入ans
            for i in range(index2,half):
                ans.append(interger2[i])
        elif index2 == half and index1 < half: #当第二个有序数组取完第一个未取完,直接将第一个有序数组剩余部分全部放入ans
            for i in range(index1,half):
                ans.append(interger1[i]) 
        #对两有序数组的当前元素进行判断,将较小的那个放入ans
        elif interger1[index1] < interger2[index2]: 
            ans.append(interger1[index1])
            index1 += 1
        elif interger2[index2] < interger1[index1]:
            ans.append(interger2[index2])
            index2 += 1
        #当两数组当前元素大小相同,全部放入ans
        else:
            ans.append(interger1[index1])
            ans.append(interger2[index2])
            index1 += 1
            index2 += 1
    for i in range(n):
        print(ans[i],end=" ")

if __name__ == '__main__':
    main()    