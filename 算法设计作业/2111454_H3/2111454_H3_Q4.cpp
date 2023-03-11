#include<iostream>

int getinnum0(int * in_num,int n)
{
    int temp;
    for(int i = 0;i < n;i++){
        if(in_num[i] == 0){
           temp = i;
           in_num[i] = 1;
           break;
        }
    }
    return temp;
}

int main()
{
    int n;//节点数
    int m;//边数
    std::cin>>n>>m;
    int ** k = new int * [n];
    int * in_num = new int[n];//入度个数数组
    //初始化
    for(int i = 0;i < n;i++){
        k[i] = new int[n];
        in_num[i] = 0;
        for(int j = 0;j < n;j++){
            k[i][j] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        int a;
        int b;
        std::cin>>a>>b;
        k[a][b] = 1;
        in_num[b]++;
    }

    int num = 1;
    do{
        num++;
        int temp = getinnum0(in_num,n);
        std::cout<<temp<<" ";
        for(int i = 0;i < n;i++){
            if(k[temp][i] == 1){
                k[temp][i] = 0;
                in_num[i]--;
            }
        }
    }while(num <= n);
}