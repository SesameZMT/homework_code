#include<iostream>

class queuenode
{
public:
    int name;
    queuenode * next;
    queuenode() : name(-1) , next(nullptr) {};
    queuenode(int Name) : name(Name) , next(nullptr) {};
};

class queue
{
public:
    queuenode * head;
    queuenode * tail;
    int num;
    queue();
    int pop();
    void push(int Name);
};
queue::queue()
{
    head = new queuenode();
    tail = new queuenode();
    head->next = tail;
    tail->next = head;
    num = 0;
}
void queue::push(int Name)
{
    queuenode * p = new queuenode(Name);
    queuenode * q = tail;
    if(num == 0){
        tail->next = p;
        p->next = head;
        head->next = p;
        num++;
    }
    else{
        p->next = q->next;
        q->next = p;
        num++;
    }
}
int queue::pop()
{
    queuenode * p = tail;
    queuenode * q = head->next;
    while(p->next != q){
        p = p->next;
    }
    p->next = head;
    head->next = p;
    num--;
    return q->name;
    
}

int main()
{
    int n;//节点数
    int e;//边数
    int s;//初始节点
    std::cin>>n>>e>>s;

    int * ans = new int[n];//结果数组
    for(int i = 0;i < n;i++){
        ans[i] = 1000000;
    }

    int ** source = new int*[e];//边的长度数组，同时进行初始化
    for(int i = 0;i < e;i++){
        source[i] = new int[e];
        for(int j = 0;j < e;j++){
            source[i][j] = 0;
        }
    }

    int ** node = new int*[n];//邻接矩阵，同时进行初始化
    for(int i = 0;i < n;i++){
        node[i] = new int[n];
        for(int j = 0;j < n;j++){
            node[i][j] = 0;
        }
    }

    for(int i = 0;i < e;i++){//输入矩阵
        int a,b,c;
        std::cin>>a>>b>>c;
        node[a-1][b-1] = 1;
        source[a-1][b-1] = c;
    }
    
    ans[s-1] = 0;
    queue q;//使用一个队列进行维护
    q.push(s);
    while(q.num){
        int t = q.pop();//首先推出队首元素
        for(int i = 0;i < n;i++){//循环判定该节点和那些节点相连
            if(node[t-1][i] == 1){//当相连时
                if(ans[i] == 1000000){//当相连节点为初始节点时，直接将路径长赋值给答案
                    ans[i] = source[t-1][i];
                }
                else if(ans[i] > source[t-1][i] + ans[t-1]){//否则进行判定，若相连节点答案比路径长加t节点答案长，则重新进行赋值
                    ans[i] = source[t-1][i] + ans[t-1]; 
                }
                q.push(i+1);//将相邻节点压入队列
            }
        }
    }

    for(int i = 0;i < n;i++){
        std::cout<<ans[i]<<" ";
    }
}