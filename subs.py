import sqlite3
import webbrowser


def add_to_sub_list():
    fname = input('First name: ')
    lname = input('Last name: ')
    email = input('E-mail: ')
    filename = 'test.html'
    file = open(filename, 'w')
    content = '<html><head><title>Test List</title><link rel="stylesheet" type="text/css" href="style.css" />' \
              '</head><body><table><tr><th>ID</th><th>First Name</th><th>Last Name</th><th>E-mail</th></tr>'

    conn = sqlite3.connect('testList.db')
    conn.execute('''CREATE TABLE IF NOT EXISTS SUBSCRIBERS(ID INTEGER PRIMARY KEY AUTOINCREMENT, FIRSTNAME TEXT NOT NULL, LASTNAME TEXT NOT NULL, EMAIL TEXT);''')
    conn.execute("INSERT INTO SUBSCRIBERS (FIRSTNAME, LASTNAME, EMAIL) VALUES (?, ?, ?);", (fname, lname, email))
    conn.commit()

    result = conn.execute('''SELECT * FROM SUBSCRIBERS''')
    for row in result:
        content += '<tr><td>' + str(row[0]) + '</td>'
        content += '<td>' + row[1] + '</td>'
        content += '<td>' + row[2] + '</td>'
        content += '<td>' + row[3] + '</td></tr>'

    content += '</table></body></html>'
    conn.close()

    file.write(content)
    file.close()

    webbrowser.open_new_tab(filename)


add_to_sub_list()
