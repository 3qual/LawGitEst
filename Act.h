#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>

#pragma once
class Act
{
private:
	std::string code;
	std::string number;
	std::string description;
	std::string correction;
	std::string line;
	std::list<Act> law;
public:
	Act(std::string str);
	void manual_list(Act object);
	void Act_file(std::string FILE);
	void write(std::string FILE);
	std::string get_line();
	virtual void list_show();
	virtual void show();
};