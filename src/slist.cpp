/*
 * slist.cpp
 *
 * Single linked list
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

using namespace std;

slist::slist(int data)
{
	m_list = new struct singlenode;
	m_list->data = data;
	m_list->next = NULL;
}

slist::~slist()
{
	struct singlenode *list = m_list;
	struct singlenode *delnode = NULL;

	while (list->next != NULL) {
		delnode = list->next;
		delete list;
		list = delnode;
	}

	delete list;
	m_list = NULL;
}
int slist::add(int data)
{
	int  rc = 0;
	struct singlenode *newnode = NULL;
	struct singlenode *list = m_list;

	while (list->next != NULL) {
		list = list->next;
	}

	newnode = new struct singlenode;
        list->next = newnode;
        newnode->data = data;
	newnode->next = NULL;
	return rc;
}

int slist::del()
{
	int rc = 0;
	struct singlenode *list = m_list;

	while (list->next != NULL && list->next->next != NULL) {
		list = list->next;
	}
	if (list->next != NULL) {
		delete list->next;
		list->next = NULL;
	}
	return rc;
}
void slist::display()
{
	struct singlenode *list = m_list;
	while(list->next != NULL) {
		cout << list->data <<"\t";
		list = list->next;
	}
	cout << list->data << "\n";
}


