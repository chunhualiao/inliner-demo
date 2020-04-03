int x;

int
w ()
{
  ::x = 5;
  {
    ::x = 6;
  }
  return 8;
}

int
main (int, char **)
{
  int rose_temp__3;
  {
    ::x = 5;
    {
      ::x = 6;
    }
    {
      rose_temp__3 = 8;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  return (!(x == 6 && rose_temp__3 == 8));
}
