// a function with a return
extern int x;


int incrementX()
{
  x++;
  return x; 
}

int main()
{
  incrementX();
  return x;
}
