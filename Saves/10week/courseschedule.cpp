#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ll> vi;
typedef vector<pair<int,int>> pi;
#define pb push_back
#define mp make_pair
#define e cout<<endl;
#define r return;
#define er cout<<endl; return;
#define re cout<<endl; return;
#define ff first
#define ss second
#define hi cout<<"HI";
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define ci cin>>
#define c >>
#define cou cout<<
#define co <<
#define des greater<int>()
#define sorted(v) sort(v.begin(),v.end())
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define f(a, c) for (int a = 0; a < c; a++)
#define fi(i,dat) for (auto i = dat.begin();i!=dat.end();++i)
#define endl "\n"
#define nl NULL
// std::cout << std::fixed;
// std::cout << std::setprecision(10);

bool sortbyCond(const pair<int, int>& a,const pair<int, int>& b) //first element by ascending and second by descending
{
if (a.first != b.first)
return (a.first < b.first); 
else
return (a.second > b.second);
}
string get_str()
{
    string s;
    getline(cin,s);
    return s;
}
int binarysearch(v64 & arr,ll n,ll k)
    {
    ll ct = -1;
    for (ll b = n;b>=1;b/=2)
    {
        while(ct + b <n && arr[ct+b]<=k) ct+=b;
    }
    return ct;
}
template<typename T>
void inp_vec(vector<T> &vec,ll n)
{
    T tmp;
    f(i,n)
    {
        cin>>tmp;
        vec.pb(tmp);
    }
}
v64 stov(string &s)
{
    v64 res;
    fi(i,s)
    {
        res.pb((ll)(*i-'0'));
    }
    return res;
}
vector<bool> seive_eratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
 
    }
    return sieve;
}



class Queue
{
public:
    int arr[9999];
    int start = 0;
    int end = -1;

    void push(int x)
    {
        end++;
        arr[end] = x;
    }
    void pop()
    {
        if(isempty()){
            cout<<"queue is empty"<<endl;
        }
        else start++;
    }
    int front()
    {
        if(isempty()){
            return -1;
        }
        return arr[start];
    }
    int back()
    {if(isempty()){
            return -1;
        }
        return arr[end];
    }
    int size()
    {
        return end-start + 1;
    }
    bool isempty()
    {
        if (end-start + 1)
            return 0;
        else
            return 1;
    }
};
void solve()
{
    int n,m;ci n c m;
    int arr[n];
    bool atleastone=false;
    for (int i = 0; i < n; i++)
    {
        arr[i]=1;
    }
    int matarr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matarr[i][j]=0;
        }
    }
    int marr[m][2];
    for (int i = 0; i < m; i++)
    {
        int x,y;ci x c y;
        marr[i][0]=x-1;
        marr[i][1]=y-1;
        matarr[x-1][y-1]=1;
        matarr[y-1][x-1]=1;
        arr[y-1]=0;
    }
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1){
            index=i;
            atleastone=true;
            break;
        }
    }
    if(atleastone==false){
        cout<<"No"<<endl;
        return;
    }
    Queue q;
    q.push(index);
    while(!q.isempty()){
        int x=q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if(matarr[x][i]==1){
                q.push(i);
                matarr[x][i]=0;
                matarr[i][x]=0;
                arr[i]=1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=1)
    
    {
        cout<<"No"<<endl;r
    }
    }
    cou "Yes";er

}


int main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("output.txt","w",stderr);
#endif
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}

