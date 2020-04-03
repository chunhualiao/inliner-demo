
int
foo ()
{
  int a = 0;
  while (a < 5)
    {
      ++a;
    }
  return a + 3;
}

int
main (int, char **)
{
  int rose_temp__3;
  {
    int a = 0;
    while (a < 5)
      {
	++a;
      }
    {
      rose_temp__3 = a + 3;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  for (int x = rose_temp__3; false;)
    {
    }
  return 0;
}
