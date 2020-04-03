
int
foo (int x)
{
  return x + 7;
}

int
main (int, char **)
{
  int w;
  {
    int rose_temp__7;
    {
      int rose_temp__11;
      {
	{
	  rose_temp__11 = 5 + 7;
	  goto rose_inline_end__10;
	}
      rose_inline_end__10:
	;
      }
      {
	rose_temp__7 = rose_temp__11 + 7;
	goto rose_inline_end__6;
      }
    rose_inline_end__6:
      ;
    }
    {
      w = rose_temp__7 + 7;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  return 0;
}
