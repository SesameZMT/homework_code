#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
int f1[25][65][65];
int f2[25][65][65];
int p,ta[25],tb[25],ka[25],kb[25];
int na,nb;
//f1[p][i][j]表示第p个节点执行i个A任务，j个B任务的最短时间
void DP1()
{
    for(int a=1;a<=p;++a)
    {
        int F[2][65][65];
        memset(F,31,sizeof(F));
        F[1][0][0]=F[0][0][0]=0;
        for(int i=0;i<=na;++i)
            for(int j=0;j<=nb;++j)
            {
                for(int k=1;k<=i;++k)F[0][i][j]=min(F[0][i][j],F[1][i-k][j]+ka[a]*k*k+ta[a]);
                for(int k=1;k<=j;++k)F[1][i][j]=min(F[1][i][j],F[0][i][j-k]+kb[a]*k*k+tb[a]);
                f1[a][i][j]=min(F[0][i][j],F[1][i][j]);
            }
    }
}
//f2[p][i][j]表示前p个节点执行i个A任务，j个B任务的最短时间
void DP2()
{
    memset(f2,31,sizeof(f2));
    for(int i=0;i<=na;++i)
        for(int j=0;j<=nb;++j)
            f2[1][i][j]=f1[1][i][j];
    for(int a=2;a<=p;++a)
    {
        for(int i=0;i<=na;++i)
            for(int j=0;j<=nb;++j)
                for(int k=0;k<=i;++k)
                    for(int l=0;l<=j;++l)
                        f2[a][i][j]=min(f2[a][i][j],max(f2[a-1][k][l],f1[a][i-k][j-l]));
    }
}
int main()
{
    freopen("hpc.in","r",stdin);
    freopen("hpc.out","w",stdout);
    na=read();nb=read();
    p=read();
    for(int i=1;i<=p;++i)ta[i]=read(),tb[i]=read(),ka[i]=read(),kb[i]=read();
    DP1();
    DP2();
    printf("%d\n",f2[p][na][nb]);
    return 0;
}
