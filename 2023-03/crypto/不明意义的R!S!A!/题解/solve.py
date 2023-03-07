from Crypto.Util.number import *
import sympy
import math
def Pollard(N):
    a = 2
    n = 2
    while True:
        a = pow(a, n, N)
        res = math.gcd(a - 1, N)
        if res != 1 and res != N:
            q = N // res
            return res, q
        n += 1
def unprotected(m):
    E = sympy.nextprime(bytes_to_long(b'e is the key of my protect function , do you konw why ?'))
    return m%E
f=open("information.txt","r")
info=f.read().split("\n")[:-1]
protected_hint,N,e,enc1,enc2=[int(i.split("=")[-1]) for i in info]
hint=unprotected(protected_hint)
print(long_to_bytes(hint).decode())
p, q = Pollard(N)
d = inverse(e, (p - 1) * (q - 1))
enc_r = (enc1 * inverse(pow(hint, e, N), N)) % N
enc_flag = (enc2 * inverse(enc_r, N)) % N
m = pow(enc_flag, d, N)
print(long_to_bytes(m).decode())