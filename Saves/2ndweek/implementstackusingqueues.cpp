#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
  queue<int> sta;

  void push(int x) { sta.push(x); }
  void size() { cout << sta.size() << endl; }
  void top()
  {
    if (sta.empty() == true)
    {
      cout << -1 << endl;
    }
    else
      cout << sta.back() << endl;
  }
  void isempty() { cout << (sta.empty()) << endl; }
  void pop()
  {
    queue<int> tempsta;
    for (auto i = 0; i < sta.size() - 1; i++)
    {
      if (sta.empty() == 1)
      {
        cout << 
stack
is
empty << endl;
        return;
      }
      else
      {
        tempsta.push(sta.front());
        sta.pop();
      }
    }
    sta = tempsta;
  }
};
int main()
{
  Stack meta;
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;

    if (s == push)
    {
      int k;
      cin >> k;
      meta.push(k);
    }
    else if (s == pop)
      meta.pop();
    else if (s == top)
      meta.top();
    else if (s == isempty)
      meta.isempty();
    else
      meta.size();
  }
  return 0;
}

