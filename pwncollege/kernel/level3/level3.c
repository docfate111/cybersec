undefined8 device_ioctl(undefined8 param_1,uint param_2,undefined8 param_3){
  undefined8 uVar1;
  printk("[device_ioctl] file=%px, cmd=%du, arg=%lu",param_1,(ulong)param_2,param_3);
  uVar1 = 0xffffffffffffffff;
  if (param_2 == 0x539) {
    __x86_indirect_thunk_rbx();
    uVar1 = 0;
  }
  return uVar1;
}

void win(void){
  printk("[flag] %s",flag);
  return;
}
