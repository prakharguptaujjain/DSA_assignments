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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition3(int arr[][3], int low, int high)
{
    int pivot = arr[high][0];
    int pi = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i][0] < pivot)
        {
            pi++;
            swap(&arr[pi][0], &arr[i][0]);
            swap(&arr[pi][1], &arr[i][1]);
            swap(&arr[pi][2], &arr[i][2]);
        }
    }
    pi++;
    swap(&arr[pi][0], &arr[high][0]);
    swap(&arr[pi][1], &arr[high][1]);
    swap(&arr[pi][2], &arr[high][2]);

    return pi;
}
void quicksort3(int arr[][3], int start, int end)
{
    if (start < end)
    {
        int pivot = partition3(arr, start, end);
        quicksort3(arr, start, pivot - 1);
        quicksort3(arr, pivot + 1, end);
    }
}
class node
{
public:
    int root;
    node *next = NULL;
    int rank = 0;
};

void solve()
{
    int n, m;
    ci n c m;
    int matarr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matarr[i][j] = 0;
        }
    }

    int arr[m][3];
    auto mainsetarr = new node *[n];
    for (int i = 0; i < n; i++)
    {
        mainsetarr[i] = new node;
    }
    for (int i = 0; i < n; i++)
    {
        mainsetarr[i]->root = i;
        mainsetarr[i]->rank = 1;
    }
    f(i, m)
    {
        int x, y, z;
        ci x c y c z;
        arr[i][0] = z;
        arr[i][1] = x - 1;
        arr[i][2] = y - 1;
    }
    quicksort3(arr, 0, m - 1);
    f(i, m)
    {
        if (mainsetarr[arr[i][1]]->root == mainsetarr[arr[i][2]]->root)
            continue;
        matarr[arr[i][1]][arr[i][2]] = arr[i][0];

        if ((mainsetarr[mainsetarr[arr[i][1]]->root]->rank > mainsetarr[mainsetarr[arr[i][2]]->root]->rank))
        {
            int newrank = mainsetarr[mainsetarr[arr[i][1]]->root]->rank + mainsetarr[mainsetarr[arr[i][2]]->root]->rank;
            mainsetarr[mainsetarr[arr[i][1]]->root]->rank = newrank;
            node *temp = mainsetarr[arr[i][1]]->next;
            node *ptr = mainsetarr[arr[i][2]];
            mainsetarr[arr[i][1]]->next = mainsetarr[arr[i][2]];
            while (ptr->next != NULL)
            {
                ptr->root = mainsetarr[arr[i][1]]->root;
                ptr = ptr->next;
            }
            ptr->root = mainsetarr[arr[i][1]]->root;
            ptr->next = temp;
        }
        else
        {
            int newrank = mainsetarr[mainsetarr[arr[i][1]]->root]->rank + mainsetarr[mainsetarr[arr[i][2]]->root]->rank;
            mainsetarr[mainsetarr[arr[i][2]]->root]->rank = newrank;
            node *temp = mainsetarr[arr[i][2]]->next;
            node *ptr = mainsetarr[arr[i][1]];
            mainsetarr[arr[i][2]]->next = mainsetarr[arr[i][1]];
            while (ptr->next != NULL)
            {
                ptr->root = mainsetarr[arr[i][2]]->root;
                ptr = ptr->next;
            }
            ptr->root = mainsetarr[arr[i][2]]->root;
            ptr->next = temp;
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += matarr[i][j];
        }
    }
    cou sum;
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
