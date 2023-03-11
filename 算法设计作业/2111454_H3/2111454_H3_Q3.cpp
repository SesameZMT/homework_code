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
    int * color = new int[n];
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

    queue q;
    q.push()
    while()


}