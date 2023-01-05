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
#define f(a, cl) for (int a = 0; a < cl; a++)
#define fi(i, dat) for (auto i = dat.begin(); i != dat.end(); ++i)
#define endl "\n"
#define nl NULL
class node
{
public:
    int data;
    int index;
    node *next = NULL;
};
node *nodeaddr(int j, int data)
{
    node *temp = new (node);
    temp->index = j;
    temp->data = data;
    return temp;
}
void Dijkstra(int arr[][3], int n, int m)
{
   node ** matarr = new node*[n];
   for (int i = 0; i < n; i++)
    {
        matarr[i] = new node;
    }
    // node *matarr=new(node[n]);

    f(i, n)
    {
        matarr[i]->data = INT_MAX;
        matarr[i]->index = i;
        matarr[i]->next = NULL;
    }
    f(i, m)
    {
        node *temp = nodeaddr(arr[i][0], arr[i][2]);
        node* motemp=(matarr[arr[i][1]])->next ;
        (matarr[arr[i][1]])->next = temp;
        temp->next=motemp;

        node *tempo = nodeaddr(arr[i][1], arr[i][2]);
        node* motempo=(matarr[arr[i][0]])->next ;
        (matarr[arr[i][0]])->next = tempo;
        tempo->next=motempo;
    }
    cout<<"";

    int k;
    ci k;
    int karr[k];
    f(i, k)
    {
        int t;
        ci t;
        karr[i] = t - 1;
    }
    int q;
    ll s = 0;
    ci q;
    int qarr[q];
    f(i, q)
    {
        int t;
        ci t;
        qarr[i] = t - 1;
    }
    bool mainset[n];
    int dist[n];
    f(i, n)
    {
        mainset[i] = false;
        dist[i] = INT_MAX;
    }
    f(i, k)
    {
        dist[karr[i]] = 0;
        mainset[karr[i]] = true;
        matarr[karr[i]]->data = 0;
        
    }
    f(i, k)
    {
        int z = karr[i];
        {
            node *ptr = matarr[z];
            while (ptr != NULL)
            {

                dist[ptr->index] = min(dist[ptr->index], ptr->data);
                ptr = ptr->next;
            }
        }
    }
    for (int i = 0; i < n - k; i++)
    {
        int min = INT_MAX;
        int min_index = 0;
        f(j, n)
        {
            if (mainset[j] == false && dist[j] <= min)
            {
                min = dist[j];
                min_index = j;
            }
        }
        mainset[min_index] = true;
        node *ptr = matarr[min_index];
        while (ptr != NULL)
        {
            if (!mainset[ptr->index] && dist[min_index] != INT_MAX && dist[min_index] + ptr->data < dist[ptr->index])
            {
                dist[ptr->index] = dist[min_index] + ptr->data;
            }
            ptr=ptr->next;
        }
    }
    f(i, q)
    {
        if (dist[qarr[i]] != INT_MAX)
            s += dist[qarr[i]];
        else
            s -= 1;
    }

    cout<< s;
}

void solve()
{
    int n, m;
    ci n c m;
    int arr[m][3];
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        ci x c y c z;
        arr[i][0] = x - 1;
        arr[i][1] = y - 1;
        arr[i][2] = z;
    }
    Dijkstra(arr, n, m);
}

int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("output.txt","w",stderr);
#endif
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
