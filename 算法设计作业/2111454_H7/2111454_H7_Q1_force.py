from typing import List
import time
class Node:
    def __init__(self,volume,weight) -> None:
        self.volume = volume
        self.weight = weight

def backpack(n : int,num : int,v : int,nodelist : List[Node]):#从n件物品中选，原有num个物品，背包可用空间为v，查找列表为nodelist
    if (n<=0) or (v<=0):#物品没有了，或背无可用空间，停止
        return 0
    if v<nodelist[num-n].volume:#如果背包可用空间比物品的体积小，则不放入
        ans=backpack(n-1,num,v,nodelist)
        return ans
    temp1=backpack(n-1,num,v-nodelist[num-n].volume,nodelist)+nodelist[num-n].weight#放入背包
    temp2=backpack(n-1,num,v,nodelist)

    #ans存放最大价值
    if temp1>=temp2:
        ans=temp1
    else:
        ans=temp2
    return ans

def main() :
    v_max , n = map(int,input().split()) #背包容量和物品总数
    node : List[Node] = []

    for _ in range(n):
        v , w = map(int,input().split())
        temp_node = Node(v,w)
        node.append(temp_node)
    
    ans = backpack(n,n,v_max,node)
    print(ans)

if __name__ == '__main__':
    start = time.time()
    main()
    end = time.time()
    print("run time is",end - start)