# Author: 		Nima Bavari
# e-mail: 		nima.bavari@gmail.com
# Date & time:	June 17, 2017, 05:30:17


def mazeConverter(inputstr):
	output = ''
	temp = []
	numChar = {}
	for char in inputstr:
		if char not in temp:
			temp.append(char)
			numChar[char] = 0

		numChar[char] += 1

	for char in numChar:
		if numChar[char] == 1:
			output += char
		else:
			output += str(numChar[char]) + char

	return output


print(mazeConverter('gkkjfgjfgghjghhgbvlkds'))
