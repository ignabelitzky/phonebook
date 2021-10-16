#include "phonebook.h"
#include "./ui_phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addItem()));
    connect(ui->editButton, SIGNAL(clicked(bool)), this, SLOT(editItem()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteItem()));
}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::addItem()
{
    EditDialog dlg(this);
    if(dlg.exec() == QDialog::Accepted)
        ui->list->addItem(dlg.name() + "--" + dlg.number());
}

void Phonebook::deleteItem()
{
    delete ui->list->currentItem();
}

void Phonebook::editItem()
{
    if(!ui->list->currentItem())
        return;
    QStringList parts = ui->list->currentItem()->text().split("--");
    EditDialog dlg(this);
    dlg.setName(parts[0].trimmed());
    dlg.setNumber(parts[1].trimmed());
    if(dlg.exec() == QDialog::Accepted)
        ui->list->currentItem()->setText(dlg.name() + "--" + dlg.number());
}

