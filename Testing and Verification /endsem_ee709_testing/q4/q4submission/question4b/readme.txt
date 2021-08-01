Note that the cnf pattern is generated from the pattern.c file\
after pattern.c is compiled it generates a.out as output file 
the file accepts command line argument 6 and generated cnf for first six steps 
do not supply any other input other than 6 since the code is not generalized .

$ gcc pattern.c 
$ ./a.out 6
 
 this generates the pattern ,
 copy paste that pattern into a cnf file and 
 add six additional clauses corresponding to output sequence as 
 suggested in the document ,they are already added in the q4b.cnf file 

$ picosat --all q4b.cnf 
  
 output ==>UNSAT
