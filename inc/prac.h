/*
 * prac.h
 *
 * Prac file
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

#ifndef __PRAC_H_
#define __PRAC_H_

#include <slist.h>

using namespace std;


class prac {
	private:
		int forward_list(struct singlenode *node);
	public:
		prac();
		~prac();
		int get_max_sum(struct singlenode *node, int *start_pos,
			int *end_pos);
};

#endif //__SLIST_H_
