#include<iostream>

int main()
{
    int n;
    std::cin>>n;

    if(n >= 0){
        std::cout<<n;
    }
    else{
        int a = n % 10;
        int b = n % 100;
        int p = (n - a) / 10;
        int q = (n - b) / 10 + a;
        int ans = std::max(p,q);
        std::cout<<ans;
    }
}