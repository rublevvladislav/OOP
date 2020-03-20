#pragma once
#include <string>
#include "Vector.h"

class Printable
{
public:
	virtual void Print(std::ostream &out) const = 0;
};

class Named : public Printable
{
public:
	Named(const std::string& name) : m_name(name) {};
	virtual void Print(std::ostream& out) const 
	{
		out << m_name << std::endl;
	}
	friend std::ostream & operator << (std::ostream& s, const Printable& obj) 
	{
		obj.Print(s);
		return s;
	}
protected:
	std::string m_name;
};