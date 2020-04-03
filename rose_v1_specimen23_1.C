#include <vector>
typedef int Index_t;
struct Domain
{
// non-reference type

  inline Index_t numNode ()
  {
    return (this)->m_numNode;
  }

  inline void AllocateNodeElemIndexes ()
  {
    Index_t rose_temp__3;
    {
      struct Domain *this__1 = this__1;
      {
	rose_temp__3 = this__1->m_numNode;
	goto rose_inline_end__2;
      }
    rose_inline_end__2:
      ;
    }
    Index_t numNode = rose_temp__3;
  }
#if 0				// the best inline result should look like the following
// call site 1 inlined
#endif
  Index_t m_numNode;
}

domain;
