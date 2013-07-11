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
#define INF 2147483647
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
using namespace std;

int n;
int memo[20][70000];
int a[20][20];

int dp(int x, int mask)
{
    if(x==n) return 0;
    else if(memo[x][mask]!=-1) return memo[x][mask];
    else
    {
        int i;
        int res,mres=0;
        for(i=0;i<n;i++)
        {
            if(!(mask & 1<<i))
            {
                res=a[x][i]+dp(x+1,mask | 1<<i);
                mres=max(res,mres);
            }
        }
        return memo[x][mask]=mres;
    }
}

int main()
{
    //FRO
    int t,ca;
    int mask;
    int i,j;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d",&n);
        reset(memo);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=dp(0,0);
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
