
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
    {
      rose_temp__4 = y + 3;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  int rose_temp__8;
  {
    {
      rose_temp__8 = 2 + 3;
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
    int rose_temp__4;
    {
      {
	rose_temp__4 = 1 + 3;
	goto rose_inline_end__3__1;
      }
    rose_inline_end__3__1:
      ;
    }
    int rose_temp__8;
    {
      {
	rose_temp__8 = 2 + 3;
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
