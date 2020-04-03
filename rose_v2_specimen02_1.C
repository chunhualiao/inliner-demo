
int
foo (int x)
{
  return x + 3;
}

int
main (int, char **)
{
  int w = 7;
  {
    {
      w = 7 + 3;
      goto rose_inline_end__3;
    }
  rose_inline_end__3:
    ;
  }
  return 0;
}
