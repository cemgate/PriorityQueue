#pragma once
#include<iostream>
#include<string>
using namespace std;

struct message
{
public:
		string name;
		string content;
		message* next;
		message();
	
};

