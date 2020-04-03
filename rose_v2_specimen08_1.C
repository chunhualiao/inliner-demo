
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
  int x = 0;
  for (; x < 7;)
    {
      {
      }
      {
	int a = 0;
	while (a < 5)
	  {
	    ++a;
	  }
	{
	  x = a + 3;
	  goto rose_inline_end__2;
	}
      rose_inline_end__2:
	;
      }
    }
  return 0;
}
