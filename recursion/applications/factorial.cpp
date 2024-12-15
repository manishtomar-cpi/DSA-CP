#include <iostream>
using namespace std;

int fact(int n)
{
  if (n < 0)
  {
    return -1;
  }
  if (n == 0)
  {
    return 1; // base case
  }
  return fact(n - 1) * n;
}

// int fact(int n){
//   if(n==0){
//     return 1;
//   }
//   int small = fact(n-1);
//   return n*small;
// }
/*
Calling Phase:

          fact(3)
           /   \
          3     fact(2)
                 /   \
                2     fact(1)
                       /   \
                      1     fact(0)
                             |
                             1 (Base Case)

Returning Phase:

          fact(3)
         (3 * 2 = 6)
           /   \
          3     fact(2)
               (2 * 1 = 2)
                 /   \
                2     fact(1)
                     (1 * 1 = 1)
                       /   \
                      1     fact(0)
                             |
                             1 (Base Case)

*/

int main()
{
  int x = 3;

  cout << fact(x) << endl;

  return 0;
}