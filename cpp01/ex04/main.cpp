#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of parameters, you need filename and two strings" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string find = argv[2];
	std::string replace = argv[3];
	if (find.empty() || replace.empty()) 
	{
		std::cout << "Error: Empty string" << std::endl;
		return 1;
	}

	std::ifstream name(filename.c_str());
	std::string file;
	std::string line;
	if (!name)
	{
		std::cout << "Error opening file: " << filename << std::endl;
		name.close();
		exit(EXIT_FAILURE);
	}

	while (std::getline (name, line))
	{
		file += line;
		if (!name.eof())
			file += "\n";
	}
	name.close();

	std::string result = file;
	size_t pos = 0;
	while ((pos = file.find(argv[2], pos)) != std::string::npos)
	{
		result = result.substr(0, pos) + replace + result.substr(pos + find.size());
    	pos += replace.size();
	}
	
	std::string new_filename = filename + ".replace";
	std::ofstream outfile(new_filename.c_str());
	if (!outfile)
	{
		std::cout << "Error creating new file" << std::endl;
		outfile.close();
		exit(EXIT_FAILURE);
	}
	outfile << result;
	outfile.close();
	return 0;
}