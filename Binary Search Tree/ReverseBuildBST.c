#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 60

struct TNode 
{
	int Data;
	struct TNode* Left;
	struct TNode* Right;
};

typedef struct TNode* Tree;


//後序
void AfterOrder(Tree p) {
    if(p != NULL) {
        AfterOrder(p->Left);
        AfterOrder(p->Right);
        printf("%c ", p->Data);
    }
}


		


Tree restoreTree(char pre[], char in[], int n)
{
	int i;
	char lpre[MAXSIZE], rpre[MAXSIZE];
	char lin[MAXSIZE], rin[MAXSIZE];
	int n1 = 0, n2 = 0;
	int m1 = 0, m2 = 0;
	if (n == 0) 
	{
		return NULL;
	}
	Tree T = (Tree)malloc(sizeof(struct TNode));
	/*if (T == NULL) {
		return NULL;//記憶體滿了，返回NULL； 
	}*/
	
	T->Data = pre[0];                    
	for (i = 0; i < n; i++) 
	{
		if (i <= n1 && in[i] != pre[0]) 
		{                                 //中序
			lin[n1++] = in[i];
		}
		else if (in[i] != pre[0]) 
		{                                 //i是大於n1的 
			rin[n2++] = in[i];
		}
	}
	//前序  
	for (i = 1; i < n; i++) 
	{
		if (i<(n1 + 1))               // n1+1 因為 從1開始，共有n1個左子數
		{
			lpre[m1++] = pre[i];
			
		}
		else 
		{
			rpre[m2++] = pre[i];     //  其餘為右子數
			
		}
	}
	T->Left = restoreTree(lpre, lin, n1);
	T->Right = restoreTree(rpre, rin, n2);
	return T; 
}




int IsEmpty_BiTree(Tree *T) {
	if(*T == NULL)
	return 1;
	else
	return 0;
}


void LevelOrder_BiTree(Tree T){
   
    int front = 0;
    int rear = 0;
    Tree BiQueue[MAXSIZE];
    Tree tempNode;
	
    if(!IsEmpty_BiTree(&T)){
		
        BiQueue[rear++] = T;
         
        while(front != rear){
            
            tempNode = BiQueue[front++];
            
            if(!IsEmpty_BiTree(&(tempNode->Left)))
                BiQueue[rear++] = tempNode->Left;
             
            if(!IsEmpty_BiTree(&(tempNode->Right)))
                BiQueue[rear++] = tempNode->Right;
             
             printf("%c ",tempNode->Data);
        }
    }
}





int main()
{
	int n;
	char pre[60], in[60];
	scanf("%d", &n);
	scanf("%s", pre);
	scanf("%s", in);
	Tree BST = NULL;
	BST = restoreTree(pre, in, n);//建樹 
	 printf("後序走訪:\n");
	 AfterOrder(BST);
	 printf("\n");
	 printf("原生樹\n");
	 printf("Level-order:\n");
     LevelOrder_BiTree(BST);
}
