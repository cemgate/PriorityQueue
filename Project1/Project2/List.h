#pragma once
#include<iostream>
#include<string>
#include"message.h"
#include"msg.h"
using namespace std;

class List : Msg
{
public:
	message* first;
	void add_msg(string name, string content);
	List sort(const List& l, Msg n);
	void display(const List& l);
	List flood(Msg);
	List();
};

void menu();


