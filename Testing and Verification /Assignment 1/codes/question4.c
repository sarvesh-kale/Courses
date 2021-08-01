/*4. Using the BDD package, find the sizes of BDD's for the
	 following formulas.
	x1.x2  + x3.x4 + x5.x6 + x7.x8
	x1.x5  + x2.x6 + x3.x7 + x4.x8
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
    //compute f = x1.x2  + x3.x4 + x5.x6 + x7.x8
    bdd t1  = bdd_or(bddm,bdd_and(bddm,x1,x2),bdd_and(bddm,x3,x4));
    bdd t2  = bdd_or(bddm,bdd_and(bddm,x5,x6),bdd_and(bddm,x7,x8));
    bdd f   = bdd_or(bddm,t1,t2);
    printf("------------------------function 1 -----------------------\n");
	//bdd_print_bdd(bddm,f,NULL, NULL,NULL, stdout);
    printf("The size of robdd is %ld\n",bdd_size(bddm,f,1));// the parameter 1 indicates not basic bdd ;
    //compute g = x1.x5  + x2.x6 + x3.x7 + x4.x8
    bdd t3  = bdd_or(bddm,bdd_and(bddm,x1,x5),bdd_and(bddm,x2,x6));
    bdd t4  = bdd_or(bddm,bdd_and(bddm,x8,x4),bdd_and(bddm,x7,x3));
    bdd g   = bdd_or(bddm,t3,t4);
    printf("------------------------function 2 -----------------------\n");
	//bdd_print_bdd(bddm,f,NULL, NULL,NULL, stdout);
    printf("The size of robdd is %ld\n",bdd_size(bddm,g,1)); // the parameter 1 indicates not basic bdd ;
    return 0;
}
