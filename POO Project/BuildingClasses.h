#pragma once
#include <iostream>
#include <string>
using namespage std;

class Table {
private:
	string tableName;
	int noColumns;
	int noRows;
public:

	Table(string tableName, int noColumns, int noRows) {
		this->tableName = tableName;
		this->noColumns = noColumns;
		this->noRows = noRows;
}
};
class DataBase {
private:
	int noOdfTables;
	string tableName;
public:
	DataBase() {
		int noOfTables = 0;
		string tableName = "";
	}

};
