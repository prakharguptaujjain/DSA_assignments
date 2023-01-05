#include <iostream>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define hi cout<<"HI";
#define des greater<int>()
#define ma(v) max_element(v.begin(), v.end())
#define mi(v) min_element(v.begin(), v.end())
#define rev(s) reverse(s.begin(), s.end())
#define endl "\n"
// std::cout << std::fixed;
// std::cout << std::setprecision(10);

class stack
{
public:
  int arr[9999];
  int cnt = -1;

  void Pop()
  {
    if (cnt >= 0)
    {
      cnt--;
    }
    else
      cout << "stackisempty" << endl;
  }
  void Push(int z)
  {
    cnt++;
    arr[cnt] = z;
  }
  int peek()
  {
    if (cnt >= 0)
      return arr[cnt];
    else
    {
      cout << 0 << endl;
      exit(0);
    }
    return 0;
  }
  int size()
  {
    return cnt + 1;
  }
  int isempty()
  {
    if (cnt < 0)
    {
      return 1;
    }
    else
      return 0;
  }
};
void solve()
{stack sta;
    string s;cin>>s;
    int i;
    for (i = 0; i < s.length()/2; i++)
    {
        sta.Push(s[i]);
    }
    if(s.length()%2==1)i++;
    {for ( i; i < s.length(); i++)
    {
        if(sta.peek()==s[i])
        sta.Pop();
        
    }
    

    }
    if(sta.isempty())cout<<1;
    else cout<<0;
    


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