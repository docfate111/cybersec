int main(int argc,char **argv){
  uint a;
  uint b;
  ulong c;
  char buf[8];
  puts("###");
  printf("### Welcome to %s!\n",*argv);
  puts("###\n");
  puts("This challenge reads in some bytes, overflows its stack, and allows you to perform a ROPattack.");
  puts("Through this series of challenges, you will become painfully familiar with the concept of");
  puts("Return Oriented Programming!\n");
  sz = 10;
  sp = buf;
  rp = (undefined *)register0x00000020;
  bp = &stack0xfffffffffffffff8;
  puts("This challenge doesn\'t give you much to work with, so you will have to be resourceful.");
  puts("What you\'d really like to know is the address of libc.");
  puts("In order to get the address of libc, you\'ll have to leak it yourself.");
  puts("An easy way to do this is to do what is known as a `puts(puts)`.");
  puts("The outer `puts` is puts@plt: this will actually invoke puts, thus initiating a leak.");
  puts("The inner `puts` is puts@got: this contains the address of puts in libc.");
  puts("Then you will need to continue executing a new ROP chain with addresses based on that leak.");
  puts("One easy way to do that is to just restart the binary by returning to its entrypoint.");
  puts("Previous challenges let you write your ROP chain directly onto the stack.");
  puts("This challenge is not so nice!");
  puts("Your input will be read to the .bss, and only a small part of it will be copied to the stack.");
  puts("You will need to figure out how to use stack pivoting to execute your full ropchain!");
  c = read(0,input,0x1000);
  a = (uint)c;
  b = a;
  if ((int)a < 0) {
    b = a + 7;
  }
  printf("Received %d bytes! This is potentially %d gadgets.\n",c & 0xffffffff,(ulong)(uint)((int)b >> 3));
  puts("Let\'s take a look at your chain! Note that we have no way to verify that the gadgets areexecutable");
  puts("from within this challenge. You will have to do that by yourself.");
  b = a;
  if ((int)a < 0) {
    b = a + 7;
  }
  print_chain(input,(ulong)(uint)((int)b >> 3),(ulong)(a + 7));
// in bss 0x4040c0 input
// the first 0x1000 characters are read into input in bss
// then the first 24 bytes of input are copied onto the stack
  memcpy(register0x00000020,input,0x18);
  printf("Of course, only %d bytes of the above ropchain was copied to the stack!\n",0x18);
  puts(
      "Let\'s take a look at just that part of the chain. To execute the rest, you\'ll have topivot the stack!"
      );
  print_chain(rp,3);
  puts("Exiting!");
  return 0;
}
