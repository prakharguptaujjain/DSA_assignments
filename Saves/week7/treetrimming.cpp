#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> pi;
#define pb push_back
#define mp make_pair
#define e cout << endl;
#define ff first
#define ss second
#define hi cout << "HI";
#define des greater<int>()
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define endl "\n"
#define nl NULL
// std::cout << std::fixed;
// std::cout << std::setprecision(10);

class node
{
    int data;
    node *next = NULL;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1 || n == 0 || n == 2)
        return;
    int grapharr[n], nodesarr1[n];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        grapharr[i] = nodesarr1[i] = 0;
    }
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        grapharr[i]=
    }
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
