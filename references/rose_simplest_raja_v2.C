// Simplest RAJA example code
// to explore the feasible of building a ROSE-based RAJA lowering tool.
//
// Liao, 3/27/2019
//
// Compile this code
//    g++ -std=c++11  // GCC 4.9.x is tested.
//----------- begin of minimal jara.h
namespace RAJA
{
  typedef int Index_type;
  // new specialized policy
  // input code , template 1
  template < typename EXEC_POLICY_T,
           typename LOOP_BODY >
             void forall ( Index_type begin, Index_type end,
                 LOOP_BODY loop_body )
             {
               forall ( EXEC_POLICY_T ( ),
                   begin, end,
                   loop_body );
             }
  // some prebuilt policies
  // the type for specialization

  struct seq_exec 
  {
  }
  ;
  // Some prebuilt specialization for sequential and parallel executions
  template < typename LOOP_BODY >
    void forall ( seq_exec,
        Index_type begin, Index_type end,
        LOOP_BODY loop_body )
    {
      ;
#pragma novector
      for ( Index_type ii = begin; ii < end; ++ ii ) {
        loop_body ( ii );
      }
      ;
    }
  // end namespace
}
//----------------------------------end of min raja.h
// Input RAJA code
// --------------------------------

void foo_input()
{
  double *a = new double [15];
  {
    auto loop_body__4 =  [=] (int i)
    {
      a[i] = 0.5;
    };
    {
      struct RAJA::seq_exec __7 = RAJA::seq_exec ();

#pragma novector
      for (RAJA::Index_type ii = 0; ii < 15; ++ii) {
        loop_body__4 (ii);
      }
    }
  }
  //After the translation: we want to have something like
  for (int i = 0; i < 15; i++) {
    a[i] = 0.5;
  }
  // not calling this to avoid including a header:   free(a);
}

int main()
{
  foo_input();
 return 0;
}
