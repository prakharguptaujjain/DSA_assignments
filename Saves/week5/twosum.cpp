#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> pi;
#define pb push_back
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
{public:
    int data;
    node *right = NULL;
    node *left = NULL;
};

int sum = 0;
void pathsum(node *root,int p)
{
    if(root==NULL)
    {
    return;

    }
    p+=root->data;
    sum=max(sum,p);
    pathsum(root->left,p);
    pathsum(root->right,p);

}

void solve()
{
    node *root=new(node);
    root->data=1;
    node *l=new(node);
    node *r=new(node);

    root->left=l;
    root->right=r;
    r->data=2;
    l->data=4;
    pathsum(root,0);
    cout<<sum;
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
