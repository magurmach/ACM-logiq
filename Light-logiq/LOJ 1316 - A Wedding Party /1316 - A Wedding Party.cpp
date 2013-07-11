//Bismillahir Rahmanir Rahim

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
#define pii pair<int,int>
using namespace std;

vector< pii >v[505];
vector< pii >v1[505];
int n,m,s;
int c[16];
int w[505][505];
pii memo[16][2<<15];

void dijkstra(int s, vector< pii > *v)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        w[s][i]=1e9;
    }
    w[s][s]=0;
    priority_queue< pii, vector< pii >, greater<pii> > pq;
    pq.push(make_pair(0,s));
    while(!pq.empty())
    {
        pii a=pq.top();
        pq.pop();
        int u=a.second,wt=a.first;
        if(w[s][u]<wt) continue;
        int sz=v[u].size();
        for(i=0;i<sz;i++)
        {
            a=v[u][i];
            int v=a.second,wt=a.first;
            if(w[s][u]+wt<w[s][v])
            {
                w[s][v]=w[s][u]+wt;
                pq.push(make_pair(w[s][v],v));
            }
        }
    }
}

/*

you can avoid case taken by counting activated bits or 1 bits

*/

pii dp(int indx, int mask, int taken)
{
    if(memo[indx][mask].first!=-1) return memo[indx][mask];
    else
    {
        pii ret;
        int i,j;
        ret.first=taken;
        ret.second=0;
        bool got=false;
        for(i=0;i<s;i++)
        {
            if(!(mask & 1<<i))
            {
                int v=c[i];
                int u=c[indx];
                if(w[v][u]<1e9)
                {
                    pii x=dp(i,mask | 1<<i,taken+1);
                    x.second+=w[v][u];
                    if(x.second>=1e9) continue;
                    got=true;
                    if(ret.first<x.first)
                    {
                        ret=x;
                    }
                    else if(ret.first==x.first)
                    {
                        ret.second=min(ret.second,x.second);
                    }
                }
            }
        }
        if(!got)
        {
            ret.second+=w[n-1][c[indx]];
            memo[indx][mask]=ret;
        }
        else
        {
            memo[indx][mask]=ret;
        }
        return memo[indx][mask];
    }
}

int main()
{
    //FRO
    int t,ca;
    scanf("%d",&t);
    int i,j;
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d %d %d",&n,&m,&s);
        for(i=0;i<s;i++)
        {
            scanf("%d",&c[i]);
        }
        for(i=0;i<n;i++)
        {
            v[i].clear();
            v1[i].clear();
        }
        int x,y,wt;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&wt);
            v[x].push_back(make_pair(wt,y));
            v1[y].push_back(make_pair(wt,x));
        }
        for(i=0;i<s;i++)
        {
            dijkstra(c[i],v1);
        }
        dijkstra(n-1,v1);
        reset(memo);
        pii ans(0,1e9),r;
        for(i=0;i<s;i++)
        {
            int v=c[i];
            //cout<<v<<" "<<w[v][0]<<endl;
            if(w[v][0]==1e9) continue;
            r=dp(i,1<<i,1);
            r.second+=w[v][0];
            //cout<<r.first<<" "<<r.second<<endl;
            if(r.first>ans.first)
            {
                ans=r;
            }
            else if(r.first==ans.first)
            {
                ans.second=min(r.second,ans.second);
            }
        }
        if(ans.second>=1e9)
        {
            printf("Case %d: Impossible\n",ca);
        }
        else
        {
            printf("Case %d: %d %d\n",ca,ans.first,ans.second);
        }
    }
    return 0;
}
