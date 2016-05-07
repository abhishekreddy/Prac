/*
 * prac.cpp
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

#include <iostream>
#include <prac.h>

using namespace std;

prac::prac()
{
}

prac::~prac()
{
}

int prac::forward_list(struct singlenode *list)
{
	int pos = 0;

	while (list != NULL) {
		if (list->data > 0) {
			break;
		} else {
			pos++;
			list = list->next;
		}
	}
	return pos;
}

int prac::get_max_sum(struct singlenode *node,
	int *start_pos, int *end_pos)
{
	struct singlenode *list = node;
	int max_sum = 0, cur_sum = 0, count = 0, start_max = 0, stop_max = 0;

	max_sum = list->data;
	start_max = 0;
	stop_max = 0;
	/* Find the first positive */
	while (list != NULL) {
	 	if (list->data > 0) {
			max_sum = list->data;
			*start_pos = count;
			*end_pos = count;
			break;
		} else {
			if (max_sum < list->data) {
				max_sum = list->data;
				*start_pos = count;
				*end_pos = count;
			}
			list = list->next;
			count++;
		}
	}

	if (list == NULL)
		return max_sum;

	while (list->next != NULL) {
		cur_sum += list->data;
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			*end_pos = count;
		}

		if (cur_sum < 0 ) {

		}
	}
	return max_sum;
}
