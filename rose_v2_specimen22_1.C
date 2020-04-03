const int a = 10;
int foo (int);

int
main ()
{
  {
    {
      1 *a;
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
