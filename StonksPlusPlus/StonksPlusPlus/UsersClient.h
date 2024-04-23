#pragma once
#include "Users.h"
#include <string>
class UsersClient: public Users
{
private:
	int CounterPost;
	string post;
public:
	string parrafo[10000];
	UsersClient();
	void normalpost();
	void premiumpost();
};