import webbrowser
import math


def is_leap_year(y):
    if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0:
        return True
    else:
        return False


def res_year(y):
    if is_leap_year(y):
        return 2
    else:
        return 1


def res_month(y, m):
    if m in [1, 3, 5, 7, 8, 10, 12]:
        return 3
    elif m in [4, 6, 9, 11]:
        return 2
    elif m == 2:
        if is_leap_year(y):
            return 1
        else:
            return 0
    else:
        return -1


def show_month(y, m):
    total_res = 0
    month_names = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    month_name = month_names[m - 1]
    content = '<h1>' + month_name + ' ' + str(y) + '</h1><table><tr><th>Mo</th><th>Tu</th><th>We</th><th>Th</th><th>Fr</th><th>Sa</th><th>Su</th></tr>'

    for i in range(1, y):
        total_res += res_year(i)

    for i in range(1, m):
        total_res += res_month(y, i)

    if m in [1, 3, 5, 7, 8, 10, 12]:
        days_in_month = 31
    elif m in [4, 6, 9, 11]:
        days_in_month = 30
    elif m == 2:
        if is_leap_year(y):
            days_in_month = 29
        else:
            days_in_month = 28
    else:
        days_in_month = 0

    day_of_week = (total_res % 7) + 1
    for i in range(1, int(math.ceil((days_in_month + day_of_week - 1) / 7) + 1)):
        content += '<tr>'
        if i == 1:
            for j in range(1, day_of_week):
                content += '<td></td>'

            for j in range(day_of_week, 8):
                content += '<td>' + str(j + 1 - day_of_week) + '</td>'
        else:
            for j in range(1, 8):
                if (i - 1) * 7 + j + 1 - day_of_week < days_in_month + 1:
                    content += '<td>' + str((i - 1) * 7 + j + 1 - day_of_week) + '</td>'
                else:
                    content += '<td></td>'

        content += '</tr>'

    content += '</table>'

    filename = 'calendar.html'
    with open(filename, 'w') as f:
        f.write(content)

    webbrowser.open_new_tab(filename)


while True:
    year = int(input('Enter the year: '))
    month = int(input('Enter the month: '))

    while year < 1:
        year = int(input('Please, type in a valid year: '))

    while month < 1 or month > 12:
        month = int(input('Please, type in a valid month: '))

    show_month(year, month)
