/* Assignment 1 game2.c
 * by Richard Lee, Section 2
 *
 * This program is the modified version of the game.c program,
 * which instead reads an ascii text file to fill the linked
 * list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

/* Node struct that builds the linked list */
typedef struct node {
    int x;
    struct node *next;
} Node;

/* Method that creates the linkedlist */
Node * createlist(FILE *fd);

/* Method that adds nodes to the linkedlist */
Node * listadd(Node *head, int intforlist);

/* Method that prints out the integers in the linkedlist (Debugging) */
void printlist(Node *head);

/* Method that loops and starts/end the game */
void playgame(Node * listhead);

/* Method that searches for the number in the linkedlist */
int inlist(Node *head, int intvalue);

int main(int argc, char **argv)
{

    FILE *fd;
    Node *root;    

    /* if the number of command line arguments are invalid, print
     * the information and exit.
     */
    if (argc != 2) 
    {
        fprintf(stderr, "usage: game <file>\n");
        exit(1);
    }

    fd = fopen(argv[1], "r");
    assert(fd != NULL);
    root = createlist(fd);
    playgame(root);
    fclose(fd);
    return 0;
}

/* Method that reads the file and puts the integers into
 * the linkedlist by calling listadd. Returns the head
 * of the list if nothing goes wrong or returns NULL
 * if the list is empty.
 */
Node * createlist(FILE *fd)
{
    char read[60];
    Node *head = NULL;
    while (1) { 
        if(fgets(read, 60, fd) != NULL) {
            int rc;
            rc = atoi(read);
            head = listadd(head, rc);
        }else {
            break;
        }
    }

    if(head == NULL) {
        return NULL;
    }
    else {
        return head;
    }

}

/* Method that adds a new node and makes the new node the head. */
Node * listadd(Node *head, int intforlist)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->x = intforlist;
    if(head == NULL) {
        head = new_node;
        head->next = NULL;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

/* Method for debugging by iterating through the linkedlist
 * and displaying each values in the nodes.
 */
void printlist(Node *head)
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL) 
    {
        printf("%d\n", ptr->x);
        ptr = ptr->next;
    }
    printf("\n");
}

/* Game logic method which prompts the user continuously until
 * the user enters 'q'. Method also lets the user guess whether
 * the number is in the linkedlist.
 */
void playgame(Node * listhead)
{   
    char str[60];
    int number;
    printf("This game has you guess which integers are in the list.\n");
    printf("Enter an integer (followed by the newline)\n");
    printf("or q (followed by the newline) to quit.\n");
    while(1) {
        printf("Integer guess: ");
        if(fgets(str, 60, stdin) != NULL) {
            if(str[0] == 'q') {
                printf("Quitting.\n");
                break;
            }
            else {
                number = atoi(str);
                if(inlist(listhead, number) == 1) {
                    printf("%d is in the list.\n", number);
                }
                else {
                    printf("%d is not in the list.\n", number);
                }
            }

        }
    }
}

/* Method that iterates through the list and finds if the number
 * the user guessed is in the list or not
 */
int inlist(Node *head, int intvalue)
{
    Node *temp;
    temp = head;
    while (temp != NULL) {
        if(temp->x == intvalue) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}




