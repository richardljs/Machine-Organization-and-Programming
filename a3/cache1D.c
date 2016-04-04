/* Assignment 3 cache1D.c 
* Richard Lee            Section 2 
* 
* This program fills an array of size 2000000 with each element of value
* of the index of its array
*/
double arraysize = 100000;     /* size of array to be initialize */
int arr[100000];             /* declaring and initializing the array */

/* This main method fills the 1D array with the value of its index through 
*  the loop.
*/
int 
main()
{	
   int i; /* for loop iteration variable */
   for(i = 0; i < arraysize; i++){
      arr[i] = i; /* placing the value of its index into the array */
   }
   return 0;
}
		
