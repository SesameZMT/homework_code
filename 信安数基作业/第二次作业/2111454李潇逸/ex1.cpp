#include<iostream>

int d2b(int n,int num,char *a)
{
    while(n != 0){
        if(n % 2 == 0){
            n /= 2;
            a[num] = '0';
            num++;
        }
        else{
            n /= 2;
            a[num] = '1';
            num++;
        }
    }
    return num;
}

int main()
{
    int a;
    int n;
    int m;
    int num;
    long long ans = 1;
    char binarry[100];
    std::cout<<"Calculate a^n(mod m)"<<std::endl;
    std::cout<<"Please input:"<<std::endl;
    std::cout<<"  a=";
    std::cin>>a;
    std::cout<<"  n=";
    std::cin>>n;
    std::cout<<"  m=";
    std::cin>>m;

    num = d2b(n,0,binarry);

    for(int i = num - 1;i >= 0;i--){
        if(binarry[i] == '1'){
            ans = ans * ans * a;
            ans = ans % m;
        }
        else{
            ans = ans * ans;
            ans = ans % m;
        }
    }

    std::cout<<a<<"^"<<n<<"(mod"<<m<<")="<<ans;
}