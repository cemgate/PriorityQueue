#pragma once 
#include<iostream>
#include<string>

using namespace std;

class Msg
{
public:
	int letter, liczbaznakow, pierwszeW, ostatnieW, n;
	string msg;
	char buffor[200];
	char buffor1[200];
	void divideMsg();
	void getMsg();
};

