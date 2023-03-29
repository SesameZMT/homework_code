def find(x,father): #查找函数,使用递归实现,用于查找x所在子树的根节点
    if father[x] == x:
        return x
    else:
        return find(father[x],father)

def unite(x,y,father): #并查集的主题函数
    #首先先查找x、y所在子树的根节点
    a = find(x,father)
    b = find(y,father)
    if a == b: #当二者根节点相同,证明二者处于同一子树,返回False
        return False
    else: #当二者跟节点不同,证明二者不处于同一子树,返回True
        return True

def main():
    n,e = map(int,input().split())
    node = []
    father = [x for x in range(n+1)]
    weights = [1000000000000000,] #存储图中边的权重
    edge = [[1000000000000000,],[1000000000000000,]] #存储该边的两个节点
    ans = 0

    for _ in range(e): #输入
        source , target , weight = map(int, input().split())
        weights.append(weight)
        edge[0].append(source)
        edge[1].append(target)

    while len(node) != n: #当所有节点都加入node中后截止
        temp = min(weights) #首先从权重数组中提取最小的
        index = weights.index(temp) #同时得到该值在数组中的位置
        #初始化两个标志位
        flag1 = False 
        flag2 = False

        if edge[0][index] not in node: #当权重对应边的左节点不在node中时,将其加入node,同时让第一个标志位为真
            node.append(edge[0][index])
            flag1 = True
        if edge[1][index] not in node: #当权重对应边的右节点不在node中时,将其加入node,同时让第一个标志位为真
            node.append(edge[1][index])
            flag2 = True

        if (not flag1) and (not flag2): #当二者都在node中时,判断是否会形成环
            flag2 = unite(edge[0][index],edge[1][index],father)

        if ((not flag1) and flag2) or (flag1 and flag2): #左节点在node中且右节点不在node中或二者都不在node中,将右节点的父节点赋值为左节点
            father[edge[1][index]] = edge[0][index]
        elif flag1 and (not flag2): #右节点在node中且左节点不在node中,将左节点的父节点赋值为右节点
            father[edge[0][index]] = edge[1][index]

        if flag1 or flag2: #当两标志位其中之一为真,则将ans加上此时的最小值,同时删除相应的节点和权重
            ans += temp
            edge[0].remove(edge[0][index])
            edge[1].remove(edge[1][index])
            weights.remove(temp)
    print(ans)

if __name__ == '__main__':
    main()