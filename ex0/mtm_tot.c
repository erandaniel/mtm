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

   printf("Enter size of input:");
   scanf("%d", &size_of_input);

   if(size_of_input <= 0){
      printf("Invalid size");
      return 0;
   }

   printf("Enter numbers:");
   users_numbers = malloc(size_of_input * sizeof(int));

   for(i=0; i < size_of_input; i++)
   {
      if (!scanf("%d", &users_numbers[i]))
      {
         free(users_numbers);
         printf("Invalid number");
         return 0;
      }
   }

 for(i=0; i < size_of_input; i++){
    if (findIfPowerOfTwo(users_numbers[i]))
    { 
       power = getPowerOfTwo(users_numbers[i]);
       printf("The number is %d power of 2: %d = 2^%d\n", users_numbers[i], users_numbers[i], power);
       sum_of_powers += power;
    }
   }

   printf("Total exponent sum is %d", sum_of_powers);

   free(users_numbers);
   return 0;

}  