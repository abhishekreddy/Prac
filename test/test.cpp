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
#include <stringsupport.h>
#include <string.h>
#include <sort.h>
#include <stdlib.h>
 
//#define TESTLIST
//#define TESTSTRING
#define SORT

int main()
{
#ifdef TESTLIST
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
	delete list;
#endif
#ifdef TESTSTRING
	char input[1000];
	list<string> printlist;
	list<string>::iterator it;

	Stringsupport *stringobj = new Stringsupport();
	memset(input, 0, sizeof(char) * 1000);

	cout << "Enter string\n";
	cin >> input;
	//if (stringobj->is_polindrome(input)) {
	//	cout << "Given string is polindrome\n";
	//} else {
	//	cout << "Given string is not polindrome\n";
	//}
	printlist = stringobj->find_possible_polindormes(input);
	it = printlist.begin();
	int count = 0;
	while (it != printlist.end()) {
		string poli = (string)(*it);
		cout << poli.c_str() << "\t" << ++count << "\n";
		it++;
	}
#endif
#ifdef SORT
	int *arr;
	int len;
	cout << "Enter array length\n";
	cin >> len;
	arr = static_cast<int*>(malloc(sizeof(int) * len));
	cout << "Enter the numbers to be sorted\n";
		for (int i = 0; i < len; i++)
			cin >> arr[i];
	cout << "Instantiating Sort Helper\n";
	sortHelper* sort = new sortHelper(arr, len);
	cout << "Doing Bubble Sort\n";
	sort->sort(BUBBLE);
#endif
	return 0;
}
