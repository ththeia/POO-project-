#pragma once
#include <iostream>
#include <string>
using namespace std;

class Table {
	string tableName;
	int noColumns;
	Column* column;
public:

	Table() {

	}

	Table(string tableName, int noColumns, int noRows, Column* column) :
		tableName(tableName), noColumns(noColumns), noRows(noRows)
	{
		if (this->column != nullptr)
		{
			delete[]this->column;
			this->column = new Column[this->noColumns];
		}
		for (int i = 0; i < this->noColumns; i++)
		{
			this->column[i] = column[i];
		}
	}

	string getTableName() {
		return this->getTableName;
	}

	void setTableName(string Name){
		this->getTableName = Name;
	}
	
};

class Data {
	int v1 = 0;
	float v2 = 0;
	string text = "";
public:
	Data(){}
	~Data(){}
};

//Class for creating a column
class Column {
public:
	string name = "";
	int noOfRows = 0;
	int intValue = 0;
	float floatValue = 0;
	string* textValue =nullptr;

public:

	Column(string Name, int noOfRows) {
		setName(Name);
		setNoOfRows(noOfRows);
	}

	//Default constructor
	Column() {
		this->name = "No column name";
		this->~columnType = type::INTEGER;
		this->noOfRows = 0;
	}
	//Constructor
	Column(string Name, int noOfRows, int Value) :name(Name), noOfRows(noOfRows) {
		//this->name = Name;
		//this->dimension = Dimension;
	}

	Column(string Name, int noOfRows, int Value) :name(Name), noOfRows(noOfRows) {
		if (this->getType() == "integer")
			this->textValue = Value;
	}

	Column(string Name, int noOfRows, float Value) :name(Name), noOfRows(noOfRows) {
		if (this->getType() == "float")
			this->textValue = Value;
	}

	Column(string Name, int noOfRows, string Value) :name(Name), noOfRows(noOfRows) {
		if (this->getType() == "text")
			this->textValue = Value;
	}

	//Copy Constructor
	Column(const Column& object) {
		this->name = object.name;
		this->noOfRows = object.noOfRows;
		//this->value=object.value;
	}

	//Destructor
	~Column()
	{
		if (textValue != nullptr)
			delete[]textValue;
	}

	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	int getNoOfRows() {
		return this->noOfRows;
	}
	void setNoOfRows(int noOfRows) {
		this->noOfRows = noOfRows;
	}

};

class DataBase {
	int noOfTables;
	string* tableNames;
public:
	DataBase() 
	{
		int noOfTables = 0;
		string* tableNames = "";
	}
	void createTable(string tableName)
	{
		this->noOfTables = this->noOfTables + 1;
		string* newTableNames = new string[this->noOfTables];
		for (int i = 0; i < this->noOfTables - 1; i++)
		{
			newTableNames[i] = this->tableNames[i];
		}
		for (int j = this->noOfTables - 1; j < this->noOfTables; j++)
		{
			newTableNames[j] = tableName[j - this->noOfTables - 1];
		}
		this->tableNames = new string[this->noOfTables];
		for (int i = 0; i < this->noOfTables; i++)
		{
			this->tableNames[i] = newTableNames[i];
		}
		delete[] newTableNames;

	}
	void dropTable(string tableName)
	{
		for (int i = 0; i < this->noOfTables; i++)
		{
			if (this->tableNames[i] == tableName)
			{
				for (int j = i; j < this->noOfTables - 1; j++)
				{
					this->tableNames[j] = this->tableNames[j + 1];
				}
			}
			this->noOfTables--;
		}
	}

	string* getTableNames()
	{
		return this->tableNames;
	}
	int noOfTables() 
	{
		return this->noOfTables;
	}

};

