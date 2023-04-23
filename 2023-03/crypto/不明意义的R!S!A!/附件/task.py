import random
from secret import flag,hint
import sympy
from Crypto.Util.number import *
'''
I have carefully protected my information , I promise you can not get my flag !
'''
def protected(m):
    p = getPrime(512)
    q = getPrime(512)
    e = sympy.nextprime(bytes_to_long(b'e is the key of my protect function , do you konw why ?'))
    N =e
    return pow(m, e, N)
def gen_key():
    while(True):
        p=1
        for i in range(30):
            p*=random.getrandbits(16)
        p+=1
        if(isPrime(p)):
            break
    q=getPrime(512)
    e = getPrime(32)
    d = inverse(e, (p - 1) * (q - 1))
    r = getPrime(512)
    N=p*q
    return p,q,N,e,r,d
f=open("information.txt","w")
hint=bytes_to_long(hint)
flag=bytes_to_long(flag)
m1=protected(hint)
m2=protected(flag)
p,q,N,e,r,d=gen_key()
enc1=pow(m1*r,e,N)
enc2=pow(m2*r,e,N)
f.write(f"protected_hint={m1}\nN={N}\ne={e}\nenc1={enc1}\nenc2={enc2}\n")
f.close()
