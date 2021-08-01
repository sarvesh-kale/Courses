---------------------------------------------------------------
                    EE 709 Assignment
---------------------------------------------------------------
All problems are with 8 variables

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


2.  Show, using BDD's that the following formulas are equivalent.

	(~ (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8))

	((~x1).(~x2).(~x3).(~x4).(~x5).(~x6).(~x7).(~x8))


3.  Show using BDD's that the following formulas are not
    equivalent.

	(x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8)

	(x1 ^ x2 ^ x3 ^ x4 ^ x5 ^ x6 ^ x7 ^ x8)

    Find a variable assignment for which 
	a. the two functions evaluate to the same value.
	b. the two functions evaluate to different values.

4.  Using the BDD package, find the sizes of BDD's for the
	following formulas.

	x1.x2  + x3.x4 + x5.x6 + x7.x8

	x1.x5  + x2.x6 + x3.x7 + x4.x8


5.  Let the function f be

	   f = (x1.x2.(~x3) + x4.x5 + (~x6).x7 + x8)
	
	a. Find  the function h on x5,x6,x7,x8 which
           has the following property.

	   h(x5,x6,x7,x8) = 1 if and only if there exists
	   some substitution for x1,x2,x3,x4 (say 
           x1=b1, x2=b2, x3=b3, x4=b4, where the bi's are 0 or 1)
           such that 

                 f(b1,b2,b3,b4,x5,x6,x7,x8) = 1

	b. Find  the function w on x5,x6,x7,x8 which
           has the following property.

	   h(x5,x6,x7,x8) = 1 if and only if 
	   for every substitution for x1,x2,x3,x4 (say 
           x1=b1, x2=b2, x3=b3, x4=b4, where the bi's are 0 or 1)

                 f(b1,b2,b3,b4,x5,x6,x7,x8) = 1


