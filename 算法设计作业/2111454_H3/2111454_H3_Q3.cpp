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
    int m;//边数
    std::cin>>n>>m;
    int ** k = new int * [n];
    int * color = new int[n];//颜色数组，用1和0表示两种状态
    //初始化
    for(int i = 0;i < n;i++){
        k[i] = new int[n];
        color[i] = -1;
        for(int j = 0;j < n;j++){
            k[i][j] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        int a;
        int b;
        std::cin>>a>>b;
        k[a][b] = 1;
        k[b][a] = 1;
    }
    bool flag = true;

    queue q;
    q.push(0);
    while(q.num != 0){
        int temp = q.pop();
        if(temp == 0){
            color[temp] = 1;
        }//当是第一个时，直接将颜色赋值为1
        for(int i = 0;i < n;i++){
            if(k[temp][i] == 1){
                if(color[i] == color[temp]){//当两个节点有边相连且颜色相同，必定不是二分图，跳出循环
                    flag = false;
                    break;
                }
                else if(color[i] == -1){//当两个节点有边相连且未被赋值，将该节点入队且染成与本节点相反的颜色
                    color[i] = 1 - color[temp];
                    q.push(i);
                }
            }
        }
    }

    if(flag){
        std::cout<<"Yes";
    }
    else{
        std::cout<<"No";
    }
}