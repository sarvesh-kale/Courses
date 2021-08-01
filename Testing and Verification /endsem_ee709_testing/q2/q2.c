#include<stdlib.h>
#include<stdio.h>
#include<bdduser.h>

int main(int argc ,char * argv[]) {
    bdd_manager bddm = bdd_init();
    // make 4 variables x0,x1,x2 (in that order)
    bdd x1 = bdd_new_var_last(bddm);
    bdd x2 = bdd_new_var_last(bddm);
    bdd x3 = bdd_new_var_last(bddm);
    bdd x4 = bdd_new_var_last(bddm);
    //make 3 output variable 
    bdd y1 = bdd_new_var_last(bddm);
    bdd y2 = bdd_new_var_last(bddm);
    bdd y3 = bdd_new_var_last(bddm);    
    //compute the three function bdd given in Qn
    bdd function1 = bdd_xor(bddm,x1,bdd_xor(bddm,x2,bdd_xor(bddm,x3,x4))) ;
    bdd function2 = bdd_xor(bddm,
             bdd_xor(bddm,bdd_and(bddm,x1,x2),bdd_and(bddm,x2,x3)),
             bdd_xor(bddm,bdd_and(bddm,x3,x4),bdd_and(bddm,x1,x4)));
    bdd function3 = bdd_xor(bddm,
             bdd_and(bddm,x1,bdd_and(bddm,x2,x3)),
             bdd_xor(bddm,bdd_and(bddm,x2,bdd_and(bddm,x3,x4)),bdd_and(bddm,x1,bdd_and(bddm,x3,x4))));
    //compute A = x1.x2 + x3.x4
    bdd A = bdd_or(bddm,bdd_and(bddm,x1,x2),bdd_and(bddm,x3,x4));
    //image computation is there exists on x1,x2,x3,x4 of A.X where X is
    //charactersitic function 
    bdd AX = bdd_and(bddm,
                     A   ,
                     bdd_and(bddm,
                                  bdd_xnor(bddm,y1,function1),
                                  bdd_and(bddm,
                                              bdd_xnor(bddm,y2,function2),
                                              bdd_xnor(bddm,y3,function3))));
    bdd Q[5]={x1,x2,x3,x4,0} ; //on these variable ext. quantification
    int assoc = bdd_new_assoc(bddm,Q,0);
    bdd_assoc(bddm,assoc);
    bdd image = bdd_exists(bddm,AX);
    bdd_print_bdd(bddm,image,NULL, NULL,NULL, stdout);
    return 0;
}

/*
y1 = x1 ⊕ x2 ⊕ x3 ⊕ x4
y2 = (x1.x2) ⊕ (x2.x3) ⊕ (x3.x4) ⊕ (x1.x4)
y3 = (x1.x2.x3) ⊕ (x2.x3.x4) ⊕ (x1.x3.x4)
*/