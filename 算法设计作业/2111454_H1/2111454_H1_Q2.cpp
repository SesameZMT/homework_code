#include<iostream>

int main()
{
    int a;//单程票票价
    int b;//m程票票价
    int m;//m程票可以使用多少次
    int n;//使用的总数
    std::cin>>n>>m>>a>>b;
    int p = n / m;
    int q = n % m;
    if(m*a <= b){
        std::cout<<a*n;
    }
    else{
        if(q*a <= b){
            std::cout<<q*a+p*b;
        }
        else{
            std::cout<<(p+1)*b;
        }
    }
    
}