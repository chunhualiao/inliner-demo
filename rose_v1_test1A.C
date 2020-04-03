int x = 1;
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
  incrementXInOtherFile ();
  return 0;
}
