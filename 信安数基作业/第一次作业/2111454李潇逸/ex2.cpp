#include<iostream>

using namespace std;

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

int main()
{
    int m;
    int n;
    int p;
    cin>>m;
    cin>>n;
    cout<<"a="<<m<<endl;
    cout<<"b="<<n<<endl;
    if(n < m){
        p = m;
        m = n;
        n = p;
    }
    int k = gcd(m,n);
    cout<<"gcd(a,b)="<<k<<endl;
    cout<<"lcm(a,b)="<<lcm(m,n,k)<<endl;
}