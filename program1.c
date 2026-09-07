#include<stdio.h>

void safeprintf(const void* ptr,int type);

  int main(){
    int intArray[5];
    float floatArray[5];
    int *ip = intArray;
    float *fp = floatArray;
    int i,option,index;


           printf("Enter 5 integer elements:");
              for(i=0;i<5;i++){
                scanf("%d",ip+i);
              }

           printf("Enter 5 floating elements:");
              for(i=0;i<5;i++){
                scanf("%f",fp+i);
              }  
              
            printf("Integer Arrays:\n");
            for(i=0;i<5;i++) 
            {
                printf("%d\n",*(ip+i));
            } 

            printf("Floating Arrays:\n");
            for(i=0;i<5;i++){
                printf("%f",*(fp+i));

            }

                  printf("\n0-Integer 1-floating \n choice:");
                  scanf("%d",&option);

                  printf("Enter index to access:\n");
                  scanf("%d",&index);

                  if(option==0){
                    if(index >= 0 && index < 5)
                     safeprint(ip+index,0);
                     else
                     safeprint(NULL,0);
                  }
                  else if(option ==1){
                    if(index>=0 && index < 5)
                    safeprint(fp+index,1);
                    else 
                    safeprint(NULL,1);
                  }
                  else
                  printf("INvalid choice\n");

                 return 0;
  }

  void safeprint (const void *ptr, int type){
    if(ptr == NULL){
        printf("Pointer is null, nothing to print\n");
        return ;
    }
    if(type == 0){
        printf("integer Value: %d",*(const int*)ptr);
    }
    else if("floating value: %f",*(const float*)ptr);

    else
    printf("Invalid type");
  }