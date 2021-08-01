//this is part a of question
#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	int i = 0;
	bdd_manager bddm = bdd_init();	
	bdd x1  = bdd_new_var_last(bddm); // 0 these are inputs  
	bdd x2  = bdd_new_var_last(bddm); // 1
	bdd q0  = bdd_new_var_last(bddm); // 2 these are present state 	
	bdd q1  = bdd_new_var_last(bddm); // 3
 	bdd q0_ = bdd_new_var_last(bddm); // 4 these are nxt state	
	bdd q1_ = bdd_new_var_last(bddm); // 5
	bdd cummulative1 =bdd_new_var_last(bddm);
	
	bdd expr1 = bdd_xor(bddm,x1,bdd_xor(bddm,x2,q1)) ;//this is next state equation for q0                                                                 //
	bdd expr2 = bdd_xor(bddm,x2,q0) ;                 //this is next state equation for q1 
	            

	
	bdd array1[]={x1,x2,q0,q1,0} ;                    // null terminated 
	bdd array2[]={q0_,q0,q1_,q1,0} ;
	int association = bdd_new_assoc(bddm,array1,0);
	int association_change = bdd_new_assoc(bddm,array2,7);
	bdd_assoc(bddm,association);
	bdd A =bdd_nor(bddm,q0,q1) ;                                               //this is the condition to begin with                                 
 	bdd X =bdd_and(bddm,bdd_xnor(bddm,q0_,expr1),bdd_xnor(bddm,q1_,expr2));    //X is the characteristic equation . 
	bdd R_previous = A ;
	bdd R_present  = A ;
	
	do{
		bdd_assoc(bddm,association);                 // for there exist op
		bdd Transition = bdd_and(bddm,A,X) ;
		bdd s_k = bdd_exists(bddm,Transition);       // there exist on x1,x2,q0,q1
		i = i + 1 ;                                  // i was initialized to zero .
		printf("---to state transition %d step ---\n",i);
		bdd_print_bdd(bddm,s_k,NULL, NULL,NULL, stdout);
		bdd_assoc(bddm,association_change);          // to replace q0_,q1_ 											
		A = bdd_substitute(bddm,s_k) ;               // above replacement happens here
		R_previous = R_present ;                     // change pointer of prev
		                                             // before adding next element
		R_present  = bdd_or(bddm,A,R_previous) ;     // R(k+1) = R(k) + S(k)
		//bdd_print_bdd(bddm,A,NULL, NULL,NULL, stdout); 	
	}while(R_present != R_previous);                 // is R(k+1) == R(k) ??
	
	
	printf("\n---------------------------------------------------------------");
	printf("\nthese are all possible states :------->\n");
	bdd_print_bdd(bddm,R_present,NULL, NULL,NULL, stdout);
	return 0;
}
