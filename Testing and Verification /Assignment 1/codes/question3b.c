/*  Show using BDD's that the following formulas are not
    equivalent.
	(x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8)
	(x1 ^ x2 ^ x3 ^ x4 ^ x5 ^ x6 ^ x7 ^ x8)
    Find a variable assignment for which 
	a. the two functions evaluate to the same value.
	b. the two functions evaluate to different values.
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
	
    // f = (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8)
    // g = (x1 ^ x2 ^ x3 ^ x4 ^ x5 ^ x6 ^ x7 ^ x8)
    bdd f = bdd_or(bddm,bdd_or(bddm , bdd_or(bddm ,  x1, x2),bdd_or(bddm ,  x3, x4)),bdd_or(bddm , bdd_or(bddm ,  x5, x6),bdd_or(bddm ,  x7, x8)));
    bdd g = bdd_xor(bddm,bdd_xor(bddm , bdd_xor(bddm ,  x1, x2),bdd_xor(bddm ,  x3, x4)),bdd_xor(bddm , bdd_xor(bddm ,  x5, x6),bdd_xor(bddm ,  x7, x8)));
        bdd Q[17];
	
	Q[0] = x1; Q[2] = x2; Q[4] = x3; Q[6] = x4;Q[8] = x5;//values entered in key,value pair format ,null terminated 
	Q[10] = x6; Q[12] = x7; Q[14] = x8;Q[16]=0;	
	printf("---------------------part b--------------------------\n");
	// here we are doing 01010101
	Q[1] = bdd_zero(bddm); Q[3] = bdd_one(bddm); Q[5] = bdd_zero(bddm); Q[7] = bdd_one(bddm);Q[9] = bdd_zero(bddm);	
	Q[11] = bdd_one(bddm); Q[13] = bdd_zero(bddm); Q[15] = bdd_one(bddm);Q[16]=0;
	int assoc = bdd_new_assoc(bddm,Q,1);//last value non-zero in parameter list 
	assoc = bdd_new_assoc(bddm,Q,1);
	bdd_assoc(bddm,assoc);
	bdd f_substituted = bdd_substitute(bddm,f);
	bdd g_substituted = bdd_substitute(bddm,g);
	printf("Functions evaluated for 01010101 : \n");
	if(f_substituted == g_substituted ){
		printf(" Their value is equal \n");
	}
	else 	
		printf(" Their value is not equal \n");
	
    return 0;
}
