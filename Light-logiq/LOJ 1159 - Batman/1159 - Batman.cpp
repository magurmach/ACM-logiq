#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
using namespace std;

char a[55],b[55],c[55];
int memo[55][55][55];

int dp(int x, int y, int z)
{
    if(a[x]=='\0' || b[y]=='\0' || c[z]=='\0')
    {
        return 0;
    }
    else if(memo[x][y][z]!=-1) return memo[x][y][z];
    else
    {
        if(a[x]==b[y] && b[y]==c[z])
        {
            int ret1=1+dp(x+1,y+1,z+1);
            return memo[x][y][z]=ret1;
        }
        else
        {
            int ret1=dp(x+1,y,z);
            int ret2=dp(x,y+1,z);
            int ret3=dp(x,y,z+1);
            memo[x][y][z]=max(ret1,ret2);
            memo[x][y][z]=max(memo[x][y][z],ret3);
            return memo[x][y][z];
        }
    }
}

int main()
{
    //FRO
    int t,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        scanf("%s %s %s",a,b,c);
        reset(memo);
        int ans=dp(0,0,0);
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
