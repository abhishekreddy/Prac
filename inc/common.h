/*
 * common.h
 *
 * Common header  file
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

#ifndef __COMMON_H_
#define __COMMON_H_

#include <iostream>

using namespace std;
#define IF_NULL_RETURN_VOID(ptr) if (!ptr) return;
#define IF_NULL_RETURN_INT(ptr)  if (!ptr) return -1;
#define IF_NULL_RETURN_BOOL(ptr) if (!ptr) return false;
#define IF_NULL(ptr)  if (!ptr)
#define IF_NULL_RETURN_NULL(ptr) if (!ptr) return NULL;

#define ERROR -1

#define MAX_CHAR 256

#endif //__COMMON_H_
