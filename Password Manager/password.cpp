#include "Password.h"

Password::Password(std::string site,
	std::string user,
	std::string pass)
{
	website = site;
	username = user;
	password = pass;
}

std::string Password::getWebsite() const
{
	return website;
}

std::string Password::getUsername() const
{
	return username;
}

std::string Password::getPassword() const
{
	return password;
}