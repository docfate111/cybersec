import pwn
s=pwn.ssh(user='narnia8', password='mohthuphog', host='narnia.labs.overthewire.org', port=2226)
sh=s.run(b'/narnia/narnia8 ')
sh.sendline()
s.close()
