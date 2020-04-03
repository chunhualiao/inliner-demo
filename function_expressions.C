int foo(int i) {
  return 5+i;
}

int main(int, char**) {
  int w;
  w = foo(1)+ foo(2);
  return w;
}
