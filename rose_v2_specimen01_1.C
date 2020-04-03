
int
foo ()
{
  return 5;
}

int
main (int, char **)
{
  int w;
  {
    {
      w = 5;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  return (!(w == 5));
}
