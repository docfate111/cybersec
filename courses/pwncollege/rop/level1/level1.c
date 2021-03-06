
undefined8 main(undefined4 param_1,undefined8 *param_2,undefined8 param_3){
  uint uVar1;
  ulong uVar2;
  undefined auStack168 [8];
  undefined8 local_a0;
  undefined8 *local_98;
  undefined4 local_8c;
  undefined local_88 [124];
  int local_c;
  
  local_a0 = param_3;
  local_98 = param_2;
  local_8c = param_1;
  puts("###");
  printf("### Welcome to %s!\n",*local_98);
  puts("###\n");
  puts(
      "This challenge reads in some bytes, overflows its stack, and allows you to perform a ROPattack."
      );
  puts("Through this series of challenges, you will become painfully familiar with the concept of");
  puts("Return Oriented Programming!\n");
  sz = 0x16;
  sp = auStack168;
  rp = (undefined *)register0x00000020;
  bp = &stack0xfffffffffffffff8;
  puts("In this challenge, there is a win() function.");
  printf("win() will open the flag and send its data to stdout; it is at %p.\n",win);
  puts("In order to get the flag, you will need to call this function.\n");
  puts("You can call a function by directly overflowing into the saved return address,");
  printf("which is stored at %p, %d bytes after the start of your input buffer.\n",rp,
         rp + -(long)local_88);
  printf("That means that you will need to input at least %d bytes (%d to fill the buffer,\n",
         rp + (8 - (long)local_88),0x7b);
  printf("%d to fill other stuff stored between the buffer and the return address,\n",
         rp + -(long)local_88 + -0x7b,rp + -(long)local_88);
  puts("and 8 that will overwrite the return address).");
  uVar2 = read(0,local_88,0x1000);
  local_c = (int)uVar2;
  printf("Received %d bytes! This is potentially %d gadgets.\n",uVar2 & 0xffffffff,
         (ulong)(local_88 + -(long)rp + local_c) >> 3,local_88 + -(long)rp);
  puts(
      "Let\'s take a look at your chain! Note that we have no way to verify that the gadgets areexecutable"
      );
  puts("from within this challenge. You will have to do that by yourself.");
  uVar1 = (int)((ulong)(local_88 + -(long)rp + local_c) >> 3) + 1;
  print_chain(rp,(ulong)uVar1,(ulong)uVar1,local_88 + -(long)rp);
  puts("Exiting!");
  return 0;
}

void win(void){
  int __in_fd;
  puts("You win! Here is your flag: ");
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,(off_t *)0x0,0x400);
  puts("");
  return;
}