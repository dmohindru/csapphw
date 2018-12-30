/* Solution seem quit ok */
static void *find_fit(size_t asize)
{
    char *bp = heap_listp;
    int size;
    /* Loop till Epilogue header */
    while((size=GET_SIZE(HDRP(bp))) != 0) {
        if (size >= asize && !GET_ALLOC(HDRP(bp)))
            return bp;
        else
            NEXT_BLKP(bp);
    }
    /* If reached till here. No free blocks available */
    return 0;

}