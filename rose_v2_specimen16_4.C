
double
abs (double x)
{
  if (x > 0)
    return x;
  else
    return -x;
}

double
vec_norm1 (double *v, int x)
{
  double sum = 0;
  for (int i = 0; i < x; ++i)
    {
      double rose_temp__4;
      {
	double x__2 = v[i];
	if (x__2 > 0)
	  {
	    rose_temp__4 = x__2;
	    goto rose_inline_end__3;
	  }
	else
	  {
	    rose_temp__4 = -x__2;
	    goto rose_inline_end__3;
	  }
      rose_inline_end__3:
	;
      }
      sum += rose_temp__4;
    }
  return sum;
}

#if 1

double
mat_norm1 (double *v, int m, int n)
{
  double norm = -1. / 0;
  for (int i = 0; i < n; ++i)
    {
      double rose_temp__9;
      {
	double *v__6 = v + i * m;
	double sum = 0;
	for (int i = 0; i < m; ++i)
	  {
	    double rose_temp__4;
	    {
	      double x__2 = v__6[i];
	      if (x__2 > 0)
		{
		  rose_temp__4 = x__2;
		  goto rose_inline_end__3__1;
		}
	      else
		{
		  rose_temp__4 = -x__2;
		  goto rose_inline_end__3__1;
		}
	    rose_inline_end__3__1:
	      ;
	    }
	    sum += rose_temp__4;
	  }
	{
	  rose_temp__9 = sum;
	  goto rose_inline_end__8;
	}
      rose_inline_end__8:
	;
      }
      double rose_temp__14;
      {
	double *v__11 = v + (n - i + 1) * m;
	double sum = 0;
	for (int i = 0; i < m; ++i)
	  {
	    double rose_temp__4;
	    {
	      double x__2 = v__11[i];
	      if (x__2 > 0)
		{
		  rose_temp__4 = x__2;
		  goto rose_inline_end__3__2;
		}
	      else
		{
		  rose_temp__4 = -x__2;
		  goto rose_inline_end__3__2;
		}
	    rose_inline_end__3__2:
	      ;
	    }
	    sum += rose_temp__4;
	  }
	{
	  rose_temp__14 = sum;
	  goto rose_inline_end__13;
	}
      rose_inline_end__13:
	;
      }
      norm = (rose_temp__9 > norm ? rose_temp__9 : norm);
    }
  return norm;
}

int
main (int, char **)
{
  double a[10][10];
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      a[i][j] = (i == j ? 1. : 0.);
  double rose_temp__20;
  {
    double *v__16 = &a[0][0];
    double norm = -1. / 0;
    for (int i = 0; i < 10; ++i)
      {
	double rose_temp__9;
	{
	  double *v__6 = v__16 + i * 10;
	  double sum = 0;
	  for (int i = 0; i < 10; ++i)
	    {
	      double rose_temp__4;
	      {
		double x__2 = v__6[i];
		if (x__2 > 0)
		  {
		    rose_temp__4 = x__2;
		    goto rose_inline_end__3__1__3;
		  }
		else
		  {
		    rose_temp__4 = -x__2;
		    goto rose_inline_end__3__1__3;
		  }
	      rose_inline_end__3__1__3:
		;
	      }
	      sum += rose_temp__4;
	    }
	  {
	    rose_temp__9 = sum;
	    goto rose_inline_end__8__4;
	  }
	rose_inline_end__8__4:
	  ;
	}
	double rose_temp__14;
	{
	  double *v__11 = v__16 + (10 - i + 1) * 10;
	  double sum = 0;
	  for (int i = 0; i < 10; ++i)
	    {
	      double rose_temp__4;
	      {
		double x__2 = v__11[i];
		if (x__2 > 0)
		  {
		    rose_temp__4 = x__2;
		    goto rose_inline_end__3__2__5;
		  }
		else
		  {
		    rose_temp__4 = -x__2;
		    goto rose_inline_end__3__2__5;
		  }
	      rose_inline_end__3__2__5:
		;
	      }
	      sum += rose_temp__4;
	    }
	  {
	    rose_temp__14 = sum;
	    goto rose_inline_end__13__6;
	  }
	rose_inline_end__13__6:
	  ;
	}
	norm = (rose_temp__9 > norm ? rose_temp__9 : norm);
      }
    {
      rose_temp__20 = norm;
      goto rose_inline_end__19;
    }
  rose_inline_end__19:
    ;
  }
  return (!(rose_temp__20 == 1.));
}
#endif
