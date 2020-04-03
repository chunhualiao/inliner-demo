int x;

int
w ()
{
  ::x = 5;
  {
    ::x = 6;
    int x;
    x = 7;
  }
  int x;
  x = 8;
  return x;
}

int
main (int, char **)
{
  int rose_temp__3;
  {
    ::x = 5;
    {
      ::x = 6;
      int x;
      x = 7;
    }
    int x;
    x = 8;
    {
      rose_temp__3 = x;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  int z = rose_temp__3;
  return (!(x == 6 && z == 8));
}
