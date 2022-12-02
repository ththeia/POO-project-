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

class Data {
	int v1 = o;
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
	int dimension = 0;
	int intValue = 0;
	float floatValue = 0;
	string textValue = "";

public:
	//Column(){}

	Column(string Name, int Dimension) {
		setName(Name);
		setDimension(Dimension);
	}

	//Default constructor
	Column() {
		this->name = "No column name";
		this->~columnType = type::INTEGER;
		this->dimension = 0;
	}
	//Constructor
	Column(string Name, int Dimension, int Value) :name(Name), dimension(Dimension) {
		//this->name = Name;
		//this->dimension = Dimension;
	}

	Column(string Name, int Dimension, int Value) :name(Name), dimension(Dimension) {
		if (this->getType() == "integer")
			this->textValue = Value;
	}

	Column(string Name, int Dimension, float Value) :name(Name), dimension(Dimension) {
		if (this->getType() == "float")
			this->textValue = Value;
	}

	Column(string Name, int Dimension, string Value) :name(Name), dimension(Dimension) {
		if (this->getType() == "text")
			this->textValue = Value;
	}

	//Copy Constructor
	Column(const Column& object) {
		this->name = object.name;
		this->dimension = object.dimension;
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
	int getDimension() {
		return this->dimension;
	}
	void setDimension(int dimension) {
		this->dimension = dimension;
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
