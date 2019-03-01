/* 
 * Readers-writers solution with weak reader priority
 * From Courtois et al, CACM, 1971.
*/
#include "csapp.h"

#define WRITE_LIMIT 100000
#define PEOPLE 4

/* Global variables */
int readcount, writetimes, readtimes;      /* Initially = 0 */
sem_t mutex, w; /* All initially = 1 */

void reader(void) 
{
    while (1) {
	P(&mutex);
	readcount++;
	if (readcount == 1)
	    P(&w);
	
	V(&mutex);

	/* Critical section: */
	readtimes++;
	/* Reading happens   */

	P(&mutex);
	readcount--;
	if (readcount == 0)
	    V(&w);
	V(&mutex);
    }
}

void writer(void) 
{
    while (1) {
	P(&w);

	/* Critical section: */
	writetimes++;
    if (writetimes == WRITE_LIMIT) {
      printf("read/write: %d/%d\n", readtimes, writetimes);
      exit(0);
    }
	/* Writing happens   */

	V(&w);
    }
}
/* $end rw2 */
void init(void) {
  readcount = 0;
  readtimes = 0;
  writetimes = 0;
  Sem_init(&w, 0, 1);
  Sem_init(&mutex, 0, 1);
}

int main(int argc, char* argv[]) {
  int i;
  pthread_t tid;

  init();

  for (i = 0; i < PEOPLE; i++)
    if (i%2 == 0)
      Pthread_create(&tid, NULL, reader, NULL);
    else
      Pthread_create(&tid, NULL, writer, NULL);

  Pthread_exit(NULL);
  exit(0);
}