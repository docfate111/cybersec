int main(int param_1,char *param_2){
  int __fd;
  uint uVar1;
  long in_FS_OFFSET;
  int flag_buffer_allocated;
  void *flag_buffer;
  char *allocated_memory;
  char input [136];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  allocated_memory = (char *)0x0;
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
            printf("[*] Function (malloc/free/puts/read_flag/quit): ");
            scanf("%127s",input);
            __fd = strcmp(input,"malloc");
            if (__fd != 0) break;
            printf("Size: ");
            scanf("%127s",input);
            uVar1 = atoi(input);
            printf("[*] allocations[%d] = malloc(%d)\n",0,(ulong)uVar1);
            allocated_memory = (char *)malloc((ulong)uVar1);
            printf("[*] allocations[%d] = %p\n",0,allocated_memory);
          }
          __fd = strcmp(input,"free");
          if (__fd != 0) break;
          printf("[*] free(allocations[%d])\n",0);
          free(allocated_memory);
        }
        __fd = strcmp(input,"puts");
        if (__fd != 0) break;
        printf("[*] puts(allocations[%d])\n",0);
        printf("Data: ");
        puts(allocated_memory);
      }
      __fd = strcmp(input,"read_flag");
      if (__fd != 0) break;
      flag_buffer_allocated = 0;
      while (flag_buffer_allocated < 1) {
        printf("[*] flag_buffer = malloc(%d)\n",0x3dd);
        flag_buffer = malloc(0x3dd);
        printf("[*] flag_buffer = %p\n",flag_buffer);
        flag_buffer_allocated = flag_buffer_allocated + 1;
      }
      __fd = open("/flag",0);
      read(__fd,flag_buffer,0x80);
      puts("[*] read the flag!");
    }
    __fd = strcmp(input,"quit");
    if (__fd == 0) break;
    puts("Unrecognized choice!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}