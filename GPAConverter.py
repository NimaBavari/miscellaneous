#!/usr/bin/python


def convert_to_nearest_base(point):
    bases = [0.0, 0.3, 0.7, 1.0, 1.3, 1.7, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0]
    min_val = 0.4
    result = 0

    for base in bases:
        if min_val > abs(point - base):
            min_val = abs(point - base)
            result = base

    return result


def convert_single_point(point):
    trans_point = point / 20 - 1

    return convert_to_nearest_base(trans_point)


def convert_from_hundred():
    sum_val, count = 0, 0
    point = None

    while not point == 0:
        point = int(input('Enter your point (0 to stop):'))
        while point < 0 or point > 100:
            print("Invalid point!")
            point = int(input('Enter your point (0 to stop):'))
        if not point == 0:
            sum_val += convert_single_point(point)
            count += 1

    final_point = convert_to_nearest_base(sum_val / count)
    print('Your GPA is {}'.format(final_point))


convert_from_hundred()
