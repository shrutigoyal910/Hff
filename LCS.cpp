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
    string s,t;
    cin>>s;
    cin>>t;
    ll ls=s.length();
    ll lt=t.length();
    ll dp[ls+1][lt+1];
    //cout<<"ls"<<ls<<" lt"<<lt<<endl;
    fo(i,0,ls+1)
        dp[i][0]=0;
    fo(i,0,lt+1)
        dp[0][i]=0;
    for(ll i=1;i<=ls;i++)
    {

        for(ll j=1;j<=lt;j++)
        {
            if(t[j-1]==s[i-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    
   /* fo(i,0,ls+1)
    {
       
        fo(j,0,lt+1)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    //cout<<dp[ls][lt];
cout<<endl;*/
string res;
ll i=ls,j=lt;
while(i!=0&&j!=0)
        {
            if(s[i-1]==t[j-1])
            {
                res+=s[i-1];  //res is string
                j--;
                i--;
            }
            else if(dp[i-1][j]==dp[i][j])
            i--;
            else
            j--;
        }
        reverse(res.begin(),res.end());
    cout<<res<<endl;
/*
while(i>0&&j>0)
{
    if(dp[i][j]==dp[i-1][j-1]+1)
    {
        ans.push(t[j-1]);
        i--;
        j--;

    }
    else
    {
        j--;
    }
    
}

while(!ans.empty())
{
    cout<<ans.top();
    ans.pop();
}
cout<<endl;*/


    return 0;
}