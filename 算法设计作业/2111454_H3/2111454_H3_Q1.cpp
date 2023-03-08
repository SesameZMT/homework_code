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
    void push(char Name);
};
queue::queue()
{
    head = new queuenode();
    tail = new queuenode();
    head->next = tail;
    tail->next = head;
    num = 0;
}
void queue::push(char Name)
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
    int n;//节点个数
    int m;//边数
    int i;//开始节点
    std::cin>>n>>m>>i;
    int ** k = new int * [n];
    for(int i = 0;i < n;i++){
        k[i] = new int[n];
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

    int * ans = new int[n];
    for(int i = 0;i < n;i++){
        ans[i] = -1;
    }
    queue q;
    q.push(i);
    
    ans[i] = 0;
    while(q.num != 0){
        int z = q.pop();
        for(int i = 0;i < n;i++){
            if(k[z][i] == 1){
                q.push(i);
                k[z][i] = 0;
                k[i][z] = 0;
                ans[i] = ans[z] + 1;
            }
        }
    }

    for(int i = 0;i < n;i++){
        std::cout<<ans[i]<<" ";
    }
}