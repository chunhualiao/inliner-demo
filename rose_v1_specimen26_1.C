#include<iostream>
using namespace std;
// better choice
//template <class T>
template < typename T > T GetMax (T a, T b)
{
  T result;
  result = (a > b) ? a : b;
  return (result);
}

int
main ()
{
  int i = 5;
  int j = 6;
  int k;
  long l = 10;
  long m = 5;
  long n;
  {
    int a__2 = i;
    int b__3 = j;
    int result;
    result = (a__2 > b__3 ? a__2 : b__3);
    {
      k = result;
      goto rose_inline_end__4;
    }
  rose_inline_end__4:
    ;
  }
  {
    long a__6 = l;
    long b__7 = m;
    long result;
    result = (a__6 > b__7 ? a__6 : b__7);
    {
      n = result;
      goto rose_inline_end__8;
    }
  rose_inline_end__8:
    ;
  }
  (std::cout << k) << std::endl;
  (std::cout << n) << std::endl;
  return 0;
}
