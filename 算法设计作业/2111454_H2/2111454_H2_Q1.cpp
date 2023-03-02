#include<iostream>

int main()
{
    int n;
    int * A = new int[n];
    int x;

    std::cin>>n;

    for(int i = 0;i < n;i++){
        std::cin>>A[i];
    }

    std::cin>>x;

    int t = n / 2;
    int max = n;
    int min = 0;
    while(A[t] != x){
        if(max <= min || (max + min) / 2 == min){
            std::cout<<"no";
            break;
        }
        if(x > A[t]){
            min = t;
            t = (t + max) / 2;
        }
        else{
            max = t;
            t = (t + min) / 2;
        }
    }
    if(A[t] == x){
        std::cout<<t;
    }
}