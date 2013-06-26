#include "addcategorydialog.h"
#include "ui_addcategorydialog.h"

addCategoryDialog::addCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCategoryDialog)
{
    ui->setupUi(this);

	connect(ui->btn_cancel,SIGNAL(clicked()),this,SLOT(on_btn_cancel_clicked()));  
	connect(ui->btn_accept,SIGNAL(clicked()),this,SLOT(on_btn_accept_clicked())); 
}

addCategoryDialog::~addCategoryDialog()
{
    delete ui;
}

void addCategoryDialog::on_btn_accept_clicked()
{
	QString newCategory = ui->edit_categoryText->text();
	m_category = newCategory.toUtf8();

	close();

}

void addCategoryDialog::on_btn_cancel_clicked()
{
	close();

}

void addCategoryDialog::setCategoryString(std::string category) {
	m_category = category;
}

std::string addCategoryDialog::getCategoryString() {
	return m_category;
}
