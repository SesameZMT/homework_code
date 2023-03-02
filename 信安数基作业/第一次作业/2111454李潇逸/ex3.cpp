#include<iostream>
#include<cmath>

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

void t(double a,int *b){
    int aa = int(a);
    int c = int(sqrt(a))+1;
    for(int i = 2;i <= c;i++){
        if(su(i)){
            if(su(aa)){
                b[aa]++;
                break;
            }
            else{
                while(aa % i == 0){
                aa /= i;
                b[i]++;
                }
            }
        }
    }
}

int main()
{
    double a;
    int *b;
    cin>>a;
    int aa = int(a);
    b = new int[aa+1];
    for(int i = 0;i <= aa;i++){
        b[i] = 0;
    }
    t(a,b);
    bool flag = false;
    for(int i = 2;i <= aa;i++){
        if(b[i] != 0 && !flag){
            cout<<i<<"^"<<b[i];
            flag = true;
        }
        else if(b[i] != 0 && flag){
            cout<<"*"<<i<<"^"<<b[i];
        }
    }
}