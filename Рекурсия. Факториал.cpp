#include <iostream>
using namespace std;
int Fact ( int N )
{
  int F;   
  printf("input N= %d \n ", N);
  if ( N <= 1 ) F = 1;
  else F = N * Fact(N - 1);
  printf("output N= %d \n ", N);
  return F;
}
void main()
{
  int N;
  printf("Введите натуральное число: ");
  cin >> N;
  cout << Fact(N);
  cin.get(); cin.get();
}
