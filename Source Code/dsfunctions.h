/*
* Made By: Darshit Ambasana [ICT, Marwadi University]
* Date: 11th September 2021
*
* Level:0 C++ Revision
*
* dsfunctions.h : User defined header file which performs Data Structure operations.
* Header file contains only declarations, definition has to be written in correponding CPP file.
* 
*/

//Pragma to avoid multiple definitions in file where header will be used.
#ifndef DATA_ELEMENTS
#define DATA_ELEMENTS

//STL functions related headers.
#include<vector>
#include<array>
#include<list>
#include<deque>
#include<iterator>

/*Defining namespace and its members.
*Class: data_elements, operations show concept of inheritance.
*/
namespace data_structures
{
	class data_elements
	{
	public:
		data_elements() {};
		~data_elements() {};

		std::vector<int> ds_vector;
		std::list<int> ds_list;
		std::deque<int> ds_queue;

		void make_ds(int *arr,int len);
	};
	class operations : public data_elements
	{
	public:
		operations() {};
		~operations() {};

		void display_ds();
		int deleteNode(int index);
		void searchValue(int key);
		void sortAll();
		void reverseAll();
	};
}
#endif // !DATA_ELEMENTS