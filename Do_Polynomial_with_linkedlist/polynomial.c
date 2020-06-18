#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"polynomial.h"

int Polynomial_Print(node head)
{
	int cc = 0;
	int ii;
	node current = head;
	if(current->right == NULL){
		printf("0");
		return cc;
	}
	
	while(current->right != NULL){

		if(cc == 0 && (current->right->expon == 0)){
			printf("%f", current->right->coef);
		}else if(cc != 0 && (current->right->expon == 0)){
			printf("%+f", current->right->coef);
		}
			
		//處理1次方 
		if(cc == 0 && (current->right->expon == 1)){
			printf("%fx", current->right->coef);
		}else if(cc != 0 && (current->right->expon == 1)){
			printf("%+fx", current->right->coef);
		}	
			
		//處理1次方以上 
		if(cc == 0 && (current->right->expon > 1)){
			printf("%fx^%d", current->right->coef, current->right->expon);
		}else if(cc != 0 && (current->right->expon > 1)){
			printf("%+fx^%d", current->right->coef, current->right->expon);
		} 
		
		current = current->right;	
		cc++;	
	}
	return cc;//回傳cc但因為老師從沒拿東西接,所以無卵用

}

int
Polynomial_isZero(node head)
{
	node current = head;
	if (current->right == NULL) {
		return YES;
	}
	return NO;
}

int
Polynomial_Degree(node head)
{
	node current = head;
	if(current->right == NULL){
		return -1;
	}	
	return current->right->expon;
		
	
}

float
Polynomial_Coef(node head, int degree)
{
	node current = head;
	while(current->right != NULL){
		if(degree == current->right->expon){
			return current->right->coef;
		}
		current = current->right;
	}

}

void
Polynomial_Attach(node head, float coef, int degree)
{	
	node current = head; 
	
	while(current->right != NULL){
		if(degree == current->right->expon){
			current->right->coef += coef;
			return;
		}else if(degree > current->right->expon){
			node now;
			MALLOC(now,sizeof(node));
			now->coef = coef;
			now->expon = degree;
			current->right->left = now;
			now->right = current->right;
			now->left = current;
			current->right = now;
			return;
		}
		current = current->right;
	}
	
	node now;
	MALLOC(now,sizeof(node));
	now->coef = coef;
	now->expon = degree;
	current->right = now; 
	now->left = current;
	now->right = NULL ;
}

void
Polynomial_Remove(node head, int degree)
{
	node current = head;
	while(current->right != NULL){
		if(degree == current->right->expon){
			current->right = current->right->right;
		}
		current = current->right;
	}
	
}

void
Polynomial_Add(node headA, node headB, node headC)
{	
	node currentA = headA;
	node currentB = headB;
	node currentC = headC;
	
	while(currentA->right != NULL){
		Polynomial_Attach(currentC, currentA->right->coef, currentA->right->expon);
		currentA = currentA->right;
	}
	
	while(currentB->right != NULL){
		Polynomial_Attach(currentC, currentB->right->coef, currentB->right->expon);
		currentB = currentB->right;
	}
	
	while(currentC->right != NULL){
		if(currentC->right->coef == 0){
			currentC->right = currentC->right->right;
		}
		currentC = currentC->right;
	}

}

void
Polynomial_Mul(node headD, node headE, node headF)
{
	node currentD = headD;
	node currentF = headF;
	
	while(currentD->right != NULL){
		node currentE = headE;
		while(currentE->right != NULL){
			Polynomial_Attach(currentF, currentD->right->coef * currentE->right->coef, currentD->right->expon + currentE->right->expon);
			currentE = currentE->right;
		}
		
		currentD = currentD->right;
	}

}




