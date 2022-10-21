/*
        /////////  /////      ////     ///
        //        //   //    //  // // //
        //////   //    //   //   //   //
            //  // /// //  //        //
      //////// //      // //        //
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define rep(i, s, n) for (ll i = s; i < n; i++)
#define For(i, s, l) for (ll i = l; i >= s; i--)
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound()
#define S second
#define F first
#define PI 3.14159265358979323846
#define bits_all_odds 0X55555555
#define bits_all_even 0XAAAAAAAA
#define setBit(x) builtin_popcount(x)
#define fix(num, dig) cout << fixed << setprecision(dig) << num
//fill(all(vec), 1);to fill vector with a number
//if (S.count(key)) returns 1 if set or map contain key else return 0
const int N = 1000010;
vector<ll> is_prime(N + 1, true);
void seive_of_eras(ll n)
{
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

ll nCr(ll n, ll r)
{
    r = min(r, n - r);
    if (r < 0)
        return 0;
    if (r == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}
ll logn(int val, int base) { return (val > base - 1) ? 1 + logn(val / base, base) : 0; }
//ll logn(int val, int base) { return (base > val - 1) ? 1 + logn(base / val, val) : 0; }
ll power(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    ll m1 = power(a, b / 2);
    if (b % 2)
        return m1 * m1 * a;
    return m1 * m1;
}
bool isprime(ll a)
{
    if (a <= 1)
        return false;
    if (a == 2 || a == 3)
        return true;
    if (a % 2 == 0 || a % 3 == 0)
        return false;
    for (ll i = 5; i * i <= a; i = i + 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }
    return true;
}
template <typename T>
void init(T *temp, T num, int n)
{
    for (int i = 0; i < n; i++)
        temp[i] = num;
}
/*********************/ /*********************/ /*********************/ /*********************/ //
void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"0 0"<<endl;
        return;
    }
    ll mx=max(a,b);
    ll mn=min(a,b);
    ll k=mx-mn;
    if(k==1)
    {
        cout<<"1 0"<<endl;
        return;
    }

    ll m=min(mn,min(k-(mx%k),k-(mn%k)));
    m=min(mx%k,min(m,mn%k));

    if(__gcd(mx,mn)==k)
        m=0;
    cout<<k<<" "<<m<<endl;
}

signed main()
{
    Fast
        ll t;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}