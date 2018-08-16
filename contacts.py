#!/usr/bin/env python3

""""
@description    A simple contact manager
@author	        Nima Bavari
                <nima.bavari@gmail.com>
"""

import sqlite3

conn = sqlite3.connect('contacts.db')
contacts = []


def add_new():
    global conn

    print('Add New Contact')
    fname = input('First name: ')
    lname = input('Last name: ')
    email = input('E-mail: ')
    phone = input('Phone number: ')

    conn.execute('''INSERT INTO CONTACTS(FIRSTNAME, LASTNAME, EMAIL, PHONE) VALUES(?, ?, ?, ?)''', (fname, lname, email, phone))
    conn.commit()


def search_contacts():
    global contacts

    print('Look Up A Contact')
    keyword = input('Enter a keyword: ')
    for contact in contacts:
        if keyword in contact.values():
            print('Search results: ')
            print('{}\t{} {}\t{}\t{}'.format(contact['id'], contact['firstname'], contact['lastname'], contact['email'], contact['phone']))


def edit_contact():
    global conn

    print('Edit A Contact')

    id_to_edit = int(input('Enter the ID of the contact you want to edit: '))
    fname = input('First name: ')
    lname = input('Last name: ')
    email = input('E-mail: ')
    phone = input('Phone number: ')

    conn.execute('''UPDATE CONTACTS SET FIRSTNAME = ? AND LASTNAME = ? AND EMAIL = ? AND PHONE = ? WHERE ID = ?''', fname, lname, email, phone, id_to_edit)
    conn.commit()
    print('Contact edited successfully!')


def delete_contact():
    global conn

    print('Delete A Contact')
    id_to_delete = int(input('Enter the ID of the contact you want to delete: '))
    conn.execute('''DELETE FROM CONTACTS WHERE ID = ?''', id_to_delete)
    conn.commit()
    print('Contact deleted successfully!')


def display_all():
    global contacts

    print('Contacts')
    for contact in contacts:
        print('{}\t{} {}\t{}\t{}'.format(contact['id'], contact['firstname'], contact['lastname'], contact['email'], contact['phone']))


def main():
    global conn, contacts

    conn.execute('''CREATE TABLE IF NOT EXISTS CONTACTS(ID INTEGER PRIMARY KEY AUTOINCREMENT, FIRSTNAME TEXT NOT NULL, LASTNAME TEXT NOT NULL, EMAIL TEXT NOT NULL, PHONE INTEGER NOT NULL);''')

    result = conn.execute('''SELECT * FROM CONTACTS''')
    for row in result:
        contact = {'id': str(row[0]), 'firstname': row[1], 'lastname': row[2], 'email': row[3], 'phone': row[4]}
        contacts.append(contact)

    conn.close()

    choice = 0
    while choice != 6:
        print('(-1-) Add New Contact')
        print('(-2-) Search Contacts')
        print('(-3-) Edit Contact')
        print('(-4-) Delete Contact')
        print('(-5-) Display Contacts')
        print('(-6-) Quit')

        choice = int(input('Make your choice: '))
        if choice == 1:
            add_new()
        elif choice == 2:
            search_contacts()
        elif choice == 3:
            edit_contact()
        elif choice == 4:
            delete_contact()
        elif choice == 5:
            display_all()
        elif choice == 6:
            print('Quitting the program...')
        else:
            print('Invalid response...')


main()
