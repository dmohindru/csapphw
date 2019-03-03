#include <stdio.h>
#include "csapp.h"

/*struct hostent 
{
    char  *h_name;            // official name of host
    char **h_aliases;         // alias list
    int    h_addrtype;        // host address type
    int    h_length;          // length of address
    char **h_addr_list;       // list of addresses
}*/

static sem_t mutex;

static void init_mutex()
{
    Sem_init(&mutex, 0, 1);
}

struct hostent *gethostbyname_ts(const char *name, struct hostent *host)
{
  struct hostent *sharehost;

  P(&mutex);
  sharehost = gethostbyname(name);
  //printf("done with gethostbyname\n");
  // Copy ints
  host->h_addrtype = sharehost->h_addrtype;
  host->h_length = sharehost->h_length;
  //printf("copied ints\n");
  // copy char *
  host->h_name = Malloc(strlen(sharehost->h_name));
  strcpy(host->h_name, sharehost->h_name);
  //printf("copied char *\n");
  //copy char **
  int i;
  for (i = 0; sharehost->h_aliases[i] != NULL; i++) {}
  host->h_aliases = (char **)Malloc(sizeof(char*) * (i+1));
  // copy ever char
  //printf("start copying h_aliases\n");
  for (i = 0; sharehost->h_aliases[i] != NULL; i++)
  {
      host->h_aliases[i] = (char *)Malloc(strlen(sharehost->h_aliases[i]));
      strcpy(host->h_aliases[i], sharehost->h_aliases[i]);
  }
  host->h_aliases[i] = NULL;
  //printf("end copying h_aliases\n");
  //printf("start copying h_addr_list\n");
  for (i = 0; sharehost->h_addr_list[i] != NULL; i++) {}
  host->h_addr_list = (char **)Malloc(sizeof(char*) * (i+1));
  // copy ever char
  for (i = 0; sharehost->h_addr_list[i] != NULL; i++)
  {
      host->h_addr_list[i] = (char *)Malloc(strlen(sharehost->h_addr_list[i]));
      strcpy(host->h_addr_list[i], sharehost->h_addr_list[i]);
  }
  host->h_addr_list[i] = NULL;
  //printf("end copying h_addr_list\n");
  V(&mutex);

  return host;
}
int main(int argc, char *argv[]) {
    init_mutex();
    struct hostent host;
    gethostbyname_ts("127.0.0.1", &host);

    return 0;
    
    
}


