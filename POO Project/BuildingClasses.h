#pragma once
#include <iostream>
#include <string>
using namespace std;

enum type { TEXT = 1, INTEGER = 2, FLOAT = 3 };
class Column {
public:
	string name = "";
	type columnType;
	int noRows = 0;
	int intValue = 0;
	float floatValue = 0;
	string textValue ;

public:

	Column() {
		this->name = "No column name";
		this->columnType = type::INTEGER;
		this->noRows = 0;
	}
	Column(string name, type Type, int row) {
		this->name = name;
		this->columnType = Type;
		this->noRows = row;
	}

	Column(string name, type Type, int row, int Value) {
		this->name = name;
		this->columnType = columnType;
		this->noRows = noRows;
		if (this->getType() == "integer")
			this->intValue = Value;
	}

	Column(string Name, type Type, int row, float floatValue) {
		this->name = Name;
		this->columnType = columnType;
		this->noRows = noRows;
		if (this->getType() == "float")
			this->floatValue = floatValue;
	}

	Column(string Name, type Type, int row, string textValue) {
		this->name = Name;
		this->columnType = columnType;
		this->noRows = noRows;
		if (this->getType() == "text")
		this->textValue = textValue;
	}


	Column(const Column& copy) {
		this->name = copy.name;
		this->columnType = copy.columnType;
		this->noRows = copy.noRows;

	}


	~Column() {

	}

	string getName() {
		return this->name;
	}
	void setName(string Name) {
		this->name = Name;
	}
	int getDimension() {
		return this->noRows;
	}
	void setDimension(int dim) {
		this->noRows = dim;
	}
	string getType() {
		if (Column::columnType == 1) {
			return "text";
		}
		else if (Column::columnType == 2) {
			return "integer";
		}
		else return "float";
	}
	type getColumnType() {
		return this->columnType;
	}

};

	class Table {
		string tableName;
		int noColumns;
		int noRows;
		Column* column;
	public:

		Table() {

		}

		Table(string tableName, int noColumns, int noRows, Column* column) {
			this->tableName = tableName;
			this->noColumns = noColumns;
			this->noRows = noRows;
			this->column = new Column[this->noColumns];
			for (int i = 0; i < this->noColumns; i++)
			{
				this->column[i] = column[i];
			}
		}

		string getTableName() {
			return this->tableName;
		}

		void setTableName(string Name) {
			this->tableName = Name;
		}

	};

	class Data {
		int v1 = 0;
		float v2 = 0;
		string text = "";
	public:
		Data() {}
		~Data() {}
	};

	class DataBase {
		int noOfTables;
		string* tableNames;
	public:
		DataBase()
		{
			noOfTables = 0;
			tableNames = nullptr;
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
	
		int getNoOfTables()
		{
			return this->noOfTables;
		}

	};

