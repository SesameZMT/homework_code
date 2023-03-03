#include<iostream>
#include<cmath>

int main()
{
    int n;
    int ** a = new int*[n];
    std::cout<<"please input n:";
    std::cin>>n;
    std::cout<<"please input n points (a,b):";
    for(int i = 0;i < n;i++){
        a[i] = new int[2];
        std::cin>>a[i][0];
        std::cin>>a[i][1];
    }
    double shortest = 0;
    bool flag = false;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            double b = double((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]));
            double temp = sqrt(b);
            if(b < shortest && flag){
                shortest = temp;
            }
            else if(!flag){
                shortest = temp;
                flag = true;
            }
        }
    }
    
    std::cout<<"shortest distance is "<<shortest;

}