#include<iostream>

//二分查找
bool bsearch(int a,int *b,int n){
    int t = n / 2;
    int max = n;
    int min = 0;
    while(b[t] != a){
        if(max <= min || (max + min) / 2 == min){
            break;
        }
        if(a > b[t]){
            min = t;
            t = (t + max) / 2;
        }
        else{
            max = t;
            t = (t + min) / 2;
        }
    }
    if(b[t] == a){
        return true;
    }
    return false;
}

int main()
{
    int m;
    int n;
    //输入两个数组的大小
    std::cin>>m;
    std::cin>>n;
    int * a = new int[m];
    int * b = new int[n];
    //将m和n中较大的赋值给t,并创建数组
    int t = std::max(m,n);
    int * c = new int[t];
    //输入两个数组
    for(int i = 0;i < m;i++){
        std::cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        std::cin>>b[i];
    }
    //二分查找进行对比判断
    //具体操作是从a中挑出一个元素在b中进行二分查找
    //时间复杂度nlogn
    int j = 0;
    for(int i = 0;i < m;i++){
        if(bsearch(a[i],b,n)){
            c[j] = a[i];
            j++;
        }
    }
    for(int i = 0;i < j;i++){
        std::cout<<c[i];
    }
}