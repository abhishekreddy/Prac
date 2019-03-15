/*
 * node.h
 *
 * Node class
 *
 * Copyright (C) 2018 Abhishek Reddy kondaveeti
 *
 * Contributor: Abhishek Reddy Kondaveeti <abhishek.kondaveeti@gmail.com>
 *
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */

#ifndef __NODE_H_
#define __NODE_H_

using namespace std;

class Node
{
	public:
		Node(void* data);
                ~Node();
		void* getData();
		void  setData(void* data);
		void  setNext(Node* node);
		Node* getNext();
		void  setPrvious(Node* node);
		Node* getPrevious();
	private:
		void* data;
		Node* next;
		Node* prev;
};






#endif // __NODE_H_
