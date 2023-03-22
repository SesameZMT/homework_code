#include<iostream>

int main()
{
    int n;//节点数
    int e;//边数
    std::cin>>n>>e;

    int * ans = new int[n];//结果数组
    for(int i = 0;i < n;i++){
        ans[i] = 1000000;
    }

    int ** source = new int*[e];//边的长度数组，同时进行初始化
    for(int i = 0;i < e;i++){
        source[i] = new int[e];
        for(int j = 0;j < e;j++){
            source[i][j] = 0;
        }
    }

    int ** node = new int*[n];//邻接矩阵，同时进行初始化
    for(int i = 0;i < n;i++){
        node[i] = new int[n];
        for(int j = 0;j < n;j++){
            node[i][j] = 0;
        }
    }

    for(int i = 0;i < e;i++){//输入矩阵
        int a,b,c;
        std::cin>>a>>b>>c;
        node[a-1][b-1] = 1;
        node[b-1][a-1] = 1;
        source[a-1][b-1] = c;
        source[b-1][a-1] = c;
    }
    
    int num = 1;
    ans[0] = 0;
    while(num != n){
        int p = 1000000;
        int temp = 0;
        int temp2 = 0;
        for(int i = 0;i < n;i++){//进行循环
            if(ans[i] != 1000000){//当节点被放入集合时   
                for(int j = 0;j < n;j++){//判断那些节点与此节点相联，直至判断完所有的集合内点哪一个的相连点路径是最小的
                    if(node[i][j] == 1){
                        if(p > source[i][j]){
                            p = source[i][j];
                            temp = j;
                            temp2 = i;
                        }
                    }
                }
            }  
        }
        ans[temp] = p;
        node[temp][temp2] = 0;
        node[temp2][temp] = 0;
        num++;
    }

    int k = 0;
    for(int i = 0;i < n;i++){
        k += ans[i];
    }
    std::cout<<k;
}