/*
 * sort.h
 *
 * Sorting Helper file
 *
 * Copyright (C) 2019 Abhishek Reddy kondaveeti
 *
 * Contributor: Abhishek Reddy Kondaveeti <abhishek.kondaveeti@gmail.com>
 *
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */

#ifndef __SORT_H_
#define __SORT_H_

using namespace std;

typedef enum
{
	BUBBLE,
	INSERTION,
	QUICK,
	MERGE,
	RADIX,
	HEAP,
	SELECTION,
	SHELL,
	BUCKET,
	COUNT,
} sortType;

class sortHelper {
	private:
		int* m_arr;
		int  m_len;

		void swap(int* first,int* second);

	public:
		sortHelper(int* arr, int len);
		~sortHelper();

		void sort(sortType type);
};

#endif // __SORT_H_
		
