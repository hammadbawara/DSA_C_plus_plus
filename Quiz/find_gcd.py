def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def mgcd(a, b):
    while b > 0:
        temp = a
        a = b
        b = temp%b
    return a

print(mgcd(10, 20))