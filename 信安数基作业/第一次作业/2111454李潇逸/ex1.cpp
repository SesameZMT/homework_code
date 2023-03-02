#include <iostream>
#include <cmath>

using namespace std;

bool su(double a){
    int aa;
    int b;
    bool flag;

    aa = int(a);
    b = int(sqrt(a)) + 1;

    for(int i = 2;i <= b;i++){
        if(aa == 2){
            flag = true;
            break;
        }
        else if(aa != 2 && aa % i == 0){
            flag = false;
            break;
        }
        else{
            flag = true;
        }
    }
    return flag;
}

void Eratosthenes(bool *a,int n){
    for(int i = 2;i <= n;i++){
        if(su(i)){
            for(int k = 2;k * i <= n;k++){
                a[k * i] = false;
            }
        }
    }
}

int main()
{
    int n;
    int m;
    char k;
    int total = 0;
    cout<<"请输入范围（格式：m-n）：";
    cin>>m;
    cin>>k;
    cin>>n;
    bool * a = new bool[n-m+1];

    for(int i = m;i <= n;i++){
        a[i] = true;
    }

    a[1] = false;

    Eratosthenes(a,n);

    bool flag = true;
    for(int i = 2;i <= n;i++){
        if(a[i]){
            
        }
        if(a[i] && !flag){
            cout<<","<<i;
            total++;
        }
        else if(a[i] && flag){
            cout<<i;
            flag = false;
            total++;
        }
    }

    cout<<endl<<"质数共计"<<total<<"个"<<endl;
}