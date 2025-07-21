#include <stdio.h>
int main(){

    int arr[100],pos,num,size,k;
    
    //size of array
    printf("Enter the size of the array = \n");
    scanf("%d",&size);
    
    //elements in array
    printf("Enter elements in the array = \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    //printing array
    for(int j=0;j<size;j++){
        printf("the element at the index %d is = %d\n",j,arr[j]);
    }
    

    //taking index
    printf("Enter the index = \n");
    scanf("%d",&pos);
    

    //value for index
    printf("Enter the element you want to insert \n");
    scanf("%d",&num);


    //shifting of the elements to right
    for(k = size;k>=pos;k--){
        arr[k] = arr[k-1];
    }
    
    //value of that index after shifting
    arr[pos] = num;
    size++;
    
    //printing new array
    for(k=0;k<size;k++){
        printf("the element at the index %d is = %d\n",k,arr[k]);
    }
    
    
    printf("Hello");
    return 0;
}

