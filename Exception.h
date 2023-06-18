#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class DeckFileNotFound : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Deck File Error : File not found";
	}
};

class DeckFileFormatError : public std::exception 
{
	std::string m_errorMessage = "Deck File Error: File format error in line ";
public:
	explicit DeckFileFormatError(const int line)
	{
		m_errorMessage += std::to_string(line);
	}
	const char* what() const noexcept override
	{
		return m_errorMessage.data();
	}
};

class DeckFileInvalidSize : public std::exception 
{
public:
	const char* what() const noexcept override
	{
		return "Deck File Error: Deck size is invalid";
	}
};

#endif EXCEPTION_H