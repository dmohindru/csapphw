/* 
 * Readers-writers solution with strong reader priority
*/
/* $begin rw2 */
#include "csapp.h"

#define WRITE_LIMIT 100000
#define PEOPLE 4

/* Global variables */
int readcount, readtimes, writetimes;      /* Initially = 0 */
sem_t w, wg; /* All initially = 1 */

void reader(void) 
{
    while (1) {
	//P(&mutex);
	
	//if (readcount == 1)
	P(&wg);
    P(&w);
	//V(&mutex);
	readtimes++;

	/* Critical section: */
	/* Reading happens   */

	//P(&mutex);
	//readcount--;
	//if (readcount == 0)
	V(&w);
    V(&wg);
	//V(&mutex);
    }
}

void writer(void) 
{
    while (1) {
	//P(&wg);
	P(&w);
	writetimes++;
	if (writetimes == WRITE_LIMIT) {
      printf("read/write: %d/%d\n", readtimes, writetimes);
      exit(0);
    }

	/* Critical section: */
	/* Writing happens   */

	V(&w);
	//V(&wg);
    }
}
/* $end rw2 */
void init(void) {
  readtimes = 0;
  writetimes = 0;
  Sem_init(&w, 0, 1);
  Sem_init(&wg, 0, 1);
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