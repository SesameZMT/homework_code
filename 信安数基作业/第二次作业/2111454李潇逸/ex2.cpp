#include<iostream>

int gcd(int a,int b){
    int k = 0;
    for(int i = 1;i <= a;i++){
        if(a % i == 0 && b % i == 0){
            k = i;
        }
    }
    return k; 
}

int lcm(int a,int b,int k){
    int p = a / k;
    int q = b / k;
    return p * q * k;
}

void sn(int s1,int s2,int q,int r1,int r2,int num){
    if(r2 == 0){
        std::cout<<s2<<std::endl;
    }
    else{
        sn(s2,s1-s2*q,r1/r2,r2,r1%r2,num++);
    }
}

void tn(int t1,int t2,int q,int r1,int r2,int num){
    if(r2 == 0){
        std::cout<<t2<<std::endl;
    }
    else{
        tn(t2,t1-t2*q,r1/r2,r2,r1%r2,num++);
    }
}

int main()
{
    int a;
    int b;
    std::cout<<"a=";
    std::cin>>a;
    std::cout<<"b=";
    std::cin>>b;
    if(a < b){
        int k = gcd(a,b);
        std::cout<<"gcd(a,b)="<<k<<std::endl;
        std::cout<<"lcm(a,b)="<<lcm(a,b,k)<<std::endl;
        std::cout<<"a^(-1)=";
        tn(0,1,0,b,a,1);
        std::cout<<"b^(-1)=";
        sn(1,0,0,b,a,1);
    }
    if(a >= b){
        int k = gcd(b,a);
        std::cout<<"gcd(a,b)="<<k<<std::endl;
        std::cout<<"lcm(a,b)="<<lcm(b,a,k)<<std::endl;
        std::cout<<"a^(-1)=";
        sn(1,0,0,b,a,1);
        std::cout<<"b^(-1)=";
        tn(0,1,0,b,a,1);
    }
}