/* Assignment 1 stats.c
 * by Richard Lee, Section 2
 *
 * This program reads integers from a binary file and computes 
 * the integer average of those integers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

/* This program will read integers from a binary file,
 * and will compute the integer average of them and print
 * them out.
 */
int main(int argc, char *argv[])
{
    /* variables to store the file descriptors and to check for errors
       when reading the files and closing them. */
    char *inFile;
    int fd;
    int cls;

    /* if the number of command line arguments are invalid, print
     * the information and exit.
     */
    if (argc != 2) 
    {
        fprintf(stderr, "usage: stats <file>\n");
        exit(1);
    }

    /* Assign the second argument to inFile */
    inFile = argv[1];

    /* Opens the file in read only mode */
    fd = open(inFile, O_RDONLY);

    /* Make sure that opening the file did not fail */
    assert(fd > -1);  

    /* Finding out the number of bits to set the array size later */
    struct stat fileStat;
    fstat(fd, &fileStat);
    int size = fileStat.st_size;

    /* Pointer to the array of integers */
    int *integers;

    integers = (int *)malloc(size);

    /* reading file */
    int count = 0;
    while (1) { 
        int rc;
        rc = read(fd, &(integers[count]), sizeof(int));
        /* if EOF */
        if (rc == 0)
            break;
        if (rc < 0) {
            fprintf(stderr, "Failed reading file!\n");
            free(integers);
            cls = close(fd);
            assert(cls > -1);
            exit(1);
        }
        count ++;
    }

    /* Close file */
    cls = close(fd);

    /* Make sure closing the file has no issues */
    assert(cls > -1);

    int i;
    int average;
    int sum = 0;

    /* Sum all the integers in the array up */
    for(i = 0; i < (size/4); i ++) {
        sum += integers[i];
    }

    /* Compute the average of the numbers */
    average = sum/(size/4);

    printf("integers read : %d | Average : %d\n",(size/4), average);

    free(integers);

    return 0;
}
