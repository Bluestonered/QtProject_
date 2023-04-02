//
// Created by blue on 18/03/23.
//

#ifndef QTPROJECT_MAINWINDOW_H
#define QTPROJECT_MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>
#include "../Controller/SlotController.h"
#include "../Model/SlotModel.h"

class MainWindow : public QWidget {

public:
    MainWindow(QString projectName, QFile file, int New);
    ~MainWindow();

    QFile fileo;
};


#endif //QTPROJECT_MAINWINDOW_H
