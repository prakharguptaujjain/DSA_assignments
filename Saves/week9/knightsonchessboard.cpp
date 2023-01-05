#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ll> vi;
typedef vector<pair<int, int>> pi;
#define pb push_back
#define mp make_pair
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
void swap(int arr[8][3], int a, int b)
{
    int temp = arr[a][0];
    int temp1 = arr[a][1];
    int temp2 = arr[a][2];
    arr[a][0] = arr[b][0];
    arr[a][1] = arr[b][1];
    arr[a][2] = arr[b][2];
    arr[b][0] = temp;
    arr[b][1] = temp1;
    arr[b][2] = temp2;
}
int partition(int arr[8][3], int s, int e)
{
    int pivot = arr[e][0];
    int fi;
    fi = s - 1;
    for (int i = s; i <= e - 1; i++)
    {
        if (arr[i][0] < pivot)
        {
            fi++;
            swap(arr, fi, i);
        }
    }
    swap(arr, fi + 1, e);
    return fi + 1;
}
void quicksort(int arr[8][3], int s, int e)
{
    if (s < e)
    {
        int t = partition(arr, s, e);
        quicksort(arr, s, t - 1);
        quicksort(arr, t + 1, e);
    }
}
class node
{
public:
    int C, D, dist;
};
class Queue
{
public:
    node *arr[900000];
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
};
node *retrieve(int i, int C, int D, int dist, int e, int f)
{
    node *ret = new (node);
    int arr[8][3];

    arr[0][1] = C + 2;
    arr[0][2] = D + 1;
    // arr[0][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[1][1] = C + 1;
    arr[1][2] = D + 2;
    // arr[1][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[2][1] = C - 1;
    arr[2][2] = D + 2;
    // arr[2][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[3][1] = C - 2;
    arr[3][2] = D + 1;
    // arr[3][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[4][1] = C - 2;
    arr[4][2] = D - 1;
    // arr[4][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[5][1] = C - 1;
    arr[5][2] = D - 2;
    // arr[5][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[6][1] = C + 1;
    arr[6][2] = D - 2;
    // arr[6][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[7][1] = C + 2;
    arr[7][2] = D - 1;
    // arr[7][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);
    // quicksort(arr,0,7);
    ret->C = arr[i][1];
    ret->D = arr[i][2];
    ret->dist = dist + 1;

    return ret;
}
node *retrieveq(int i, int C, int D, int dist, int e, int f)
{
    node *ret = new (node);
    int arr[8][3];

    arr[0][1] = C + 2;
    arr[0][2] = D + 1;
    // arr[0][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[1][1] = C + 1;
    arr[1][2] = D + 2;
    // arr[1][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[2][1] = C - 1;
    arr[2][2] = D + 2;
    // arr[2][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[3][1] = C - 2;
    arr[3][2] = D + 1;
    // arr[3][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[4][1] = C - 2;
    arr[4][2] = D - 1;
    // arr[4][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[5][1] = C - 1;
    arr[5][2] = D - 2;
    // arr[5][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[6][1] = C + 1;
    arr[6][2] = D - 2;
    // arr[6][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);

    arr[7][1] = C + 2;
    arr[7][2] = D - 1;
    // arr[7][0] = pow((arr[0][1] - e), 2) + pow((arr[0][2] - f), 2);
    quicksort(arr, 0, 7);
    ret->C = arr[i][1];
    ret->D = arr[i][2];
    ret->dist = dist + 1;

    return ret;
}
int cnt = 0;

void bfs(int a, int b, int C, int D, int e, int f, int dist, int visited[501][501])
{
    Queue q;
    node *root = new (node);
    root->C = C;
    root->D = D;
    root->dist = dist;
    q.push(root);
    while (!q.isempty())
    {
        node *o = q.front();
        q.pop();
        cnt++;
        if (!(o->C < 0 || o->D < 0 || o->C > a || o->D > b))
        {
            if (!(visited[o->C][o->D]))
            {
                visited[o->C][o->D] = 1;

                if (o->C == e && o->D == f)
                {
                    cout << o->dist << endl;
                    exit(0);
                }
                // if( pow((o->C - e), 2) + pow((o->D - f), 2)>=400)
                // for (int i = 0; i < 2; i++)
                // {
                //     q.push(retrieveq(i, o->C, o->D, o->dist,e,f));
                // }
                // else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        q.push(retrieve(i, o->C, o->D, o->dist, e, f));
                    }
                }
            }
        }
    }
}

void solve()
{
    int a, b, C, D, e, f;
    ci a c b c C c D c e c f;
    int dist = 0;
    if (C == D && e == f && C<e)
    {
        while (abs(C - e) > 32)
        {
            C += 3;
            D += 3;
            dist += 2;
        }
    }
    int visited[501][501];
    for (int i = 0; i <= 500; i++)
    {
        for (int j = 0; j <= 500; j++)
        {
            visited[i][j] = 0;
        }
    }

    bfs(a, b, C, D, e, f, dist, visited);
    cou - 1;
    return;
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
