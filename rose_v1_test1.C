extern int x;
void incrementXInOtherFile ();

void
incrementX ()
{
  x++;
}

int
main ()
{
  {
    x++;
  rose_inline_end__2:
    ;
  }
  {
    x++;
  rose_inline_end__4:
    ;
  }
  return x;
}
