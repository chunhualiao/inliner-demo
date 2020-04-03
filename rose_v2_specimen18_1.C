
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
    ++w;
  }
  return (!(w == 8));
}
