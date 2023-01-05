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
// std::cout << std::fixed;
// std::cout << std::setprecision(10);
int precedence(string s)
{
    if (s == "^")
        return 3;
    else if (s == "*" || s == "/")
        return 2;
    else if (s == "+" || s == "-")
        return 1;
    else
        return 0;
}
float eval(float a, string s, float b)
{
    if (s == "*")
        return a * b;
    else if (s == "/")
        return a / b;
    else if (s == "-")
        return a - b;
    else
        return a + b;
}
void Ptoi(string s)
{
    int p = -1;
    // int ans = 0;
    stack<float> sta;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',' || i == (s.length() - 1))
        {
            if (i == (s.length() - 1))
                i++;
            string temp = s.substr(p + 1, i - p - 1);
            p = i;
            if (precedence(temp) == 3)
            {
                // string m = "";
                if ((!sta.empty()))
                {
                    float z = (sta.top()) * (sta.top());
                    sta.pop();
                    sta.push(z);
                }
                // sta.push(m);
            }
            else if (precedence(temp))
            {
                // string m = "";

                if ((!sta.empty()))
                {
                    // m += "(";

                    float t = sta.top();
                    sta.pop();
                    // cout << sta.top();
                    // m += sta.top();

                    // cout<<temp;
                    // m += temp;
                    // cout<<t;
                    // m += t;
                    float z = eval((sta.top()), temp, (t));

                    sta.pop();
                    // m += ")";
                    sta.push(z);
                }
            }

            else
                sta.push(stoi(temp));
        }
    }
    while (!sta.empty())
    {
        cout << setprecision(3)<< sta.top();
        sta.pop();
    }
    // cout<<ans;
}
void solve()
{
    string s;
    cin >> s;
    Ptoi(s);
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