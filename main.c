#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {

  printf("server\n");

  int so = socket(AF_INET, SOCK_STREAM, 0);
  if (so < 0) {
    printf("socket err");
    return EXIT_FAILURE;
  }

  return 0;
}

