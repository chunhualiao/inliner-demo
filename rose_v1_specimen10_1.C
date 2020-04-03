
struct w
{
  int data;


  inline w (int data, int dog):data (data)
  {
  }
}
 ;

int
foo ()
{
  return 7;
}

int
main (int, char **)
{
  int rose_temp__3;
  {
    {
      rose_temp__3 = 7;
      goto rose_inline_end__2;
    }
  rose_inline_end__2:
    ;
  }
  struct w zzz (rose_temp__3, 9);
  return (!(zzz.data == 7));
}
