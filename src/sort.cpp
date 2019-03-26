/*
 * sort.cpp
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

#include <stdlib.h>
#include <sort.h>
#include <common.h>

using namespace std;

sortHelper::sortHelper(int* arr, int len)
{
	m_arr = NULL;
	m_len = 0;

	IF_NOT_NULL(arr)
	{
		if (len > 0)
		{
			m_arr = static_cast<int*>(malloc(sizeof(int) * len));
			for (int i = 0; i < len; i++)
				m_arr[i] = arr[i];
			m_len = len;
		}
	}
}

sortHelper::~sortHelper()
{
	IF_NOT_NULL(m_arr)
	{
		free(m_arr);
		m_arr = NULL;
		m_len = 0;
	}
}

void sortHelper::swap(int* first,int* second)
{
	IF_NULL_RETURN_VOID(first);
	IF_NULL_RETURN_VOID(second);

	*first  = *first + *second;
	*second = *first - *second;
	*first  = *first - *second; 
}

void sortHelper::sort(sortType type)
{
	int *arr = NULL;
	int len  = m_len;

	IF_NULL_RETURN_VOID(m_arr);

	arr = static_cast<int*>(malloc(sizeof(int) * len));
	for (int i = 0; i < len; i++)
	{
		arr[i] = m_arr[i];		
	}

	switch (type)
	{
	case BUBBLE:
	{
		PRINT_ARRAY(arr, len);
		bool isSwapped = false;
		do
		{
			isSwapped = false;
			for (int i = 0; i < len; i++)
			{
				if (arr[i] > arr[i+1])
				{
					swap(&arr[i], &arr[i+1]);
					isSwapped = true;
				}
			}
			PRINT_ARRAY(arr, len);
		} while(isSwapped);
		break;
	}
	case INSERTION:
	{
		PRINT_ARRAY(arr, len);
		for (int i = 0; i < len; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (arr[j-1] > arr[j])
					swap(&arr[j-1], &arr[j]);
			}
			PRINT_ARRAY(arr, len); 
		}
		break;
	}
	default:
		break;
	}

}
