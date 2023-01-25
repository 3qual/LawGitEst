#include "Act.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>

Act::Act(std::string str)
{
	setlocale(LC_ALL, "Russian");

	size_t prepos = 0;
	size_t pos = 0;

	pos = str.find_first_of(';', 0);
	if (pos != std::string::npos) {
		this->code = str.substr(0, pos);
		prepos = pos + 1;
	}
	else {
		return;
	}

	pos = str.find_first_of(';', pos + 1);
	if (pos != std::string::npos) {
		this->number = str.substr(prepos, pos - prepos);
		prepos = pos + 1;
	}
	else {
		return;
	}

	pos = str.find_first_of(';', pos + 1);
	if (pos != std::string::npos) {
		this->description = str.substr(prepos, pos - prepos);
		prepos = pos + 1;
	}
	else {
		return;
	}

	pos = str.find_first_of(';', pos + 1);
	if (pos != std::string::npos) {
		this->correction = str.substr(prepos, pos - prepos);
		prepos = pos + 1;
	}
	else {
		return;
	}

	this->line = str;
	std::cout << std::endl << "Object created sucsesfully, data introduced into list" << std::endl;
}

void Act::manual_list(Act object)
{
	law.push_back(object);
}

void Act::Act_file(std::string FILE)
{
	std::string str;
	std::ifstream file(FILE);
	std::cout << std::endl << std::endl << "File data extracted sucsesfully, objects introduced into list" << std::endl << std::endl;
	while (getline(file, str)) {
		law.push_back(Act(str));
	}
	file.close();
}

void Act::write(std::string FILE)
{
	setlocale(LC_ALL, "Russian");

	std::ofstream out;
	out.open(FILE);

	if (out.is_open())
	{
		for (auto inc = law.begin(); inc != law.end(); ++inc) {
			out << (*inc).get_line() << std::endl;
		}
	}
	std::cout << std::endl << "List data sucsesfully writed to the file" << std::endl << std::endl;
}

std::string Act::get_line()
{
	return line;
}

void Act::list_show()
{
	for (auto inc = law.begin(); inc != law.end(); ++inc)
		(*inc).show();
}

void Act::show()
{
	setlocale(LC_ALL, "Russian");
	std::cout << std::endl << "Кодекс - " << code << std::endl
		<< "Номер - " << number << std::endl
		<< "Описание:" << std::endl << "  " << description << std::endl
		<< "Ответственность:" << std::endl << "  " << correction << std::endl << std::endl;
}