// Test suggested by Alin Jula
int x;

int
w ()
{
  ::x = 6;
  return 7;
}

int
main (int, char **)
{
  int rose_temp__3;
  {
    ::x = 6;
    {
      rose_temp__3 = 7;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  return (!(x == 6 && rose_temp__3 == 7));
}
