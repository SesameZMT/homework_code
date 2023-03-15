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
    int room = 0;//需要的房间数
    int num;
    int ** a = new int *[2];
    std::cin>>num;
    a[0] = new int[num];
    a[1] = new int[num];
    for(int i = 0;i < num;i++){
        std::cin>>a[0][i];
        std::cin>>a[1][i];
    }
    
    int * temp = new int[num];
    int z = num;
    while(z != 0){
        int k = min(a[0],num);
        if(z == num){//当是第一个时，看是否还有与他同时开始的，将这些分别制定一个房间
            for(int i = 0;i < num;i++){
                if(a[0][i]==a[0][k]){
                    temp[room] = i;
                    a[0][i] = -1;
                    room++;
                    z--;
                }
            }
        }
        else{//若不是第一个
            bool flag = false;
            for(int i = 0;i < room;i++){//看是否有房间可以容纳
                if(a[0][k] >= a[1][temp[i]]){
                    temp[i] = k;
                    a[0][k] = -1;
                    z--;
                    flag = true;
                    break;
                }
            }
            if(flag == false){//没有的话新建一个房间
                temp[room] = k;
                a[0][k] = -1;
                room++;
                z--;
            }
        }
    }
    std::cout<<room;
}