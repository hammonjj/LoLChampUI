#ifndef UICADDCHAMPIONDIALOG_H
#define UICADDCHAMPIONDIALOG_H

#include <QDialog>

namespace Ui {
class UICAddChampionDialog;
}

class UICAddChampionDialog : public QDialog
{
    Q_OBJECT
    
signals:
	void newChampionString();

public:
    explicit UICAddChampionDialog(QWidget *parent = 0);
    ~UICAddChampionDialog();
    
private slots:
    void on_btn_cancel_clicked();
    void on_btn_accept_clicked();

private:
    Ui::UICAddChampionDialog *ui;
};

#endif // UICADDCHAMPIONDIALOG_H
