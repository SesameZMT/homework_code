#include<iostream>

using namespace std;

class node 
{
public:
    char name;
    char like;
    bool flag;
    node * next;
    node() : name('0') , next(nullptr) , flag(false) , like('0') {};
    node(char Name) : name(Name) , next(nullptr) , flag(false) , like('0') {};
};

class queuenode
{
public:
    char name;
    queuenode * next;
    queuenode() : name('0') , next(nullptr) {};
    queuenode(char Name) : name(Name) , next(nullptr) {};
};

class queue
{
public:
    queuenode * head;
    queuenode * tail;
    int num;
    queue();
    queuenode * pop();
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
queuenode * queue::pop()
{
    queuenode * p = tail;
    queuenode * q = head->next;
    while(p->next != q){
        p = p->next;
    }
    p->next = head;
    head->next = p;
    num--;
    return q;
    
}

void insert(char t,node * &a){
    node * p = new node(t);
    node * q = a;
    while(q->next != nullptr){
        q = q->next;
    }
    q->next = p;
}

void Delete(node * &a){
    node * p = a->next;
    a->next = p->next;
    delete p;
}

int main()
{
    int n;//男女配对的总数

    cin >> n;

    node * man[n];
    node * woman[n];

    int i = 1;
    int j = 0;
    int k = 0;
    char temp;
    do{
        cin >> temp;
        if(temp>'Z' || temp<'A'){
            continue;
        }
        if(i % (n + 1) == 1 && i <= n * (n + 1)){
            j++;
            man[j-1] = new node(temp);
            i++;
        }
        else if(i % (n + 1) != 1 && i <= n * (n + 1)){
            insert(temp,man[j-1]);
            i++;
        }
        else if(i % (n + 1) == 1 && i > n * (n + 1)){
            k++;
            woman[k-1] = new node(temp);
            i++;
        }
        else if(i % (n + 1) != 1 && i > n * (n + 1)){
            insert(temp,woman[k-1]);
            i++;
        }
    }while(i <= ((n + 1) * 2 * n));
    
    char a[2][1000];
    for(int i = 0;i < n;i++){
        a[0][i] = man[i]->name;
    }
    char man0 = man[0]->name;
    char woman0 = woman[0]->name;
    queue q;
    for(int i = 0;i < n;i++){
        q.push(man[i]->name);
    }
    while(q.num != 0){
        char name = q.pop()->name;
        int man_n = name - man0;
        node * p = man[man_n]->next;
        while(woman[p->name - woman0]->flag){
            node * pw = woman[p->name - woman0];
            node * p2 = woman[p->name - woman0]->next;
            
            while(p2->name != name && p2->name != pw->like){
                p2 = p2->next;
            }
            if(p2->name == name){
                q.push(pw->like);
                pw->like = name;
                a[1][man_n] = pw->name;
                break;
            }
            else{
                p = p->next;
            }
        }
        if(!woman[p->name - woman0]->flag){
            a[1][man_n] = woman[p->name - woman0]->name;
            woman[p->name - woman0]->flag = true;
            woman[p->name - woman0]->like = name;
        }
    }
    
    for(int i = 0;i < n;i++){
        cout<<"("<<a[0][i]<<","<<a[1][i]<<")"<<endl;
    }
}