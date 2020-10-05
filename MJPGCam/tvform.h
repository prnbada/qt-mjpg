#ifndef TVFORM_H
#define TVFORM_H

#include <QWidget>

namespace Ui {
class TvForm;
}

class TvForm : public QWidget
{
    Q_OBJECT

public:
    explicit TvForm(QWidget *parent = nullptr);
    ~TvForm();

private:
    Ui::TvForm *ui;
};

#endif // TVFORM_H
