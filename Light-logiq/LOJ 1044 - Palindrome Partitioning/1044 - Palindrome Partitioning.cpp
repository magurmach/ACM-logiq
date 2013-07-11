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
#define lld long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

char a[1005];
int memo[1005][1005];
bool ispal[1005][1005];
int len;

int dp(int l, int r)
{
    if(l>=r)
    {
        return 0;
    }
    else if(memo[l][r]!=-1) return memo[l][r];
    else if(ispal[l][r]) return 0;
    else
    {
        int i;
        int ret=r-l+1;
        for(i=l;i<r;i++)
        {
            if(ispal[l][i])
            {
                ret=min(ret,1+dp(i+1,r));
            }
        }
        return memo[l][r]=ret;
    }
}

int main()
{
    //FRO
    int t,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        scanf("%s",a);
        reset(memo);
        len=strlen(a);
        clr(ispal);
        int i;
        for(i=0;i<len;i++)
        {
            int j,k;
            ispal[i][i]=true;
            j=i-1,k=i+1;
            while(j>=0 && k<len && a[j]==a[k])
            {
                ispal[j][k]=true;
                j--,k++;
            }
            j=i-1,k=i;
            while(j>=0 && k<len && a[j]==a[k])
            {
                ispal[j][k]=true;
                j--,k++;
            }
            j=i,k=i+1;
            while(j>=0 && k<len && a[j]==a[k])
            {
                ispal[j][k]=true;
                j--,k++;
            }
        }
        int ans=dp(0,len-1);
        printf("Case %d: %d\n",ca,ans+1);
    }
    return 0;
}
