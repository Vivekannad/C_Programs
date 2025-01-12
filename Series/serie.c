#include <stdio.h>



int main(){
    /*
    //Expected Ouput:- Geometric Series: 2, 6, 18, 54, 162 if common ratio = 3 and n = 5 and firstTerm = 2.
    int firstTerm , commonRatio , n, i;

    printf("Enter the first term: ");
    scanf("%d", &firstTerm);
    printf("ENter the common ratio: ");
    scanf("%d", &commonRatio);
    printf("ENter the number of terms: ");
    scanf("%d", &n);

    printf("Geometric Series: ");
    for(i = 1; i <= n; i++){
        printf("%d ,", firstTerm );
        firstTerm = firstTerm * commonRatio;
    }

    */

   /*
   //Expected Output:- Arithmetic Series: 3, 7, 11, 15, 19, 23 if common diff = 4 and n = 6 and firstTerm = 3; 
   int firstTerm , commonDiff , n , i;
   printf("Enter the first term: ");
   scanf("%d", &firstTerm);
   printf("Enter the common difference: ");
   scanf("%d", &commonDiff);
   printf("ENter the number of terms ");
   scanf("%d", &n);

   printf("Arithmetic Series: ");

   for(i = 0; i < n; i++){
    printf(" %d,", firstTerm);
    firstTerm += commonDiff;
   }

    */

   //Fibonacci Series
   /*
   int firstTerm = 0, lastTerm = 1, n , i , finalTerm = 0;

   printf("Enter the number of terms: ");
   scanf("%d", &n);
   for(i = 0; i < n; i++){
    printf("%d ", finalTerm);
    firstTerm = lastTerm;
    lastTerm = finalTerm;
    finalTerm = finalTerm + firstTerm;

    
   }
   */
    return 0;
}