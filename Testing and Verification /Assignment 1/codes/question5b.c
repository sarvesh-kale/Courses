/*5.  Let the function f be
	   f = (x1.x2.(~x3) + x4.x5 + (~x6).x7 + x8)
        b. Find  the function w on x5,x6,x7,x8 which
           has the following property.
	   h(x5,x6,x7,x8) = 1 if and only if 
	   for every substitution for x1,x2,x3,x4 (say 
           x1=b1, x2=b2, x3=b3, x4=b4, where the bi's are 0 or 1)
                 f(b1,b2,b3,b4,x5,x6,x7,x8) = 1
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
	//compute bdd of  f = (x1.x2.(~x3) + x4.x5 + (~x6).x7 + x8)
	bdd f1 =  bdd_or(bddm,bdd_and(bddm,x4,x5),bdd_and(bddm,bdd_not(bddm,x3),bdd_and(bddm,x1,x2)));
	bdd f2 =  bdd_or(bddm,x8,bdd_and(bddm,x7,bdd_not(bddm,x6)));
	bdd f  =  bdd_or(bddm,f1,f2);
	printf("-----------------------f-----------------------------\n");
	// print f bdd
	bdd_print_bdd(bddm,f,NULL, NULL,NULL, stdout);  
	//set x1,x2,x3,x4 = 1 , 1 ,0 ,0 
	bdd Q[9];
	Q[0] = x1; Q[2] = x2; Q[4] = x3;Q[6]=x4 ;// these are variables 
	Q[1] = bdd_zero(bddm);Q[3]=bdd_one(bddm);Q[5]=bdd_one(bddm);Q[7]=bdd_zero(bddm);// these are values 
	Q[8]=0 ;// null terminated  
	int assoc = bdd_new_assoc(bddm,Q,1);//non zero value for our substitutions 
	bdd_assoc(bddm,assoc);
	bdd new_bdd = bdd_forall(bddm,f);
	printf("----------------------h---------------------------\n");
	bdd_print_bdd(bddm,new_bdd,NULL, NULL,NULL, stdout);
	
}
