#pragma once

// Exception
namespace erro
{
	class no_future_infoamtion : public std::exception	// no future information
	{
	public:
		char const* what(const char* info) const throw()
		{
			return "No Future Information: " + *info;
		}
	};

	class command_end_erro : public std::exception	// the end of command is error
	{
	public:
		char const* what() const throw()
		{
			return "The end of command should begin with \'-\' !";
		}
	};

	class head_command_erro : public std::exception	// the head command is error
	{
	public:
		char const* what(const char* info) const throw()
		{
			return info;
		}
	};

	class no_load_file : public std::exception	// can not open file
	{
	public:
		char const* what(const char* file, const char* reason) const throw()
		{
			return "Threw a error when load " + *file + *" . Reason: " + *reason;
		}
	};

	class file_command_error : public std::exception
	{
	public:
		char const* what(const char* info) const throw()
		{
			return info;
		}
	};

	class file_command_not_found : public std::exception
	{
	public:
		char const* what(const char* info) const throw()
		{
			return info;
		}
	};

	class create_folder_error : public std::exception
	{
	public:
		char const* what(const char* info) const throw()
		{
			return info;
		}
	};

	class should_double_command : public std::exception
	{
	public:
		char const* what() const throw()
		{
			return "Should have double command!";
		}
	};
}
