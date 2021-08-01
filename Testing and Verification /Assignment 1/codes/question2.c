/*  Show, using BDD's that the following formulas are equivalent.
	(~ (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8))
	((~x1).(~x2).(~x3).(~x4).(~x5).(~x6).(~x7).(~x8))
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

	// compute f  = ((~ (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8))
	bdd t1  = bdd_or (bddm,bdd_or(bddm,x1,x2),bdd_or(bddm,x7,x8));	
	bdd t2  = bdd_or (bddm,bdd_or(bddm,x3,x4),bdd_or(bddm,x5,x6));
    bdd f   = bdd_not(bddm,bdd_or (bddm,t1,t2)) ;

    // compute g  = ((~x1).(~x2).(~x3).(~x4).(~x5).(~x6).(~x7).(~x8))
    bdd t3  = bdd_and(bddm,bdd_not(bddm,x1),bdd_not(bddm,x2));
    bdd t4  = bdd_and(bddm,bdd_not(bddm,x3),bdd_not(bddm,x4));
    bdd t5  = bdd_and(bddm,bdd_not(bddm,x6),bdd_not(bddm,x5));
    bdd t6  = bdd_and(bddm,bdd_not(bddm,x7),bdd_not(bddm,x8));
    bdd g   = bdd_and(bddm,bdd_and(bddm,t3,t4),bdd_and(bddm,t5,t6)); 

    printf("------------------------function 1 -----------------------\n");
	bdd_print_bdd(bddm,f,NULL, NULL,NULL, stdout);
    printf("------------------------function 2 -----------------------\n");
	bdd_print_bdd(bddm,g,NULL, NULL,NULL, stdout);
    if ( f == g ){
        printf(".....Equal.....\n");
    }
    else
        printf("...Not Equal...\n");
    return 0 ;
}