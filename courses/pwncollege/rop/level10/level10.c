void vuln(undefined8 param_1,undefined8 *param_2){
  ssize_t sVar1;
  undefined8 buf;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_c;
  puts("###");
  printf("### Welcome to %s!\n",*param_2);
  puts("###\n");
  buf = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  printf("[LEAK] Your input buffer is located at: %p.\n\n",&buf);
  sVar1 = read(0,&buf,0x1000);
  local_c = (undefined4)sVar1;
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
