#include<iostream>

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

//时间复杂度为O(n^3)
//三重for循环
void nnn(int *a,int n,int t)
{
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            for(int k = j;k < n;k++){
                if(a[i] + a[j] + a[k] == t){
                std::cout<<a[i]<<","<<a[j]<<","<<a[k]<<std::endl;
                return;
                }
            }
            
        }
    }
}

//时间复杂度为O(n^2logn)
//两重for循环后执行二分查找
void nnlogn(int *a,int n,int t)
{
     for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            int temp = t - a[i] - a[j];
            int k = bsearch(temp,a,n);
            if(k != -1){
                std::cout<<a[i]<<","<<a[j]<<","<<a[k]<<std::endl;
                return;
            }
        }
    }
}

//时间复杂度为O(n^2)
//一重for循环后进行双标志法查找
void nn(int *a,int n,int t)
{
    for(int k = 0;k < n;k++){
        int z = t - a[k];
        int i = 0;
        int j = n-1;
        do{
            int temp = a[i] + a[j];
            if(temp > z){
                j -= 1;
            }
            else if(temp < z){
                i += 1;
            }
            else{
                std::cout<<a[k]<<","<<a[i]<<","<<a[j]<<std::endl;
                return;
            }
        }while(i <= j);
    }
}

int main()
{
    int n;
    int * a = new int[n];
    int t;
    //输入n
    std::cout<<"please inpt n:";
    std::cin>>n;
    //输入数组
    std::cout<<"please input a sorted array of n distinct integers:";
    for(int i = 0;i < n;i++){
        std::cin>>a[i];
    }
    std::cout<<"please input target t:";
    std::cin>>t;
    clock_t start_time=clock();
    nnn(a,n,t);
    clock_t end_time=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
    clock_t start_time1=clock();
    nnlogn(a,n,t);
    clock_t end_time1=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time1-start_time1)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
    clock_t start_time2=clock();
    nn(a,n,t);
    clock_t end_time2=clock();
    std::cout<< "Running time is: "<<static_cast<double>(end_time2-start_time2)/CLOCKS_PER_SEC*1000<<"ms"<<std::endl;
}