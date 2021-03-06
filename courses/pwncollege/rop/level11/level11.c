void vuln(undefined4 param_1,undefined8 *param_2,undefined8 param_3){
  uint uVar1;
  ulong uVar2;
  long lVar3;
  code **ppcVar4;
  byte bVar5;
  undefined auStack136[8];
  undefined8 local_80;
  undefined8 *local_78;
  undefined4 local_6c;
  code *win;
  undefined buffer[84];
  int local_c;
  bVar5 = 0;
  local_80 = param_3;
  local_78 = param_2;
  local_6c = param_1;
  puts("###");
  printf("### Welcome to %s!\n",*local_78);
  puts("###\n");
  puts("This challenge reads in some bytes, overflows its stack, and allows you to perform a ROPattack.");
  puts("Through this series of challenges, you will become painfully familiar with the concept of");
  puts("Return Oriented Programming!\n");
  lVar3 = 0xb;
  ppcVar4 = &win;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *ppcVar4 = (code *)0x0;
    ppcVar4 = ppcVar4 + (ulong)bVar5 * 0x1ffffffffffffffe + 1;
  }
  win = win;
  sz = 0x12;
  sp = auStack136;
  rp = (undefined *)register0x00000020;
  bp = &stack0xfffffffffffffff8;
  puts("PIE is turned on!");
  puts("This means that you do not know where any of the gadgets in the main binary are.");
  puts("However, you can do a partial overwrite of the saved instruction pointer in order to execute1 gadget!");
  puts("If that saved instruction pointer goes to libc, you will need to ROP from there.");
  puts("If that saved instruction pointer goes to the main binary, you will need to ROP from there.");
  puts("You may need need to execute your payload several times to account for the randomnessintroduced.");
  puts("This might take anywhere from 0-12 bits of bruteforce depending on the scenario.");
  puts("In this challenge, there is a win() function.");
  printf("win() will open the flag and send its data to stdout; it is at %p.\n",win);
  puts("In order to get the flag, you will need to call this function.\n");
  puts("You can call a function by directly overflowing into the saved return address,");
  printf("which is stored at %p, %d bytes after the start of your input buffer.\n",rp,
         rp + -(long)buffer);
  printf("That means that you will need to input at least %d bytes (%d to fill the buffer,\n",
         rp + (8 - (long)buffer),0x50);
  printf("%d to fill other stuff stored between the buffer and the return address,\n",
         rp + (-0x50 - (long)buffer),buffer);
  puts("and 8 that will overwrite the return address).");
  puts("In this challenge, a pointer to the win function is stored on the stack.");
  printf("That pointer is stored at %p, %d bytes before your input buffer.\n",&win,8);
  puts("If you can pivot the stack to make the next gadget run be that win function, you will getthe flag!\n");
  puts("ASLR means that the address of the stack is not known,");
  puts("but I will simulate a memory disclosure of it.");
  puts("By knowing where the stack is, you can now reference data");
  puts("that you write onto the stack.");
  puts("Be careful: this data could trip up your ROP chain,");
  puts("because it could be interpreted as return addresses.");
  puts("You can use gadgets that shift the stack appropriately to avoid that.");
  printf("[LEAK] Your input buffer is located at: %p.\n\n",buffer);
  uVar2 = read(0,buffer,0x1000);
  local_c = (int)uVar2;
  printf("Received %d bytes! This is potentially %d gadgets.\n",uVar2 & 0xffffffff,
         (ulong)(buffer + -(long)rp + local_c) >> 3,buffer + -(long)rp);
  puts(
      "Let\'s take a look at your chain! Note that we have no way to verify that the gadgets areexecutable"
      );
  puts("from within this challenge. You will have to do that by yourself.");
  uVar1 = (int)((ulong)(buffer + -(long)rp + local_c) >> 3) + 1;
  print_chain(rp,(ulong)uVar1,(ulong)uVar1,buffer + -(long)rp);
  puts("Goodbye!");
  return;
}
void win(void){
  int __in_fd;
  puts("You win! Here is your flag: ");
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,(off_t *)0x0,0x400);
  puts("");
  return;
}
