#include <stdio.h>
#include <string.h>

void Merge(int a[], int b[], int l, int m, int r){
	int i=l, j=m+1, k=l;
	while(i<=m&&j<=r){
		if(a[i]<a[j])b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	while(i<=m) b[k++]=a[i++];
	while(j<=r) b[k++]=a[j++];
}

void MergePass(int x[], int y[], int s, int n){
	int i=0;
	while(i<=n-2*s){	//剩下不超過2S長度的元素 
		Merge(x, y, i,i+s-1, i+2*s-1);
		i=i+2*s;
	}
	
	if(i+s<n)Merge(x,y,i,i+s-1,n-1);	//剩下的長度小於2*s大於s 
	else{	//剩下的長度小於s 
		for(int j=i;j<=n-1;j++){
			y[j]=x[j];
		}
	}
}

void MergeSort(int a[],int n){
	int b[10];
	int s=1;
	while(s<n){
		MergePass(a,b,s,n);		//把a合併到b中 
		s+=s;
		MergePass(b,a,s,n);		//把b合併到a中 
		s+=s;
	}
}

int main(){
	int a[10]={2,5,1,3,4,9,7,8,6,0};
	int n=10;
	MergeSort(a,n);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;	
}
