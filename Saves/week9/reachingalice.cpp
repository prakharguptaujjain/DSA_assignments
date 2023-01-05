#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<ll> vi;
typedef vector<pair<int,int>> pi;
#define pb push_back
#define mp make_pair

#define r return;
#define er cout<<endl; return;
#define re cout<<endl; return;
#define ff first
#define ss second
#define hi cout<<"HI";
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

void swap(auto arr,int a,int b)
{
    int temp=arr[a][0];
    int temp1=arr[a][1];
    arr[a][0]=arr[b][0];
    arr[a][1]=arr[b][1];
    arr[b][0]=temp;
    arr[b][1]=temp1;

}
int partition (auto arr,int s,int e){
    int pivot = arr[e][0];
    int fi;
    fi=s-1;
    for (int i = s; i <= e-1; i++)
    {
        if(arr[i][0]<pivot){
        fi++;swap(arr,fi,i);
        }
    }
    swap(arr,fi+1,e);
    return fi+1;
    
}
void quicksort(auto arr,int s,int e){
    if(s<e){
        int t=partition(arr,s,e);
        quicksort(arr,s,t-1);
        quicksort(arr,t+1,e);

    }

}


void solve()
{
    int n,m,k;ci n c m c k;
    int arr[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }

int nearr[m][2];
for (int i = 0; i < m; i++)
{
    int a,b;ci a c b;
    int tempa=min(a,b);
    int tempb=max(a,b);

nearr[i][0]=tempa;
nearr[i][1]=tempb;
}
quicksort(nearr,0,n-1);
for (int i = 0; i < m; i++)
{
    if(nearr[i][0]==1)
    {
        arr[nearr[i][1]]=1;
        continue;
    }
    if(arr[nearr[i][0]]==1 && nearr[i][0]!=k)
    {
        arr[nearr[i][1]]=1;
    }
}
if(arr[n]==1)
{
    cout<<1;
}
else
{
    cout<<0;

}

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

