//
// Created by blue on 18/03/23.
//

#ifndef QTPROJECT_STARTWINDOW_H
#define QTPROJECT_STARTWINDOW_H

#include <QWidget>
#include <QLineEdit>

class StartWindow : public QWidget {

public:
    StartWindow();
    ~StartWindow();
    void onButton1Clicked();
    void onButton2Clicked();

private:

    QLineEdit *projectNameLineEdit;
};


#endif //QTPROJECT_STARTWINDOW_H
