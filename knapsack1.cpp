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
#define mod 1000000007


int main()
{
    Fast
    ll n,w;
    
    cin>>n>>w;
    vector<ll>dp(w+1);
    for(int i=1;i<=n;i++)
    {
        ll a, b;
        cin>>a>>b;
        for(int j=w;j>=a;j--)
            dp[j]=max(dp[j-a]+b,dp[j]);

    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;

    return 0;
}