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
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};
void insert(node *head, int x)
{
    node *ptr = head;
    while (true)
    {
        if ((ptr->data) > (x))
        {
            if (ptr->left == NULL)
                break;
            ptr = ptr->left;
        }

        else
        {
            if (ptr->right == NULL)
                break;

            ptr = ptr->right;
        }
    }

    node *temp = new (node);
    temp->data = x;
    if (ptr->data > x)
        ptr->left = temp;
    else
        ptr->right = temp;
}
node *ca(node *root, int a, int b)
{
    node *ptr = root;
    while (((ptr->data) < a && (ptr->data) < b) || ((ptr->data) > a && (ptr->data) > b))
    {
        if (ptr->data > a)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return ptr;
}
int node2nodexor(node *root, int till)
{
    node *ptr = root;
    int sum = ptr->data;
    while (ptr->data != till)
    {
        if (ptr->data > till)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
        sum = sum ^ (ptr->data);
    }
    return sum;
}
void solve()
{
    int n,d;
    ci n ;
    int arr[n];
    ci d;
    arr[0]=d;
    node *root = new (node);
    root->data = d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d;
        arr[i+1]=d;
        insert(root, d);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        ci a c b;
        a=arr[a];
        b=arr[b];

        node *cac = ca(root, a, b);
        // if(cac->data==a || cac->data==b)
        // {
        // cout << ((node2nodexor(cac, a)) ^ (node2nodexor(cac, b)) );
        // }
        // else
        cout << ((node2nodexor(cac, a)) ^ (node2nodexor(cac, b)) ^ ((cac->data))^ ((cac->data)));
        e
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
    // cin >> t; // INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
