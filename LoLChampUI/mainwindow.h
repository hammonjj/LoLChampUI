#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "LCMChampion.h"
#include "LCMCategory.h"
#include "addcategorydialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
	void openNewCategoryWindow(std::string &category);

public:
    explicit MainWindow(QWidget *parent = 0);
    void UpdatePrimaryList_Champion(void);
	void UpdatePrimaryList_Category(void);
	void UpdateSecondaryList_Champion(void);
    void pullChampionNames(QStringList &l_championNames);
	void pullCategoryNames(QStringList &l_categoryNames);
	void setChampionInventory(std::vector<LCMChampion> &championInventory);
	void setCategoryInventory(std::vector<LCMCategory> &categoryInventory);

    ~MainWindow();
    
private slots:
    void on_addPrimary_clicked();
    void on_removePrimary_clicked();
    void on_addSecondary_clicked();
    void on_removeSecondary_clicked();
	void on_restore_clicked();
	void on_apply_clicked();
	void on_rad_byCategory_selected(bool checked);
	void on_rad_byChampion_selected(bool checked);


    void on_list_primary_changed(QModelIndex index);

private:
    Ui::MainWindow *ui;
	addCategoryDialog *newCategoryDialog;
    QStringListModel* m_model;
	QStringListModel* m_smodel;
    std::vector<LCMChampion> m_championInventory;
	std::vector<LCMCategory> m_categoryInventory;

	void listByChampion(void);
	void listByCategory(void);
	void clear_secondaryList(void);
};

#endif // MAINWINDOW_H
