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

void solve(int n,int h[],int k)
{
    int dp[n+1];
    fo(i,0,n+1)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {  
            if(i-j>=0)
                dp[i]=min((abs(h[i]-h[i-j])+dp[i-j]),dp[i]);
        }
    }
   // fo(i,0,n)
     //   cout<<dp[i]<<" ";
    cout<<dp[n-1];
}

int main()
{
    Fast
    int n,k;
    cin>>n>>k;
    int h[n];
    fo(i,0,n)
        cin>>h[i];
    solve(n,h,k);
    return 0;
}