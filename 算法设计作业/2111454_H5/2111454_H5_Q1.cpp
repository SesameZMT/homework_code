#include<iostream>

class node
{
public:
    char name;
    node * next;
    node() : name('0') , next(nullptr) {};
    node(char temp) : name(temp) , next(nullptr) {};
};

class nodelist
{
public:
    nodelist();
    void insert(char temp);
    char pop();
    char which(int k,char * cache,int * time);

private:
    int num;
    node * head;
};
nodelist::nodelist()
{
    head = new node();
    num = 0;
}
void nodelist::insert(char temp)
{
    node * p = head;
    node * q = new node(temp);
    for(int i = 0;i < num;i++){
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
    num++;
}
char nodelist::pop()
{
    node * p = head->next;
    head->next = p->next;
    char t = p->name;
    delete p;
    num--;
    return t;
}
char nodelist::which(int k,char * cache,int * time)//找到后续中与当前最远的
{
    node * p = head;
    int * z = new int[k];//存储标志位，以此判断cache中是否有元素不在后续序列中
    for(int i = 0;i < k;i++){//初始化
        z[i] = 0;
    }

    char temp;
    for(int i = 0;i < num;i++){
        p = p->next;
        for(int j = 0;j < k;j++){
            if(p->name == cache[j] && z[j] == 0){//当序列中的数和cache一样时，将temp赋值为序列中的字符，并标志位赋值为1
                temp = p->name;
                z[j] = 1;
            }
        }
    }

    int flag = 0;
    for(int i = 0;i < k;i++){//探查是否存在不再后续序列中的cache字符
        if(z[i] == 0 && flag == 0){
            flag = i+1;
        }
        else if(z[i] == 0 && time[i] > time[flag-1]){//当出现多个时，比较时间，将时间较大的进行赋值
            flag = i+1;
        }
    }

    if(flag != 0){
        return cache[flag-1];
    }
    else{
        return temp;
    }
}

void addtime(int k,int * time){//增加时间
    for(int i = 0;i < k;i++){
        time[i]++;
    }
}

int main()
{
    int k;//共有多少cache
    int n;
    int s;//序列共有多少
    int no;
    nodelist q;
    std::cin>>k>>n>>s;
    char * cache = new char[k];
    int * time = new int[k];//存储未被使用的时间
    char ans[1000];
    int ans_num = 0;
    std::cin>>no;
    for(int i = 0;i < s;i++){
        char temp;
        std::cin>>temp;
        q.insert(temp);
    }

    for(int i = 0;i < k;i++){//初始化time、cache
        time[i] = 0;
        cache[i] = 0;
    }
    for(int i = 0;i < k;i++){//最初时直接将序列中的字符存入cache
        cache[i] = q.pop();
        for(int i = 0;i < k;i++){
            if(cache[i] != 0){
                time[i]++;
            }
        }
        s--;
    }
    while(s != 0){
        char temp = q.which(k,cache,time);
        char temp2 = q.pop();
        bool flag = true;
        for(int i = 0;i < k;i++){//当序列中的字符在cache中存在时，跳出
            if(temp2 == cache[i]){
                time[i] = 0;
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i = 0;i < k;i++){//当序列中的字符等于cache中的字符，将二者替换，同时重置时间
                if(temp == cache[i]){
                    ans[ans_num] = cache[i];
                    ans_num++;
                    cache[i] = temp2;
                    time[i] = 0;
                    break;
                }
            }
        }
        addtime(k,time);
        s--;
    }

    for(int i = 0;i < ans_num;i++){
        if(i == 0){
            std::cout<<ans[i];
        }
        else{
            std::cout<<" "<<ans[i];
        }
    }
}