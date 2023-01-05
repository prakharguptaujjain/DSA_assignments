#include <iostream>
using namespace std;

void pileprinter(int arr[], int temp[], int *kipointer, int p)
{
       for (int i = 0; i < 9; i++)
       {
              arr[*kipointer] = temp[9 * (p - 1) + i];
              (*kipointer)++;
       }
}
void Distribute(int arr[])
{
       int temp[27];
       for (int i = 0; i < 27; i++)
       {
              temp[i] = arr[i];
       }
       for (int i = 0; i < 9; i++)
       {
              arr[i] = temp[3 * i];
              arr[i + 9] = temp[3 * i + 1];
              arr[i + 18] = temp[3 * i + 2];
       }
}
int posdistribute(int arr[],int t){
    for (int i = 0; i < 27; i++){
              if (arr[i] == t)
                     return (int(i / 9) + 1);
        
            }
       }
void pileprintershortner(int arr[],int temp[],int *ki,int a,int b,int c){
    pileprinter(arr, temp, ki, a);
    pileprinter(arr, temp, ki, b);
    pileprinter(arr, temp, ki, c);
}
void pilePrinter(int arr[], int x, int positioner)
{
       int temp[27];
       for (int i = 0; i < 27; i++)
       {
              temp[i] = arr[i];
       }
       int z;
       if(x==1)z=2;
       else z=1;
       int e = 6 - x - z;
       {
              int ki = 0;
              if (positioner == 1)
              {
                     pileprintershortner(arr, temp, &ki, x,z,e);
              }
              else if (positioner == 2)
              {  pileprintershortner(arr, temp, &ki, z,x,e);
              }
              else
              {
                     pileprintershortner(arr, temp, &ki,z,e,x);
              }
       }
       for (int i = 0; i < 27; i++)
       {
              cout << arr[i] << 
;
       }
       cout<<endl;
}
int main()
{
       int arr[27];
       for (int i = 0; i < 27; i++)
       {
cin>>arr[i];
       }
       int number,t;
       cin >>t>> number;
       number--;
       int z[3];
       int k=9;
       for (int i=2;i>=0;i--){
           z[i]=int(number/k);
           number-=z[i]*k;
           k/=3;
       }
       for(int i=0;i<3;i++){
           Distribute(arr);
           int posidistribute=posdistribute(arr,t);
           pilePrinter(arr, posidistribute, z[i]+1);}
       return 0;
}

