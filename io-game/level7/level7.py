from pwn import *
s = ssh(user='level7', host='io.netgarage.org', password='U3A6ZtaTub14VmwV', port=22)
# game at http://io.netgarage.org/
# a simple buffer overflow with code redirection to shellcode
# strcat causes buffer greeting to overflow
# source /usr/local/peda/peda.py to get peda
# sh = s.run('bash')
s.interactive()
