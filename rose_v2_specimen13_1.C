#include <stdlib.h>

int
foo ()
{
  exit (1);
  return 0;
}

int
main (int, char **)
{
  int w;
  if (7 == 8)
    {
      int rose_temp__4;
      {
	exit (1);
	{
	  rose_temp__4 = 0;
	  goto rose_inline_end__2;
	}
      rose_inline_end__2:
	;
      }
      w = rose_temp__4;
    }
  else
    {
      w = 0;
    }
  return w;
}
