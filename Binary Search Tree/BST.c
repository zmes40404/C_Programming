#include<stdio.h>
#include<stdlib.h>

typedef struct tree{ 

    int data;
    struct tree *left_child, *right_child;  
}tn,*bst;

bst root = NULL;

void insert(int d);//���J�s��� 
void preorder(bst ptr);//�e�Ǩ��X
void inorder(bst ptr);//���Ǩ��X
void postorder(bst ptr);//��Ǩ��X
int search(int d);//�j�M
bst deletet(int d); //�R��

int main(){
    
    int d, sel;
     
    printf("�C�ӼƦr�N���P�����, ��ƬҬ����\n\n");
    printf("(1)�s�W�@�����\n(2)�R���@�����\n(3)�d�߬Y�����\n");
		printf("(4)�L�X�e�Ǩ��X���G\n(5)�L�X���Ǩ��X���G\n(6)�L�X��Ǩ��X���G\n(7)�L�X�e�B���B��Ǩ��X���G\n(0)����\n\n");
    
    while(1){
        
		printf("�п�J�Ʀr�M�w���: (1)�W�[ (2)�R�� (3)�d�� (4)�e�� (5)���� (6)��� (7)�e�B���B��� (0)����: ");
        scanf("%d",&sel);
		printf("\n");
		
		switch(sel)
		{
		case 1:
			printf("�п�J�Q�n�W�[����: ");
			scanf("%d",&d);
			if(search(d))
			    printf("\n��ƭ���\n");
            else
			    {
			insert(d);
			printf("�Ʀr %d �w�gŪ�J",d);
			}
			printf("\n");
			break;
	    case 2:
			printf("�п�J���R������: ");
			scanf("%d",&d);
			deletet(d);

			printf("\n");
			break;
		case 3:
			printf("�п�J���d�ߪ��Ʀr: ");
			scanf("%d",&d);
			if(search(d))
                printf("\n�ӭȦs�b\n\n");
            else
                printf("\n�ӭȤ��s�b\n\n");
			break;
		case 4:
			preorder(root);
			printf("\n\n");
			break;
		case 5:
			inorder(root);
			printf("\n\n");
			break;
		case 6:
			postorder(root);
			printf("\n\n");
			break;
		case 7:
			printf("�e�ǡG");
			preorder(root);
			printf("\n\n");
			printf("���ǡG");
			inorder(root);
			printf("\n\n");
			printf("��ǡG");
			postorder(root);
			printf("\n\n");
			break;
		default:
		    if(sel != 0)
			    printf("���O���~\n");
			break;
		}
		if(sel == 0){
		    printf("Goodbye\n");
            break;
        }    
    }     

    system("pause");
    return 0;
}

void insert(int d){

    bst new_node, current;
    int insert = 0;

    new_node = (bst)malloc(sizeof(tn));

    new_node->data = d; //�n�s�W����� 
    new_node->left_child = new_node->right_child = NULL; //�n�s�W���`�I�����k�l�𳣬O�Ū� 

    if(root == NULL) //�p�Groot�O�Ū� ���s�`�I���w���L 
        root = new_node;  
    else{

        current = root;

        while(!insert){
            if(current->data > new_node->data){//�ڸ`�I��Ƥ�[�J����Ƥj 
                if(current->left_child == NULL){ // �p�G���l�𬰪� 
    
                    current->left_child = new_node;//���w���l�𬰷s�`�I 
                    insert = 1;    
                }
                else
                    current = current->left_child; //�p�G���l�𤣬��� �h���w�����l�𪺥��l�� 
            }
            else{//�ڸ`�I��Ƥ�[�J����Ƥp 
        
                if(current->right_child == NULL){ //If�k�l�𬰪� 
        
                    current->right_child = new_node; //���w�k�l�𬰷s�`�I 
                    insert = 1;      
                }
                else
                    current = current->right_child; //if not���w���k�l�𪺥k�l�� 
            }
        }        
    }
}

int search(int d){  //ptr:�ާ@�\��ɪ��Ȧs���� 

    bst ptr = root; //�����Vroot 

    while(ptr != NULL){ //root���F�� 
    
        if(ptr->data == d) //root=�n�䪺 �^��1 
            return 1;
        else{
        
            if(ptr->data > d) //�Y���Ы��V��data�j��ڭ̭n�M�䪺d 
                ptr = ptr->left_child; //���V���l�� 
            else
                ptr = ptr->right_child;   //if not���V�k�l�� 
        }    
    }
    return 0;   
}

bst deletet(int d){
    
	bst parent,ptr,child;
    int find = 0; // �M��n�R���� 
   
// ��M�R���`�I�M����`�I���� 
    parent = ptr = root;
    while(ptr != NULL && !find ){ //�j��]�]�]�]����Ь��� �άO find=1 (����o) 
        if(ptr->data == d )   //�Y���V�n�M�䪺 
            find = 1; //����o 
        else{
            parent = ptr;  
            
            if(ptr->data > d ) //�j��n�M�䪺 
                ptr = ptr->left_child; //�����l��M�� 
            else
                ptr = ptr->right_child; //if not go right 
        }       
    }
    
    if ( ptr == NULL ){ 
        printf("\n���R�����Ȥ��s�b\n");
        return 0;  
    }    

//�u�Ѯڸ`�I, �åB�R���ڸ`�I 
    if(ptr->left_child == NULL && ptr->right_child == NULL && ptr == root){ //only root is left
        
        root = NULL; //root and ptr���Q�M�ŨæL�X�w�R�� 
        ptr = NULL;
        printf("\n�w�R��\n");
        return 0;
    }  
 
//�R���G���j�M�𪺸��`�I
    if(ptr->left_child == NULL && ptr->right_child == NULL ){  
         
         if(parent->left_child == ptr) //ptr���V���l�� 
             parent->left_child = NULL; //��ptr�R�� 
         else
             parent->right_child = NULL; //���V�k�l��h�R���k 
       
         ptr = NULL;  
         printf("\n�w�R��\n");
         return 0;
    }
    
//�S�����l�� 
    if(ptr->left_child == NULL){ //�S�����l�� 
        
        if(parent != ptr){  //delete left and right child and root at the same time
            
            if(parent->left_child == ptr) //���Ы��V���l�� 
                parent->left_child = ptr->right_child; //�⥪�l��right���w replace�� 
            else
                parent->right_child = ptr->right_child; //or else ptr���k�l����w replace 
        }    
        else
            root = root->right_child; //ptr���Vroot �]���S�����l�� �k�䩹�W���Nptr �A�R�� 
       
        ptr = NULL; //�M��ptr 
        printf("\n�w�R��\n"); //�L�X�w�R��~~~ 
        return 0;
    }

//�S���k�l��
    if(ptr->right_child == NULL){
    
        if(parent != ptr){
  
          if(parent->right_child == ptr)
              parent->right_child = ptr->left_child;
          else
              parent->left_child = ptr->left_child;
       }    
       else 
           root = root->left_child;
       
       ptr = NULL;
       printf("\n�w�R��\n");
       return 0;
    } 
      
//�����l��M�k�l��
    parent = ptr;
    child = ptr->left_child;

    while(child->right_child != NULL){ //ptr���V����Ƥw�Q�R�� parent���U��쥻child���a�� child���k�l���ܦ�child 
     
        parent = child;
        child = child->right_child;
    } 
    
    ptr->data = child->data; //ptr already���U�� �ҥH�쥻ptr���V��data = �쥻��child���V��Data 
    
    if(parent->left_child == child)
        parent->left_child = child->left_child; 
    else 
        parent->right_child = child->left_child;
      
    child = NULL;
    printf("\n�w�R��\n");
    return 0;
}

void preorder(bst ptr){

    if(ptr != NULL){
    
        printf("%d, ", ptr->data);
		preorder(ptr->left_child);
        preorder(ptr->right_child);
    }    
}
void inorder(bst ptr){

    if(ptr != NULL){
    
        inorder(ptr->left_child);
        printf("%d, ", ptr->data);
        inorder(ptr->right_child);
    }    
}

void postorder(bst ptr){

    if(ptr != NULL){
    
        postorder(ptr->left_child);
        postorder(ptr->right_child);
		printf("%d, ", ptr->data);
    }    
}

