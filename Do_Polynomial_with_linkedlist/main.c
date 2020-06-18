#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"

static	void
myPrint(char *pn, node head, int testZero, int showDegree)
{	

	printf("%s(x)=", pn);
	Polynomial_Print(head); 
	if (testZero) {
		printf(", is %sa zero polynomial",
			(Polynomial_isZero(head) ? "" : "not ") 
		);
	}
	if (showDegree) {
		printf(", degree = %d",
			Polynomial_Degree(head)
		);
	}
	printf("\n");
}


int
main(int argc, char *argv[])
{	
	
	node headA;
	MALLOC(headA,sizeof(node));
	myPrint("A", headA, YES, YES); 
	
	
	Polynomial_Attach(headA, 3, 0);myPrint("A", headA, NO, YES);
	Polynomial_Attach(headA, -12, 1);	myPrint("A", headA, NO, YES);
	Polynomial_Attach(headA, 5, 6);	myPrint("A", headA, NO, YES);
	Polynomial_Attach(headA, -1, 4);	myPrint("A", headA, NO, YES);
	Polynomial_Attach(headA, 3, 3);	myPrint("A", headA, NO, YES);
	Polynomial_Attach(headA, -2, 7);	myPrint("A", headA, NO, YES); 
	Polynomial_Remove(headA, 1);		myPrint("A", headA, NO, YES);
	Polynomial_Remove(headA, 7);		myPrint("A", headA, NO, YES);

	printf("coef of x^0 is %f\n", Polynomial_Coef(headA, 0));
	printf("coef of x^4 is %f\n", Polynomial_Coef(headA, 4));
	
	node headB;
	MALLOC(headB,sizeof(node));
	Polynomial_Attach(headB, -3, 3);	myPrint("B", headB, NO, YES);

	node headC;
	MALLOC(headC,sizeof(node));
	Polynomial_Add(headA, headB, headC);	
	myPrint("C", headC, NO, YES);
	
	node headD;
	MALLOC(headD,sizeof(node));
	Polynomial_Attach(headD, 1, 0);
	Polynomial_Attach(headD, 1, 50);	myPrint("D", headD, NO, YES);
	
	node headE;
	MALLOC(headE,sizeof(node));
	Polynomial_Attach(headE, 1, 0);
	Polynomial_Attach(headE, 1, 50);	myPrint("D", headE, NO, YES);
	
	node headF;
	MALLOC(headF,sizeof(node));
	Polynomial_Mul(headD, headE, headF);	myPrint("F", headF, NO, YES);
	return 0;
	
}
