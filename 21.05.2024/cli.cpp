#include <iostream>
#include <string>
#include <fstream>
#include <CLI/CLI.hpp>

int main(int argc, char** argv)
{
	CLI::App app;

	struct options
	{
		std::string file="";
		std::string pattern="";
		bool newline;
		bool ignore;
	}opts;

	app.add_option("-f,--filename", opts.file, "File to read")->required();
	app.add_flag("-n", opts.newline, "Every word in new line");
	app.add_flag("-i", opts.ignore, "Ignore lower upper case");
	app.add_option("-s", opts.pattern, "Search for pattern");

	CLI11_PARSE(app, argc, argv);

	if (opts.file.length() > 0)
	{
		std::fstream in;
		in.open(opts.file, std::ios::in);

		if (in.is_open())
		{
			if (opts.newline)
			{
				std::string word;
				while (!in.eof())
				{
					in >> word;
					if (opts.pattern.length() > 0)
					{
						if (opts.ignore)
						{
							std::transform(word.begin(), word.end(), word.begin(),
								[](unsigned char c) { return std::tolower(c); });
						}

						if (word.find(opts.pattern) != std::string::npos)
						{
							std::cout << word << "\n";
						}
					}
					else
					{
						std::cout << word << "\n";
					}
				}
			}
			else
			{
				std::string tmp;
				while (std::getline(in, tmp))
				{
					if (opts.pattern.length() > 0)
					{
						if (opts.ignore)
						{
							std::transform(tmp.begin(), tmp.end(), tmp.begin(),
								[](unsigned char c) { return std::tolower(c); });
						}

						if (tmp.find(opts.pattern) != std::string::npos)
						{
							std::cout << tmp << "\n";
						}
					}
					else
					{
						std::cout << tmp << "\n";
					}
				}
			}
		}
		else
		{
			std::cout << "File doesnt exists";
		}
	}
	return 0;
}