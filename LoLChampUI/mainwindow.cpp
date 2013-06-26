#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMainWindow>
#include <QStringList>
#include <string>
#include <vector>

#include "LCMChampion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->btn_addPrimary->setEnabled(false);
	ui->btn_removePrimary->setEnabled(false);
	ui->list_primary->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->list_secondary->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//Event Listeners
	connect(ui->list_primary,SIGNAL(clicked(const QModelIndex)),this,SLOT(on_list_primary_changed(QModelIndex)));  

	connect(ui->btn_addPrimary,SIGNAL(clicked()),this,SLOT(on_addPrimary_clicked()));  
	connect(ui->btn_removePrimary,SIGNAL(clicked()),this,SLOT(on_addSecondary_clicked()));  
	connect(ui->btn_addSecondary,SIGNAL(clicked()),this,SLOT(on_addSecondary_clicked()));  
	connect(ui->btn_removeSecondary,SIGNAL(clicked()),this,SLOT(on_removeSecondary_clicked()));  
	connect(ui->btn_apply,SIGNAL(clicked()),this,SLOT(on_apply_clicked()));  
	connect(ui->btn_restore,SIGNAL(clicked()),this,SLOT(on_restore_clicked()));  

	connect(ui->rad_byChampion,SIGNAL(toggled(bool)),this,SLOT(on_rad_byChampion_selected(bool)));  
	connect(ui->rad_byCategory,SIGNAL(toggled(bool)),this,SLOT(on_rad_byCategory_selected(bool)));  

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clear_secondaryList(void) {
	m_smodel = new QStringListModel(ui->list_secondary);
    QString str = " ";
	QStringList emptyList;
	emptyList.append(str);
    m_smodel->setStringList(emptyList);
    ui->list_secondary->setModel(m_smodel);
}

void MainWindow::UpdatePrimaryList_Champion(void) {
    m_model = new QStringListModel(ui->list_primary);
	QStringList l_championNames;

    pullChampionNames(l_championNames);
    m_model->setStringList(l_championNames);
    ui->list_primary->setModel(m_model);
}

void MainWindow::UpdatePrimaryList_Category(void) {
    m_model = new QStringListModel(ui->list_primary);
    QStringList l_categoryNames;

	pullCategoryNames(l_categoryNames);
    m_model->setStringList(l_categoryNames);
    ui->list_primary->setModel(m_model);
}

void MainWindow::pullChampionNames(QStringList &l_championNames) {
    std::string nameString;
    QString str;

    for(int i = 0; i < m_championInventory.size() ; i++) {
        //Convert from string to qstring
        nameString = m_championInventory[i].getChampName();
        str = QString::fromUtf8(nameString.c_str());

        //Add converted name to m_championNames
        l_championNames.append(str);
    }
}

void MainWindow::pullCategoryNames(QStringList &l_categoryNames) {
    std::string categoryString;
    QString str;

    for(int i = 0; i < m_categoryInventory.size() ; i++) {
        //Convert from string to qstring
        categoryString = m_categoryInventory[i].getCategory();
        str = QString::fromUtf8(categoryString.c_str());

        //Add converted name to m_championNames
        l_categoryNames.append(str);
    }
}

void MainWindow::setChampionInventory(std::vector<LCMChampion> &championInventory) {
	 m_championInventory = championInventory;
	 UpdatePrimaryList_Champion();
}

void MainWindow::setCategoryInventory(std::vector<LCMCategory> &categoryInventory) {
	m_categoryInventory = categoryInventory;
}

void MainWindow::listByChampion(void) {
	ui->list_primary->setModel(m_model);
}

void MainWindow::listByCategory(void) {
	ui->list_secondary->setModel(m_model);
}

//Event Listener Methods
/**********************************************************************************************************/
void MainWindow::on_addPrimary_clicked()
{
	bool bByCategory = ui->rad_byCategory->isChecked();
	if(bByCategory == true) {
		//Create addCategoryDialog box
		std::string category;
		openNewCategoryWindow(category);
		
		LCMCategory tempCat(category);
		m_categoryInventory.push_back(tempCat);
	}

	if(ui->rad_byChampion->isChecked()) {
		return;
	}
}

void MainWindow::openNewCategoryWindow(std::string &category) {
	newCategoryDialog = new addCategoryDialog();
	newCategoryDialog->show();
	category = newCategoryDialog->getCategoryString();
}

void MainWindow::on_removePrimary_clicked()
{
	if(ui->rad_byCategory->isChecked()) {
		//Remove Category from list
	}

	if(ui->rad_byChampion->isChecked()) {
		return;
	}
}

void MainWindow::on_addSecondary_clicked()
{
	if(ui->rad_byCategory->isChecked()) {
		//Create addCategoryDialog box
	}

	if(ui->rad_byChampion->isChecked()) {
		//Create addChampionDialog box
	}
}

void MainWindow::on_removeSecondary_clicked()
{
	int x=0;
	if(ui->rad_byCategory->isChecked()) {
		
	}

	if(ui->rad_byChampion->isChecked()) {
		//Create addChampionDialog box
	}
}

void MainWindow::on_restore_clicked() {
	//Restore original riot .swf file
}

void MainWindow::on_apply_clicked() {
	//Make changes to asasm vector and assemble file
}

void MainWindow::on_rad_byCategory_selected(bool checked) {
	if(checked == true) {
		ui->btn_addPrimary->setEnabled(true);
		ui->btn_removePrimary->setEnabled(true);

		clear_secondaryList();
		UpdatePrimaryList_Category();
	}
}

void MainWindow::on_rad_byChampion_selected(bool checked) {
	if(checked == true) {
		ui->btn_addPrimary->setEnabled(false);
		ui->btn_removePrimary->setEnabled(false);

		clear_secondaryList();
		UpdatePrimaryList_Champion();
	}
}

void MainWindow::on_list_primary_changed(QModelIndex index)
{
	bool byChampionToggled = ui->rad_byChampion->isChecked();

	if(byChampionToggled == true) {
		int row = index.row();
		m_smodel = new QStringListModel(ui->list_secondary);

		QStringList searchTagList;

		std::vector<std::string> searchTag = m_championInventory[row].getSearchTags();

		for(int i = 0; i < searchTag.size(); i++) {
			QString str = QString::fromUtf8(searchTag[i].c_str());
			searchTagList.append(str);
		}

		//Add converted name to model
		m_smodel->setStringList(searchTagList);
		ui->list_secondary->setModel(m_smodel);
	}

	if(byChampionToggled == false) {
		int row = index.row();
		m_smodel = new QStringListModel(ui->list_secondary);

		QStringList championList;

		std::vector<std::string> championList_s = m_categoryInventory[row].getChampionList();

		for(int i = 0; i < championList_s.size(); i++) {
			QString str = QString::fromUtf8(championList_s[i].c_str());
			championList.append(str);
		}

		//Add converted name to model
		m_smodel->setStringList(championList);
		ui->list_secondary->setModel(m_smodel);
	}
}

/**********************************************************************************************************/
