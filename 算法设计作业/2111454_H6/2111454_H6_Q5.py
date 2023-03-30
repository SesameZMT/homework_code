from typing import List

class points: #存储输入的点
    def __init__(self,x : float,y : float) -> None:
        self.x = x
        self.y = y

def sort(pointlist:List[points],n): #将输入的点依照x的升序进行排序
    for i in range(n):
        for j in range(i,n):
            if pointlist[i].x > pointlist[j].x:
                temp = pointlist[i]
                pointlist[i] = pointlist[j]
                pointlist[j] = temp
    return pointlist

def distance(point1:points,point2:points): #求两点之间的距离
    d = (point1.x - point2.x) ** 2 + (point1.y - point2.y) ** 2
    return d

def mindistance(pointlist:List[points]): #求x有序点序列中的两点之间最短距离
    n = len(pointlist)
    mn = 100000000000
    for i in range(n):
        for j in range(i+1,n):
            temp = distance(pointlist[i],pointlist[j])
            mn = temp if mn > temp else mn
    return mn

def main():
    #输入
    n = int(input())
    pointlist : List[points] = []
    for i in range(n):
        x , y = map(float , input().split())
        point = points(x,y)
        pointlist.append(point)
    pointlist = sort(pointlist,n)
    
    #分治为两个子问题
    half = int(n/2)
    pointlist1 = []
    pointlist2 = []
    for i in range(half):
        pointlist1.append(pointlist[i])
        pointlist2.append(pointlist[half + i])
    
    #分别求出两个序列中的最小距离和两序列首尾点之间的距离,将三者之中的最小值输出,输出时保留两位小数
    mn1 = mindistance(pointlist1)
    mn2 = mindistance(pointlist2)
    mn3 = distance(pointlist1[half-1],pointlist2[0])
    ans = min(mn1,mn2,mn3)
    ans = round(ans,2)
    print(ans)

if __name__ == '__main__':
    main()