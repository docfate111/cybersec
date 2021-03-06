#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int param_1,char *param_2){
  int fd;
  unsigned int index;
  unsigned int chunk_size;
  char *pcVar2;
  long lVar3;
  char **ppcVar4;
  long in_FS_OFFSET;
  int local_12c;
  char *allocations [16];
  char input [136];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = 0x10;
  ppcVar4 = allocations;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *ppcVar4 = (char *)0x0;
    ppcVar4 = ppcVar4 + 1;
  }
  local_12c = 0;
  while (local_12c < 8) {
    fd = rand();
    *(char *)((long)local_12c + 0x427d40) = (char)fd + (char)(fd / 0x1a) * -0x1a + 'a';
    local_12c = local_12c + 1;
  }
  if (0 < param_1) {
    puts("###");
    printf("### Welcome to %s!\n",*param_2);
    puts("###");
    puts(
        "This challenge allows you to perform various heap operations, some of which may involve the flag."
        );
    puts(
        "Through this series of challenges, you will become familiar with the concept of heap exploitation.\n"
        );
    printf("This challenge can manage up to %d unique allocations.\n\n",0x10);
    printf("In this challenge, there is a secret stored at %p.\n",0x427d40);
    puts("If you can leak out this secret, you can redeem it for the flag.\n");
    while(1) {
      while(1) {
        printf("[*] Function (malloc/free/puts/scanf/send_flag/quit): ");
        scanf("%127s",input);
        fd = strcmp(input,"malloc");
        if (fd == 0) break;
        fd = strcmp(input,"free");
        if (fd == 0) {
          printf("Index: ");
          scanf("%127s",input);
          index = atoi(input);
          if (0xf < index) {
            perror("allocation_index < 16");
            return 0;
          }
          printf("[*] free(allocations[%d])\n",(unsigned long)index);
          free(allocations[index]);
        }
        else {
          fd = strcmp(input,"puts");
          if (fd == 0) {
            printf("Index: ");
            scanf("%127s",input);
            index = atoi(input);
            if (0xf < index) {
              perror("allocation_index < 16");
              return 0;
            }
            printf("[*] puts(allocations[%d])\n",(unsigned long)index);
            printf("Data: ");
            puts(allocations[index]);
          }
          else {
            fd = strcmp(input,"scanf");
            if (fd == 0) {
              printf("Index: ");
              scanf("%127s",input);
              index = atoi(input);
              if (0xf < index) {
                perror("allocation_index < 16");
                return 0;
              }
              chunk_size = malloc_usable_size(allocations[index]);
              sprintf(input,"%%%ds",(unsigned long)chunk_size);
              printf("[*] scanf(\"%s\", notebook[%d])\n",input,(unsigned long)index);
              scanf(input,allocations[index],allocations[index]);
            }
            else {
              fd = strcmp(input,"send_flag");
              if (fd == 0) {
                printf("Secret: ");
                scanf("%127s",input);
                fd = strncmp(input,(char *)0x427d40,8);
                if (fd == 0) {
                  puts("Authorized!");
                  fd = open("/flag",0);
                  sendfile(1,fd,(off_t *)0x0,0x80);
                } else {
                  puts("Not authorized!");
                }
              } else {
                fd = strcmp(input,"quit");
                if (fd == 0) {
                  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
                    return 0;
                  }
                   exit();
                }
                puts("Unrecognized choice!");
              }
            }
          }
        }
      }
      printf("Index: ");
      scanf("%127s",input);
      index = atoi(input);
      if (0xf < index) break;
      printf("Size: ");
      scanf("%127s",input);
      chunk_size = atoi(input);
      printf("[*] allocations[%d] = malloc(%d)\n",(unsigned long)index,(unsigned long)chunk_size);
      pcVar2 = (char *)malloc((unsigned long)chunk_size);
      allocations[index] = pcVar2;
      printf("[*] allocations[%d] = %p\n",(unsigned long)index,allocations[index]);
    }
    perror("allocation_index < 16","<stdin>",0x4a,(char *)&__PRETTY_FUNCTION__.4437);
  }
  perror("argc > 0","<stdin>",0x32,(char *)&__PRETTY_FUNCTION__.4437);
}