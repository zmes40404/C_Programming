#include<stdio.h>
#include<stdlib.h>
//�����e�m�B�z��SWAP(x, y, t)���洫 

typedef struct {
	int	start;
	int	end;
	int	cost;
}mst;

int parent[1000];
void quickSort(mst *e, int left, int right);
void makeSet(int size); 
int find(int v);
int unionSet(int v, int u);

int main(int argc, char *argv[]) {
	int i, n, m, sum = 0, count = 0, set_num = 0;
	mst *e;
	mst *ptr;
	FILE* fin;
	
	if (argc < 1) {
		fin = stdin;
	}
	else {
		fin = fopen(argv[1], "rt");
		if (!fin) {
			fprintf(stderr, "file %s not found\n", argv[1]);
			exit(1);
		}
	}
	fscanf(fin, "%d, %d", &n, &m);
	printf("nodes = %3d, edges = %3d\n", n, m);
	
	e = (mst *)malloc(sizeof(mst)*(m+1));
	for (i = 0; i < m; i++) {
		ptr = &(e[i]);
		fscanf(fin, "%d, %d, %d",);  //������J (Ū�J�ɮפ�A�I��B�I����O) 
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n",); //������X (��XA�I��B�I����O)
	}
	fclose(fin);
	
	//�I�sfunction��l�� 
	
	quickSort(e, 0, m-1);
	puts("");
	puts("MST...������");
	
	for (i = 0; i < m; i++) {
		
		if (count == n - 1) {
			break;
		}
		
		if (unionSet(e[i].start, e[i].end)) { 
			count++;
			
			//�����[�` 
			
			printf("[%3d] start = %3d, end = %3d, cost = %3d\n");//�����L�X 
		}
		
	}
	
	for (i = 0; i < n; i++) {
		if (parent[i] == i) {
			set_num++;
		}
	} 
	
	if () {//������if�P�_���� 
		puts("");
		puts("�䤣��ͦ���");
	}
	else {
		printf("�`����:%d\n", sum);
	} 
	
	free(e);
	return 0;
}


void makeSet(int size){  
//��������� ��l�� 
}

//�N���ƧǪk��g��heap sort
void quickSort(mst *e, int left, int right) {
	int i, j, pivot;
	mst t;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = e[left].cost;

		do {
			do { i++; } while (e[i].cost < pivot);
			do { j--; } while (e[j].cost > pivot);
			if (i < j) {
				SWAP(e[i], e[j], t);
			}
		} while (i < j);

		SWAP(e[left], e[j], t);
		quickSort(e, left, j - 1);
		quickSort(e, j + 1, right);
	}
}

//�ˬd�O�_���j��(���|���Y �Ѧҽҥ��𳹸`�̫�) 
int find(int v) {
//��������� 
}

int unionSet(int v, int vv) {
//��������� 
}
