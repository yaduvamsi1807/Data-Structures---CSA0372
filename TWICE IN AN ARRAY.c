#include<stdio.h>
int main() 
{ 
    int arr[] = {20, 30, 10, 2, 10, 20, 30, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    int visited[n];
    int i,j;
 
    for(i=0; i < n; i++){
        
        if(visited[i] == 0){
            int count = 1;
          
            for(j = i+1; j < n; j++) { 
				
				if(arr[i] == arr[j]) 
				{
					count++; 
					visited[j] = 1; 
				} 
			} 
			
            if(count > 1)
                printf("%d ",arr[i]);
        }
    }
   return 0; 
}

