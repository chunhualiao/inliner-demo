
int
foo (int x)
{
  return x + 3;
}

int
bar (int y)
{
  int rose_temp__4;
  {
    int x__2 = y;
    {
      rose_temp__4 = x__2 + 3;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  int rose_temp__8;
  {
    int x__6 = 2;
    {
      rose_temp__8 = x__6 + 3;
      goto rose_inline_end__7;
    }
  rose_inline_end__7:
    ;
  }
  return rose_temp__4 + rose_temp__8;
}

int
main (int, char **)
{
  int w;
  {
    int y__10 = 1;
    int rose_temp__4;
    {
      int x__2 = y__10;
      {
	rose_temp__4 = x__2 + 3;
	goto rose_inline_end__3__1;
      }
    rose_inline_end__3__1:
      ;
    }
    int rose_temp__8;
    {
      int x__6 = 2;
      {
	rose_temp__8 = x__6 + 3;
	goto rose_inline_end__7__2;
      }
    rose_inline_end__7__2:
      ;
    }
    {
      w = rose_temp__4 + rose_temp__8;
      goto rose_inline_end__11;
    }
  rose_inline_end__11:
    ;
  }
  return 0;
}
