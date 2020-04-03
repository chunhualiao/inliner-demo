
void
foo (int &x)
{
  ++x;
}

int
main (int, char **)
{
  int w = 7;
  {
    int &x__2 = w;
    ++x__2;
  rose_inline_end__3:
    ;
  }
  return (!(w == 8));
}
