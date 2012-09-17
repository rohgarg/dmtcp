#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024

void parent(int fd)
{
  int shmid;
  if ((shmid = shmget((key_t) 9979, SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }
  struct shmid_ds shmid_ds;
  if (shmctl(shmid, IPC_STAT, &shmid_ds) == -1) {
    perror("shmctl: shmctl failed");
    exit(1);
  }
  printf("Shmid: %d\n", shmid);

  void *addr = shmat(shmid, NULL, 0);
  if (addr == (void*) -1) {
    perror("main: shmat");
    abort();
  }
  memset(addr, 0, SIZE);

  if (write(fd, &shmid, sizeof(shmid)) != sizeof(shmid)) {
    perror("write");
    abort();
  }

  int *ptr = (int*) addr;
  int i;
  for (i = 1; i< 100000; i++) {
    printf("Server: %d\n", i);
    fflush(stdout);
    *ptr = i;
    while(*ptr != -i)
      sleep(1);
  }
  *ptr = 0;
  exit(0);
}

void child(int fd)
{
  int shmid;
  if (read(fd, &shmid, sizeof(shmid)) != sizeof(shmid)) {
    perror("write");
    abort();
  }

  void *addr = shmat(shmid, NULL, 0);
  if (addr == (void*) -1) {
    perror("Child: shmat");
    abort();
  }

  int *ptr = (int*) addr;
  sleep(2);
  int val;
  while((val = *ptr) != 0) {
    int i = *ptr;
    if (i>0) {
      printf("Client: %d\n", i);
      fflush(stdout);
      *ptr = -i;
    } else {
      sleep(1);
    }
  }
  int a;
  while(!a);
  exit(0);
}

int main(int argc, char **argv)
{
  int fds[2];
  if (pipe(fds) == -1) {
    perror("pipe");
    exit(1);
  }

  if (fork() == 0) {
    child(fds[0]);
  } else {
    parent(fds[1]);
  }
  return 0;
}
