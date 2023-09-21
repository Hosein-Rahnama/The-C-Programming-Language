#ifndef ALLOC
#define ALLOC

#define NALLOC 1024                 // Minimum number of units to request

typedef long int Align;             // For alignment to long boundary

union header
{
    struct
    {
        union header *ptr;          // Next block if on free list
        unsigned int size;          // Size of this block
    } s;
    Align x;                        // Force alignment of blocks
};

typedef union header Header;

void *mem_alloc(unsigned int);
static Header *more_core(unsigned int);
void mem_free(void *);
int free_space(void);

#endif