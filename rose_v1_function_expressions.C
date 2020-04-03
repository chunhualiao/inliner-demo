
int
foo (int i)
{
  return 5 + i;
}

int
main (int, char **)
{
  int w;
  int rose_temp__4;
  {
    int i__2 = 1;
    {
      rose_temp__4 = 5 + i__2;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  int rose_temp__8;
  {
    int i__6 = 2;
    {
      rose_temp__8 = 5 + i__6;
      goto rose_inline_end__7;
    }
  rose_inline_end__7:
    ;
  }
  w = rose_temp__4 + rose_temp__8;
  return w;
}
