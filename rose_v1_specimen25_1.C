template < typename T > void
swap (T & x, T & y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

int
foo (int a, int b)
{
  {
    int &x__2 = a;
    int &y__3 = b;
    int tmp = x__2;
    x__2 = y__3;
    y__3 = tmp;
  rose_inline_end__4:
    ;
  }
}

int
main ()
{
}
