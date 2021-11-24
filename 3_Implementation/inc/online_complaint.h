/**
 * @file online_complaint.h
 * @author Prasanna
 * @brief online complaint structure definition
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

#ifndef __ONLINE_COMPLAINT_H__
#define __ONLINE_COMPLAINT_H__


#include<string.h>
struct complaint
{
	char number[6];
	char name[15];
    char problem[15];
	int complaint_num;
	char local_address[15];
	struct complaint *following;
}

#endif //#ifndef ONLINE_COMPLAINT
