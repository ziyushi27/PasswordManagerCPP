#pragma once
#include <string>

class Password
{
private:
	std::string website;
	std::string username;
	std::string password;

public:
	Password(std::string site = "",
		std::string user = "",
		std::string pass = "");

	std::string getWebsite() const;
	std::string getUsername() const;
	std::string getPassword() const;
};
