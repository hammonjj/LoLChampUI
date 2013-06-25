#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


#include "LCMChampion.h"
#include "LCMCategory.h"
#include "asasmlibrary.h"

using std::cout;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

string L_CHAMP_GENERATED_DATA_PATH = "Resources\\ASAM\\0.0.1.28\\AirGeneratedContent-0\\com\\riotgames\\platform\\gameclient\\domain\\";
string L_CHAMP_GENERATED_DATA_ASAM = "ChampionGeneratedData.class.asasm";

asasmlibrary* ChampionGeneratedData;

void readChampList(vector<string> &champList);
void printChampInventory(vector<LCMChampion> &championInventory);
void championHandler(vector<string> &championList, 	vector<string> &championSearchTags, vector<LCMChampion> &championInventory);
void categoryHandler(vector<string> &categoryList, vector<LCMCategory> &categoryInventory, vector<LCMChampion> &championInventory);
void printCategoryInventory(vector<string> &categoryInvetory);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	w.show();

    vector<string> championList;
    vector<string> championSearchTags;
    vector<LCMChampion> championInventory;

    vector<LCMCategory> categoryInventory;
    vector<string> categoryList;

    ChampionGeneratedData = new asasmlibrary(L_CHAMP_GENERATED_DATA_PATH + L_CHAMP_GENERATED_DATA_ASAM);

    championHandler(championList, championSearchTags, championInventory);
    categoryHandler(categoryList, categoryInventory, championInventory);   

    w.setChampionInventory(championInventory);
	w.setCategoryInventory(categoryInventory);

    delete ChampionGeneratedData;

    return a.exec();
}

//Function Definitions
/***************************************************************************/
void championHandler(vector<string> &championList, 	vector<string> &championSearchTags, vector<LCMChampion> &championInventory) {
    readChampList(championList);

    for(int i = 0; i <= championList.size(); i++) {
        //Break loop at the end of championList
        if(championList[i] == "END") {
            break;
        }

        //Retrive search tags and place in vector of champions
        ChampionGeneratedData->readSearchTags(championList[i], championSearchTags);
        LCMChampion tempChampionContainer(championList[i], championSearchTags);
        championInventory.push_back(tempChampionContainer);
        championSearchTags.clear();
    }
}

/***************************************************************************/
void categoryHandler(vector<string> &categoryList, vector<LCMCategory> &categoryInventory, vector<LCMChampion> &championInventory) {
        ChampionGeneratedData->readCategoryList(categoryList);
		
		
		//Iterate through category list
		for(int i = 0; i < categoryList.size(); i++) {
			vector<string> championList;
			//Iterate through champion list
			for(int j = 0; j < championInventory.size(); j++) {
				vector<string> tempVec = championInventory[j].getSearchTags();

					//Match champion name with category and add to category list
					for(int k = 0; k < tempVec.size(); k++) {
						if(tempVec[k] == categoryList[i]) {
							string name = championInventory[j].getChampName();
							championList.push_back(name);
						}
					}
			}
			LCMCategory temp(categoryList[i], championList);
			categoryInventory.push_back(temp);
		}

}

/***************************************************************************/
void readChampList(vector<string> &champList) {
    ifstream chplst_stream;
    chplst_stream.open("Resources\\chplst.dat");

    if(chplst_stream.is_open()) {
        string line;

        while(chplst_stream.good()) {
            getline(chplst_stream, line);
            champList.push_back(line);
        }
    }
    chplst_stream.close();
}

/***************************************************************************/
void printChampInventory(vector<LCMChampion> &championInventory) {
    for(int i = 0; i < championInventory.size(); i++) {
        cout << championInventory[i].getChampName() << "\n";

        vector<string> tempSearchTags = championInventory[i].getSearchTags();

        for(int j = 0; j < tempSearchTags.size(); j++) {
            cout << "-> " << tempSearchTags[j] << "\n";
        }

        cout << "\n\n";
    }
}

void printCategoryInventory(vector<string> &categoryInvetory) {
    for(int i = 0; i < categoryInvetory.size(); i++) {
        cout << categoryInvetory[i] << "\n";
    }
}
