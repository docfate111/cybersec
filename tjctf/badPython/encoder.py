import random
import itertools
import functools
P = lambda a, b: (ord(a)^ord(b)).to_bytes(1,'big')
#15 unknown chars
B=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o']
E = ((0,3),(1,4),(0,1),(3,4),(2,3),(1,2))
B=sorted(list(B))
x = lambda a, b: ((ord(a)-ord(b))^1023)>=0
def u(li):
    return [li[i::3] for i in range(3)] #every element with index i such that i+3 mod 3 == 0
def W(i):
    random.shuffle(i)
    return [n(True,x(i[E[j][0]],i[E[j][1]])) for j in range(len(E))][-1]
def n(g,k):
    return (g[0] and k)
f=u(B)
a='Lorem ipsum dolor sit amet, consectetur adipiscing elit/n'
print(repr(b''.join([functools.reduce(P,[(((ord(a[i])&(~ord(f[j][i%5])))|((~ord(a[i]))&(ord(f[j][i%5])))).to_bytes(1,"big")) for j in range(len(f))]) for i in range(len(a))])))

#   if c%100000==0:
#     print(i)
#     print(c)