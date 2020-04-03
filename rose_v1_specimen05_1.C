
int
foo ()
{
  return 7;
}

int
main (int, char **)
{
  {
    bool rose__temp1 = true;
    do
      {
	{
	  return 0;
	}
      rose_label__3:
	{
	}
	int rose_temp__4;
	{
	  {
	    rose_temp__4 = 7;
	    goto rose_inline_end__2;
	  }
	rose_inline_end__2:
	  ;
	}
	rose__temp1 = ((bool) (rose_temp__4 == 9));
      }
    while (rose__temp1);
  }
  return 0;
}
