/*

        /////////  /////      ////      ///
        //        //   //    //  //  // //
        //////   //    //   //    //   //
            //  // /// //  //         //
      //////// //      // //         //
      
         

*/

#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(0);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define mod 1000000007
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound()
#define PI 3.14159265
#define S second
#define F first 
//fill(all(vec), 1);to fill vector with a number
//if (S.count(key)) returns 1 if set or map contain key else return 0
ll nCr(ll n,ll r)
{
	r = min(r,n-r);
	if(r<0)
		 return 0;
	if(r == 0)
		return 1;
	ll ans = 1;
	for(ll i = 1;i<=r;i++)
	{
		ans = ans*(n-i+1)/i;
    }
	return ans;
 		
}


ll logn(int n, int r) 
{ 
     return (n > r - 1) ? 1 + logn(n / r, r) : 0; 
} 


ll power(ll a,ll b) {
	if(b == 1) return a;
	if(b == 0) return 1;
	ll m1 = power(a,b/2);
	if(b%2) return m1*m1*a;
	return m1*m1;
}


bool isprime(ll a)
{
    if(a<=1)
        return false;
    if(a==2||a==3)
        return true;
    if(a%2==0||a%3==0)
        return false;
    for(ll i=5;i*i<=a;i=i+6)
    {
        if(a%i==0||a%(i+2)==0)
            return false;
    }
    return true;

}
/*********************//*********************///*********************///*********************//

int main()
{
    Fast
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        char temp,ans='z';
        while(n--)
        {
            cin>>temp;
            if(temp<ans)
            {
                ans=temp;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}