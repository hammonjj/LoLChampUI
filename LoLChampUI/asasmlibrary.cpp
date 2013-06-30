#include "asasmlibrary.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "toolbox.h"

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

const string CHAMP_GENERATED_DATA_REWRITE = "Test Space\\AirGeneratedContent-0\\com\\riotgames\\platform\\gameclient\\domain";
const string CHAMP_GENERATED_DATA_PATH = "Resources\\ASAM\\0.0.1.28\\AirGeneratedContent-0\\com\\riotgames\\platform\\gameclient\\domain";
const string CHAMP_GENERATED_DATA_ASAM = "ChampionGeneratedData.class.asasm";

//Function Definitions
/***************************************************************************/
asasmlibrary::asasmlibrary(string fileName) {
		asamPrefix = "      pushstring          \"";
		asamSuffix = "\"";

		readFile(fileName);
}

//asasmlibrary::~asasmlibrary() {
//
//}

void asasmlibrary::readFile(string fileName) {
	ifstream asamFile;
	asamFile.open(fileName);

	if(asamFile.is_open()) {
		string line;
		
		while(asamFile.good()) {
			getline(asamFile, line);
			m_asasmFile.push_back(line);
		}
	}
	asamFile.close();
}

/***************************************************************************/
void asasmlibrary::writeFile(string fileName, vector<string> fileLines) {
	string path = "Test Space\\" + fileName;
	ofstream outputAsam;
	outputAsam.open(path);

	vector<string> locLines = fileLines;

	int x = 0;
	while(x < locLines.size()-1) {
		outputAsam << locLines[x] << '\n';
		x++;
	}

	outputAsam.close();
}

/***************************************************************************/
void asasmlibrary::assembleFile() {
	system("assembleAirGeneratedContent.bat");
}

/***************************************************************************/
void asasmlibrary::changeSearchTags(vector<string> championSearchTags, vector<string> &asamInputFile, string championName) {
	string asamSearchString = "      pushstring          \"" + championName + "\"";
	int lineCounter = 10; //Line displacement between champion name and search tags.

	//Iterate through input file for champion
	for(int i = 0; i < asamInputFile.size()-1; i++) { 
		if(asamInputFile[i] == asamSearchString) {
			
			//replace current search tags with user defined ones.
			for(int j = 0; j <= championSearchTags.size()-1; j++) { 
				asamInputFile[i+lineCounter] = asamPrefix + championSearchTags[j] + asamSuffix;
				lineCounter++;
			}

			asamInputFile[i+lineCounter] = "      newarray            " + toolbox::IntToString(championSearchTags.size());
			return;
		}
	}
}

/***************************************************************************/
void asasmlibrary::readSearchTags(const string champName, vector<string> &searchTags) {
	string asamSearchString = "      pushstring          \"" + champName + "\"";
	string beginSTag =		  "      pushstring          \"";
	string endSTag = "\"";
	string endTags = "newarray";

	int endSTagLength = beginSTag.length();

	int lineCounter = 10; //Line displacement between champion name and search tags.
	int index = -1;

	for(int i = 0; i < m_asasmFile.size()-1; i++) 
	{ 
		if(m_asasmFile[i] == asamSearchString) 
		{
			
			//return current search tags.
			while(true) 
			{ 
				index = m_asasmFile[i+lineCounter].find(endTags);
				
				if(index != -1) 
				{
					break;
				}

				//Remove excess characters around category string
				string temp = m_asasmFile[i+lineCounter];
				temp.erase(0, endSTagLength);
				temp.erase(temp.end() - 1, temp.end());

				searchTags.push_back(temp);
				m_asasmFile.erase(m_asasmFile.begin()+i+lineCounter, m_asasmFile.begin()+i+lineCounter+1);
				//lineCounter++;
			}

		}
	}
}

//Read Categories
void asasmlibrary::readCategoryList(vector<string> &categoryList) {
	string categoryListBegin = "      findproperty        QName(PackageNamespace(\"\"), \"championSearchTags\")";
	string categoryListEnd = "      newarray";
	string categoryPrefix = "      pushstring          \"";
	int begin;
	int index;

	int prefixLength = categoryPrefix.size();
	
	for(int i = 6361;i < m_asasmFile.size(); i++) {
			begin = m_asasmFile[i].find(categoryListBegin);

			if(begin != -1) {
				for(int j = i+1; j < m_asasmFile.size(); j++) {
					index = m_asasmFile[j].find(categoryListEnd);

					if(index != -1) {
						break;
					}

					//Remove excess characters around category string
					string temp = m_asasmFile[j];
					temp.erase(0, prefixLength);
					temp.erase(temp.end() - 1, temp.end());

					categoryList.push_back(temp);
				}
			}

	}
}

void asasmlibrary::getAsasmFile(std::vector<std::string> &asamFile)
{
	asamFile = m_asasmFile;
}
