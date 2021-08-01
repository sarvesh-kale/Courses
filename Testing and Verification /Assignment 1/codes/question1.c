/*All problems are with 8 variables
	x1, x2, x3, x4, x5, x6, x7, x8
You will order the variables in the same order
as they are indexed above.
1.  The function f is
	f = (x1.x4 + 
		(~x1).x2.x5 +
		(~x1).(~x2).x3.x6 +
		(~x1).(~x2).(~x3).x4.x8)
    The care set is
	h = (x1.(~x3) + (~x1).x3)
    The claimed implementation is
	g = (x1.x4 + (~x1).((~x2).x6 + x2.x5))
    Show using BDDs that  h => (f = g) is always 1.
*/
#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	

	// make 8 variables from x1 to x8 
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);	
	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);	
	bdd x7 = bdd_new_var_last(bddm);
	bdd x8 = bdd_new_var_last(bddm);

	// compute f =  = (x1.x4 + (~x1).x2.x5 + (~x1).(~x2).x3.x6 + (~x1).(~x2).(~x3).x4.x8)
	bdd t1  = bdd_and (bddm,x1,x4);	
	bdd t2  = bdd_and (bddm,bdd_and(bddm,x2,x5),bdd_not(bddm,x1));
	bdd t3  = bdd_and (bddm,bdd_and(bddm,bdd_not(bddm,x1),bdd_not(bddm,x2)),bdd_and(bddm,x3,x6)) ;
	bdd t4  = bdd_and (bddm,bdd_and(bddm,bdd_not(bddm,x1),bdd_not(bddm,x2)),bdd_and(bddm,x3,x6));
	bdd f  =  bdd_or  (bddm , bdd_or(bddm,t1,t2),bdd_or(bddm,t3,t4)) ;

	// compute g =  (x1.x4 + (~x1).((~x2).x6 + x2.x5))
	bdd t5 = bdd_and (bddm, x1,x4);
	bdd t6 = bdd_and (bddm, bdd_or(bddm ,bdd_and(bddm,bdd_not(bddm,x2),x6),bdd_and(bddm,x2,x5)),bdd_not(bddm,x1));
    bdd g  = bdd_or(bddm , t5,t6 ) ;
	
	// compute h  = (x1.(~x3) + (~x1).x3)
    bdd h = bdd_or(bddm,bdd_and(bddm,bdd_not(bddm,x3),x1),bdd_and(bddm,bdd_not(bddm,x1),x3));
    
	//compute h=>(f=g)
	bdd result= bdd_or(bddm,bdd_not(bddm,h),bdd_xnor(bddm,f,g)) ;

	printf("--------------------------result-------------------------\n");
    bdd_print_bdd(bddm,result,NULL, NULL,NULL, stdout);
    
	return(0);
}

