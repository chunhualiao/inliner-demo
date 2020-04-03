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
  }
  {
    x++;
  }
  return x;
}
