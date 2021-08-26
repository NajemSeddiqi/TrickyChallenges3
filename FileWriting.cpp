#include "FileWriting.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>


struct Person
{
	char name[50];
	int age;
	double height;
};

void FileWriting::WriteSomeShit()
{
	std::ofstream outFile;

	const std::string outfileName = "text.txt";
	outFile.open(outfileName);

	if (outFile.is_open())
	{
		outFile << "Herrllo there" << std::endl;
		outFile << 123 << std::endl;
		outFile.close();
	}
	else
		std::cout << "Could not create file: " << outfileName << std::endl;
}

void FileWriting::ReadSomeShit()
{
	const std::string inFileName = "text.txt";
	std::ifstream inFile;

	inFile.open(inFileName);

	if (inFile.is_open())
	{
		std::string line;

		while (!inFile.eof())
		{
			std::getline(inFile, line);
			std::cout << line << std::endl;
		}

		inFile.close();
	}
	else
	{
		std::cout << "Cannot open file: " << inFileName << std::endl;
	}
}

int FileWriting::ParseSomeShit()
{
	const std::string fileName = "text.txt";
	std::ifstream input;

	input.open(fileName);

	if (!input.is_open())
		return 1;

	while (!input.eof())
	{
		std::string line;
		std::getline(input, line, ':');

		int population;
		input >> population;

		std::cout << line << " -- " << population << std::endl;
	}

	input.close();

	return 0;
}

void FileWriting::BinaryParsingShit()
{
	Person someone = { "Frodo", 220, 0.8 };
	const std::string fileName = "test.bin";
	std::fstream output;

	output.open(fileName, std::ios::binary | std::ios::out);
	if (output.is_open())
	{
		output.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		output.close();
	}
	else
	{
		std::cout << "Could not create file " + fileName;
	}
}

void FileWriting::ReadBinaryShit()
{
	Person someone = { "Frodo", 220, 0.8 };
	const std::string fileName = "test.bin";
	std::fstream output;

	output.open(fileName, std::ios::binary | std::ios::out);
	if (output.is_open())
	{
		output.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		output.close();
	}
	else
	{
		std::cout << "Could not create file " + fileName;
	}

	Person someoneElse = {};
	std::ifstream input;

	input.open(fileName, std::ios::binary);
	if (input.is_open())
	{
		input.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
		input.close();
	}
	else
	{
		std::cout << "Could not read file " + fileName;
	}

	std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;
}
