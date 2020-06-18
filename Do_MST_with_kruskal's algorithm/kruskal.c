#include<stdio.h>
#include<stdlib.h>
//完成前置處理器SWAP(x, y, t)的交換 

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
		fscanf(fin, "%d, %d, %d",);  //完成輸入 (讀入檔案內A點至B點的花費) 
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n",); //完成輸出 (輸出A點至B點的花費)
	}
	fclose(fin);
	
	//呼叫function初始化 
	
	quickSort(e, 0, m-1);
	puts("");
	puts("MST...成長中");
	
	for (i = 0; i < m; i++) {
		
		if (count == n - 1) {
			break;
		}
		
		if (unionSet(e[i].start, e[i].end)) { 
			count++;
			
			//成本加總 
			
			printf("[%3d] start = %3d, end = %3d, cost = %3d\n");//完成印出 
		}
		
	}
	
	for (i = 0; i < n; i++) {
		if (parent[i] == i) {
			set_num++;
		}
	} 
	
	if () {//完成此if判斷條件 
		puts("");
		puts("找不到生成樹");
	}
	else {
		printf("總成本:%d\n", sum);
	} 
	
	free(e);
	return 0;
}


void makeSet(int size){  
//完成此函數 初始化 
}

//將此排序法改寫成heap sort
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

//檢查是否為迴路(路徑壓縮 參考課本樹章節最後) 
int find(int v) {
//完成此函數 
}

int unionSet(int v, int vv) {
//完成此函數 
}
