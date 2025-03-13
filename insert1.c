#include<stdio.h> 
int main() {
   int arr[30], element, num, i, location; 
   printf("\nEnter no of elements :");
   scanf("%d", &num);   
   for (i = 0; i < num; i++) {
      printf("\nEnter the values :");
      scanf("%d", &arr[i]);
   }
   printf("\nEnter the element to be inserted :");
   scanf("%d", &element);
   printf("\nEnter the location");
   scanf("%d", &location);
   for (i = num; i >= location; i--) {
      arr[i] = arr[i - 1]; //if location is say 3,shifting will occur upto index 2 ie index 2’s contents will move to 3
   }                               //as our intention is actually to insert it into the 3rd position ie the 2nd index
   num++;                   //if its desired to literally insert it in index 3,then run the loop from end to index 4 (location+1)
                                    //then insert it at location
   arr[location - 1] = element;
printf("\nThe elements are : ");
   for (i = 0; i < num; i++)
      printf("%d\t",arr[i]);
return 0;

}
