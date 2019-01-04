/* Solution is quite correct logically 
   Ok well done
*/
static void place(void *bp, size_t asize)
{
    int min_size = DSIZE;
    int size = GET_SIZE(HDRP(bp));
    int block_size, pending_size;
    void *bp_next;

    if ((size - asize) < min_size) {
        /* Can't split this block */
        size = PACK(size, 1);
        PUT(HDRP(bp), size);
        //PUT(FTRP(bp), size);
    }
    else { 
        /* Split this block */
        block_size = GET_SIZE(HDRP(bp));
        size = PACK(asize, 1); /* for allocated block */
        pending_size = PACK(block_size-asize, 0); /* for remaining block */
        /* for allocated block */
        PUT(HDRP(bp), size); 
        //PUT(FTRP(bp), size);
        /* for remaining unallocated block */
        bp_next = bp;
        NEXT_BLKP(bp_next);
        PUT(HDRP(bp_next), pending_size);
        PUT(FTRP(bp_next), pending_size);
    }
}