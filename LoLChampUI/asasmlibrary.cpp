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
void asasmlibrary::writeFile(string fileName, vector<string> &fileLines) {
	//string path = "Test Space\\" + fileName;
	ofstream outputAsam;
	outputAsam.open(fileName);


	for(int i = 0; i < fileLines.size(); i++)
	{
		outputAsam << fileLines[i] << '\n';
	}

	outputAsam.close();
}

void asasmlibrary::writeFile(string fileName) {
	//string path = "tmp\\" + fileName;
	ofstream outputAsam;
	outputAsam.open(fileName);


	for(int i = 0; i < m_asasmFile.size(); i++)
	{
		outputAsam << m_asasmFile[i] << '\n';
	}

	outputAsam.close();
}

/***************************************************************************/
void asasmlibrary::assembleFile() {
	system("assembleAirGeneratedContent.bat");

	//Commands are happening too fast?  Batch file works for now.
	//system("\"C:\\Users\\admin\\Documents\\GitHub\\LoLChampUI\\LoLChampUI\\Resources\\RABCDAsm_v1.13\\rabcasm.exe\" \"C:\\Users\\admin\\Documents\\GitHub\\LoLChampUI\\LoLChampUI\\asasm\\0.0.1.30\\AirGeneratedContent-0\\AirGeneratedContent-0.main.asasm\"");
	//system("\"C:\\Users\\admin\\Documents\\GitHub\\LoLChampUI\\LoLChampUI\\Resources\\RABCDAsm_v1.13\\abcreplace.exe\" \"C:\\Users\\admin\\Documents\\GitHub\\LoLChampUI\\LoLChampUI\\asasm\\0.0.1.30\\AirGeneratedContent.swf\" 0 \"C:\\Users\\admin\\Documents\\GitHub\\LoLChampUI\\LoLChampUI\\asasm\\0.0.1.30\\AirGeneratedContent-0\\AirGeneratedContent-0.main.abc\"");
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
				m_asasmFile.erase(m_asasmFile.begin()+i+lineCounter);
			}
		}
	}
}

//Read Categories
void asasmlibrary::readCategoryList(vector<string> &categoryList) {
	string categoryListBegin = "      findproperty        QName(PackageNamespace(\"\"), \"championSearchTags\")";
	string categoryListEnd = "      initproperty        QName(PackageNamespace(\"\"), \"championSearchTags\")";
	string categoryPrefix = "      pushstring          \"";
	bool complete = false;

	int prefixLength = categoryPrefix.size();
	
	for(int i = 6000;i < m_asasmFile.size(); i++) 
	{
		if(m_asasmFile[i] == categoryListBegin)
		{
			for(int j = i+1; j < m_asasmFile.size(); ) 
			{
				if(categoryListEnd == m_asasmFile[j+1])
				{
					m_asasmFile.erase(m_asasmFile.begin()+j);
					complete = true;
					break;
				}

				if(m_asasmFile[j] == "end ; class")
				{
					_ASSERT("End of file reached without finding end of categories!");
					break;
				}

				//Remove excess characters around category string
				string temp = m_asasmFile[j];
				temp.erase(0, prefixLength);
				temp.erase(temp.end() - 1, temp.end());

				categoryList.push_back(temp);
				m_asasmFile.erase(m_asasmFile.begin()+j);
			}
		}

		if(complete == true)
		{
			break;
		}
	}
}

void asasmlibrary::getAsasmFile(std::vector<std::string> &asamFile)
{
	asamFile = m_asasmFile;
}

void asasmlibrary::insertSearchTags(std::vector<LCMChampion> &championInventory)
{
	int lineCounter = 10; //Line displacement between champion name and search tags.
	string beginSTag =		  "      pushstring          \"";
	string endSTag = "\"";
	string endTags = "      newarray            ";

	for(int i = 0; i < championInventory.size(); i++)
	{
		string asamSearchString = "      pushstring          \"" + championInventory[i].getChampName() + "\"";
		for(int j = 0; j < m_asasmFile.size(); j++)
		{
			if(m_asasmFile[j] == asamSearchString)
			{
				std::vector<std::string> searchTags = championInventory[i].getSearchTags();
				m_asasmFile[j+lineCounter] = endTags + std::to_string(searchTags.size());
				for(int k = 0; k < searchTags.size(); k++)
				{
					std::string str = beginSTag + searchTags[k] + endSTag;
					m_asasmFile.insert(m_asasmFile.begin()+j+lineCounter, str);
				}
			}
		}
	}
}

void asasmlibrary::insertCategories(std::vector<LCMCategory> &categoryInventory)
{
	string categoryListBegin = "      findproperty        QName(PackageNamespace(\"\"), \"championSearchTags\")";
	string categoryListEnd = "      newarray            ";
	string categoryPrefix = "      pushstring          \"";
	string endCatTag = "\"";
	
	for(int i = 6000; i < m_asasmFile.size(); i++)
	{
		if(m_asasmFile[i] == categoryListBegin)
		{
			std::string sizeStr = categoryListEnd + std::to_string(categoryInventory.size());
			m_asasmFile.insert(m_asasmFile.begin()+i+1, sizeStr);
			for(int j = 0; j < categoryInventory.size(); j++)
			{
				std::string str = categoryPrefix + categoryInventory[j].getCategory() + endCatTag;
				m_asasmFile.insert(m_asasmFile.begin()+i+1, str);		
			}

		}
	}
}