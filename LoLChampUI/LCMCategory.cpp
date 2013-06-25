#include "LCMCategory.h"

//Function Definitions
/***************************************************************************/
LCMCategory::LCMCategory(std::string category, std::vector<std::string> championList) {
	m_category = category;
	m_championList = championList;
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
std::string LCMCategory::getCategory(void) {
	return m_category;
}

/***************************************************************************/
std::vector<std::string> LCMCategory::getChampionList(void) {
	return m_championList;
}