undefined8 main(int param_1,undefined8 *param_2){
  int __fd;
  uint usable_size;
  long in_FS_OFFSET;
  int flagAllocated;
  void *flag_buf;
  char *ptr;
  char buf [136];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  ptr = (char *)0x0;
  if (param_1 < 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("argc > 0","<stdin>",0x19,(char *)&__PRETTY_FUNCTION__.4419);
  }
  puts("###");
  printf("### Welcome to %s!\n",*param_2);
  puts("###");
  puts(
      "This challenge allows you to perform various heap operations, some of which may involve theflag."
      );
  puts(
      "Through this series of challenges, you will become familiar with the concept of heapexploitation.\n"
      );
  printf("This challenge can manage up to %d unique allocations.\n\n",1);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              printf("[*] Function (malloc/free/puts/scanf/read_flag/quit): ");
              scanf("%127s",buf);
              __fd = strcmp(buf,"malloc");
              if (__fd != 0) break;
              printf("Size: ");
              scanf("%127s",buf);
              usable_size = atoi(buf);
              printf("[*] allocations[%d] = malloc(%d)\n",0,(ulong)usable_size);
              ptr = (char *)malloc((ulong)usable_size);
              printf("[*] allocations[%d] = %p\n",0,ptr);
            }
            __fd = strcmp(buf,"free");
            if (__fd != 0) break;
            printf("[*] free(allocations[%d])\n",0);
            free(ptr);
          }
          __fd = strcmp(buf,"puts");
          if (__fd != 0) break;
          printf("[*] puts(allocations[%d])\n",0);
          printf("Data: ");
          puts(ptr);
        }
        __fd = strcmp(buf,"scanf");
        if (__fd != 0) break;
        usable_size = malloc_usable_size(ptr);
        sprintf(buf,"%%%ds",(ulong)usable_size);
        printf("[*] scanf(\"%s\", notebook[%d])\n",buf,0);
        scanf(buf,ptr,ptr);
      }
      __fd = strcmp(buf,"read_flag");
      if (__fd != 0) break;
      flagAllocated = 0;
      while (flagAllocated < 1) {
        printf("[*] flag_buffer = malloc(%d)\n",0x33c);
        flag_buf = malloc(0x33c);
        printf("[*] flag_buffer = %p\n",flag_buf);
        flagAllocated = flagAllocated + 1;
      }
      __fd = open("/flag",0);
      read(__fd,flag_buf,0x80);
      puts("[*] read the flag!");
    }
    __fd = strcmp(buf,"quit");
    if (__fd == 0) break;
    puts("Unrecognized choice!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}