#include "LCMCategory.h"

//Function Definitions
/***************************************************************************/
LCMCategory::LCMCategory(std::string category, std::vector<std::string> championList) {
	m_category = category;
	m_championList = championList;
}

/***************************************************************************/
LCMCategory::LCMCategory(std::string category) {
	m_category = category;
	m_championList.clear();
}

/***************************************************************************/
void LCMCategory::setChampionList(std::vector<std::string> championList) {
	m_championList = championList;
}

/***************************************************************************/
void LCMCategory::setCategory(std::string category) {
	m_category = category;
}

/***************************************************************************/
void LCMCategory::addChampion(std::string newChampion) {
	int index;

	for(int i = 0; i < m_championList.size(); i++) {
		if(m_championList[i] == newChampion) {
			throw "Champion already in list!";
		}

		if(m_championList[i] > newChampion) {
			index = i;
		}
	}
	
	//Insert champion alphabetically into vector
	m_championList.insert(m_championList.begin()+index, newChampion);
}

/***************************************************************************/
void LCMCategory::removeChampion(std::string oldChampion) {
	for(int i = 0; i < m_championList.size(); i++) {
		if(m_championList[i] == oldChampion) {
			m_championList.erase(m_championList.begin()+i);
			return;
		}
	}

	//If loops completes, champion not in list, but UI won't allow that.
}
/***************************************************************************/
std::string LCMCategory::getCategory(void) {
	return m_category;
}

/***************************************************************************/
std::vector<std::string> LCMCategory::getChampionList(void) {
	return m_championList;
}