/* Assignment 4 division.c 
* Richard Lee            Section 2 
* 
* This program is a simplistic calculator program that loops (forever) that computes
* the operation the user specifies on two integers given by the user.
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int count = 0; /* Global variable that stores the number of completed operations */
int numOfChar = 1024;

/* handle_sigfpe is a handler function that catches the SIGFPE signal
 * and displays an error message and exits the program.
 * This function especially sends error messages regarding division by 0.
 */
void handle_sigfpe() {
   printf ("Sorry, can't divide by 0!\n");
   printf ("Total number of operations done : %d\n", count);
   exit(0);
}

/* handle_sigint is a handler function that catches the SIGINT signal
 * and displays exits the program after displaying the number of 
 * operations completed.
 */
void handle_sigint() {
   printf ("\nTotal number of operations done : %d\n", count);
   exit(0);
}

int main() {

   char integer [numOfChar];  /*Stores user input*/
   int result;                /*Stores the result of the operation*/
   int number1;	            /*Stores the first integer*/
   int number2;               /*Stores the second integer*/

   /*Structs for handler functions*/
   struct sigaction sa, sb;
   sa.sa_handler = (&handle_sigfpe);
   sb.sa_handler = (&handle_sigint);

   if(sigaction(SIGINT, &sb, NULL) != 0){
         printf("Handler execution failed!\n");
         exit(1);
   }

   if(sigaction(SIGFPE, &sa, NULL) != 0){
         printf("Handler execution failed!\n");
         exit(1);
   }

   while(1) {
      
      /*Prompts the user for 2 inputs*/
      printf("Enter first integer: ");
      fgets(integer, numOfChar, stdin);
      number1 = atoi(integer);/*Converts user inputs from string to integer*/

      printf("Enter second integer: ");
      fgets(integer, numOfChar, stdin);
      number2 = atoi(integer);/*Converts user inputs from string to integer*/

      result = number1 / number2;
      printf("%d / %d is %d with a remainder of %d\n", number1, number2, result, number1%number2);

      /*Increment no. of operations*/
      count ++;
   }

   return 0;

}
