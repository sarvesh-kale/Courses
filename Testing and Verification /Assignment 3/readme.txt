in question 1 i have two files 
run the assignment3q1.cnf with SAT solver it does not have any comments 
for more understability of the cnf file I have the same file but with comments added \
the name of that file is assignment3q1c.txt

in question 2 if you run the files file.txt ,file2.txt ,file3.txt,file4.txt using the SAT solver 
individually like minisat_static_static file.txt 1.out then you will get UNSAT as output 
because the negation of test vectors are also added at the end of the file ,if you want to get the 
test vector remove the line that says the following :- 

c everything after this is test vector 

