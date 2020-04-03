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
  }
  incrementXInOtherFile ();
  return 0;
}
