// This test code is a combination of pass1 and pass7, selected somewhat randomly
// from Jeremiah's test code of his inlining transformation from summer 2004.
int x = 0;
// Function it increment "x"

void
incrementX ()
{
  x++;
}

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
  {
    x++;
  }
  {
    x++;
  }
// Something more interesting to inline
  for (; true;)
    {
      int rose_temp__7;
      {
	int a = 0;
	while (a < 5)
	  {
	    ++a;
	  }
	{
	  rose_temp__7 = a + 3;
	  goto rose_inline_end__6;
	}
      rose_inline_end__6:
	;
      }
      bool rose__temp = (bool) (rose_temp__7 < 7);
      if (!rose__temp)
	{
	  break;
	}
      else
	{
	}
      {
	x++;
      }
    }
  return 0;
}
