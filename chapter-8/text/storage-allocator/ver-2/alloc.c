#include <unistd.h>

#include "alloc.h"

static Header base;                     // Empty list to get started
static Header *freep = NULL;            // Start of free list

// General purpose storage allocator
void *mem_alloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned int nunits;

    nunits = (nbytes + (sizeof(Header) - 1)) / sizeof(Header) + 1;
    // No free list yet
    if ((prevp = freep) == NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = freep->s.ptr; 1; prevp = p, p = p->s.ptr)
    {
        // Big enough space
        if (p->s.size >= nunits)
        {
            // Exactly the required space
            if (p->s.size == nunits)
                // Unlink block
                prevp->s.ptr = p->s.ptr;
            else
            {   
                // Allocate tail end
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            
            return (void *)(p + 1);
        }
        // Wrapped around free list
        if (p == freep)
            // Get free space from OS and handle possible failure
            if ((p = more_core(nunits)) == NULL)
                return NULL;
    }
}

// Ask system for memory
static Header *more_core(unsigned int nu)
{
    char *cp;
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    // No space at all
    if (cp == (char *)(-1))
        return NULL;
    up = (Header *)(cp);
    up->s.size = nu;
    mem_free((void *)(up + 1));

    return freep;
}

// Put block ap in free list
void mem_free(void *ap)
{
    Header *bp, *p;

    // Point to block header
    bp = (Header *)(ap) - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        // Check if freed block is at start or end of free list
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;

    if (bp + bp->s.size == p->s.ptr)
    {
        // Join to the right neighbor
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp)
    {
        // Join to the left neighbor
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
        p->s.ptr = bp;
    freep = p;

    return;
}

int free_space()
{
    int sum = 0;
    Header *p, *prevp = NULL;

    for (p = freep->s.ptr; prevp != freep; prevp = p, p = p->s.ptr)
        sum += (p->s.size - 1) * sizeof(Header);

    return sum;
}