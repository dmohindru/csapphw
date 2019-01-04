static char *rover;           /* Next fit rover initalized in mm_init function */
static void *find_fit(size_t asize)
{
    char *old_rover = rover;

    /* Loop till Epilogue header */
    for ( ; GET_SIZE(rover)>0; rover=NEXT_BLK(rover)) {
        if (GET_SIZE(rover) >= asize && !GET_ALLOC(HDRP(rover)))
            return rover;
    }

    /* Search from begining till the old_rover */
    for (rover = heap_listp; rover < old_rover; rover=NEXT_BLK(rover)) {
        if (GET_SIZE(rover) >= asize && !GET_ALLOC(HDRP(rover)))
            return rover;
    }
    
    /* If reached till here. No free blocks available */
    return 0;

}