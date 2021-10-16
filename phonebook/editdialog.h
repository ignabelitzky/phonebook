#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

    const QString name() const;
    void setName(const QString&);

    const QString number() const;
    void setNumber(const QString&);

private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
