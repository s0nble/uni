# Euclidean Algorithm for GCD
def gcd_euclidean(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


# Stein Algorithm (Binary GCD)
def gcd_stein(a, b):
    if a == 0:
        return b
    if b == 0:
        return a

    shift = 0

    while ((a | b) & 1) == 0:
        a >>= 1
        b >>= 1
        shift += 1

    while (a & 1) == 0:
        a >>= 1

    while b != 0:
        while (b & 1) == 0:
            b >>= 1

        if a > b:
            a, b = b, a

        b = b - a

    return a << shift


# Euler Totient Function
def phi(x):
    count = 0
    for i in range(1, x):
        if gcd_euclidean(i, x) == 1:
            count += 1
    return count


# Main program
a = int(input("Enter first positive number: "))
b = int(input("Enter second positive number: "))

print("GCD using Euclidean Algorithm:", gcd_euclidean(a, b))
print("GCD using Stein Algorithm:", gcd_stein(a, b))

x = int(input("Enter a number for Euler Totient (>=100): "))

if x < 100:
    print("Number must be >= 100")
else:
    print("Euler Totient phi(", x, ") =", phi(x))