#pragma once
#include <iostream>
#include <string>
using namespage std;

class Table {
private:
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
	string textValue = "";

public:
	//Column(){}

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
	~Column(){}

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
private:
	int noOdfTables;
	string tableName;
public:
	DataBase() {
		int noOfTables = 0;
		string tableName = "";
	}

};

