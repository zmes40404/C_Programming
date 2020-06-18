#include<stdio.h>
#include<stdlib.h>

typedef struct tree{ 

    int data;
    struct tree *left_child, *right_child;  
}tn,*bst;

bst root = NULL;

void insert(int d);//插入新資料 
void preorder(bst ptr);//前序走訪
void inorder(bst ptr);//中序走訪
void postorder(bst ptr);//後序走訪
int search(int d);//搜尋
bst deletet(int d); //刪除

int main(){
    
    int d, sel;
     
    printf("每個數字代表不同的選擇, 資料皆為整數\n\n");
    printf("(1)新增一筆資料\n(2)刪除一筆資料\n(3)查詢某筆資料\n");
		printf("(4)印出前序走訪結果\n(5)印出中序走訪結果\n(6)印出後序走訪結果\n(7)印出前、中、後序走訪結果\n(0)結束\n\n");
    
    while(1){
        
		printf("請輸入數字決定選擇: (1)增加 (2)刪除 (3)查詢 (4)前序 (5)中序 (6)後序 (7)前、中、後序 (0)結束: ");
        scanf("%d",&sel);
		printf("\n");
		
		switch(sel)
		{
		case 1:
			printf("請輸入想要增加的值: ");
			scanf("%d",&d);
			if(search(d))
			    printf("\n資料重複\n");
            else
			    {
			insert(d);
			printf("數字 %d 已經讀入",d);
			}
			printf("\n");
			break;
	    case 2:
			printf("請輸入欲刪除的值: ");
			scanf("%d",&d);
			deletet(d);

			printf("\n");
			break;
		case 3:
			printf("請輸入欲查詢的數字: ");
			scanf("%d",&d);
			if(search(d))
                printf("\n該值存在\n\n");
            else
                printf("\n該值不存在\n\n");
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
			printf("前序：");
			preorder(root);
			printf("\n\n");
			printf("中序：");
			inorder(root);
			printf("\n\n");
			printf("後序：");
			postorder(root);
			printf("\n\n");
			break;
		default:
		    if(sel != 0)
			    printf("指令錯誤\n");
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

    new_node->data = d; //要新增的資料 
    new_node->left_child = new_node->right_child = NULL; //要新增的節點的左右子樹都是空的 

    if(root == NULL) //如果root是空的 那新節點指定給他 
        root = new_node;  
    else{

        current = root;

        while(!insert){
            if(current->data > new_node->data){//根節點資料比加入的資料大 
                if(current->left_child == NULL){ // 如果左子樹為空 
    
                    current->left_child = new_node;//指定左子樹為新節點 
                    insert = 1;    
                }
                else
                    current = current->left_child; //如果左子樹不為空 則指定給左子樹的左子樹 
            }
            else{//根節點資料比加入的資料小 
        
                if(current->right_child == NULL){ //If右子樹為空 
        
                    current->right_child = new_node; //指定右子樹為新節點 
                    insert = 1;      
                }
                else
                    current = current->right_child; //if not指定給右子樹的右子樹 
            }
        }        
    }
}

int search(int d){  //ptr:操作功能時的暫存指標 

    bst ptr = root; //先指向root 

    while(ptr != NULL){ //root有東西 
    
        if(ptr->data == d) //root=要找的 回傳1 
            return 1;
        else{
        
            if(ptr->data > d) //若指標指向之data大於我們要尋找的d 
                ptr = ptr->left_child; //指向左子樹 
            else
                ptr = ptr->right_child;   //if not指向右子樹 
        }    
    }
    return 0;   
}

bst deletet(int d){
    
	bst parent,ptr,child;
    int find = 0; // 尋找要刪除的 
   
// 找尋刪除節點和其父節點指標 
    parent = ptr = root;
    while(ptr != NULL && !find ){ //迴圈跑跑跑跑到指標為空 或是 find=1 (找到囉) 
        if(ptr->data == d )   //若指向要尋找的 
            find = 1; //找到囉 
        else{
            parent = ptr;  
            
            if(ptr->data > d ) //大於要尋找的 
                ptr = ptr->left_child; //往左子樹尋找 
            else
                ptr = ptr->right_child; //if not go right 
        }       
    }
    
    if ( ptr == NULL ){ 
        printf("\n欲刪除的值不存在\n");
        return 0;  
    }    

//只剩根節點, 並且刪掉根節點 
    if(ptr->left_child == NULL && ptr->right_child == NULL && ptr == root){ //only root is left
        
        root = NULL; //root and ptr都被清空並印出已刪除 
        ptr = NULL;
        printf("\n已刪除\n");
        return 0;
    }  
 
//刪除二元搜尋樹的葉節點
    if(ptr->left_child == NULL && ptr->right_child == NULL ){  
         
         if(parent->left_child == ptr) //ptr指向左子樹 
             parent->left_child = NULL; //把ptr刪掉 
         else
             parent->right_child = NULL; //指向右子樹則刪除右 
       
         ptr = NULL;  
         printf("\n已刪除\n");
         return 0;
    }
    
//沒有左子樹 
    if(ptr->left_child == NULL){ //沒有左子樹 
        
        if(parent != ptr){  //delete left and right child and root at the same time
            
            if(parent->left_child == ptr) //指標指向左子樹 
                parent->left_child = ptr->right_child; //把左子樹的right指定 replace它 
            else
                parent->right_child = ptr->right_child; //or else ptr的右子樹指定 replace 
        }    
        else
            root = root->right_child; //ptr指向root 因為沒有左子樹 右邊往上取代ptr 再刪除 
       
        ptr = NULL; //清空ptr 
        printf("\n已刪除\n"); //印出已刪除~~~ 
        return 0;
    }

//沒有右子樹
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
       printf("\n已刪除\n");
       return 0;
    } 
      
//有左子樹和右子樹
    parent = ptr;
    child = ptr->left_child;

    while(child->right_child != NULL){ //ptr指向的資料已被刪除 parent往下到原本child的地方 child的右子樹變成child 
     
        parent = child;
        child = child->right_child;
    } 
    
    ptr->data = child->data; //ptr already往下移 所以原本ptr指向的data = 原本的child指向的Data 
    
    if(parent->left_child == child)
        parent->left_child = child->left_child; 
    else 
        parent->right_child = child->left_child;
      
    child = NULL;
    printf("\n已刪除\n");
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

