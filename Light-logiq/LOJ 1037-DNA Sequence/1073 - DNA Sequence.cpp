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

int n;

char l[19][105];
char final[19][105];
int lnf[19];

bool cmp(string a, string b)
{
    return a<b;
}

int judge(int x, int y)
{
    int i,j,k;
    int ln=lnf[x],ln1=lnf[y];
    int mn=ln1;
    for(i=ln-1;i>=0;i--)
    {
        for(j=i,k=0;j<ln;j++,k++)
        {
            if(final[x][j]!=final[y][k])
            {
                break;
            }
        }
        if(j>=ln) mn=ln1-k;
    }
    return mn;
}

int maskpath[15+1][(1<<15)+5];
int al[15+1][(1<<15)+5];
int again[15][100][15][100];
int jdg[15][15];

int memo[16][(1<<15)+5];

bool is_smaller(char *temp, char *temp1)
{
   return strcmp(temp,temp1)>=0;
}

int dp(int indx, int mask)
{
    if(mask==(1<<n)-1)
    {
        return 0;
    }
    else if(memo[indx][mask]!=-1)
    {
        return memo[indx][mask];
    }
    else
    {
        int i;
        int ret=1e9,amask,lp;
        for(i=0;i<n;i++)
        {
            if(!(mask & 1<<i))
            {
                int x,y=jdg[indx][i],ln=lnf[i],mni;
                x=dp(i,mask | 1<<i) +y;
                if(x<ret)
                {
                    lp=ln-y;
                    ret=x;
                    amask=mask | 1<<i;
                    mni=i;
                }
                else if(x==ret)
                {
                    if(again[mni][lp][i][ln-y]==-1)
                    {
                        again[mni][lp][i][ln-y]=is_smaller(final[mni]+lp,final[i]+(ln-y));
                    }
                    if(again[mni][lp][i][ln-y])
                    {
                        lp=ln-y;
                        amask=mask | 1<<i;
                        mni=i;
                    }
                }
            }
        }
        maskpath[indx][mask]=amask;
        al[indx][mask]=lp;
        return memo[indx][mask]=ret;
    }
}

int find_active(int a, int b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!(a & 1<<i) && (b & 1<<i))
        {
            return i;
        }
    }
}

void print_string(int indx,int a)
{
    if(a==(1<<n)-1) return;
    int to=maskpath[indx][a];
    int act=find_active(a,to);
    int ind=al[indx][a];
    printf("%s",final[act]+ind);
    print_string(act,to);
}

int main()
{
    //FRO
    //FROut
    int t;
    scanf("%d",&t);
    int ca;
    int x;
    for(ca=1;ca<=t;ca++)
    {
        reset(memo);
        reset(again);
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%s",l[i]);
        }
        x=0;
        bool f[15];
        memset(f,1,sizeof(f));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j && f[j] && strstr(l[j],l[i])!=NULL)
                {
                    f[i]=false;
                }
            }
        }
        for(i=0,x=0;i<n;i++)
        {
            if(f[i])
            {
                strcpy(final[x],l[i]);
                lnf[x]=strlen(final[x]);
                x++;
            }
        }
        n=x;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    jdg[i][j]=judge(i,j);
                }
            }
        }
        int ans=1e9;
        int mni;
        int s;
        for(i=0;i<n;i++)
        {
            x=dp(i, 0 | 1<<i)+lnf[i];
            if(x<ans)
            {
                ans=x;
                al[0][0]=0;
                maskpath[0][0]=1<<i;
                mni=i;
            }
            else if(x==ans)
            {
                if(is_smaller(final[mni],final[i]))
                {
                    al[0][0]=0;
                    maskpath[0][0]=1<<i;
                    mni=i;
                }
            }
        }
        printf("Case %d: ",ca);
        print_string(0,0);
        printf("\n");
    }
    return 0;
}
