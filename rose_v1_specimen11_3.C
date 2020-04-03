
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
	int x__9 = 5;
	{
	  rose_temp__11 = x__9 + 7;
	  goto rose_inline_end__10;
	}
      rose_inline_end__10:
	;
      }
      int x__5 = rose_temp__11;
      {
	rose_temp__7 = x__5 + 7;
	goto rose_inline_end__6;
      }
    rose_inline_end__6:
      ;
    }
    int x__2 = rose_temp__7;
    {
      w = x__2 + 7;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  return 0;
}
