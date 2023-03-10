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
class Queue{
    public:
    stack sta;
    void push(int x){
        sta.Push(x);
    }
    void pop(){
        stack temp1,temp2;
        while(sta.isempty()==0 && sta.size()!=1){
            temp1.Push(sta.peek());
            sta.Pop();
        }
        if(sta.isempty()){
            cout<<"empty"<<endl;
        }
        else cout<<sta.peek()<<endl;
        while(temp1.isempty()==0){
            temp2.Push(temp1.peek());
            temp1.Pop();
        }
        sta=temp2;
    }
};
int main()
{
  Queue meta;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        if (s == "push")
        {
            int k;
            cin >> k;
            meta.push(k);
        }
        else
            meta.pop();
    }
    return 0;
}

