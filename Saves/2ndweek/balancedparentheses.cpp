#include <iostream>
using namespace std;

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
      cout << 
stack
is
empty << endl;
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
  void isempty()
  {
    if (cnt < 0)
    {
      cout << 1 << endl;
    }
    else
      cout << 0 << endl;
  }
};

int main()
{
  stack meta;
  string s;
  cin >> s;
  for (char c : s)
  {
    if (c == '{')
      meta.Push(1);
    else if (c == '[')
      meta.Push(2);
    else if (c == '(')
      meta.Push(3);
    else if (c == '}')
    {
      if (meta.peek() != 1)
      {
        cout << 0 << endl;
        return 0;
      }
      meta.Pop();
    }

    else if (c == ']')
    {
      if (meta.peek() != 2)
      {
        cout << 0 << endl;
        return 0;
      }
      meta.Pop();
    }
    else if (c == ')')
    {
      if (meta.peek() != 3)
      {
        cout << 0 << endl;
        return 0;
      }
      meta.Pop();
    }
  }
  if (meta.size() == 0)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}

