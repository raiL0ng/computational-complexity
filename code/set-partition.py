import numpy as np

def isSubsetSum(set_list, n, sum):
	if sum == 0:
		return True
	if n == 0 and sum != 0:
		return False

	if set_list[n - 1] > sum:
		return isSubsetSum(set_list, n - 1, sum)

	return isSubsetSum(set_list, n - 1, sum) \
	or isSubsetSum(set_list, n - 1, sum - set_list[n - 1])


def findPartition(set_list, n, sum):
	if sum % 2 != 0:
		return False

	return isSubsetSum(set_list, n, sum // 2)


def print_set(s, n):
    print('{', end=' ')
    k = 1
    for el in s:
        if k == n:
            print(el, '}', end=' ')
        else:
            print(str(el) + ',', end=' ')
        k += 1


def divide_set(set_list, sum):
	cnt = sum
	n = len(set_list)
	tmp_list = set_list
	part = []
	while cnt != 0:
		if cnt < 0:
			tmp_list = np.random.permutation(set_list)
			cnt = sum
			n = len(set_list)
			part = []
		cnt -= tmp_list[n - 1]
		part.append(tmp_list[n - 1])
		n -= 1
	part.sort()
	scnd_part = []
	for el in set_list:
		if el not in part:
			scnd_part.append(el)
	return part, scnd_part
	
	
print('Введите через пробел элементы множества:')
s = input()
set_list = [int(i) for i in s.split(' ')]
set_list = np.array(set_list)

sum = 0
for el in set_list:
	sum += el

if findPartition(set_list, len(set_list), sum) == True:
	print("Данное множество можно разделить на два подмножества равной суммы")
	frst, scnd = divide_set(set_list, sum // 2)
	print('Например:', end=' ')
	print_set(frst, len(frst))
	print_set(scnd, len(scnd))
	
else:
	print("Данное множество нельзя разделить на два подмножества равной суммы")
