#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool findIfPowerOfTwo(int n)
   {
   return (n != 0) && ((n & (n - 1)) == 0);
   }


int getPowerOfTwo(int n){
   int power = 0;
   bool finished = false;

   while (!finished)
   {
      n = n/2;
      if (n != 0)
      {
         power++;
      }
      else{
         finished = true;
      }
   }
   
   return power;
}

int main() {
   int size_of_input, power, i;
   int sum_of_powers = 0;
   int *users_numbers;

   printf("Enter size of input:\n");
   if (scanf("%d", &size_of_input) <= 0 || size_of_input <= 0 ){
      printf("Invalid size\n");
      return 0;
   }

   printf("Enter numbers:\n");
   users_numbers = malloc(size_of_input * sizeof(int));

    if (!users_numbers){
       printf("Memory error\n");
         return 0;
   }

   for(int i=0; i < size_of_input; i++)
   {
      if (scanf("%d", &users_numbers[i]) <= 0)
      {
         free(users_numbers);
         printf("Invalid number\n");
         return 0;
      }
   }

 for(i=0; i < size_of_input; i++){
    if (users_numbers[i] > 0 && findIfPowerOfTwo(users_numbers[i]))
    { 
       power = getPowerOfTwo(users_numbers[i]);
       printf("The number %d is a power of 2: %d = 2^%d\n", users_numbers[i], users_numbers[i], power);
       sum_of_powers += power;
    }
   }

   printf("Total exponent sum is %d\n", sum_of_powers);

   free(users_numbers);
   return 0;

}  