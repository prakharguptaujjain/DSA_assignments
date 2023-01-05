#include <bits/stdc++.h>
using namespace std;

void solve()
{
    stack<int> lar;
    stack<int> rar;
    int n;
    cin >> n;
    int res[n];
       int res2[n];

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[i]=0;
        res2[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        if(lar.size()!=0){
            while(!lar.empty() && arr[lar.top()]<arr[i])lar.pop();
            if(!lar.empty())res[i]=lar.top();
            lar.push(i);

        }
        else lar.push(i);

    }

        for (int i = n-1; i>=0; i--)
{
        if(rar.size()!=0){
            while(!rar.empty() && arr[rar.top()]<arr[i])rar.pop();
            if(rar.size()!=0)res2[i]=rar.top();
            rar.push(i);

        }
        else rar.push(i);

    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<res2[i]<<" ";
    // }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
       ans=max(ans,res[i]*res2[i]);
    }
    cout<<ans;
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