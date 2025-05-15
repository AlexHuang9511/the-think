#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

  printf("server\n");
  int maxPlayer;
  int clients[10];
  struct sockaddr_in server_addr;

  if (argc != 2) {
    printf("Usage: ./main <# of players>\n");
    exit(EXIT_FAILURE);
  } else {
    maxPlayer = strtol(argv[1], NULL, 0);
  }

  for (int i=0; i < 10; i++) {
    clients[i] = 0;
  }

  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) != 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  if (listen(sfd, maxPlayer) != 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  int kq = kqueue();
  if (kq < 0) {
    perror("kqueue");
    exit(EXIT_FAILURE);
  }

  struct kevent change;


  return 0;
}

