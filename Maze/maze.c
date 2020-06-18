#include <stdio.h>
typedef struct{
	int row;
	int col;
	int dir;
}element;
int top = -1;

typedef struct{
	int vert;
	int horiz;
}offsets;

void maze_zero(int **maze,int row,int col);
void maze_print(int **maze,int row,int col);
void maze_input(int **maze,FILE *fptr,int row,int col);
void stack_zero(element *stack,int n);
void move_creat(offsets *move);
int find(int **mark,element *stack,offsets *move,int exit_row,int exit_col);
void stack_printf(element *stack);
void point(int dir);

int main(){
	FILE *fptr;
	char *name;
	printf("輸入路徑:");
	scanf("%s",name);
	puts("");
	fptr = fopen(name,"r");//C:\\file\\maze.txt 
	int row, col;
	fscanf(fptr,"%d %d",&row,&col);
	
	int exit_row, exit_col;
	fscanf(fptr,"%d %d", &exit_row, &exit_col);
	exit_row--;
	exit_col--;
	int maze[row][col];
	int mark[row][col];
	
	int *p[row];
	int i,j;
	for(i = 0;i < row;i++){
		p[i] = maze[i];
	}
	
	int *p_mark[row];
	for(i = 0;i < row;i++){
		p_mark[i] = mark[i];
	}
	
	maze_zero(p,row,col);	
	maze_input(p,fptr,row,col);
	fclose(fptr);
	
	
	for(i = 0;i < row;i++){
		for(j = 0;j < col;j++){
			mark[i][j] = maze[i][j];
		}
	}
	
	element stack[row*col];
	stack_zero(stack,row*col);
	top = 0;
	
	offsets move[8];
	move_creat(move);
	int check = find(p_mark,stack,move,exit_row,exit_col);
	
	maze_print(p,row,col);
	printf("\n");
	if(check == -1){
		printf("找不到路\n");
	}else{
		stack_printf(stack);
	}
	
}
void maze_zero(int **maze,int row,int col){
	int i,j;
	
	for(i = 0;i < row;i++){
		for(j = 0;j < col;j++){
			maze[i][j] = 0;
		}
	}
}

void maze_print(int **maze,int row,int col){
	int i,j;
	
	for(i = 0;i < row;i++){
		for(j = 0;j < col;j++){
			printf("%d",maze[i][j]);
			if(j == (col-1)){
				printf("\n");
			}
		}
	}
}

void maze_input(int **maze,FILE *fptr,int row,int col){
	int i = 0,j = 0;
	
	for(i = 0;i < row;i++){
		for(j = 0;j < col;j++){
			fscanf(fptr,"%d",&maze[i][j]);
		}
	}
	
} 
void stack_zero(element *stack,int n){
	int i;
	for(i = 0;i < n;i++){
			stack[i].row = 0;
			stack[i].col = 0;
			stack[i].dir = 0;
	}
}

void move_creat(offsets *move){
	//N
	move[0].vert = -1;
	move[0].horiz = 0;
	//NE
	move[1].vert = -1;
	move[1].horiz = 1;
	//E
	move[2].vert = 0;
	move[2].horiz = 1;
	//SE
	move[3].vert = 1;
	move[3].horiz = 1;
	//S
	move[4].vert = 1;
	move[4].horiz = 0;
	//SW
	move[5].vert = 1;
	move[5].horiz = -1;
	//W
	move[6].vert = 0;
	move[6].horiz = -1;
	//NW
	move[7].vert = -1;
	move[7].horiz = -1;
}

int find(int **mark,element *stack,offsets *move,int exit_row,int exit_col){
	int i = 0,nextrow, nextcol, dir = 0, found = 0;
	mark[1][1] = 1;
	stack[0].row = 1; stack[0].col = 1;
	
	while(top > -1 && found == 0){
		while(dir < 8 && found == 0){
			nextcol = stack[top].col+move[dir].horiz;
			nextrow = stack[top].row+move[dir].vert;
			
			if(nextrow == exit_row && nextcol == exit_col){
				stack[top].dir = dir;
				stack[++top].row = nextrow; 
				stack[top].col = nextcol;
				stack[top].dir = -1;
				return 0;
			}else if(mark[nextrow][nextcol] == 0){
				stack[top].dir = dir;
				stack[++top].row = nextrow; 
				stack[top].col = nextcol;
				mark[nextrow][nextcol] = 1;
				dir = 0;
			}else{
				dir++;
			}			
		}
		
		top--;
		dir = 0;
	}
	
	return -1;
}

void stack_printf(element *stack){
	int i;
	printf("row  col  dir\n");
	for(i = 0;i < top+1;i++){
		printf("%d    ",stack[i].row);
		printf("%d    ",stack[i].col);
		point(stack[i].dir);
	}
	
}

void point(int dir){
	switch(dir){
		case -1:
			printf("終點\n");
			break;
		case 0:
			printf("上\n");
			break;
		case 1:
			printf("右上\n");
			break;
		case 2:
			printf("右\n");
			break;
		case 3:
			printf("右下\n");
			break;	
		case 4:
			printf("下\n");
			break;
		case 5:
			printf("左下\n");
			break;
		case 6:
			printf("左\n");
			break;
		case 7:
			printf("左上\n");
			break;						
	}
}
