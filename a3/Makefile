BLOCK_SIZE = 64

all: cache1D cache2Drows cache2Dcols
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib $(BLOCK_SIZE) -ds 16384 -da 1 -db $(BLOCK_SIZE) -- cache1D

	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib $(BLOCK_SIZE) -ds 16384 -da 1 -db $(BLOCK_SIZE) -- cache2Drows

	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib $(BLOCK_SIZE) -ds 16384 -da 1 -db $(BLOCK_SIZE) -- cache2Dcols

cache1D: cache1D.c
	gcc -o cache1D cache1D.c -Wall -m32

cache2Drows: cache2Drows.c
	gcc -o cache2Drows cache2Drows.c -Wall -m32

cache2Dcols: cache2Dcols.c
	gcc -o cache2Dcols cache2Dcols.c -Wall -m32

clean:
	rm -rf cache1D cache2Drows cache2Dcols
