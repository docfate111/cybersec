import pwn
s=pwn.ssh(user='narnia6', password='neezocaeng', host='narnia.labs.overthewire.org', port=2226)
sh=s.run('/narnia/narnia6 ')
print(sh.recv(timeout=0.2))
s.close()

