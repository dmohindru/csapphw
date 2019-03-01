/* 
 * Readers-writers solution that is fair to both readers and
 * writers. Simplifying assumption is that the number of concurrent
 * active readers is at most N.
 *
 * Source: Henri Casanova, University of Hawaii
*/
/* $begin rw3 */
#include "csapp.h"

#define N 4
#define WRITE_LIMIT 100000
#define PEOPLE 8

/* Global variables */
sem_t sem;    /* Initially = N */
sem_t wmutex; /* Initially = 1 */
int readtimes, writetimes;

void reader(void) 
{
    while (1) {
	P(&sem);
	readtimes++;

	/* Critical section: */
	/* Reading happens   */

	V(&sem);
    }
}

void writer(void) 
{
    int i;

    while (1) {
	P(&wmutex);
	for (i=0; i<N; i++)
	    P(&sem);
	V(&wmutex);
	/* Critical section: */
	/* Writing happens   */
	writetimes++;
	if (writetimes == WRITE_LIMIT) {
      printf("read/write: %d/%d\n", readtimes, writetimes);
      exit(0);
    }

	for (i=0; i<N; i++)
	    V(&sem);
    }
	
}
/* $end rw3 */
void init(void) {
  readtimes = 0;
  writetimes = 0;
  Sem_init(&sem, 0, N);
  Sem_init(&wmutex, 0, 1);
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