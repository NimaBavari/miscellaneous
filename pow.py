import math

def pow(num, exp):
	if isinstance(exp, int):
		result = 1
		for i in range(exp):
			result *= num
		return result
	elif isinstance(exp, float):
		m = int(exp // 1)
		f = exp % 1
		coefficient = f * math.log(num)
		full_coefficient = 0
		for i in range(21):
			full_coefficient += pow(coefficient, i) / math.factorial(i)
		return pow(num, m) * full_coefficient
	else:
		raise ValueError


print(pow(3.2, 5.7))