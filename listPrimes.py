import math


def is_prime(num):
    if num < 2 or num % 2 == 0:
        return False
    i = 3
    while i < math.sqrt(num):
        if num % i == 0:
            return False
        i += 2
    return True


def list_primes(lower, upper):
    primes = [num for num in range(lower, upper + 1) if is_prime(num)]
    for prime in primes:
        print(prime)


list_primes(20123, 1998876)
