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
    ll h,w;
    cin>>h>>w;
    ll dp[h][w]={0};
    char a;
    fo(i,0,w)
        dp[0][i]=1;
    fo(i,0,h)
        dp[i][0]=1;
    fo(i,0,h)
    {
        fo(j,0,w)
        {
            cin>>a;
            if(a=='#')
                dp[i][j]=-1;
            
            
        }
    }
    if(dp[0][0]==-1)
    {
         cout<<0;
         exit(0);
    }
    else
    {
        fo(i,1,h)
        {
            fo(j,1,w)
            {
                if(dp[i][j]>=0)
                {
                    if((dp[i][j-1]>=0))
                        dp[i][j]=dp[i][j]+(dp[i][j-1]);
                    if(dp[i-1][j]>=0)
                        dp[i][j]=dp[i][j]+(dp[i-1][j]);
                    dp[i][j]=(dp[i][j])%mod;
                    

                }
            }
        }
       cout<<dp[h-1][w-1]%mod<<endl;
    }
    
    

    return 0;
}