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
int maximumarr[10000];
int cntmax=0;
class node
{
public:
    int data = 0;
    int maxa = 0;
    int sum = 0;
};
class Queue
{
private:
    node *arr[9999];

public:
    int start = 0;
    int end = -1;

    void push(node *x)
    {
        end++;
        arr[end] = x;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
        }
        else
            start++;
    }
    node *front()
    {

        return arr[start];
    }
    int size()
    {
        return end - start + 1;
    }
    bool isempty()
    {
        if (end - start + 1)
            return 0;
        else
            return 1;
    }
    Queue()

    {
        for (int z = 0; z < 9999; z++)
        {
            arr[z] = new node;
        }
    }
};
int counter = 0;
void recurse(int matarr[10000][10000], int sumtillnow, int ultimatesum, int sumarr[], int n, int j,int maxtillnow)
{
    for (int i = 0; i < n; i++)
    {
        if (matarr[j][i] != -1)
        {

            if (sumtillnow + matarr[j][i] > ultimatesum)
            {
                return;
            }
            if (i == n - 1)
            {
                sumarr[counter] = sumtillnow + matarr[j][i];
                maximumarr[counter]=max(maxtillnow,matarr[j][i]);
                counter++;
 
                return;
            }
            recurse(matarr, sumtillnow + matarr[j][i], ultimatesum, sumarr, n, i,max(maxtillnow,matarr[j][i]));
        }
    }
}

void solve()
{
    int n, m;
    ci n c m;
    int ultimatesum = 0;
    int arr[n];
    int marr[m][3];
    f(i, m)
    {
        int tempo;
        int x, y;
        ci x c y c tempo;
        marr[i][0] = x - 1;
        marr[i][1] = y - 1;
        marr[i][2] = tempo;
        ultimatesum += tempo;
    }
    int matarr[10000][10000];
    f(i, 10000)
    {
        f(j, 10000)
        {
            matarr[i][j] = -1;
        }
    }
    f(i, m)
    {
        matarr[marr[i][0]][marr[i][1]] = marr[i][2];
    }
    node *nodearr[n];
    f(i, n)
    {
        nodearr[i] = new node();
        nodearr[i]->data = i;
        nodearr[i]->maxa = 0;
        nodearr[i]->sum = 0;
    }
    Queue q;
    q.push(nodearr[0]);
    int sumarr[n + m];
    f(i, n + m) sumarr[i] = 0;
    // while (!q.isempty())
    // {
    //     node *tmp = q.front();
    //     q.pop();
    //     f(i, n)
    //     {
    //         if (matarr[tmp->data][i] != -1)
    //         {

    //             nodearr[i]->maxa = max(matarr[tmp->data][i], tmp->maxa);
    //             nodearr[i]->sum = tmp->sum + matarr[tmp->data][i];
    //             nodearr[i]->data = i;
    //             if (ultimatesum < nodearr[i]->sum)
    //                 continue;
    //             if (i == n - 1)
    //             {
    //                 sumarr[counter] = (nodearr[i]->sum) - (nodearr[i]->maxa) + int(nodearr[i]->maxa);
    //                 counter++;
    //                 continue;
    //             }
    //             q.push(nodearr[i]);
    //         }
    //     }
    // }
    recurse(matarr, 0, ultimatesum, sumarr, n, 0,0);
    int mini = INT_MAX;
    f(i, counter)
    {
        // cout<< sumarr[i]<<" "<<maximumarr[i]<<endl;
        sumarr[i] = sumarr[i] - maximumarr[i] + int(maximumarr[i]/2);
        mini=min(mini,sumarr[i]);

    }
    cou mini;
    e
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
