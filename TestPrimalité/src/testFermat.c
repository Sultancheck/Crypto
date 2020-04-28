#include <stdlib.h>
#include <stdio.h>
#include "gmp.h"
#include <stdarg.h> 
#include <obstack.h>
#include <string.h>
#define TAILLE 256


void squaremultiply(mpz_t *res,mpz_t a, char *exp)
{
	int i=0;
	//mpz_t res;
	mpz_set(*res,a);
	int taille=strlen(exp);
	printf("res%Zd\n",*res);
	printf("a %Zd\n",a);
	printf("exp %s\n",exp);
	for(i=1;i<taille;i++)
	{
		mpz_mul(*res, *res, *res);
		printf("res carré %Zd\n",*res);
		if(exp[i]==1)
		{
			mpz_mul(*res,*res,a);
			printf("res carré %Zd \n",*res);
		}
	}
//	return res;
}
	
int main(int argc, char *argv[])

{
	
	char *nb1 =strtok(argv[1],"^");
	char *exp1 =strtok(NULL,"^");
	
	char *nb2=strtok(argv[2],"^");
	char *exp2=strtok(NULL,"^");
	mpz_t test;
	mpz_init(test);
	mpz_set_str(test,exp1,10);
	gmp_printf("%Zd\n", test);
	char * conv2= mpz_get_str(NULL,2,test);
	mpz_clear(test);
	
	mpz_t test2;
	mpz_init(test2);
	mpz_set_str(test2,exp2,10);
	gmp_printf("%Zd\n", test2);
	char * conv= mpz_get_str(NULL,2,test2);
	mpz_clear(test2);
	printf("%s\n",conv);
	
	printf("%s\n",conv2);
	
	printf("%s %s \n", nb1,exp1);
	printf("%s %s \n", nb2,exp2);
	mpz_t x;
	mpz_init(x);
	squaremultiply(&x,test,conv);  // met 12345 (lu en base 10) dans x
	//mpz_mul(x, x, x);
	gmp_printf("%Zd\n", x);
	mpz_clear(x);
	return 0;
}
