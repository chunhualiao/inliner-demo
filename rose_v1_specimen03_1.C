
int
foo ()
{
  return 7;
}

int
main (int, char **)
{
  {
    bool rose__temp2 = true;
    int rose_temp__3;
    {
      {
	rose_temp__3 = 7;
	goto rose_inline_end__2;
      }
    rose_inline_end__2:
      ;
    }
    rose__temp2 = ((bool) (rose_temp__3 == 9));
    if (rose__temp2)
      return 1;
    else
      return 0;
  }
}
