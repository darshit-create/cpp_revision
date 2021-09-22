/*
* Made By: Darshit Ambasana [ICT, Marwadi University]
* Date: 11th September 2021
*
* Level:0 C++ Revision
*
* dsfunctions.cpp : Logic definition file for user defined header dsfunctions.h
*
* NOTE: STL data structure and algorithm implemented can be replaced by conventional iterative methods, and
* class definition for allocating memory to data structure.
*/

//User Defined header.
#include "dsfunctions.h"

//STL related headers.
#include<array>
#include<list>
#include<iterator>
#include<vector>
#include<deque> //used deque instead of queue because this provides iterator functionality.

//For algorithms like sort and reverse.
#include<algorithm>

//For priting outputs.
#include<iostream>

using namespace data_structures;

/*Function: make_ds
* Parameters: int*, int
* Return: void
* 
* Adds data taken from user to LinkedList, Queue, Vector.
*/
	void data_elements::make_ds(int *arr, int len) {
		for (int i = 0;i < len;i++) {
			ds_vector.push_back(arr[i]);
			ds_list.push_back(arr[i]);
			ds_queue.push_back(arr[i]);
		}
	}
	
/*Function: display_ds()
* Parameters: N/A
* Return: void
* 
* Prints all data structures.
*/
	void operations::display_ds() {

		std::list<int>::iterator it_list;
		std::deque<int>::iterator it_queue;

		std::cout << "\n\nVector: ";
			for (int i = 0; i < ds_vector.size(); i++) {
				std::cout << data_elements::ds_vector[i] << ", ";
			}
			std::cout << "\n\nList: ";
			for (it_list = ds_list.begin(); it_list != ds_list.end(); ++it_list) {
				std::cout << *it_list << ", ";
			}
			std::cout << "\n\nQueue: ";
			for (it_queue = ds_queue.begin(); it_queue != ds_queue.end(); ++it_queue) {
				std::cout << *it_queue << ", ";
			}
		
	}

	void data_elements::display_ds() {

		std::list<int>::iterator it_list;
		std::deque<int>::iterator it_queue;

		std::cout << "\n\nVector: ";
		for (int i = 0; i < ds_vector.size(); i++) {
			std::cout << data_elements::ds_vector[i] << ", ";
		}
		std::cout << "\n\nList: ";
		for (it_list = ds_list.begin(); it_list != ds_list.end(); ++it_list) {
			std::cout << *it_list << ", ";
		}
		std::cout << "\n\nQueue: ";
		for (it_queue = ds_queue.begin(); it_queue != ds_queue.end(); ++it_queue) {
			std::cout << *it_queue << ", ";
		}
	}

/*Function: deleteNode
* Parameters: int
* Return: int
* 
* Accepts index and delete data at that index from data structures,
* and return 1 or 0 for status of operation.
*/
	int operations::deleteNode(int index) {
		std::list<int>::iterator it_list;
		std::deque<int>::iterator it_queue;
		std::vector<int>::iterator it_vector;

		if (index < ds_vector.size() && index >= 0) {
			
			it_vector = ds_vector.begin();
			it_list = ds_list.begin();
			it_queue = ds_queue.begin();
			while (index--) {
				it_vector++;
				it_list++;
				it_queue++;
			}
			ds_vector.erase(it_vector);
			ds_list.erase(it_list);
			ds_queue.erase(it_queue);
			return 1;
		}
		else {
			std::cout << "\n\nERROR: Index out of scope!!";
			return 0;
		}
	}

/*Function: searchValue
* Parameters: int
* Return: void
* 
* Accepts key value and tries to search it in data structures and print the index.
*/
	void operations::searchValue(int key) {
		std::list<int>::iterator it_list;
		std::deque<int>::iterator it_queue;
		int flag = 0;

		//Vector
		for (int i = 0;i < ds_vector.size();i++) {
			if (ds_vector[i] == key) {
				std::cout << "\nAt Vector index: " << i;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			std::cout << "\nNot found in Vector...";
		}

		//List
		flag = 0;
		int i = 0;
		for (it_list = ds_list.begin();it_list != ds_list.end();++it_list) {
			if (*it_list == key) {
				std::cout << "\nAt List index: " << i;
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0) {
			std::cout << "\nNot found in List...";
		}

		//Queue
		flag = 0;
		i = 0;
		for (it_queue = ds_queue.begin();it_queue != ds_queue.end();++it_queue) {
			if (*it_queue == key) {
				std::cout << "\nAt Queue index: " << i;
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0) {
			std::cout << "\nNot found in Queue...";
		}
	}

/*Function: sortAll
* Parameters: N/A
* Return: void
* 
* Sorts all data structures in ascending order.
*/
	void operations::sortAll() {
		ds_list.sort();
		std::sort(ds_vector.begin(), ds_vector.end());
		std::sort(ds_queue.begin(), ds_queue.end());
	}

/*Function: reverseAll
* Parameters: N/A
* Return: void
* 
* Uses std::reverse function to reverse all data structures.
*/
	void operations::reverseAll() {
		std::reverse(ds_vector.begin(), ds_vector.end());
		std::reverse(ds_list.begin(), ds_list.end());
		std::reverse(ds_queue.begin(), ds_queue.end());
	}

