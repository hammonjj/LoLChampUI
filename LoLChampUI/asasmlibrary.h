/****************************************
* File: asasmtest.h						*
* Created: 6/13/2013					*
* Author: James Hammond					*
* Comments: Doxygen						*
****************************************/

#ifndef ASASMLIBRARY_H
#define ASASMLIBRARY_H

#include <string>
#include <vector>

class asasmlibrary {
	private:
		std::vector<std::string> m_asasmFile;
		std::string asamPrefix;
		std::string asamSuffix;

	public:
		asasmlibrary(std::string fileName);
		void readFile(std::string fileName); //!< Reads AMASM file and returns the file as a string vector, where each index is a line of text 
		void writeFile(std::string fileName, std::vector<std::string> fileLines); //!< Writes ASASM file from string vector.  Will print each index on a new line.
		void assembleFile(); //!< Runs Windows batch file that assembles the data using RABCDAsm v1.13
		void changeSearchTags(std::vector<std::string> champtionSearchTags, std::vector<std::string> &asamInputFile, std::string championName); //!< Searches asamInput vector for a bookmark location (championName) and replaces the entries below it with championSearchTag indexes
		void readSearchTags(const std::string champName, std::vector<std::string> &searchTags); //!< Stub for function that will read XML data file
		void readCategoryList(std::vector<std::string> &categoryList);
		void getAsasmFile(std::vector<std::string> &asamFile);

		~asasmlibrary(){;};
};


#endif