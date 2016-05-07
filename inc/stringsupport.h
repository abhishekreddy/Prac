/*
 * stringsupport.h
 *
 * String support file
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

#ifndef __STRINGSUPPORT_H_
#define __STRINGSUPPORT_H_

#include <list>
#include <vector>
#include <map>
#include <string>

#include <common.h>
using namespace std;

class Stringsupport {
public:
	Stringsupport();
	~Stringsupport();

	bool is_polindrome(char* str);
	void find_unique_permutations(string str, list<string>& prime_list);
	list<string> find_possible_polindormes(char *str);

private:
	void analyze_string(char* str, int char_list[]);
	void find_all_permutations(string str, int start, int end, list<string>& per_list);
	void permute(string str, int *count, string result, int depth, list<string>& prime_list);
};

#endif //__STRINGSUPPORT_H_
