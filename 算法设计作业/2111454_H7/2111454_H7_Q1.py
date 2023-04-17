from typing import List
import time

class Node:
    def __init__(self,volume,weight) -> None:
        self.volume = volume
        self.weight = weight

def backpack(n : int,v_max : int,nodelist : List[Node],ans : List[int]) -> None:
    for i in range(1,n+1):
        for j in range(1,v_max+1):
            if j < nodelist[i-1].volume:
                ans[i][j] = ans[i-1][j]
            else:
                ans[i][j] = max(ans[i-1][j],ans[i-1][j-nodelist[i-1].volume]+nodelist[i-1].weight)

    

def main() :
    v_max , n = map(int,input().split()) #背包容量和物品总数
    node : List[Node] = []
    ans : List[List[int]] = [[0 for _ in range(v_max+1)] for _ in range(n+1)]

    for _ in range(n):
        v , w = map(int,input().split())
        temp_node = Node(v,w)
        node.append(temp_node)
    
    backpack(n,v_max,node,ans)
    ans_num = max(max(ans))
    print(ans_num)
    

if __name__ == '__main__':
    start = time.time()
    main()
    end = time.time()
    print("run time is",end - start)