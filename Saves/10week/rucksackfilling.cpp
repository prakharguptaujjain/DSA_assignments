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
#define min(a, b) (a > b ? b : a)
#define ci cin >>

#define cou cout <<
#define co <<
#define des greater<int>()
#define sorted(v) sort(v.begin(), v.end())
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define f(a, cl) for (int a = 0; a < cl; a++)
#define fi(i, dat) for (auto i = dat.begin(); i != dat.end(); ++i)
#define endl "\n"
#define nl NULL
// std::cout << std::fixed;
// std::cout << std::setprecision(10);

bool sortbyCond(const pair<int, int> &a, const pair<int, int> &b) // first element by ascending and second by descending
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}
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
int dp[100][501];
int rucksack(int n, int w, int *warr, int *varr)
{

    if (n <0)
    {
        return 0;
    }
    // if (w < 0)
    // {
    //     return 0;
    // }
    if (dp[n][w] != -1)
        return dp[n][w];

    
    if (warr[n] > w)

    {
        dp[n][w] = rucksack(n - 1, w, warr, varr);
        // cout << dp[n][w] << " ";
        return dp[n][w];
    }
    else

    {
        int x=rucksack(n - 1, w, warr, varr);
        int y=0;
        y=varr[n] + rucksack(n - 1, w - warr[n], warr, varr);
        dp[n][w] = max(x, y);

        // cout << dp[n][w] << " ";
        return dp[n][w];
    }
}

void solve()
{
    int n;
    ci n;
    int warr[n];
    int varr[n];
    f(j, n)
    {
        ci warr[j];
    }
    f(j, n)
    {
        ci varr[j];
    }

    int w;
    ci w;
    for (int i = 0; i < 100; i++)
    {
        for (int k = 0; k < 501; k++)
        {
            dp[i][k] = -1;
        }
    }
    cou rucksack(n - 1, w, warr, varr);
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
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
