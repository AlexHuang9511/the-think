#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

  printf("server\n");

  struct sockaddr_in server_addr;

  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd < 0) {
    printf("socket err\n");
    return EXIT_FAILURE;
  }

  bzero(&server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) != 0) {
    printf("bind err\n");
    return EXIT_FAILURE;
  }

  return 0;
}

