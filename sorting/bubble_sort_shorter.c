#include<stdio.h>
void main(){
	 int a[5]={5,1,4,3,2},i,j,temp;
	 for(i=0;i<5;i++){
	 	for(j=0;j<5-i-1;j++){
	 		if(a[j]>a[j+1]){
	 			temp=a[j];
	 			a[j]=a[j+1];
	 			a[j+1]=temp;
			 }                     
		 }
	 }for(i=0;i<5;i++){
	 	printf("%d",a[i]);
	 }
}