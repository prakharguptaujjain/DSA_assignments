#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ll> vi;
typedef vector<pair<int, int>> pi;
#define pb push_back
#define mp make_pair
#define e cout << endl;
#define r return;
#define er        \
    cout << endl; \
    return;
#define re        \
    cout << endl; \
    return;
#define ff first
#define ss second
#define hi cout << "HI";
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define ci cin >>
#define c >>
#define cou cout <<
#define co <<
#define des greater<int>()
#define sorted(v) sort(v.begin(), v.end())
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define f(a, c) for (int a = 0; a < c; a++)
#define fi(i, dat) for (auto i = dat.begin(); i != dat.end(); ++i)
#define endl "\n"
#define nl NULL
// std::cout << std::fixed;
// std::cout << std::setprecision(10);

string get_str()
{
    string s;
    getline(cin, s);
    return s;
}
int binarysearch(v64 &arr, ll n, ll k)
{
    ll ct = -1;
    for (ll b = n; b >= 1; b /= 2)
    {
        while (ct + b < n && arr[ct + b] <= k)
            ct += b;
    }
    return ct;
}
template <typename T>
void inp_vec(vector<T> &vec, ll n)
{
    T tmp;
    f(i, n)
    {
        cin >> tmp;
        vec.pb(tmp);
    }
}
v64 stov(string &s)
{
    v64 res;
    fi(i, s)
    {
        res.pb((ll)(*i - '0'));
    }
    return res;
}
    int ans=0;
    int a,b;

vector<bool> seive_eratosthenes(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    return sieve;
}

void recurse(int arr[500][500], int i,int j,int n,int m)
{
if(i>=0 && j>=0 && i<n && j<m)
{
    if(arr[i][j] && !ans)
    {
        if((i==0 || i==n-1 )||(j==0 || j==m-1 ))
        {
            ans=1;
        }
        arr[i][j]=0;
        recurse(arr,i+1,j,n,m);
        recurse(arr,i-1,j,n,m);    
        recurse(arr,i,j+1,n,m);    
        recurse(arr,i,j-1,n,m);    
        recurse(arr,i+1,j+1,n,m);    
        recurse(arr,i+1,j-1,n,m);    
        recurse(arr,i-1,j+1,n,m);    
        recurse(arr,i-1,j-1,n,m);    
            }
}
}
void solve()
{
    int n, m;
    ci n c m;
    int cnt = 0;
    int arr[500][500];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ci arr[i][j];
        }
    }
  ci a c b;
  if((a==0 || a==n-1 || b==1|| b==m-1))
  {
    cout<<1;er
  }
    recurse(arr,a,b,n,m);
    cou ans;e
}

int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("output.txt","w",stderr);
#endif
    int t = 1;
    // cin >> t; // INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
