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
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define lld long long int
#define llu unsigned long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define came "came"
using namespace std;

bool g,b;
bool memo[55][5][7];
char a[55];
map<char,int> mp;
int len;

void dp(int indx, int v, int c)
{
    if(v==3 || c==5)
    {
        b=true;
    }
    else if(indx==len)
    {
        g=true;
    }
    else if(memo[indx][v][c]) return;
    else
    {
        if(mp[a[indx]])
        {
            dp(indx+1,v+1,0);
        }
        else if(a[indx]=='?')
        {
            dp(indx+1,v+1,0);
            dp(indx+1,0,c+1);
        }
        else
        {
            dp(indx+1,0,c+1);
        }
        memo[indx][v][c]=true;
    }
}

int main()
{
    //FRO
    int t,ca;
    scanf("%d",&t);
    mp['A']=1;
    mp['E']=1;
    mp['I']=1;
    mp['O']=1;
    mp['U']=1;
    for(ca=1;ca<=t;ca++)
    {
        scanf("%s",a);
        len=strlen(a);
        clr(memo);
        b=g=false;
        dp(0,0,0);
        if(b==true && g==true)
        {
            printf("Case %d: MIXED\n",ca);
        }
        else if(b==true)
        {
            printf("Case %d: BAD\n",ca);
        }
        else
        {
            printf("Case %d: GOOD\n",ca);
        }
    }
    return 0;
}
