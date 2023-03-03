#include<iostream>
#include <time.h>

//test
/*
    n : 100
    a : 1 2 3 4 5 6 7 8 9 10 
        11 12 13 14 15 16 17 18 19 20 
        21 22 23 24 25 26 27 28 29 30 
        31 32 33 34 35 36 37 38 39 40 
        41 42 43 44 45 46 47 48 49 50 
        51 52 53 54 55 56 57 58 59 60 
        61 62 63 64 65 66 67 68 69 70 
        71 72 73 74 75 76 77 78 79 80 
        81 82 83 84 85 86 87 88 89 90 
        91 92 93 94 95 96 97 98 99 100
*/

//二分查找
int bsearch(int a,int *b,int n){
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
        return t;
    }
    return -1;
}

//时间复杂度为O(n^2)
//两重for循环
void nn(int *a,int n,int t)
{
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(a[i] + a[j] == t){
                std::cout<<a[i]<<","<<a[j]<<std::endl;
                return;
            }
        }
    }
}

//时间复杂度为O(nlogn)
//一重for循环内嵌套一个二分查找
void nlogn(int *a,int n,int t)
{
    for(int i = 0;i < n;i++){
        int temp = t - a[i];
        int j = bsearch(temp,a,n);
        if(j != -1){
            std::cout<<a[i]<<","<<a[j]<<std::endl;
            return;
        }
    }
}

//时间复杂度为O(n)
//两个标志位，a[i]+a[j]大则末标志前移，小则前标志后移
void n1(int *a,int n,int t)
{
    int i = 0;
    int j = n-1;
    do{
        int temp = a[i] + a[j];
        if(temp > t){
            j -= 1;
        }
        else if(temp < t){
            i += 1;
        }
        else{
            std::cout<<a[i]<<","<<a[j]<<std::endl;
            return;
        }
    }while(i <= j);
}

int main()
{
    int n;
    int * a = new int[n];
    int t;
    //输入n
    std::cout<<"please input n:";
    std::cin>>n;
    //输入数组
    std::cout<<"please input a sorted array of n distinct integers:";
    for(int i = 0;i < n;i++){
        std::cin>>a[i];
    }
    //输入目标值
    std::cout<<"please input target t:";
    std::cin>>t;
    clock_t start_time=clock();
    nn(a,n,t);
    clock_t end_time=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
    clock_t start_time1=clock();
    nlogn(a,n,t);
    clock_t end_time1=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time1-start_time1)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
    clock_t start_time2=clock();
    n1(a,n,t);
    clock_t end_time2=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time2-start_time2)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
}