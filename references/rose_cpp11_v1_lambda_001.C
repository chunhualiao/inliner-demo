// The template function is already inlined.
// Next step is to inline the labmda expression
// Liao, 4/30/2020
//
// Compile this code
//    g++ -std=c++11  // GCC 4.9.x is tested.
namespace RAJA
{
typedef int Index_type;
}

void foo_input()
{
double *a = new double [15];
auto loop_body__4 =  [=] (int i)
{
 a[i] = 0.5;
};
{
#pragma novector
  for (RAJA::Index_type ii = 0; ii < 15; ++ii) {
    auto rose_temp__1 = loop_body__4;
    {
      auto *this__2 = &rose_temp__1;
      this__2 -> a[ii] = 0.5;
    }
  }
}
//After the translation: we want to have something like
for (int i = 0; i < 15; i++) {
a[i] = 0.5;
}
// not calling this to avoid including a header:   free(a);
}
