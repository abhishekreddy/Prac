/*
 * test.c
 *
 * Single linked list file
 *
 * Copyright (C) 2016 Abhishek Reddy kondaveeti
 *
 * Contributor: Abhishek Reddy Kondaveeti <abhishek.kondaveeti@gmail.com>
 *
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */
#include <iostream>
#include <slist.h>

int main()
{
	int loop = 1, choice = 0, data = 0;
	slist *list = NULL;
	while (loop) {
		cout << "Enter the choice\n";
		cout << "1.ADD\n" << "2.DEL\n" << "3.QUIT\n";
		cin >> choice;
		switch (choice)	{
			case 1:
				cout << "Enter the element\n";
				cin >> data;
				if (list != NULL)
					list->add(data);
				else {
					list = new slist(data);
				}
				break;
			case 2:
				list->del();
				break;
			case 3:
			default:
				loop = 0;
		}
		list->display();
	}
	return 0;
}
