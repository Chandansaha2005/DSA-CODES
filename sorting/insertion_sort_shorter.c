#include<stdio.h>
void main(){
	int a[5]={3,5,4,2,1};
	int i,j,n,k,p;
	printf("\n BEFORE SORTING ARRAY ELEMENTS ARE:-\n");
	//INSERTION SORT
	for(i=1;i<5;i++,a[j+1]=k){
		for(k=a[i],j=i-1 ; j>=0 && a[j]>k ; --j){
			a[j+1]=a[j];
		}	
	}printf("\n AFTER SORTING ARRAY ELEMENTS ARE:-\n");
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
}