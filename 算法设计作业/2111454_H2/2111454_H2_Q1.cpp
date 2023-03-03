#include<iostream>

int main()
{
    int n;
    int * A = new int[n];
    int x;
    
    //输入数组大小
    std::cin>>n;

    //输入数组
    for(int i = 0;i < n;i++){
        std::cin>>A[i];
    }
    
    //输入需要查找的数字
    std::cin>>x;
    
    //初始化t,使之等于数字大小的一半
    int t = n / 2;
    //设置最大最小标志
    int max = n;
    int min = 0;
    //开始二分查找
    //循环条件为当前数组元素不等于需查找元素
    while(A[t] != x){
        //当最大标志小于最小标志或最大最小标志的平均数恒为最小标志时输出no，并跳出循环
        if(max <= min || (max + min) / 2 == min){
            std::cout<<"no";
            break;
        }
        //当需查找元素大于当前数组元素时，将最小标志更新为此时元素的下脚标
        //同时将t更新为t和最大标志的平均数
        if(x > A[t]){
            min = t;
            t = (t + max) / 2;
        }
        //当需查找元素小于当前数组元素时，将最大标志更新为此时元素的下脚标
        //同时将t更新为t和最小标志的平均数
        else{
            max = t;
            t = (t + min) / 2;
        }
    }
    //输出索引
    if(A[t] == x){
        std::cout<<t;
    }
}