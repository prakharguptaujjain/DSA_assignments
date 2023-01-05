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

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void Dijsktra(int arr[][2], int n, int m)
{
    bool matarr[n][n];
    f(i, n)
    {
        f(j, n)
        {
            matarr[i][j] = 0;
        }
    }
    f(i, m)
    {
        matarr[arr[i][0]][arr[i][1]] = 1;
        matarr[arr[i][1]][arr[i][0]] = 1;
    }
    int mainset[n];
    f(i, n)
    {
        mainset[i] = -1;
    }
    mainset[arr[0][0]] = 1;
    f(j, n) if (matarr[arr[0][0]][j])
    {
        mainset[j] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (mainset[i] != -1)
            f(j, n)
            {
                if (matarr[arr[0][0]][j])
                {
                    mainset[j] = min(mainset[i], mainset[j]);
                }
            }
    }
    int cnt = 5;
    while (cnt--)
    {
        bool alldone = false;
        for (int i = 0; i < n; i++)
        {
            if (mainset[i] != -1)
            {

                {
                    int j = i - 1;
                    while(mainset[j] == -1 && j >= 0) 
                    // if (j >= 0 && mainset[j] == -1)
                    {
                        mainset[j] = mainset[i] + (i-j);
                        j--;
                    }
                }
                {
                    int j = i + 1;
                    while(mainset[j] == -1 && j < n) 
                    // if (j < n && mainset[j] == -1)
                    {
                        mainset[j] = mainset[i] + (j-i);
                        j++;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (mainset[i] != -1)
                f(j, n)
                {
                    if (matarr[arr[0][0]][j])
                    {
                        mainset[j] = min(mainset[i], mainset[j]);
                    }
                }
        }
    }
    for (int i = n - 1; i >= 0; i++)
    {
        if (mainset[i] != -1)
        {
            cout << n - 1 - i + mainset[i];
            break;
        }
    }
}

void solve()
{
    int n, m;
    ci n c m;
    int arr[m][2];
    if (!m)

    {
        cout << n - 1;
        re
    }

    f(i, m)
    {
        int x, y;
        ci x c y;
        arr[i][0] = x - 1;
        arr[i][1] = y - 1;
    }
    Dijsktra(arr, n, m);
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
