#include<iostream>

int sn(int s1,int s2,int q,int r1,int r2,int num){
    if(r2 == 0){
        return s2;
    }
    else{
        return sn(s2,s1-s2*q,r1/r2,r2,r1%r2,num++);
    }
}

int main()
{
    int n;//共有几个方程
    std::cout<<"n=";
    std::cin>>n;
    int * b = new int[n];
    int * m = new int[n];

    for(int i = 0;i < n;i++){
        std::cout<<" b_"<<i+1<<"=";
        std::cin>>b[i];
    }
    int M = 1;
    for(int i = 0;i < n;i++){
        std::cout<<" m_"<<i+1<<"=";
        std::cin>>m[i];
        M *= m[i];
    }

    int * mn = new int[n];

    for(int i = 0;i < n;i++){
        mn[i] = M / m[i];
    }

    int * nm = new int[n];
    for(int i = 0;i < n;i++){
        nm[i] = sn(1,0,mn[i]/m[i],m[i],mn[i]%m[i],n);
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += mn[i] * nm[i] * b[i];
    }

    ans = ans % M;
    if(ans < 0){
        ans += M;
    }

    std::cout<<"x="<<ans<<"(mod "<<M<<")";
}