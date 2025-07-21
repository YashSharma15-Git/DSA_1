#include <stdio.h>
int main(){

    int arr[100],pos,num,size,k;
    
    printf("Enter the size of the array = \n");
    scanf("%d",&size);
    
    printf("Enter elements in the array = \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<size;j++){
        printf("the element at the index %d is = %d\n",j,arr[j]);
    }
    
    printf("Enter the index = \n");
    scanf("%d",&pos);
    
    printf("Enter the element you want to insert \n");
    scanf("%d",&num);
    
    for(k = size;k>=pos;k--){
        arr[k] = arr[k-1];
    }
    
    arr[pos] = num;
    size++;
    
    for(k=0;k<size;k++){
        printf("the element at the index %d is = %d\n",k,arr[k]);
    }
    
    
    printf("Hello");
    return 0;
}

