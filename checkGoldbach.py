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


def check_goldbach(lower, upper):
	exceptions = []
	message = ''
	primes = [num for num in range(3, upper - 1, 2) if is_prime(num)]
	primes.append(2)
	for i in range(lower // 2, upper // 2 + 1):
		exception = True
		for prime in primes:
			if i < (1 + prime) / 2:
				pass
			elif isPrime(2 * i - prime):
				exception = False
				message += f'{2*i}={prime}+{2*i-prime}\n'
				break
			else:
				exception = True
		if exception:
			if i > lower / 2:
				exceptions.append(2 * i)
	if exceptions:
		message += f'Even numbers that do not satisfy Goldbach conjecture between {lower} and {upper} are: '
		for exception in exceptions:
			message += str(exception) + ', '
		message = message[:-2] + '.'
	else:
		message += f'All the even numbers between {lower} and {upper} satisfy Goldbach conjecture.'
	print(message)


check_goldbach(1, 1000000)
