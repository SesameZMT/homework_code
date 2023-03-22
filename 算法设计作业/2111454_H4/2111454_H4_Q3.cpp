#include<iostream>

int min(int * a,int num)
{
    int temp = 1000000;
    int k = 0;
    for(int i = 0;i < num;i++){
        if(a[i] < temp && a[i] != -1){
            temp = a[i];
            k = i;  
        }
    }
    
    return k;
}

int main()
{
    int day = 0;//现在的时间
    int num;
    int ** a = new int *[2];
    std::cin>>num;
    a[0] = new int[num];
    a[1] = new int[num];
    for(int i = 0;i < num;i++){
        std::cin>>a[0][i];
        std::cin>>a[1][i];
    }

    int z = num;
    int ans = 0;
    while(z != 0){
        int k = min(a[1],num);
        if(z == num){//若是第一个，记录下截止日期
            day = a[0][k];
            a[1][k] = -1;
            ans = 0;
            z--;
        }
        else{//如果不是
            if(day + a[0][k] > a[1][k]){//当已经经过的时间day与将要过去的时间相加大于截止日期时，
                int t = day + a[0][k] - a[1][k];//令t = day + a[0][k] - a[1][k] 
                if(t > ans){
                    ans = t;
                }//当现在的差值大于原先的差值时，ans替换为t
                day += a[0][k];
                a[1][k] = -1;
                z--;
            }
            else{
                day += a[0][k];
                a[1][k] = -1;
                z--;
            }
        }
    }
    std::cout<<ans;
}