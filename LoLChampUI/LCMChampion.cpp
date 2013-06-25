#include "LCMChampion.h"



//Function Definitions
/***************************************************************************/
LCMChampion::LCMChampion(std::string champName, std::vector<std::string> &searchTags) {
	m_champName = champName;
	m_searchTags = searchTags;
}

/***************************************************************************/
void LCMChampion::setSearchTags(std::vector<std::string> searchTags) {
	m_searchTags = searchTags;
}

/***************************************************************************/
void LCMChampion::setChampName(std::string champName) {
	m_champName = champName;
}

/***************************************************************************/
std::string LCMChampion::getChampName() {
	return m_champName;
}

/***************************************************************************/
std::vector<std::string> LCMChampion::getSearchTags() {
	return m_searchTags;
}
