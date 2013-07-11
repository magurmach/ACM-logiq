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
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("ouput.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define came "came"
using namespace std;

string memo[105][105];

char a[103],b[103];
int lena, lenb;
bool cmp(string a, string b)
{
    if(a.length()!=b.length())
    {
        return a.length()>b.length();
    }
    return a<b;
}

string dp(int l, int r)
{
    if(l>=lena || r>=lenb)
    {
        return "";
    }
    else if(memo[l][r]!="-")
    {
        return memo[l][r];
    }
    else
    {
        string ret[3];
        ret[0]=dp(l+1,r);
        ret[1]=dp(l,r+1);
        ret[2]="";
        if(a[l]==b[r])
        {
            ret[2]=a[l]+dp(l+1,r+1);
        }
        sort(ret,ret+3,cmp);
        return memo[l][r]=ret[0];
    }
}

int main()
{
    //FRO
    int t,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        int i,j;
        scanf("%s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lena;i++)
        {
            for(j=0;j<lenb;j++)
            {
                memo[i][j]="-";
            }
        }
        string ans=dp(0,0);
        if(ans=="")
        {
            printf("Case %d: :(\n",ca);
        }
        else
        {
            printf("Case %d: ",ca);
            cout<<ans<<endl;
        }
    }
    return 0;
}
