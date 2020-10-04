/*

        /////////     /////        ////      ////
        //           //   //      //   //  // //
        //////      //    //     //     //   //
            //     // /// //    //          //
      ////////    //      //   //          //
*/

#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define pb(x) push_back(x);
#define Mod 1000000007

void solve(int n,int h[])
{
    ll dp[n+1]={INT_MAX};
    //dp[0]=h[0];
    dp[0]=0;//abs(h[1]-h[0]);
    dp[1]=abs(h[0]-h[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
    }
    //fo(i,0,n)
    //    cout<<dp[i]<<" ";
    cout<<dp[n-1];
}

int main()
{
    Fast
    int n;
    cin>>n;
    int h[n];
    fo(i,0,n)
        cin>>h[i];
    solve(n,h);
    return 0;
}