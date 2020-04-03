
int
foo (int i)
{
  return 5 + i;
}

int
main (int, char **)
{
  int rose_temp__4;
  {
    {
      rose_temp__4 = 5 + 1;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  int rose_temp__8;
  {
    {
      rose_temp__8 = 5 + 2;
      goto rose_inline_end__7;
    }
  rose_inline_end__7:
    ;
  }
  int w = rose_temp__4 + rose_temp__8;
  return w;
}
