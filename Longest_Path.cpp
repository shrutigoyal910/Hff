/*

        /////////     /////        ////      ////
        //           //   //      //   //  // //
        //////      //    //     //     //   //
            //     // /// //    //          //
      ////////    //      //   //          //
*/



#include<bits/stdc++.h>


#define eps 1e-8
#define PI 3.141592653589793
#define bsize 512

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define bs 1000000007

using namespace std;

const int N=1e5+10;
vi edges[N];
bool visited[N];
int d[N];

void dfs(int i)
{
	visited[i]=1;
	d[i]=-1;
	for(int v : edges[i])
    {
		if(!visited[v]) 
            dfs(v);

		d[i]=max(d[i],d[v]);
	}
	d[i]++;
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--) 
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
    }
    
    int answer=0;
	for(int i=1;i<=n;i++)
    {
		if(!visited[i]) 
            dfs(i);

		answer=max(answer,d[i]);
	}
    printf("%d\n", answer);

    return 0;
}