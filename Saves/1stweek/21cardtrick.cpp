#include <iostream>
using namespace std;

void Distribute(int arr[]){
  int temp[21];
  for (int i = 0; i < 21; i++)
  {
    temp[i]=arr[i];
  }
  for (int i = 0; i < 7; i++)
  {
    arr[i]=temp[3*i];
    arr[i+7]=temp[3*i+1];
    arr[i+14]=temp[3*i+2];
  }
}
void pilePrinter(int arr[], int x)
{
  int temp[21];
  for (int i = 0; i < 21; i++)
  {
    temp[i]=arr[i];
  }
  int z;
  if(x==1){z=2;}
  else{z=1;}
int e=6-x-z;
  {
    int ki=0;
    for (int i = 0; i < 7; i++)
    {
      arr[ki]=temp[7*(z-1)+i];
      ki++;
    }
    for (int i = 0; i < 7; i++)
    {
      arr[ki]=temp[(x-1)*7+i];
      ki++;
    }
    for (int i = 0; i < 7; i++)
    {
      arr[ki]=temp[(e-1)*7+i];
      ki++;
    }
  }
  for (int i = 0; i < 21; i++)
  {
    cout<<arr[i]<<
;
  }
  cout<<endl;
  }
int main()
{
  int arr[21];
  for (int i = 0; i < 21; i++)
  {
    cin>>arr[i];
  }
  int t;
  cin>>t;
  for (int i=0;i<3;i++){  Distribute(arr);
  int numdistribute;
  for (int i = 0; i < 21; i++)
  {
    if(arr[i]==t){
      numdistribute=int(i/7)+1;
      break;
    }
  }
  pilePrinter(arr, numdistribute);
  }
  
  return 0;
}
