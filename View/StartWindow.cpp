//
// Created by blue on 18/03/23.
//

#include "StartWindow.h"
#include "MainWindow.h"
#include <QMenuBar>
#include <QPushButton>
#include <QWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

#include <iostream>

StartWindow::StartWindow()
{
    setFixedSize(612, 312);
    setWindowTitle(tr("QtProject"));

    // Création de la barre de menu
    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *characMenu = menuBar->addMenu("File");
    QAction *action1 = new QAction("New", this);
    QAction *action2 = new QAction("Open", this);
    characMenu->addAction(action1);
    characMenu->addAction(action2);

    // Création des deux boutons
    QPushButton *button1 = new QPushButton("New Project", this);
    QPushButton *button2 = new QPushButton("Open Project", this);

    // Calcul de la position des boutons
    int buttonWidth = 200;
    int buttonHeight = 200;
    int x = width() / 2 - buttonWidth;
    int y = height() / 2 - buttonHeight / 2;

    // Positionnement des boutons
    button1->setGeometry(QRect(QPoint(x, y), QSize(buttonWidth, buttonHeight)));
    button2->setGeometry(QRect(QPoint(x + buttonWidth + 50, y), QSize(buttonWidth, buttonHeight)));

    // Connexion des signaux des boutons à des slots
    connect(button1, &QPushButton::clicked, this, &StartWindow::onButton1Clicked);
    connect(button2, &QPushButton::clicked, this, &StartWindow::onButton2Clicked);

    // Connexion de l'action "New" à la même fonction que le bouton 1
    connect(action1, &QAction::triggered, this, &StartWindow::onButton1Clicked);
    connect(action2, &QAction::triggered, this, &StartWindow::onButton2Clicked);
}

StartWindow::~StartWindow()
{

}

void StartWindow::onButton1Clicked()
{
    QString projectDir = QDir::homePath() + "/Documents/ProjectQT";
    QDir dir(projectDir);
    if(!dir.exists()){
        dir.mkpath(projectDir);
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Create Project", projectDir, "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            file.close();
            MainWindow *NewWindow = new MainWindow(QFileInfo(fileName).fileName(), fileName);
            NewWindow->show();
            this->close();
        }
    }
}


void StartWindow::onButton2Clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Project", QDir::homePath() + "/Documents/ProjectQT", "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            file.close();

            MainWindow *newWindow = new MainWindow(QFileInfo(fileName).fileName(), fileName);
            newWindow->setAttribute(Qt::WA_DeleteOnClose); // Supprimer la fenêtre lorsque elle est fermée
            newWindow->show();
            this->close();
        }
    }
}



