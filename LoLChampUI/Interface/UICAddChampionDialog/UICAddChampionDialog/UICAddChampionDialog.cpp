#include "UICAddChampionDialog.h"
#include "ui_UICAddChampionDialog.h"

UICAddChampionDialog::UICAddChampionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UICAddChampionDialog)
{
    ui->setupUi(this);

    connect(ui->btn_cancel,SIGNAL(clicked()),this,SLOT(on_btn_cancel_clicked()));
    connect(ui->btn_accept,SIGNAL(clicked()),this,SLOT(on_btn_accept_clicked()));
	
	connect(w, SIGNAL(currentCategories(std::vector<std::string>)),this,SLOT(on_championListRecieved(std::vector<std::string>)));
}

UICAddChampionDialog::~UICAddChampionDialog()
{
    delete ui;
}

void UICAddChampionDialog::on_championListRecieved(std::vector<std::string> championList)
{
	for(int i = 0; i < championList.size(); i++) 
	{
		//Add vector strings to combo box.
		//myComboBox->addItem(myString);
	}
}

void UICAddChampionDialog::on_btn_cancel_clicked()
{
    close();
}

void UICAddChampionDialog::on_btn_accept_clicked()
{
    close();
    emit newChampionString();
}
