/* Made By: Darshit Ambasana [ICT, Marwadi University]
* Date: 11th September 2021
* 
* Level:0 C++ Revision 
* 
* main.cpp: Main source file of the project.
* 
* Frontend Flow : Menu Driven Program.
* Divided in 2 parts File I/O operations and Data Structure Operations.
*/

//Standard Functions.
#include<iostream> 

//Logs Mechanism related headres.
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

//XML parsing related headers.
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/xml_parser.hpp>
#include<boost/foreach.hpp>

//JSON parsing related headers.
#include<json/value.h>
#include<json/json.h>

//String functions.
#include<string>

//File functions.
#include<fstream>

//Multithreading functions.
#include<thread>

//User Defined header.
#include "dsfunctions.h"

// Short alias for namespace
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
using boost::property_tree::ptree;
using namespace std;
using namespace data_structures;

/*Function: log_init()
* Parameters: N/A
* Return type: void
* 
* Defines Log File name, path and format of what to write in file.
*/
void log_init()
{
	logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

	logging::add_file_log(
		keywords::file_name = "MyProjectLogs.log",
		keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] [%LineID%] %Message%"
	);
	logging::add_common_attributes();
}

/*class: marks
* Concepts: Constructor/Destructor, Plymorphism(function overloading)
* Overloading functions: void add(int,int), void add(string,string)
*/
class marks
{
public:
	marks() {}
	~marks() {}
	int total_marks=0;
	void add(int mark_1, int mark_2) {
		total_marks = mark_1 + mark_2;
	}
	string full_name;
	void add(string f_name, string l_name) {
		full_name = f_name + " " + l_name;
	}
};

/*Function: ds_operations
* Parameters: N/A
* Return: void
* 
* Concepts: Array, accessing user defined header file functions.
*/
void ds_operations() {
	BOOST_LOG_TRIVIAL(info) << "Data Structure function."; //Logging message in log file.

	operations obj;
	int value=0;
	int len = 0;
	cout << "\n\nEnter number of nodes to add: ";
	while (!(cin >> len)) {
		cout << "\nERROR: Enter a number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	int* arr = new int[len];
	int i = 0;
	int j = len;
	while (j--) {
		cout << "\nEnter data value: ";
		while (!(cin >> value)) {
			cout << "\nERROR: Enter a number: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		arr[i] = value;
		i++;
	}
	obj.data_elements::make_ds(arr,len);
	obj.display_ds();
	delete[] arr;
	char choice;
	cout << "\n\n1. Delete Node";
	cout << "\n2. Sort";
	cout << "\n3. Reverse";
	cout << "\n4. Search";
	cout << "\nEnter choice index to perform operation OR 0 to Exit: ";
	cin >> choice;

	int key = 0;
	int index = 0;
	while (choice != '0') {
		switch (choice)
		{
		case '1':
			cout << "\nEnter node index to delete: ";
			while (!(cin >> index)) {
				cout << "\nERROR: Enter a number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			if(obj.deleteNode(index))
				obj.display_ds();
			break;
		case '2':
			obj.sortAll();
			obj.display_ds();
			break;
		case '3':
			obj.reverseAll();
			obj.display_ds();
			break;
		case '4':
			cout << "\nEnter value to search: ";
			while (!(cin >> key)) {
				cout << "\nERROR: Enter a number: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			obj.searchValue(key);
			break;
		default:
			cout << "\nERROR: Choice index out of scope!!";
			break;
		}

		cout << "\n\n1. Delete Node";
		cout << "\n2. Sort";
		cout << "\n3. Reverse";
		cout << "\n4. Search";
		cout << "\nEnter choice index to perform operation OR 0 to Exit: ";
		cin >> choice;
	}
}

/*Function: write_to_textFile
* Parameters: list<pair<int,string>>
* Return: void
* 
* Concepts: Write to Text file, LinkedList.
*/
void write_to_textFile(std::list< std::pair<int, string> >& MyDataList) {
	ofstream fileObj;
	fileObj.open("students.txt",ios_base::out);
	for (auto const &i : MyDataList) {
		fileObj << i.second << "\t" << i.first << "\n";
	}
	fileObj.close();
}

/*Function: write_to_xml
* Parameters: N/A
* Return: void
* 
* Concepts: Read from Text file, split string with spaces, write to XML file.
*/
void write_to_xmlFile() {
	string myData;
	ifstream readFile("students.txt");
	
	ptree pt;
	ptree mychild;
	string myFields[3] = {"fname","lname","total"};
	int studentIndex = 1;
	int fieldIndex = 0;
	while (getline(readFile, myData)) {
		stringstream ss(myData);
		string field;
		while (ss >> field) {
			if (fieldIndex > 2) {
				fieldIndex = 0;
			}
			mychild.add(myFields[fieldIndex],field);
			fieldIndex++;
		}
		pt.add_child("Students."+std::to_string(studentIndex),mychild);
		mychild.clear();
		write_xml("students.xml",pt);
		studentIndex++;
	}
	readFile.close();
}

/*Function: file_operation
* Parameters: N/A
* Return: void
* 
* Concepts: Read from JSON file, string operations, Exception Handling.
*/
void file_operations() {
	BOOST_LOG_TRIVIAL(info) << "File I/O function.";

	try {
		Json::Value student_data;
		std::ifstream data_file("data.json");
		data_file >> student_data;
		std::cout << "\n\tData being read from data.json";
		std::list< std::pair<int, string> > MyDataList;

		for (int i = 1; i <= student_data.size(); i++) {
			marks obj;
			int mark_1 = atoi(student_data[std::to_string(i)]["maths"].asCString());
			int mark_2 = atoi(student_data[std::to_string(i)]["science"].asCString());
			obj.add(mark_1, mark_2);

			string fname = student_data[std::to_string(i)]["fname"].asString();
			string lname = student_data[std::to_string(i)]["lname"].asString();
			obj.add(fname, lname);

			auto t = std::make_pair(obj.total_marks, obj.full_name);
			MyDataList.push_back(t);
		}
		write_to_textFile(MyDataList);
		write_to_xmlFile();
		MyDataList.clear();
		std::cout << "\n\tPlease checkout students.txt and students.xml";
	}
	catch (Json::RuntimeError) {
		BOOST_LOG_TRIVIAL(error) << "JSON file might be missing or empty!!";
		std::cout << "\n\tERROR: JSON file might be missing or empty!!";
	}
	catch (Json::LogicError) {
		BOOST_LOG_TRIVIAL(error) << "Fault in JSON file format!!";
		std::cout << "\n\tERROR: Fault in JSON file format!!";
	}
}

/*Function: main
* Parameters: N/A
* Return: int
* Entry point to C++ program.
* 
* Concepts: Multithreading
*/
int main()
{
	log_init();
	BOOST_LOG_TRIVIAL(info) << "START";
	
	char choice;
	std::cout << "\t\t**** Level:0 C++ Revision ****\n\n";
	std::cout << "1. Data Structure \n2. File Input/Output\n\n";
	std::cout << "Enter choice(1/2) to run respective Demo OR 0 to Exit: ";
	std::cin >> choice;
	
	while (choice != '0') {
		if (choice == '1') {
			thread dataStructureDemo(ds_operations);
			BOOST_LOG_TRIVIAL(info) << "Data Structure Function Thread ID = " << dataStructureDemo.get_id();
			dataStructureDemo.join();
		}
		else if (choice == '2') {
			thread filesDemo(file_operations);
			BOOST_LOG_TRIVIAL(info) << "File I/O Function Thread ID = " << filesDemo.get_id();
			filesDemo.join();
		}
		else {
			std::cout << "\nERROR: Choice index out of scope!!";
			BOOST_LOG_TRIVIAL(error) << "Choice index out of scope";
		}
		std::cout << "\t\n\n**** Level:0 C++ Revision ****\n\n";
		std::cout << "1. Data Structure \n2. File Input/Output\n\n";
		std::cout << "\nEnter choice(1/2) to run respective Demo OR 0 to Exit: ";
		std::cin >> choice;
	}
	BOOST_LOG_TRIVIAL(info) << "END";
	return 0;
}