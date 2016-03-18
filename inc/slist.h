/*
 * slist.h
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

#ifndef __SLIST_H_
#define __SLIST_H_

using namespace std;

struct singlenode {
	int data;
	struct singlenode *next;
};

class slist {
	private:
		struct singlenode *m_list;
	public:
		slist(int data);
		~slist();
		int add(int data);
		int del();
		void display();
};

#endif //__SLIST_H_
