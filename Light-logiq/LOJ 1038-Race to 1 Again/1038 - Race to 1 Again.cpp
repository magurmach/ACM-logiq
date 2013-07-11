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

double memo[100008];

double expected_value(int n)
{
    if(n<=1)
    {
        return 0;
    }
    else if(memo[n]>0.0000) return memo[n];
    else
    {
        int i,j;
        int x=2,sq=sqrt(n);
        double ret=0.0,sum=0.0;
        for(i=2;i<=sq;i++)
        {
            if(n%i==0)
            {
                x++;
                sum+=(1.0+expected_value(n/i));
                if((n/i)>sq)
                {
                    x++;
                    sum+=(1.0+expected_value(i));
                }
            }
        }
        ret=(sum+1+1)/(double)(x-1);
        return memo[n]=ret;
    }
}

int main()
{
    //FRO
    int ca,t;
    int i,n;
    scanf("%d",&t);
    for(i=0;i<100005;i++) memo[i]=-1.0;
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d",&n);
        printf("Case %d: %.6lf\n",ca,expected_value(n));
    }
    return 0;
}
