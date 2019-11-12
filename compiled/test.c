#include "test.h"
	#include <stdbool.h>
	#include <stdio.h>
	int main(void){
r1 = 1;
x = r1 ; 
printf("x de type <int> vaut %d ;", r1 );
 putchar(10);
r2 = 3;
y = r2 ; 
printf("y de type <int> vaut %d ;", r2 );
 putchar(10);
r3 = r1 + r2;
printf("<exp> de type <int> vaut %d;", r3 );
putchar(10);
r4 = 1;
x = r4 ; 
printf("x de type <int> vaut %d ;", r4 );
 putchar(10);
r5 = 3;
x = r5 ; 
printf("x de type <int> vaut %d ;", r5 );
 putchar(10);
r6 = 1;
r7 = r6 + r4;
printf("<exp> de type <int> vaut %d;", r7 );
putchar(10);
y = r7 ; 
printf("y de type <int> vaut %d ;", r7 );
 putchar(10);
r8 = r7 + r4;
printf("<exp> de type <int> vaut %d;", r8 );
putchar(10);
r9 = 1;
x = r9 ; 
printf("x de type <int> vaut %d ;", r9 );
 putchar(10);
r11 = 2;
r12 = (r9 == r11);
goto ifstatement1;
	iftrue1:
r13 = 3;
r10=r13;
	goto end1;
	iffalse1:
r14 = 6;
r10=r14;
	goto end1;
	ifstatement1:
	if (!r12) goto iffalse1;
	goto iftrue1;
	end1:
y = r10 ; 
printf("y de type <int> vaut %d ;", r10 );
 putchar(10);
r15 = 1.000000;
a = r15 ; 
printf("a de type <float> vaut %f;", r15 );
 putchar(10);
r16 = 3;
y = r16 ; 
printf("y de type <int> vaut %d ;", r16 );
 putchar(10);
r17 = r15 + r16;
printf("<exp> de type <float> vaut %f;", r17 );
putchar(10);
r18 = 5;
f = r18 ; 
printf("f de type <int> vaut %d ;", r18 );
 putchar(10);
r20 = 2;
x = r20 ; 
printf("x de type <int> vaut %d ;", r20 );
 putchar(10);
r21 = 2;
r22 = (r20 == r21);
goto ifstatement2;
	iftrue2:
r23 = 1;
r19=r23;
	goto end2;
	iffalse2:
r24 = 3;
r19=r24;
	goto end2;
	ifstatement2:
	if (!r22) goto iffalse2;
	goto iftrue2;
	end2:
f = r19 ; 
printf("f de type <int> vaut %d ;", r19 );
 putchar(10);
return 0;
}