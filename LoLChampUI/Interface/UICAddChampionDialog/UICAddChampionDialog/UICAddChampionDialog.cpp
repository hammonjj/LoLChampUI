#include "UICAddChampionDialog.h"
#include "ui_UICAddChampionDialog.h"

UICAddChampionDialog::UICAddChampionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UICAddChampionDialog)
{
    ui->setupUi(this);

    connect(ui->btn_cancel,SIGNAL(clicked()),this,SLOT(on_btn_cancel_clicked()));
    connect(ui->btn_accept,SIGNAL(clicked()),this,SLOT(on_btn_accept_clicked()));
}

UICAddChampionDialog::~UICAddChampionDialog()
{
    delete ui;
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
