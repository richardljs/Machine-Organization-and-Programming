/* Assignment 4 intdate.c 
* Richard Lee            Section 2 
* 
* This program sets an alarm to go off every 3 second (forever). 
*/

#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void alarm(int i);

int alarmtime = 3;
int ctrl_c = 0;

/* handle_sigalrm is a handler function that catches the SIGALRM signal
 * and displays the current time in a specified format and rearms the alarm.
 */
void handle_sigalrm() {
   time_t rawtime;
   time(&rawtime);
   printf("current time is %s", ctime (&rawtime) );
   alarm(alarmtime);
}

/* Function to count the number of ctrl + c pressed and to exit appropriately */
void handle_sigint() {
   ctrl_c ++;
   if(ctrl_c != 5) {
      printf("\nControl-c caught. %d more before program is ended.\n", 5 - ctrl_c);
      signal(SIGINT, handle_sigint);
   } else {
      printf("\nFinal Control-c caught. Exiting.\n");
      exit(0);
   }
}

int main()
{
   printf("Date will be printed every 3 seconds.\n");
   printf("Enter ^C to end the program:\n");

   /*Structs for handler functions*/
   struct sigaction sa, sb;
   sa.sa_handler = (&handle_sigalrm);
   sb.sa_handler = (&handle_sigint);

   if(sigaction(SIGALRM, &sa, NULL) != 0){
         printf("Sigalrm Handler execution failed!\n");
         exit(1);
   }

   if(sigaction(SIGINT, &sb, NULL) != 0){
         printf("Sigint Handler execution failed!\n");
         exit(1);
   }

   /* Arm the alarm */
   alarm(alarmtime);
   /* Arm the signal interrupt for control + c */
   signal(SIGINT, handle_sigint);
   
   while(1) {}

   return 0;
}	
    
