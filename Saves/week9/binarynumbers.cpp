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
class Queue
{
public:
    string arr[1000];
    int start = 0;
    int end = -1;

    void push(string x)
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
    string front()
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
};
int n;

long long int sti(string s,int n)
{
    long long int sum = 0;
    for (long long int i = 0; i < s.length(); i++)
    {
        sum += pow(10, i) * (s[s.length() - i - 1]-'0');
        sum=sum%n;
    }
    return sum;
}
void recurs(string s,int n)
{
    Queue q;
    q.push(s);
    while (!q.isempty())
    {
        string o = q.front();
        
        q.pop();
        if (sti(o,n) % n == 0)
        {
            cou o;
            exit(0);
        }
        q.push(o + "1");
        q.push(o + "0");
    }
}
void solve()
{
    ci n;
    if(n==0){cout<<"0";return;}
    if(n==1){cout<<"1";return;}
    recurs("1",n);
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
