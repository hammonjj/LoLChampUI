#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class addCategoryDialog;
}

class addCategoryDialog : public QDialog
{
    Q_OBJECT

signals:
	void newCategoryString();

public:
    explicit addCategoryDialog(QWidget *parent = 0);
	void setCategoryString(std::string category);
	std::string getCategoryString();
    ~addCategoryDialog();
    
private slots:
    void on_btn_accept_clicked();
    void on_btn_cancel_clicked();

private:
	std::string m_category;
    Ui::addCategoryDialog *ui;
};

#endif // ADDCATEGORYDIALOG_H
