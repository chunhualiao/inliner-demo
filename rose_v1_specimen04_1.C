
int
foo ()
{
  return 7;
}

int
main (int, char **)
{
  while (true)
    {
      int rose_temp__3;
      {
	{
	  rose_temp__3 = 7;
	  goto rose_inline_end__2;
	}
      rose_inline_end__2:
	;
      }
      bool rose__temp = (bool) (rose_temp__3 == 9);
      if (!rose__temp)
	{
	  break;
	}
      else
	{
	}
      return 1;
    }
  return 0;
}
