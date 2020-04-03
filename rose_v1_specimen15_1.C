#include <stdlib.h>

bool
foo ()
{
  exit (1);
  return false;
}

int
main (int, char **)
{
  bool x;
  if (true)
    {
      x = true;
    }
  else
    {
      bool rose_temp__4;
      {
	exit (1);
	{
	  rose_temp__4 = false;
	  goto rose_inline_end__2;
	}
      rose_inline_end__2:
	;
      }
      x = rose_temp__4;
    }
  return 0;
}
