#ifndef	_POLYNOMIAL_H
#define	_POLYNOMIAL_H
#ifndef	_POLYNOMIAL_H_
#define	_POLYNOMIAL_H_

#ifdef	__cplusplus
extern "C" {
#endif	/* __cplusplus */


#define	YES	(0 == 0)
#define	NO	(1 == 0)

#define	Polynomial_MaxDegree	100
#define MALLOC(p,s){\
	p = malloc(s);\
	p->right = NULL;\
	p->left = NULL;\
}

/* Definition: Polynomial */
typedef struct listnode *node;
typedef struct listnode{
	float coef;
	int expon;
	node right;
	node left;
};

/* API (Application Programming Interface */

int Polynomial_Print(node head);
/* print the polynomial pointed by poly as 2x^8-6x^4+3x-5 */
/* return: number of terms */

//void Polynomial_Zero(node head);
/* initialize the polynomial pointed by poly to a zero ploynomial */

int Polynomial_isZero(node head);
/* test whether the polynomial pointed by poly is a zero polynomial */

int Polynomial_Degree(node head);
/* return the degree of the polynomial pointed by poly */



float Polynomial_Coef(node head, int degree);
///* return the coefficient of the specified term
//   in the polynomial pointed by poly */
//
void Polynomial_Attach(node head, float coef, int degree);
///* attach a term onto the polynomial pointed by poly */
//
void Polynomial_Remove(node head, int degree);
///* remove the specified term from the polynomial pointed by poly */
//
void Polynomial_Add(node headA, node headB, node headC);
///* add two polynomials pointed by pa and pb, the resultant is stored in
//   the polynomial pointed by pc */
//void add_attach(Polynomial *poly, float coe, int exp, int *avail);
//int compare(int pa_exp, int pb_exp);
//
void Polynomial_Mul(node headD, node headE, node headF);///* multiply two polynomials pointed by pa and pb, the resultant is stored in
//   the polynomial pointed by pc */
//int mul_compare(Polynomial *poly,int expon,int *startF,int *avail);
//#ifdef	__cplusplus
//extern "C" {
//#endif	/* __cplusplus */

#endif	/* _POLYNOMIAL_H_ */
#endif	/* _POLYNOMIAL_H */
