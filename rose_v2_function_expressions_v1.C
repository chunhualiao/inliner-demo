
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
    {
      w = 5 + 1;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  return w;
}
