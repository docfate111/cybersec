undefined8 device_ioctl(undefined8 param_1,uint n,char *s){
  int iVar1;
  undefined8 uVar2; 
  printk(&DAT_00100518,param_1,(ulong)n,s);
  uVar2 = 0xffffffffffffffff;
  if (n == 0x539) {
    iVar1 = strncmp(s,"qfgzmkvhtclhpaag",0x10);
    if (iVar1 == 0) {
      device_state = 2;
      uVar2 = 0;
    }
    else {
      device_state = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

