//this is part a of question
#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();	
	bdd x1  = bdd_new_var_last(bddm); // these are inputs  
	bdd x2  = bdd_new_var_last(bddm);
	bdd q1  = bdd_new_var_last(bddm); // these are present state 	
	bdd q2  = bdd_new_var_last(bddm);
	bdd q3  = bdd_new_var_last(bddm);
 	bdd q1_ = bdd_new_var_last(bddm); // these are nxt state	
	bdd q2_ = bdd_new_var_last(bddm);
	bdd q3_ = bdd_new_var_last(bddm);
	bdd cummulative1 =bdd_new_var_last(bddm);
	bdd expr1 = bdd_xor(bddm,x1,x2) ;                                                                 //
	bdd expr2 = bdd_or(bddm,bdd_and(bddm,bdd_and(bddm,x1,x2),q1),bdd_not(bddm,bdd_xor(bddm,x1,x2))) ; //X(x1,x2,q1,q2,q3)
	bdd expr3 = bdd_xor(bddm,q1,q2) ;                                                                 //
	
	bdd A = bdd_and(bddm,bdd_not(bddm,q1),bdd_and(bddm,bdd_not(bddm,q2),bdd_not(bddm,q3))) ; // A
	bdd A_ = bdd_and(bddm,bdd_not(bddm,q1_),bdd_and(bddm,bdd_not(bddm,q2_),bdd_not(bddm,q3_))) ; // A
	
	bdd array1[]={x1,x2,q1,q2,q3,0} ; // null terminated 
	bdd array2[]={q1_,q1,q2_,q2,q3_,q3,0} ;
	int association = bdd_new_assoc(bddm,array1,0);
	int association_change = bdd_new_assoc(bddm,array2,7);
	bdd_assoc(bddm,association);
                                      //~q2_ ^ expr2                     ~q1_ ^ expr1                 ~q3_ ^ expr3
 	bdd R = bdd_and(bddm,A,bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,bdd_xor(bddm,q2_,expr2)),bdd_not(bddm,bdd_xor(bddm,q1_,expr1))),bdd_not(bddm,bdd_xor(bddm,q3_,expr3))));
	//begin first time------------------------------------------------------------------------------------------
	bdd new_bdd = bdd_exists(bddm,R);
	printf("------------------------states reachable at 1 step -----------------------\n");
	printf("------------------------q1_=var5 , q2_=var6 ,q3_=var7-----------------------\n");
	bdd_print_bdd(bddm,new_bdd,NULL, NULL,NULL, stdout);
	//now A takes the value of new_bdd
	cummulative1  = bdd_or(bddm,A_,new_bdd) ;
	if(A_ == cummulative1) 
		printf("No new additions to set of states after 1 step");
	//use different association
	bdd_assoc(bddm,association_change);/////////////////////
	A = bdd_substitute(bddm,new_bdd) ;
	//begin second time-----------------------------------------------------------------------------------------	
	R = bdd_and(bddm,A,bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,bdd_xor(bddm,q2_,expr2)),bdd_not(bddm,bdd_xor(bddm,q1_,expr1))),bdd_not(bddm,bdd_xor(bddm,q3_,expr3))));
	bdd_assoc(bddm,association);////////////////////
	bdd new_bdd2 = bdd_exists(bddm,R);
	printf("------------------------states reachable at 2 step -----------------------\n");
	printf("------------------------q1_=var5 , q2_=var6 ,q3_=var7-----------------------\n");
	bdd_print_bdd(bddm,new_bdd2,NULL, NULL,NULL, stdout);
	bdd cummulative2 = bdd_or(bddm,cummulative1,new_bdd2);
	if(cummulative1 == cummulative2) 
		printf(" No new additions to set of states after 2 steps");
	//use different association
	bdd_assoc(bddm,association_change);/////////////////////
	A = bdd_substitute(bddm,new_bdd2) ;
	//begin third time -------------------------------------------------------------------------------------------	
	R = bdd_and(bddm,A,bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,bdd_xor(bddm,q2_,expr2)),bdd_not(bddm,bdd_xor(bddm,q1_,expr1))),bdd_not(bddm,bdd_xor(bddm,q3_,expr3))));
	bdd_assoc(bddm,association);////////////////////
	bdd new_bdd3 = bdd_exists(bddm,R);
	printf("------------------------states reachable at 3 step -----------------------\n");
	printf("------------------------q1_=var5 , q2_=var6 ,q3_=var7-----------------------\n");
	bdd_print_bdd(bddm,new_bdd3,NULL, NULL,NULL, stdout);
	bdd cummulative3 = bdd_or(bddm,cummulative2,new_bdd3);
	if(cummulative2 == cummulative3) 
		printf(" No new additions to set of states after 3 steps");
	//use different association
	bdd_assoc(bddm,association_change);/////////////////////
	A = bdd_substitute(bddm,new_bdd2) ;
	printf("\n---------------------------------------------------------------");
	printf("\nthese are all possible states :------->\n");
	bdd_print_bdd(bddm,cummulative3,NULL, NULL,NULL, stdout);
	return 0;
}
