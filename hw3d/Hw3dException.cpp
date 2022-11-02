#include "Hw3dException.h"
#include <sstream>


Hw3dException::Hw3dException( int line,const char* file ) noexcept
	:
	line( line ),
	file( file )
{}

const char* Hw3dException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* Hw3dException::GetType() const noexcept
{
	return "Hw3d Exception";
}

int Hw3dException::GetLine() const noexcept
{
	return line;
}

const std::string& Hw3dException::GetFile() const noexcept
{
	return file;
}

std::string Hw3dException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}