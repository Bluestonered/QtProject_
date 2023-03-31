//
// Created by blue on 18/03/23.
//

#ifndef QTPROJECT_MAINWINDOW_H
#define QTPROJECT_MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>

class MainWindow : public QWidget {
public:
    MainWindow(QString projectName, QFile file);
    ~MainWindow();

    QFile fileo;
};


#endif //QTPROJECT_MAINWINDOW_H
