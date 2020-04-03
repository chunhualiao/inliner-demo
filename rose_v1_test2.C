// a function with a return
extern int x;

int
incrementX ()
{
  x++;
  return x;
}

int
main ()
{
  {
    x++;
    {
      x;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  return x;
}
