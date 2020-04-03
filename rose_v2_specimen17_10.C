
int
fact (int n)
{
  if (n == 0)
    return 1;
  else
    return n * fact (n - 1);
}

int
main (int, char **)
{
  int rose_temp__4;
  {
    if (5 == 0)
      {
	rose_temp__4 = 1;
	goto rose_inline_end__3;
      }
    else
      {
	int rose_temp__8;
	{
	  int n__6 = 5 - 1;
	  if (n__6 == 0)
	    {
	      rose_temp__8 = 1;
	      goto rose_inline_end__7;
	    }
	  else
	    {
	      int rose_temp__12;
	      {
		int n__10 = n__6 - 1;
		if (n__10 == 0)
		  {
		    rose_temp__12 = 1;
		    goto rose_inline_end__11;
		  }
		else
		  {
		    int rose_temp__16;
		    {
		      int n__14 = n__10 - 1;
		      if (n__14 == 0)
			{
			  rose_temp__16 = 1;
			  goto rose_inline_end__15;
			}
		      else
			{
			  int rose_temp__20;
			  {
			    int n__18 = n__14 - 1;
			    if (n__18 == 0)
			      {
				rose_temp__20 = 1;
				goto rose_inline_end__19;
			      }
			    else
			      {
				int rose_temp__24;
				{
				  int n__22 = n__18 - 1;
				  if (n__22 == 0)
				    {
				      rose_temp__24 = 1;
				      goto rose_inline_end__23;
				    }
				  else
				    {
				      int rose_temp__28;
				      {
					int n__26 = n__22 - 1;
					if (n__26 == 0)
					  {
					    rose_temp__28 = 1;
					    goto rose_inline_end__27;
					  }
					else
					  {
					    int rose_temp__32;
					    {
					      int n__30 = n__26 - 1;
					      if (n__30 == 0)
						{
						  rose_temp__32 = 1;
						  goto rose_inline_end__31;
						}
					      else
						{
						  int rose_temp__36;
						  {
						    int n__34 = n__30 - 1;
						    if (n__34 == 0)
						      {
							rose_temp__36 = 1;
							goto
							  rose_inline_end__35;
						      }
						    else
						      {
							int rose_temp__40;
							{
							  int n__38 =
							    n__34 - 1;
							  if (n__38 == 0)
							    {
							      rose_temp__40 =
								1;
							      goto
								rose_inline_end__39;
							    }
							  else
							    {
							      rose_temp__40 =
								n__38 *
								fact (n__38 -
								      1);
							      goto
								rose_inline_end__39;
							    }
							rose_inline_end__39:
							  ;
							}
							rose_temp__36 =
							  n__34 *
							  rose_temp__40;
							goto
							  rose_inline_end__35;
						      }
						  rose_inline_end__35:
						    ;
						  }
						  rose_temp__32 =
						    n__30 * rose_temp__36;
						  goto rose_inline_end__31;
						}
					    rose_inline_end__31:
					      ;
					    }
					    rose_temp__28 =
					      n__26 * rose_temp__32;
					    goto rose_inline_end__27;
					  }
				      rose_inline_end__27:
					;
				      }
				      rose_temp__24 = n__22 * rose_temp__28;
				      goto rose_inline_end__23;
				    }
				rose_inline_end__23:
				  ;
				}
				rose_temp__20 = n__18 * rose_temp__24;
				goto rose_inline_end__19;
			      }
			  rose_inline_end__19:
			    ;
			  }
			  rose_temp__16 = n__14 * rose_temp__20;
			  goto rose_inline_end__15;
			}
		    rose_inline_end__15:
		      ;
		    }
		    rose_temp__12 = n__10 * rose_temp__16;
		    goto rose_inline_end__11;
		  }
	      rose_inline_end__11:
		;
	      }
	      rose_temp__8 = n__6 * rose_temp__12;
	      goto rose_inline_end__7;
	    }
	rose_inline_end__7:
	  ;
	}
	rose_temp__4 = 5 * rose_temp__8;
	goto rose_inline_end__3;
      }
  rose_inline_end__3:
    ;
  }
  return (!(rose_temp__4 == 120));
}
