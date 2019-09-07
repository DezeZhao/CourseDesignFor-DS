#ifndef PERSONINFOWINDOW_H
#define PERSONINFOWINDOW_H

#include <QMainWindow>

namespace Ui {
class PersonInfoWindow;
}

class PersonInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonInfoWindow(QWidget *parent = nullptr);
    ~PersonInfoWindow();

private:
    Ui::PersonInfoWindow *ui;
};

#endif // PERSONINFOWINDOW_H
