
//Bismillahir Rahmanir Raheem

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
#include<set>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define lld long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ui unsigned int
#define came "came"
#define pii pair<long long int,int>
#define ninf (-1e9)-2
#define inf (1e9)+2
using namespace std;

int memo[102][102][102];
int grid[102][102];
int n,m;

int dp()
{
    int i,j,k;
    memo[1][1][1]=grid[1][1];
    for(i=2;i<=m;i++)
    {
        memo[1][1][i]=memo[1][1][i-1]+grid[i][1];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=j+1;k<=m;k++)
            {
                memo[i][j][k]=memo[i-1][j][k]+grid[j][i]+grid[k][i];
            }
        }
        for(j=1;j<=m;j++)
        {
            for(k=j+1;k<=m;k++)
            {
                memo[i][j][k]=max(memo[i][j][k],memo[i][j-1][k]+grid[j][i]);
            }
        }
        for(j=1;j<=m;j++)
        {
            for(k=j+2;k<=m;k++)
            {
                memo[i][j][k]=max(memo[i][j][k],memo[i][j][k-1]+grid[k][i]);
            }
        }
    }
    return memo[n][m-1][m];
}

int main()
{
    //FRO
    int t;
    scanf("%d",&t);
    int ca;
    int i,j;
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }
        clr(memo);
        int ans=dp();
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
