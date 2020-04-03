
int
foo (int i)
{
  return 5 + i;
}

int
main (int, char **)
{
  int w;
  {
    int i__2 = 1;
    {
      w = 5 + i__2;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  return w;
}
