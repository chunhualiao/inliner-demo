const int a = 10;
int foo (int);

int
main ()
{
  int x = 1;
  {
    int x__2 = x;
    {
      x__2 *a;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
}

int
foo (int x)
{
  return x * a;
}
