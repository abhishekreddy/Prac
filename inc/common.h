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
#include <stdio.h>

using namespace std;
#define IF_NULL_RETURN_VOID(ptr) if (!ptr) return;
#define IF_NULL_RETURN_INT(ptr)  if (!ptr) return -1;
#define IF_NULL_RETURN_BOOL(ptr) if (!ptr) return false;
#define IF_NULL(ptr)  if (!ptr)
#define IF_NOT_NULL(ptr) if (ptr != NULL)
#define IF_NULL_RETURN_NULL(ptr) if (!ptr) return NULL;

#define ERROR -1

#define MAX_CHAR 256

#if (DEBUG_MODE)
	#define LOG_INFO(fmt, ...)	\
		fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__);
#else
	#define LOG_INFO(fmt, ...)
#endif

#define LOG_ERROR(fmt, ...) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__);

#if (DEBUG_MODE)
#define PRINT_ARRAY(arr, len)				\
	if (arr)					\
		for (int i = 0; i < len; i++)		\
			printf("%d\t", arr[i]);		\
	printf("\n");
#else
#define PRINT_ARRAY(arr, len)
#endif

#endif //__COMMON_H_
