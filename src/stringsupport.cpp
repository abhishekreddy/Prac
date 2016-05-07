/*
 * stringsupport.cpp
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

#include <iostream>
#include <string.h>
#include <algorithm>

#include <stringsupport.h>


using namespace std;

Stringsupport::Stringsupport()
{

}

Stringsupport::~Stringsupport()
{

}

bool Stringsupport::is_polindrome(char *str)
{
	int len = 0;

	IF_NULL_RETURN_BOOL(str);
	len = strlen(str);

	if (len <= 0) {
		return false;
	}

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[(len - 1) - i]) {
			return false;
		}
	}

	return true;
}

void Stringsupport::find_all_permutations(string str, int start, int end, list<string>& per_list)
{
	int j;


	if (start >= end) {
		per_list.push_back(str);
	}
	else {

		for (j = start; j < end; j++) {
			if (j == start) {
				find_all_permutations(str, start + 1, end, per_list);
			} else if (str[start] == str[j]) {

			} else {
				swap(str[start], str[j]);
				find_all_permutations(str, start + 1, end, per_list);
				swap(str[start], str[j]);
			}
		}
	}


}

void Stringsupport::permute(string str, int *count, string result, int depth, list<string>& prime_list) {
	if ((unsigned int)depth == result.length()) {
		string permutedstring = result;
		prime_list.push_back(permutedstring);
		return;
	}

	for (unsigned int i = 0; i < str.length(); i++) {
		if (*(count +i) == 0) {
			continue;
		}
		result[depth] = str[i];
		(*(count +i))--;
		permute(str, count, result, depth + 1, prime_list);
		(*(count + i))++;
	}

}

void Stringsupport::find_unique_permutations(string str, list<string>& prime_list)
{
	string sorted = str;
	string unique;
	map<char, int> countmap;
	map<char, int>::iterator countit;

	sort(sorted.begin(), sorted.end());

	for (unsigned int i = 0; i < sorted.length(); i++) {
		if (!count(unique.begin(), unique.end(), sorted[i])) {
			int cnt = count(sorted.begin(), sorted.end(), sorted[i]);
			unique += sorted[i];
			countmap.insert(pair<char, int>(sorted[i], cnt));
		}
	}

	int* count = new int[unique.length()];
	string result = sorted;

	for (unsigned int i = 0; i < unique.length(); i++) {

		countit = countmap.find(unique[i]);
		if (countit != countmap.end()) {
			*(count + i) = countit->second;
		}
	}
	permute(unique, count, result, 0, prime_list);

}
list<string> Stringsupport::find_possible_polindormes(char *str)
{
	int char_list[MAX_CHAR] = {0};
	int len = 0, uni_char = 0;
	list<string> polindrome_list;
	list<string>::iterator it;
	char single_char;
	list<char> double_list;
	list<char>::iterator double_it;
	list<string> prime_list;
	list<string>::iterator prime_it;
	list<char>::iterator base_it;
	list<char>::iterator var_it;
	list<char>::iterator fill_it;
	string prime;

	if (str == NULL) {
		return polindrome_list;
	}

	it = polindrome_list.begin();
	double_it = double_list.begin();
	len = strlen(str);

    /*Analyse the string*/
	analyze_string(str, char_list);

	for (int i = 0; i < MAX_CHAR; i++) {
		if ((char_list[i]%2) != 0) {
			if (!uni_char && (len%2 != 0)) {
				single_char = (char)i;
				char_list[i]--;
				uni_char++;
			} else {
				cout << "Mutiple uni chars detected\n";
				return polindrome_list;
			}

		}
		if (char_list[i] > 1 && (char_list[i]%2 == 0)) {
			for (int j = 0; j < char_list[i] / 2; j++) {
				prime += (char)i;
			}
		}
	}

	find_unique_permutations(prime, prime_list);


	prime_it = prime_list.begin();
    it = polindrome_list.begin();
	while (prime_it != prime_list.end()) {
		string act = (string)*prime_it;
		string tac = act;
		reverse(tac.begin(), tac.end());
		string acttac = act;
		if (uni_char) {
			acttac += single_char;
		}
		acttac.append(tac.begin(), tac.end());
		polindrome_list.push_back(acttac);
		prime_it++;
	}

	return polindrome_list;
}

void Stringsupport::analyze_string(char *str, int char_list[])
{

	int len = 0;

	IF_NULL_RETURN_VOID(str);

	len = strlen(str);

	for (int i = 0; i < len; i++) {
		char_list[(unsigned char)str[i]]++;
	}
}
