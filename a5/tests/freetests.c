/* Author : Richard Lee | rlee23@wisc.edu */
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int
main()
{
	assert(Mem_Init(1024) == 0);
	void* pointer = Mem_Alloc(9);
	assert(pointer != NULL);
	assert(Mem_Free(pointer) == 0);
	assert(Mem_Free(NULL) == -1);
	exit(0);
}
