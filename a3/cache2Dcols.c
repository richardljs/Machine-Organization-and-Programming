/* Assignment 3 cache2Dcols.c 
* Richard Lee            Section 2 
* 
* This program fills a 2-D array of row size 2000 and column size 1000 
* with each element of the value of its row index + its column index
*/
  
int rowsize = 3000;        /* size of the column in the array to be initialize */
int columnsize = 500;      /* size of the row in the array to be initialize */
int array[3000][500];      /* declaring and initializing the array */

/* This main method fills the 2D array with the value of row + column through 
*  2 for loops using the column-major order.
*/
int main()
{	
   int i;                   /* column iteration loop variable */
   for(i = 0; i < columnsize; i++){
      int j;                /* row iteration loop variable */
      for(j = 0; j < rowsize; j++){
         array[j][i] = i + j;    /* array[j][i] instead of [i][j] for column-major order */
      }
   }
   return 0;
}
		
