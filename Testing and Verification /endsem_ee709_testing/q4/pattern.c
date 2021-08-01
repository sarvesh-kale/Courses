#include<stdio.h>
#include<stdlib.h>
int main(int argc ,char **argv )
{
	int i=1 ,j=13 ,k=15,counter=1,counter_max; // counter_max = 6 j = counter_max *2 +1
				      		   // k = counter_max *2 +2
	counter_max = atoi(argv[1]);
	while(counter<=counter_max){
		
		printf("-%d -%d -%d 0 \n-%d %d %d 0 \n%d -%d %d 0 \n%d"
				 " %d -%d 0 \n",j+4,i+1,j,j+4,i+1,j,\
				 j+4,i+1,j,j+4,i+1,j);//for q1

		printf("-%d %d -%d -%d 0 \n%d -%d %d 0\n-%d %d 0\n"
			"%d %d %d -%d 0\n%d -%d %d 0\n",k,i,j,j+1,k,j,j+1,\
			                i,k, j,j+1,i,k, j,j+1,k);//for y

		printf("-%d -%d -%d %d 0 \n-%d -%d %d -%d 0 \n-%d %d -%d -%d 0 \n"
		       "-%d %d %d %d 0 \n%d -%d -%d -%d 0 \n%d -%d %d %d 0 \n"
		       "%d %d -%d %d 0 \n%d %d %d -%d 0\n",j+3,i,i+1,j+1,\
		                                      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1,\
						      j+3,i,i+1,j+1); // for q0

		counter++ ;
		i = i + 2;
		j = j + 3;
		k = k + 3;
	}
	return 0;
}
